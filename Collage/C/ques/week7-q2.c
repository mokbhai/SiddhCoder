#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void sumArr(int [], int);

int main(void)
{
    int arr[100], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    sumArr(arr, n);
}

void sumArr(int b[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += b[i];
    }
    printf("%d", sum);
}