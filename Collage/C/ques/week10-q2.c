#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int n;
    scanf("%d", &n);
    if (n < 5 || n > 50)
    {
        printf("Invalid input");
    }
    else
    {
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%i", &arr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 5 == 0)
                printf("%d\n", arr[i]);
        }
    }
    return 0;
}
