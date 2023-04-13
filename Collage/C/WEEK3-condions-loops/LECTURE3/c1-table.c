// to print table of number
#include <stdio.h>

int main(void)
{
    int num;
    printf("Enter Number: ");
    scanf("%i", &num);
    for (int i = 1; i <= 10; i++)
    {
        printf("%i * %i = %i\n", num, i, num * i);
    }
}