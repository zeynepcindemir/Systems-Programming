/*
An integer number is said to be a perfect number if its factors, including 1 (but not the number itself), sum to the number.
For example, 6 is a perfect number because 6 = 1 + 2 + 3.
Write a function isPerfect that determines whether parameter number is a perfect number.
Use this function in a program that determines and prints all the perfect numbers between 1 and 1000.
Print the factors of each perfect number to confirm that the number is indeed perfect.
*/

#include <stdio.h>
#include <stdbool.h>

bool isPerfect(int n)
{
    int sum = 1;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
            if (i * i != n)
            {
                sum += n / i;
            }
        }
    }
    return sum == n;
}

int main()
{
    printf("Perfect numbers between 1 and 1000:\n");
    for (int n = 1; n <= 1000; n++)
    {
        if (isPerfect(n))
        {
            printf("%d is a perfect number. Factors: 1 ", n);
            for (int i = 2; i <= n / 2; i++)
            {
                if (n % i == 0)
                {
                    printf("+ %d ", i);
                }
            }
            printf("= %d\n", n);
        }
    }
    return 0;
}
