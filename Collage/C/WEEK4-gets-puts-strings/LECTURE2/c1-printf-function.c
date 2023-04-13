#include<stdio.h>

int main(void)
{
    int a = 5643;
    printf("%d\n", a); //5643
    printf("*%d\n", a); //*5643
    printf("*%d*\n", a); //*5643*
    printf("*%-6d*\n", a); //*5643  *
    printf("*%6d*\n", a); //*  5643*
    printf("*%06d*\n", a); //*005643*
    printf("*%16d*\n", a); //*            5643*
}