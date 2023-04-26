// Pointer to an array

#include <stdio.h>

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    
    int *p = a; // pointer p start pointing towards 1st elemet of array
    printf("%d\n", *p); // 10
    printf("%d\n", p); // address of 10

    p++;
    printf("%d\n", *p); // 20
    printf("%d\n", p); // address of 20

    p = p + 2;
    printf("%d\n", *p); // 40
    printf("%d\n", p); // address of 40

    p = &a[4];
    printf("%d\n", *p); // 50
    printf("%d\n", p); // address of 50
}