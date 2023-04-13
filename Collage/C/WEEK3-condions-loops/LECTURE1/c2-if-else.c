// divisible by 5
#include<stdio.h>

int main(void)
{
    int a;
    scanf("%i",&a);
    if (a % 5 == 0)
    {
        printf("%i is divisible by 5", a);
    }
    else
    {
        printf("%i is not divisible by 5", a);
    }
}