// print sum of digit of number
#include<stdio.h>
int main(void)
{
    int num, sum = 0;
    printf("Enter Number: ");
    scanf("%i", &num);
    while (num <= 0)
    {
        sum = num % 10;
        num = num / 10;
    }
}