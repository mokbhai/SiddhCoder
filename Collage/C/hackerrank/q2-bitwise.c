#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void calculate_the_maximum(int n, int k)
{
    int max, a = 0, o = 0, x = 0, a1, o1, x1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            a1 = i & j;
            o1 = i | j;
            x1 = i ^ j;
            if (a1 > a && a1 < k)
                a = a1;
            if (o1 > o && o1 < k)
                o = o1;
            if (x1 > x && x1 < k)
                x = x1;
        }
        // printf("a = %i\no = %i\nx = %i\n", a, o, x);
    }
    printf("%i\n%i\n%i\n", a, o, x);
}

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);

    return 0;
}
