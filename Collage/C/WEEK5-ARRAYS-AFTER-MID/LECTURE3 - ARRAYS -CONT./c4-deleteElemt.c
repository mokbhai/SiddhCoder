// Delete Element in 1d arr from given positon
#include <stdio.h>

void printArr(int [], int);

int main(void)
{
    int arr[100], pos, c, n, value;
    printf("Enter Size Of Array: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        // printf("Enter %d Element: ", i);
        scanf("%d",&arr[i]);
    }
    printf("Enter the location where you wish to insert element: ");
    scanf("%d",&pos);

    for (c = pos - 1; c < n - 1; c++)
    {
        arr[c] = arr[c+1];
    }
    n--;
    arr[n] = 0;
    printArr(arr, n);
}
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}