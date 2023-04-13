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
    int max = a[0], min = a[0];
    for (int j = 1; j < n; j++)
    {
        if (max < a[j])
        {
            max = a[j];
        }
        if (min > a[j])
        {
            min = a[j];
        }
    }
    printf("Max Element is %d\nMin Element is %d", max, min);
}