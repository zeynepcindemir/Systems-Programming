
/*
The Hadamard product (also known as the element-wise product, entry-wise product) is a binary operation that takes two matrices of the same dimensions and produces another matrix of the same
dimension as the operands, where each element (i, j) of the output is the product of elements (i, j) of the two input matrices.
Using two-dimensional arrays and assuming that all possible input matrices are smaller than 20x20, write a C program that implements the Hadamard product on integer matrices.
Your code should take the input matrices from the user via terminal input, compute the Hadamard product of the inputs and print out the result.
You are required to conduct dimensionality checks on the inputs and accept only matrices of equal sizes.
*/

#include <stdio.h>

#define MAX_SIZE 20

int main()
{
    int m1[MAX_SIZE][MAX_SIZE], m2[MAX_SIZE][MAX_SIZE], res[MAX_SIZE][MAX_SIZE];
    int m, n, i, j;

    // input first matrix
    printf("Enter the dimensions of the first matrix (m x n): ");
    scanf("%d %d", &m, &n);
    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &m1[i][j]);
        }
    }

    // input second matrix
    printf("Enter the dimensions of the second matrix (m x n): ");
    int m2_m, m2_n;
    scanf("%d %d", &m2_m, &m2_n);
    if (m2_m != m || m2_n != n)
    {
        printf("Error: matrices must have the same dimensions.\n");
        return 1;
    }
    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &m2[i][j]);
        }
    }

    // compute the Hadamard product
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            res[i][j] = m1[i][j] * m2[i][j];
        }
    }

    // output the result
    printf("The Hadamard product of the matrices is:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}
