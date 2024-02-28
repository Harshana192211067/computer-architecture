#include <stdio.h>

int main() {
    int a = 8;
    int b = 10;
    int fetch_stage_clock = 1; // Clock cycle for fetch stage
    int execute_stage_clock = 1; // Clock cycle for execute stage

    // Fetch stage: Fetch instruction
    printf("Fetch stage: Instruction fetched\n");
    printf("Clock cycle: %d\n", fetch_stage_clock);

    // Execute stage: Perform addition
    printf("Execute stage: Addition performed\n");
    printf("Clock cycle: %d\n", execute_stage_clock);

    // Result
    int result = a + b;
    printf("Result of addition: %d\n", result);

    return 0;
}

