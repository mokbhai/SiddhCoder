// img size
// l = 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int l, n;
    scanf("%i\n%i", &l, &n);
    int w[n], h[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d  %d", &w[i], &h[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        if (w[i] < l || h[i] < l)
        {
            printf("UPLOAD ANOTHER\n");
        }
        else if (w[i] >= l && h[i] >= l && w[i] == h[i])
        {
            printf("ACCEPTED\n");
        }
        else if (w[i] >= l && h[i] >= l && w[i] != h[i])
        {
            printf("CROP IT\n");
        }
    }
    return 0;
}
