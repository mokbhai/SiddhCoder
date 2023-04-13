// LinerSearch

#include <stdio.h>

int linearSearch(int [], int, int);
// void binarySearch(int [], int);

int main(void)
{
    int arr[100], n, elm;
    printf("Enter Size Of Array: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        // printf("Enter %d Element: ", i);
        scanf("%d",&arr[i]);
    }
    printf("Enter the element you want to search: ");
    scanf("%d", &elm);
    linearSearch(arr, n, elm);
}

int linearSearch(int a[], int n, int elm)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == elm)
        {
            printf("Found at %d", i);
            return i;
        }
    }
    printf("Not Found");
    return -1;
}