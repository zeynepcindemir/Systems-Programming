

/*
Write a C program that decomposes a given integer as powers of its prime divisors. For example, given
12 as input, its output should be 22 * 3, or given 9 as input, its output should be 32.
*/

#include <stdio.h>

void primeFactorization(int n);

int main()
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    primeFactorization(n);
    return 0;
}

void primeFactorization(int n)
{
    int i, j, count;
    printf("%d = ", n);
    for (i = 2; i <= n; i++)
    {
        count = 0;
        while (n % i == 0)
        {
            count++;
            n /= i;
        }
        if (count > 0)
        {
            printf("%d", i);
            if (count > 1)
            {
                printf("^%d", count);
            }
            if (n > 1)
            {
                printf(" * ");
            }
        }
    }
    printf("\n");
}
