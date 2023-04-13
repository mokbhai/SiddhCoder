// Program to create right handed pyramid.
#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int max, n;
    do
    {
    printf("Height: ");
    n = max = get_int("d: ");
    }
    while(max<1 && max<8);
    for(int j=0; j<max+1; j++)
    {
        for(int i=0; i<n; i++)
        {
            printf(" ");
        }
        for(int i=n; i<max; i++)
        {
            printf("#");
        }
        n--;
        printf("\n");
    }
}