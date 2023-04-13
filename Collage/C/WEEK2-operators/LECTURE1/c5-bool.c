#include<stdio.h>

int main(void)
{
    int x = 1, y = 0, z = 5;
    int a = x && y && z++;
    printf("%d",z);
}