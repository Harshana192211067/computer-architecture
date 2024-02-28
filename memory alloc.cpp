#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array; // Pointer to store dynamically allocated memory
    int size, i;

    // Asking user for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocating memory for the array
    array = (int *)malloc(size * sizeof(int));

    // Checking if memory allocation was successful
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exiting the program with error code
    }

    // Getting input for the array elements from the user
    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    // Displaying the array elements
    printf("The elements in the array are: ");
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Freeing dynamically allocated memory
    free(array);

    return 0;
}

