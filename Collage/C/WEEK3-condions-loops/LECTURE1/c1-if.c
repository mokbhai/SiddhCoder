// program to find wheather the given number is greater than 10
#include<cs50.h>
#include<stdio.h>

int main(void)
{
    int a;
    scanf("%i", &a);
    // both if will work
    if (a > 10)
        printf("%i is greater than 10");
    if (a > 10)
    {
        printf("%i is greater than 10");
    }
}