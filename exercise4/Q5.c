
#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4

void minimum(const int grades[][EXAMS], size_t pupils, size_t tests);
void maximum(const int grades[][EXAMS], size_t pupils, size_t tests);
void average(const int grades[][EXAMS], size_t pupils, size_t tests);
void modifiedAverage(const int grades[][EXAMS], size_t pupils, size_t tests);
void printArray(const int grades[][EXAMS], size_t pupils, size_t tests);

int main()
{

    void (*processGrades[5])(const int[][EXAMS], size_t, size_t);

    processGrades[0] = &printArray;
    processGrades[1] = &minimum;
    processGrades[2] = &maximum;
    processGrades[3] = &average;
    processGrades[4] = &modifiedAverage;

    int studentGrades[STUDENTS][EXAMS] = {{77, 68, 86, 73},
                                          {96, 87, 89, 78},
                                          {70, 90, 86, 81}};

    int choice;
    printf("Please select your choice [0-4]\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 0:
        processGrades[0](studentGrades, STUDENTS, EXAMS);
        break;
    case 1:
        processGrades[1](studentGrades, STUDENTS, EXAMS);
        break;
    case 2:
        processGrades[2](studentGrades, STUDENTS, EXAMS);
        break;
    case 3:
        processGrades[3](studentGrades, STUDENTS, EXAMS);
        break;
    case 4:
        processGrades[4](studentGrades, STUDENTS, EXAMS);
        break;
    }

    /*
    puts("The array is:\n");
    printArray(studentGrades, STUDENTS, EXAMS);

    minimum(studentGrades, STUDENTS, EXAMS);
    maximum(studentGrades, STUDENTS, EXAMS);

    average(studentGrades, STUDENTS, EXAMS);
    modifiedAverage(studentGrades, STUDENTS, EXAMS);
    */

    return 0;
}

void minimum(const int grades[][EXAMS], size_t pupils, size_t tests)
{
    int lowGrade = 100;

    for (size_t i = 0; i < pupils; ++i)
    {

        for (size_t j = 0; j < tests; ++j)
        {

            if (grades[i][j] < lowGrade)
            {
                lowGrade = grades[i][j];
            }
        }
    }

    printf("lowest grade is %d\n", lowGrade);
}

void maximum(const int grades[][EXAMS], size_t pupils, size_t tests)
{
    int highGrade = 0;

    for (size_t i = 0; i < pupils; ++i)
    {

        for (size_t j = 0; j < tests; ++j)
        {

            if (grades[i][j] > highGrade)
            {
                highGrade = grades[i][j];
            }
        }
    }
    printf("highest grade is %d\n", highGrade);
}
void average(const int grades[][EXAMS], size_t pupils, size_t tests)
{

    for (size_t i = 0; i < pupils; ++i)
    {

        int total = 0;
        double average = 0;
        for (size_t j = 0; j < tests; j++)
        {
            total += grades[i][j];
        }
        average = (double)total / tests;
        printf("average grade of student %d is %.2lf\n", i, average);
    }
}
void printArray(const int grades[][EXAMS], size_t pupils, size_t tests)
{

    printf("\t\t%s", " [0]  [1]  [2]  [3]");

    for (size_t i = 0; i < pupils; ++i)
    {

        printf("\nstudentGrades[%u]  ", i);

        for (size_t j = 0; j < tests; ++j)
        {
            printf("%-5d", grades[i][j]);
        }
    }
    printf("\n");
}

void modifiedAverage(const int grades[][EXAMS], size_t pupils, size_t tests)
{

    int highGrade;
    for (size_t i = 0; i < pupils; ++i)
    {
        highGrade = 0;
        for (size_t j = 0; j < tests; ++j)
        {

            if (grades[i][j] > highGrade)
            {
                highGrade = grades[i][j];
            }
        }
    }

    int lowGrade;
    for (size_t i = 0; i < pupils; ++i)
    {
        lowGrade = 100;
        for (size_t j = 0; j < tests; ++j)
        {

            if (grades[i][j] < lowGrade)
            {
                lowGrade = grades[i][j];
            }
        }
    }

    for (size_t i = 0; i < pupils; ++i)
    {
        int total = 0;
        double average;
        for (size_t j = 0; j < tests; j++)
        {
            total += grades[i][j];
        }
        average = ((double)total - (lowGrade + highGrade)) / tests - 2;
        printf("modified average grade of student %d is %.2lf\n", i, average);
    }
}
