/*
A two-dimensional matrix can be multiplied by another matrix to give a matrix whose elements are
the sum of the products of the elements within a row from the first matrix and the associated elements
of a column of the second matrix.
Both matrices should either be square matrices, or the number of columns of the first matrix should equal the number of rows of the second matrix.
To calculate each element of the resultant matrix, multiply the first element of a given row from the
first matrix and the first element of a given column in the second matrix, add that to the product of
the second element of the same row and the second element of the same column, and keep doing so
until the last elements of the row and column have been multiplied and added to the sum.
Write a program to calculate the product of 2 integer matrices and store the result in a third matrix.
Use two-dimensional arrays for your implementation.
Assume that all possible input matrices are smaller than 20x20.
Your code should take the input matrices from the user via terminal input, compute matrix product of the inputs and print out the result.
You are required to conduct dimensionality checks on the inputs.
*/

#include <stdio.h>

#define MAX_SIZE 20

int main()
{
    int m1[MAX_SIZE][MAX_SIZE], m2[MAX_SIZE][MAX_SIZE], res[MAX_SIZE][MAX_SIZE];
    int m1_m, m1_n, m2_m, m2_n, i, j, k;

    // input first matrix
    printf("Enter the dimensions of the first matrix (m x n): ");
    scanf("%d %d", &m1_m, &m1_n);
    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < m1_m; i++)
    {
        for (j = 0; j < m1_n; j++)
        {
            scanf("%d", &m1[i][j]);
        }
    }

    // input second matrix
    printf("Enter the dimensions of the second matrix (m x n): ");
    scanf("%d %d", &m2_m, &m2_n);
    if (m1_n != m2_m)
    {
        printf("Error: the number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return 1;
    }
    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < m2_m; i++)
    {
        for (j = 0; j < m2_n; j++)
        {
            scanf("%d", &m2[i][j]);
        }
    }

    // calculate matrix product
    for (i = 0; i < m1_m; i++)
    {
        for (j = 0; j < m2_n; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < m1_n; k++)
            {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    // output the result
    printf("The product of the matrices is:\n");
    for (i = 0; i < m1_m; i++)
    {
        for (j = 0; j < m2_n; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}
