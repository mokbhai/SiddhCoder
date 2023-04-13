#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int r;
    float pi = 22 / 7.0;
    printf("Radius: ");
    scanf("%i",&r);
    int d = 2 * r;
    float dist_travelled = pi * d;
    printf("Distance travelled is %g having radius %i with diameter %i\n",dist_travelled, r, d);
}