#include<stdio.h>

int main(void)
{
    int age;
    printf("Input Age: ");
    scanf("%d",&age);
    // if (age > 18)
    // {
    //     printf("Preson is eligiable to vote");
    // }
    // else
    // {
    //     printf("Person is not eligiable to vote");
    // }
    (age >= 18) ? printf("Preson is eligiable to vote") : printf("Person is not eligiable to vote");
}