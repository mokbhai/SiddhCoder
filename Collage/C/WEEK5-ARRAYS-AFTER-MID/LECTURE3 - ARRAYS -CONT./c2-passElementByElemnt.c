// In two ways We can pass array to function 1 Pass Entire Array,, 2 Pass Element bu Element 
// Pass Entire Array
#include <stdio.h>

void value(int);

int main(void)
{
    int arr[100], i, n;
    printf("Enter Size Of Array: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Passing Elements by value\n");
    for (int i = 0; i < n; i++)
    {
        value(arr[i]);
    }
}

void value(int val)
{
    printf("%d\n", val);
}