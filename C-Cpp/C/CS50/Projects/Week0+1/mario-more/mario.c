// Program to create right handed pyramid.
#include <cs50.h>
#include <stdio.h>

// declaration of function
int size();
void print_grid(int n);

int main(void)
{
    // calling Functions
    int max = size();
    print_grid(max);
}

// size function for getting size from user
int size()
{
    int max;
    do
    {
        do
        {
            max = get_int("Height: ");
        }
        while (max < 1);
    }
    while (8 < max);
    return max;
}

// print_grid function print the required output
void print_grid(int max)
{
    int n = max - 1;
    for (int j = 0; j < max; j++)
    {
        for (int i = 0; i < n; i++)
        {
            printf(" ");
        }
        for (int i = n; i < max; i++)
        {
            printf("#");
        }
        printf("  ");
        for (int i = n; i < max; i++)
        {
            printf("#");
        }
        n--;
        printf("\n");
    }
}