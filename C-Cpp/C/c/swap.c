#include <stdio.h>
int main()
{
    int c, d, temp;
    scanf("%d %d", &c, &d);
    temp = d;
    d = c;
    c = temp;

    printf("%d, %d", c, d);
    return 0;
}