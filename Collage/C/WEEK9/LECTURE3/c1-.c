#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int *ptr = arr;
    int i;
    int n = sizeof(arr) / 4;
    for (i = 0; i < n; i++)
    {
        printf("%d\n", ptr[i]);
    }
    printf("Addresses are\n");
    for (i = 0; i < n; ptr++, i++)
    {
        printf("%d\n", *ptr);
    }
}