#include <stdio.h>

// Function to perform Booth's multiplication algorithm
int boothMultiplication(int multiplicand, int multiplier) {
    int product = 0;  // Initialize product register to 0

    // Perform iterations
    for (int i = 0; i < 4; i++) { // For 4-bit multiplier (specific to 11 * 13)
        int multiplierBit = (multiplier >> i) & 1;

        // If the current multiplier bit is 1, add the shifted multiplicand to the product
        if (multiplierBit == 1) {
            product += (multiplicand << i);
        }
    }

    return product;
}

int main() {
    int multiplicand = 11;
    int multiplier = 13;

    printf("Multiplicand: %d\n", multiplicand);
    printf("Multiplier: %d\n", multiplier);

    int result = boothMultiplication(multiplicand, multiplier);

    printf("Result of multiplication: %d\n", result);

    return 0;
}

