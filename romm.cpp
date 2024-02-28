#include <stdio.h>

#define ROM_SIZE 256  // Size of the ROM (number of memory locations)

// Function to initialize the ROM with sample data
void initializeROM(int rom[]) {
    // Initialize ROM with sample data
    for (int i = 0; i < ROM_SIZE; i++) {
        rom[i] = i * 2;  // Storing even numbers as sample data
    }
}

// Function to read data from the ROM
int readFromROM(int rom[], int address) {
    // Check if address is within valid range
    if (address >= 0 && address < ROM_SIZE) {
        // Read data from the specified address
        return rom[address];
    } else {
        // Address out of range
        printf("Error: Address out of range\n");
        return -1;  // Return -1 to indicate error
    }
}

int main() {
    int ROM[ROM_SIZE];  // Array to simulate ROM

    // Initialize ROM with sample data
    initializeROM(ROM);

    // Read data from ROM at different addresses
    printf("Reading data from ROM:\n");
    for (int i = 0; i < 10; i++) {  // Reading data from first 10 memory locations
        int address = i;
        int data = readFromROM(ROM, address);
        if (data != -1) {
            printf("Address %d: Data = %d\n", address, data);
        }
    }

    return 0;
}

