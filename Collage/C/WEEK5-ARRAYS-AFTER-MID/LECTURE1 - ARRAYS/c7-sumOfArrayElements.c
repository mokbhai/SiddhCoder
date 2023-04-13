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
    printf("Adding All Elements\n");
    int sum = a[0];
    for (int i = 1; i < n; i++)
    {
        sum += a[i];
    }
    printf("Sum Of All Elements is %d", sum);
}