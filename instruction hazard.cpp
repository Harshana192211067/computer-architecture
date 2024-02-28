#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;
    int c = a + b;  // Instruction 1: Addition
    int d = c * 2;  // Instruction 2: Multiplication, depends on the result of Instruction 1

    // Output the result of the multiplication
    printf("Result: %d\n", d);

    return 0;
}

