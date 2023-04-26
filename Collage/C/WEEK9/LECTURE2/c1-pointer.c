// Pointer -> special type of charater holds the address of other variables
// syntax
// datatype *pointer_name

#include <stdio.h>

int main()
{
    int *i;
    double *p;
    float *f;
    printf("%d\n", sizeof(i)); // 8
    printf("%d\n", sizeof(p)); // 8
    printf("%d\n", sizeof(f)); // 8
}
