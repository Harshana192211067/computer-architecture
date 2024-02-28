#include <stdio.h>

int main() {
    // Given data
    int access_time_main_memory = 50; // in ns
    int transfer_time_virtual_to_main = 10; // in ns
    double probability_page_fault = 1e-6; // 10^-6

    // Calculate average access time
    double average_access_time = (1 - probability_page_fault) * access_time_main_memory +
                                 probability_page_fault * (access_time_main_memory + transfer_time_virtual_to_main);

    // Print the result
    printf("Average Access Time: %.2f ns\n", average_access_time);

    return 0;
}

