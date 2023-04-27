// display and read elements of 1d array using pinter to an array
#include <stdio.h>

// int main()
// {
//     int i, n;
//     printf("Enter number of elements: ");
//     scanf("%d", &n);
//     int arr[n];
//     int *parr = arr;
//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", (parr + i));
//     }
//     printf("Display Elemetes\n");
//     for (i = 0; i < n; i++)
//     {
//         printf("%d\n", *(parr + i));
//     }
// }

// sum and mean of array
int main()
{
    int i, n, sum = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    int *parr = arr;
    for (i = 0; i < n; i++)
    {
        scanf("%d", (parr + i));
    }
    for (i = 0; i < n; i++)
    {
        sum += *(parr + i);
    }
    printf("Sum = %d\nMean = %d", sum, sum / n);
}