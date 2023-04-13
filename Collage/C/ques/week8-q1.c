#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void check(int [], int);

int main(void)
{
    int arr[100], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    check(arr, n);
}

void check(int arr[], int n)
{
    long int num = 0;
    int j = n - 1;
    for (int i = 0; i < n; i++, j--)
    {
        num *= 10;
        num += (arr[i] % 10);
    }
    if (num % 10 == 0)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    printf("%d", num);
}