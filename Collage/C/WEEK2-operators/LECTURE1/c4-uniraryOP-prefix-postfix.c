#include<stdio.h>

int main(void)
{
    int x = 3;
    int y = x++;
    printf("X: %i Y: %i\n",x,y);
    int z = ++x;
    printf("X: %i Z: %i\n",x,z);
}