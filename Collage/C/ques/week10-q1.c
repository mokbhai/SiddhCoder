#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int marks_summation(int* marks, int number_of_students, char gender) 
{
    int sum = 0;
    if (gender == 'b')
    {
        for (int i = 0; i < number_of_students; i += 2)
        {
            sum += marks[i];
        }
    }
    else if (gender == 'g')
    {
        for (int i = 1; i < number_of_students; i += 2)
        {
            sum += marks[i];
        }
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    int marks[n];
    char gender;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &marks[i]);
    }
    gender = getchar();
    int sum = marks_summation(marks, n, gender);
    printf("%d", sum);
}