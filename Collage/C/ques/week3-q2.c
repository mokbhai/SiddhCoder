#include<stdio.h>

int main(void)
{
    int n, fact;
    fact = 1;
    scanf("%i", &n);
    for (int i = n; i > 0; i--)
    {
        fact *= i;
    }
    printf("%i", fact);
}