// check which number is greater from 3 numbers
#include<stdio.h>

int main(void)
{
    int a, b, c;
    printf("Enter 3 numbers:\n");
    scanf("%i", &a);
    scanf("%i", &b);
    scanf("%i", &c);
    if (a > b && a > c)
    {
        printf("%i is greater than %i and %i", a, b, c);
    }
    else if (b > c && b > a)
    {
        printf("%i is greater than %i and %i", b, c, a);
    }
    else if (c > a && c > b)
    {
        printf("%i is greater than %i and %i", c, b, a);
    }
    else
    {
        printf("%i, %i and %i are equal", a, b, c);
    }
}