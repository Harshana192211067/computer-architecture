#include <stdio.h>

void booth_multiplication(int multiplicand, int multiplier, int *result) {
    *result = 0;
    int multiplier_bits = 0;
    int sign_bit = multiplier & 0x80000000;
    int multiplicand_temp = multiplicand; // Store the original value of multiplicand
    while (multiplier != 0) {
        int ls_bit = multiplier & 0x1;

        if (ls_bit != multiplier_bits) {
            if (ls_bit == 1) {
                *result += multiplicand_temp;
            } else {
                *result -= multiplicand_temp;
            }
        }
        multiplicand_temp <<= 1;
        int msb = multiplicand_temp & 0x80000000;

        if (msb != 0) {
            multiplicand_temp |= 0xFFFFFFFF;
        }
        multiplier >>= 1;
        multiplier_bits = ls_bit;
    }

    if (sign_bit != 0) {
        *result = -*result;
    }
}

int main() {
    int multiplicand, multiplier;
    int product;

    printf("Enter multiplicand: ");
    scanf("%d", &multiplicand);

    printf("Enter multiplier: ");
    scanf("%d", &multiplier);

    booth_multiplication(multiplicand, multiplier, &product);

    printf("Product: %d\n", product);

    return 0;
}

