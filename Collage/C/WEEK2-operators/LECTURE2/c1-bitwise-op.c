// Bitwise Operator
#include<stdio.h>

int main(void)
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("Bitwise AND &   : %d\n", (a & b));
    printf("Bitwise OR |    : %d\n", (a | b));
    printf("Bitwise XOR ^   : %d\n", (a ^ b));
    printf("Bitwise Compl ~a:  %d\n", (~ a));
    printf("Bitwise Compl ~b:  %d\n", (~ b));
    printf("Bitwise Left Shift << : %d\n", (a << 1));
    printf("Bitwise Left Shift << : %d\n", (b << 1));
    printf("Bitwise Right Shift >>: %d\n", (a >> 1));
    printf("Bitwise Right Shift >>: %d\n", (b >> 1));

}