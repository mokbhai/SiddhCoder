#include <stdio.h>

int main(void)
{
    int x = 7;
    char y = 'A';
    void *ptr;
    ptr = &x;
    printf("Value of x is %d\n", *(int*)ptr); // 7
    ptr = &y;
    printf("Value of y is %c\n", *(char*)ptr); // A
}