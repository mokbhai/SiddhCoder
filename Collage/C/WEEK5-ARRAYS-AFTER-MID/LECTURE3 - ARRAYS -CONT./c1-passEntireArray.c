// In two ways We can pass array to function 1 Pass Entire Array,, 2 Pass Element bu Element 
// Pass Entire Array
#include <stdio.h>

void refrence(int [], int);

int main(void)
{
    int arr[100], i, n;
    printf("Enter Size Of Array: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Elements By Refrence");
    refrence(arr, n);
}

void refrence(int b[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        // printf("\n%d", b[i]);
        sum += b[i];
    }
}