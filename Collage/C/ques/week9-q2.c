#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct player
{
    int num, score;
};

int main() {
    int n, total = 0;
    scanf("%d", &n);
    struct player p[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &p[i].num, &p[i].score);
        total += p[i].score;
    }
    printf("%d", total);
    return 0;
}
