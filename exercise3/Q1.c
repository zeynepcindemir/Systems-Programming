/*
Write a C program that prompts the user to enter three floating point numbers and reads these inputs into three floats, say, A, B and C.
Then, it does the following multiplications using these floats:
D = (A * B) * C
E = A * (B * C)
Once these computations are done, your program evaluates the following condition:
D == E
and reports the result by printing one of the messages: “D is equal to E.” -or- “D is NOT equal to E.”
*/

#include <stdio.h>

int main()
{
    float A, B, C, D, E;

    printf("Enter three floating point numbers: ");
    scanf("%f %f %f", &A, &B, &C);

    D = (A * B) * C;
    E = A * (B * C);

    if (D == E)
    {
        printf("D is equal to E.\n");
    }
    else
    {
        printf("D is NOT equal to E.\n");
    }

    return 0;
}
