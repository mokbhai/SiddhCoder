// even number upto n
#include  <stdio.h>
int main(void)
{
    int n;
    int tnum = 0;
    printf("Enter number: ");
    scanf("%i", &n);
    for (int i = 0; i < n; i++)
    {
        if (i % 2 != 0)
        {
            continue;
        }
        tnum++;
        printf("%i\n", i);
    }
}