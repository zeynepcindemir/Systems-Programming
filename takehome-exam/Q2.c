#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ZEYNEP CINDEMIR 201401012 Q2

#define MAX_SIZE 1000
#define exp myExp
#define pow myPow
#define factorial myFactorial

// Function prototypes
int memory[MAX_SIZE];
int factorial(int n);
double pow(double x, int n);
double exp(double x, int M);
double exp_2(double x, int M);
void execute1(int M);
void execute2(int M);

int main()
{
    // 0.0 < 𝑥 < 1.0 and 0 ≤ 𝑀 ≤ 10

    int M;
    srand(time(NULL));
    clock_t start, end;
    double total_time;

    start = clock();
    // 1. Compute exp(𝑥) for 1000 random values of 0.0 < 𝑥 < 1.0 with M=10.
    M = 10;
    execute1(10);
    end = clock();
    total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Scenario 1 (OLD) - M=%d, Time taken: %.8f seconds\n", M, total_time);

    start = clock();
    // 2. Compute exp(𝑥) for 1000 random values of 0.0 < 𝑥 < 1.0 with M=15.
    M = 15;
    execute1(15);
    end = clock();
    total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Scenario 2 (OLD) - M=%d, Time taken: %.8f seconds\n", M, total_time);

    start = clock();
    // 3. Compute exp(𝑥) for 1000 random values of 0.0 < 𝑥 < 1.0 with M=18.
    M = 18;
    execute1(18);
    end = clock();
    total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Scenario 3 (OLD) - M=%d, Time taken: %.8f seconds\n", M, total_time);

    start = clock();
    // 1. Compute exp(𝑥) for 1000 random values of 0.0 < 𝑥 < 1.0 with M=10.
    M = 10;
    execute2(10);

    end = clock();
    total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Scenario 1 (NEW) - M=%d, Time taken: %.8f seconds\n", M, total_time);

    start = clock();
    // 2. Compute exp(𝑥) for 1000 random values of 0.0 < 𝑥 < 1.0 with M=15.
    M = 15;
    execute2(15);
    end = clock();
    total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Scenario 2 (NEW) - M=%d, Time taken: %.8f seconds\n", M, total_time);

    start = clock();
    // 3. Compute exp(𝑥) for 1000 random values of 0.0 < 𝑥 < 1.0 with M=18.
    M = 18;
    execute2(18);
    end = clock();
    total_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Scenario 3 (NEW) - M=%d, Time taken: %.8f seconds\n", M, total_time);

    return 0;
}

int factorial(int n)
{
    if (n < 0)
    {
        printf("Error: Factorial is undefined for negative numbers.\n");
        exit(1);
    }
    else if (n == 0 || n == 1)
    {
        return 1.0;
    }
    else if (n < MAX_SIZE && memory[n] != 0)
    {
        return memory[n];
    }
    else
    {
        int result = n * factorial(n - 1);
        if (n < MAX_SIZE)
        {
            memory[n] = result;
        }
        return result;
    }
}

double pow(double x, int n)
{
    double result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= x;
    }
    return result;
}

double exp(double x, int M)
{
    double sum = 0.0;
    for (int i = 0; i <= M; i++)
    {
        sum += pow(x, i) / factorial(i);
    }
    return sum;
}

double exp_2(double x, int M)
{
    double sum = 1.0;
    double term = 1.0;
    for (int i = 1; i <= M; i++)
    {
        term *= x / i;
        sum += term;
    }
    return sum;
}
void execute1(int M)
{
    for (int i = 0; i < 1000; i++)
    {
        double x = (double)rand() / RAND_MAX;
        exp(x, M);
    }
}
void execute2(int M)
{
    for (int i = 0; i < 1000; i++)
    {
        double x = (double)rand() / RAND_MAX;
        exp_2(x, M);
    }
}
