#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PAGE_SIZE 1024
#define NUM_PAGES 256
#define MEMORY_SIZE (PAGE_SIZE * NUM_PAGES)
#define FRAME_SIZE 256
#define NUM_FRAMES (MEMORY_SIZE / FRAME_SIZE)

int page_table[NUM_PAGES];
char physical_memory[MEMORY_SIZE];
char disk_space[MEMORY_SIZE];

void init_page_table() {
    for (int i = 0; i < NUM_PAGES; i++) {
        page_table[i] = -1; // Indicates page is not in memory
    }
}

void handle_page_fault(int page_number) {
    // Simulate page replacement (Random page replacement strategy)
    int frame_number = rand() % NUM_FRAMES;

    // Evict the existing page in the frame if it's occupied
    if (page_table[frame_number] != -1) {
        // Simulate writing back to disk (optional)
        // disk_space[page_table[frame_number] * PAGE_SIZE] = physical_memory[frame_number * PAGE_SIZE];
        printf("Page %d evicted from frame %d\n", page_table[frame_number], frame_number);
    }

    // Load the page from disk into memory
    for (int i = 0; i < PAGE_SIZE; i++) {
        physical_memory[frame_number * PAGE_SIZE + i] = disk_space[page_number * PAGE_SIZE + i];
    }
    printf("Page %d loaded into frame %d\n", page_number, frame_number);

    // Update the page table
    page_table[page_number] = frame_number;
}

void read_memory(int virtual_address) {
    int page_number = virtual_address / PAGE_SIZE;
    int offset = virtual_address % PAGE_SIZE;
    
    if (page_table[page_number] == -1) {
        printf("Page fault occurred for virtual address %d\n", virtual_address);
        handle_page_fault(page_number);
    }
    
    int physical_address = page_table[page_number] * PAGE_SIZE + offset;
    char value = physical_memory[physical_address];
    
    printf("Read from virtual address %d. Physical address: %d. Value: %c\n", virtual_address, physical_address, value);
}

int main() {
    // Initialize page table
    init_page_table();
    
    // Initialize disk space with random data
    for (int i = 0; i < MEMORY_SIZE; i++) {
        disk_space[i] = rand() % 256; // Random byte
    }
    
    // Perform some memory reads
    read_memory(0); // Access page 0
    read_memory(5000); // Access page 4
    read_memory(4096); // Access page 4
    read_memory(8192); // Access page 8
    
    return 0;
}

