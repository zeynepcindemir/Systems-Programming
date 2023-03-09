
/*
Write a C program to swap two int arrays using pointers.
Then write a random initializer to randomly fill two int arrays.
When your program is run, it should first prompt the user for an array length that must be less than 20.
Once the array length is given, your program should create, randomly initialize, and print two random int arrays.
Finally, it should swap these arrays and print the final arrays.
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void swapArrays(int *arr1, int *arr2, int size);
int *randArray(int size);
void printArray(int *arr, int size);

int main()
{

    int size;
    printf("Please enter the length value of two arrays (less than 20):\n");
    scanf("%d", &size);

    if (size >= 20)
    {
        printf("Array length must be less than 20.\n");
        return 1;
    }

    printf("Creating two randomly initialized arrays:\n");

    int *arr1 = randArray(size);
    int *arr2 = randArray(size);

    printf("\nBefore swapping:\n");
    printf("arr1: ");
    printArray(arr1, size);
    printf("\narr2: ");
    printArray(arr2, size);

    swapArrays(arr1, arr2, size);

    printf("\nAfter swapping:\n");
    printf("arr1: ");
    printArray(arr1, size);
    printf("\narr2: ");
    printArray(arr2, size);

    free(arr1);
    free(arr2);

    return 0;
}

void swapArrays(int *arr1, int *arr2, int size)
{
    for (int i = 0; i < size; i++)
    {
        int temp = *(arr1 + i);
        *(arr1 + i) = *(arr2 + i);
        *(arr2 + i) = temp;
    }
}

void seed_random_number_generator()
{
    static int seed_initialized = 0;
    if (!seed_initialized)
    {
        srand(time(NULL));
        seed_initialized = 1;
    }
}

int *randArray(int size)
{
    int *arr = malloc(size * sizeof(int));

    seed_random_number_generator();
    int r;

    for (int i = 0; i < size; i++)
    {
        r = rand() % 20;
        *(arr + i) = r;
    }

    return arr;
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            printf("%d,", *(arr + i));
        }
        else
        {
            printf("%d", *(arr + i));
        }
    }
}
