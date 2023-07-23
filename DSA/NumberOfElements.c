#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted sub array
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}
 
int countNum(int arr[], int N, int x)
{
    int count = 0;
    for (int i = 0; i < N; i++)
        if (arr[i] == x)
            count++;
    return count;
}
void print(int arr[], int i, int count)
{
    if (arr[i] == arr[i - 1])
    {
    }
    else
    {
        printf("The array element %d appears %d times\n", arr[i], count);
    }
}
int main()
{
    int arr[] = {0, 4, 4, 4, 4, 4, 1, 4, 2, 4, 5, 4};
    int len = sizeof(arr) / 4;
    selectionSort(arr, len); //nlogn
    for (int i = 0; i < len; i++) // n
    {
        int count = countNum(arr, len, arr[i]);
        if (count > len / 2)
            print(arr, i, count);
    }
}
