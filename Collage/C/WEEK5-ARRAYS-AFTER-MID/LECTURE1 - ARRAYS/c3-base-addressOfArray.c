// write a progrm to take input from usr and treverse it
#include <stdio.h>
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int i;
    printf("\n Printing base address of the array");
    printf("\n%u %u %u", &a[0], a, &a);
    printf("\n Printing address of all array elements: ");
    for(i = 0; i < 5; i++)
    {
        printf("\n%u", &a[i]);
    }
    return 0;
}