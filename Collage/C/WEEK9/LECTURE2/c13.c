#include <stdio.h>
int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int i;
    int *p;
    p = arr;
    printf("First value is = %d\n", *p);
    p = p + 1;
    printf("Second value is = %d\n", *p);
    *p = 45;
    p = p + 2;
    *p = -2;
    printf("Modified array is\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]); // We can also write i[arr]
    }
    p = arr;
    *(p + 1) = 0;
    *(p - 1) = 1;
    printf("Modified array is\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d\n", *(p + i)); // We can also write *(i+arr)
    }
    return 0;
}
