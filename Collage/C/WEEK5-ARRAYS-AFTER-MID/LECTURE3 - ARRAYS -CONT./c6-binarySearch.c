// BinearySearch used to search in sorted array

#include <stdio.h>

// void linearSearch(int [], int, int);
int binarySearch(int [], int , int);

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
    int loc = binarySearch(arr, n, elm);
    
    if (loc == -1)
    {
        printf("Not Found");
    }
    else
    {
        printf("Found at %d", loc);
    }
}

int binarySearch(int a[], int n, int elm)
{
    int loc = -1;
    if (a[n/2] == elm)
    {
        loc = n/2;
    }
    else if (a[0] > elm)
    {
        loc = -1;
        return loc;
    }
    else if (a[n/2] > elm)
    {
        loc = binarySearch(a, n/2, elm);
    }
    else if (a[n] < elm)
    {
        loc = -1;
        return loc;
    }
    else if (a[n/2] < elm)
    {
        loc = binarySearch(&a[n/2], n/2, elm) + n / 2;
    }
    return loc;
}