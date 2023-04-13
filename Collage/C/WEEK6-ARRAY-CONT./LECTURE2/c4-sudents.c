// structure as an array
#include <stdio.h>

void display(char name[], int reg_num, float cgpa, int roll_num);

struct student
{
    char name[100];
    int reg_num;
    float cgpa;
    int roll_num;
};

int main(void)
{
    int n;
    printf("Enter How Many student: ");
    scanf("%i", &n);
    struct student s[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter Details of %d student.\n", i + 1);
        printf("Enter student Name: ");
        scanf("%s", &s[i].name);
        printf("Enter student reg_num: ");
        scanf("%d", &s[i].reg_num);
        printf("Enter student Roll_num: ");
        scanf("%d", &s[i].roll_num);
        printf("Enter student cgpa: ");
        scanf("%f", &s[i].cgpa);
    }
    printf("Display Deatils\n");
    for (int i = 0; i < n; i++)
    {
        printf("Displaying Details of %d student\n", i + 1);
        display(s[i].name, s[i].reg_num, s[i].cgpa, s[i].roll_num);
    }
}

void display(char name[], int reg_num, float cgpa, int roll_num)
{
    printf("***************\n");
    // printf("Name = %s\nReg Num = %d\nRoll Num = %d\nCGPA = %f\n", name, reg_num, roll_num, cgpa);
    printf("Student Name = %s\n", name);
    printf("Registration Num = %i\n", reg_num);
    printf("Roll Num = %d\n", roll_num);
    printf("CGPA = %f\n", cgpa);
    printf("***************\n");
}