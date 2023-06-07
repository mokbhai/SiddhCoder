#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n > 100)
    {
        printf("Wrong input\n");
    }
    else
    {
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if ((arr[i] % 5) == 0)
            {
                sum += arr[i];
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}