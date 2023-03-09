/*
Write a C program to merge two sorted (increasing array index means increasing value) int arrays using pointers.
Arrays can have different lengths. 
Then write a random initializer to create and randomly initialize two sorted int arrays. 
When your program is run, it should first prompt the user for two array lengths that must be less than 50. Once the array lengths are given, your program should create, 
randomly initialize, and print two sorted int arrays. 
Finally, it should merge these arrays and print the final sorted array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 50

void seed_random_number_generator() {
    static int seed_initialized = 0;
    if (!seed_initialized) {
        srand(time(NULL));
        seed_initialized = 1;
    }
}

void print_array(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int* rand_sorted_array(int len) {
    int *arr = (int*) malloc(sizeof(int) * len);
    if (arr != NULL) {
        seed_random_number_generator();
        arr[0] = rand() % 10;
        for (int i = 1; i < len; i++) {
            arr[i] = arr[i - 1] + rand() % 10 + 1;
        }
    }
    return arr;
}

int* merge_sorted_arrays(int *arr1, int len1, int *arr2, int len2) {
    int *merged = (int*) malloc(sizeof(int) * (len1 + len2));
    int i = 0, j = 0, k = 0;
    while (i < len1 && j < len2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }
    while (i < len1) {
        merged[k++] = arr1[i++];
    }
    while (j < len2) {
        merged[k++] = arr2[j++];
    }
    return merged;
}

int main() {
    int len1, len2;
    int *arr1, *arr2, *merged;

    printf("Enter the length of array 1 (<%d): ", MAX_LEN);
    scanf("%d", &len1);

    printf("Enter the length of array 2 (<%d): ", MAX_LEN);
    scanf("%d", &len2);

    arr1 = rand_sorted_array(len1);
    arr2 = rand_sorted_array(len2);

    printf("Array 1: ");
    print_array(arr1, len1);

    printf("Array 2: ");
    print_array(arr2, len2);

    merged = merge_sorted_arrays(arr1, len1, arr2, len2);

    printf("Merged array: ");
    print_array(merged, len1 + len2);

    free(arr1);
    free(arr2);
    free(merged);

    return 0;
}


