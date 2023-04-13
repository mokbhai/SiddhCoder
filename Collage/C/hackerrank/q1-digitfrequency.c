#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char s[100];
    scanf("%s", &s);
    int k = 0;
    int n = sizeof(s);
    for (int i = 0; i < 10; i++)
    {
        k = 0;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == i)
            {
                k++;
            }
        }
        printf("%d ", k);
    }
    return 0;
}
