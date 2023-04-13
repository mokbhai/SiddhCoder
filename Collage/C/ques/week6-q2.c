#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.
// S = S1 + S2 + S3
int find_nth_term(int n, int a, int b, int c);
int main() 
{
    int n, a, b, c;
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
 
    printf("%d", ans); 
    return 0;
}
int find_nth_term(int n, int a, int b, int c)
{
    if (n > 4)
    {
        a = b;
        b = c;
        c += find_nth_term(n -= 1, a, b, c);
    }
    else
    {
        switch (n)
        {
        case 1:
            return a;
            break;
        case 2:
            return b;
        case 3:
            return c;
        default:
            return c = a + b + c;
            break;
        }
    }
    return c;
}