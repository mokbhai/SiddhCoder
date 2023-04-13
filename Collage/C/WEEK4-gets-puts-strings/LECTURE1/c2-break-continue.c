#include <stdio.h>
int main(void)
{
    printf("For Break: ");
    for (int i = 0; i < 10; i++)
    {
        if (i == 5)
        {
            break;
        }
        printf("%i", i);
    }
    printf("\nFor Conitnue: ");
    for (int i = 0; i < 10; i++)
    {
        if (i == 5)
        {
            continue;
        }
        printf("%i", i);
    }
}
// continue cannot be used in switch