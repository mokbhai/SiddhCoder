// l to r how many numbers are divisible by k
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int l, r, k, h = 0;
    scanf("%i %i %i", &l, &r, &k);
    for (int i = l; i <= r; i++)
    {
        if (i % k == 0)
        {
            h++;
        }
    }
    printf("%i", h);
    return 0;
}
