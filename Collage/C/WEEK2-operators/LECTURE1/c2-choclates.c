#include<stdio.h>

int main(void)
{
    int no_choclates;
    int no_students;
    printf("Enter number of choclates: ");
    scanf("%i",&no_choclates);
    printf("Enter number of students: ");
    scanf("%i",&no_students);
    int remaining = no_choclates % no_students;
    printf("So %i choclates will be left as all %i students will have %i choclates", remaining, no_students, no_choclates / no_students);
}