#include <math.h>
#include <stdio.h>

int pow1(int a, int b)
{
    for (int i = 0; i < b; i++)
    {
        a *= (a);
    }
    return a;
}

void ftoa1(float f1, char s[])
{
    sprintf(s, "%f", f1); // s is array, %f format specifier and f1 is float variable
}

int atoi1(char *s)
{
    int a, k;
    int n = sizeof(s) / 4;
    for (int i = n - 1; i >= 0; i++)
    {
        k = pow1(10, i);
        a += (int)s[i] * (k);
    }
    return a;
}

int main()
{
    // char str[20];
    // float f = 12.340000;
    // ftoa1(f, str); // it means convert float value f to string and store it in str// function call//
    // printf("\nFTOA%s", str);
    char str[] = "1234";
    int a = atoi1(str);
    printf("Atoi= %d", a);
    return 0;
}