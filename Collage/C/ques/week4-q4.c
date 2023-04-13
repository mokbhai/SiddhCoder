// prime or not
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, p = 0;
    scanf("%d", &n);
    for (int i = 2; i < n / 2; i++)
    {
        if (n % i == 0)
        {
            printf("NO");
            break;
        }
        p++;
    }
    if (p == (n / 2) - 2)
    {
        printf("YES");
    }
    return 0;
}
