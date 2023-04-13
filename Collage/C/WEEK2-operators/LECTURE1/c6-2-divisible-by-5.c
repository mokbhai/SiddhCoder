#include<stdio.h>

int main(void)
{
    int num;
    printf("Input Numberr: ");
    scanf("%d",&num);
    (num % 5 == 0) ? printf("Divisible by 5") : printf("Not Divisible by 5");
}