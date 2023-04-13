#include <stdio.h>

void bubbleSort(int [], int);
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
    printf("Bubble Sorting\n");
    bubbleSort(arr, n);
    printf("Sorted Array\n");
    refrence(arr, n);
}

void refrence(int b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", b[i]);
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}