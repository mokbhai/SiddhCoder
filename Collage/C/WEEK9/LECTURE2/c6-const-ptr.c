#include <stdio.h>

int main(void)
{
    int a = 5, b = 7;
    int * const ptr = &a;
    printf("Value of a is %d\n", *ptr);
    // ptr = &b; // error -> it is a constant pointer
    printf("Value of b is %d\n", *ptr);

}