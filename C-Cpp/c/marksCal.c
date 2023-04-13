#include <stdio.h>
int main()
{
    int p, m, c, e, h, aggrigate_form, percentage;
    scanf("%d %d %d %d %d", &p, &c, &m, &e, &h);
    aggrigate_form = p + m + c + e + h;
    percentage = aggrigate_form * 100 / 500;
    printf("aggrigate_form = %d\n  percentage = %d", aggrigate_form, percentage);
    return 0;
}