#include <stdio.h>
int main()
{
    int km, cm, m, feet;
    scanf("%d", &km);
    m = km * 1000;
    cm = m * 10;
    feet = cm * 1.5;
    printf("%d, %d, %d, %d", km, m, cm, feet);
    return 0;
}