//Write your code in this file

#include <stdio.h>
#include <ctype.h>

#define STUDENTS 5
#define TESTS 13

struct Student
{
    char name[11];
    int scores[13];
    float average;
};

int main()
{
    struct Student students[STUDENTS];

    float combinedAverage = 0;
    int bestIndex = 0;

    for (int i = 0; i < STUDENTS; i++)
    {
        float sum = 0;

        scanf("%s", students[i].name);

        students[i].name[0] = toupper(students[i].name[0]);
        for (int j = 1; students[i].name[j] != '\0'; j++)
        {
            students[i].name[j] = tolower(students[i].name[j]);
        }

        for (int j = 0; j < TESTS; j++)
        {
            scanf("%d", &students[i].scores[j]);
            sum += students[i].scores[j];
        }

        students[i].average = sum / TESTS;

        if (i == 0 || students[i].average > students[bestIndex].average)
        {
            bestIndex = i;
        }

        combinedAverage += students[i].average;
    }
    combinedAverage /= STUDENTS;

    printf("%s\n", students[bestIndex].name);

    for (int i = 0; i < STUDENTS; i++)
    {
        if (students[i].average < combinedAverage)
        {
            printf("%s\n", students[i].name);
        }
    }



    return 0;
}