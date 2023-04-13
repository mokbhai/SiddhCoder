#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int sp_size, ep_size, n;
    int year = 0;
    // TODO: Prompt for start size
    do
    {
        n = sp_size = get_int("Start size: ");
    }
    while(sp_size<9);

    // TODO: Prompt for end size
    do
    {
        ep_size = get_int("End size: ");
    }
    while(ep_size<sp_size);

    // TODO: Calculate number of years until we reach threshold

    while(n<ep_size)
    {
        n = n + (n/3) - (n/4);
        year++;
    }

    // TODO: Print number of years
    printf("Years: %d",year);
}
