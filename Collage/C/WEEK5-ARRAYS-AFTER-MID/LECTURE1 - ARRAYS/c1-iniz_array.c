// write a progrm to take input from usr and treverse it
#include <stdio.h>
int main(void)
{
    int n;
    printf("Input Size Of Array: ");
    scanf("%d", &n);
    int a[n];
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter Element for index %d: ", i);
        scanf("%d", &a[i]);
    }
    printf("Traversing Array Elenmets\n");

    for (int i = 0; i < n; i++)
    {
        printf("Element at index %d is %d\n", i, a[i]);
    }
}