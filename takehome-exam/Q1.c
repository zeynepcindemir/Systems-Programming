#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ZEYNEP CINDEMIR 201401012 Q1

// Function prototypes
char* reverse(char* input);

int main()
{
    printf("=========================================\n");
    printf("There are two bugs in the previous version of the code:\n");
    printf("First, it does not allocate memory for the output string.\n");
    printf("Second, output variable is the local variable of the function, so it is not accessible outside of the function. (Unexpected behaviour)\n");
    printf("=========================================\n");

    printf("A correct version:\n");
    
    char *input;
    printf("Please enter a string to reverse: \n");
    gets(input);
    printf("The reversed string is: \n");
    char* output = reverse(input);
    printf("%s\n", output);
    free(output);

    return 0;
}

char* reverse(char* input)
{
    int len = strlen(input);
    char* output = (char*) malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++)
    {
        output[len - i - 1] = input[i];
    }
    output[len] = '\0';
    return output;
}
