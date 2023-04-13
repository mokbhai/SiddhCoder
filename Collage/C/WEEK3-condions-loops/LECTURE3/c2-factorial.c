// to print factoraial of number
#include <stdio.h>

int main(void)
{
    int num, fact = 1;
    printf("Enter Number: ");
    scanf("%i", &num);
    for (int i = 0; i < num; i++)
    {
        fact *= num - i;
    }
    printf("Factorial of %i is %i", num, fact);
}