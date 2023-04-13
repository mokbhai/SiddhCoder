// goto statement
// demonstrate the concept of goto statement
#include  <stdio.h>
int main(void)
{
    int n = 10;
    mok:
    printf("%i", n);
    n = n - 1;
    if (n > 0)
    {
        goto mok;
    }
}