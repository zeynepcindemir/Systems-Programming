/*
Write a C program to set all values of a 2-D int array to a given int value using one pointer.
Then write a random initializer to randomly fill a 2-D int array.
When your program is run, it should first prompt the user for an int value that will assigned to all array elements and the array dimensions that must be
less than 10.
Once the int value and the array dimensions are given, your program should create, randomly initialize, and print a 2-D int array.
Finally, it should set all the array elements to the int value given by the user and print the final array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void seed_random_number_generator() {
    static int seed_initialized = 0;
    if (!seed_initialized) {
        srand(time(NULL));
        seed_initialized = 1;
    }
}

int *create_array(int rows, int cols) {
    int *arr = malloc(rows * cols * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return arr;
}

void fill_array_randomly(int *arr, int rows, int cols) {
    seed_random_number_generator();
    for (int i = 0; i < rows * cols; i++) {
        arr[i] = rand() % 10;
    }
}

void print_array(int *arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(arr + i * cols + j));
        }
        printf("\n");
    }
}

void set_array_values(int *arr, int rows, int cols, int val) {
    for (int i = 0; i < rows * cols; i++) {
        *(arr + i) = val;
    }
}

int main() {
    int val, rows, cols;

    printf("Enter an integer value: ");
    scanf("%d", &val);

    printf("Enter the number of rows (<10): ");
    scanf("%d", &rows);

    printf("Enter the number of cols (<10): ");
    scanf("%d", &cols);

    int *arr = create_array(rows, cols);
    fill_array_randomly(arr, rows, cols);

    printf("Randomly initialized array:\n");
    print_array(arr, rows, cols);

    set_array_values(arr, rows, cols, val);

    printf("Array after setting all values to %d:\n", val);
    print_array(arr, rows, cols);

    free(arr);
    return 0;
}
