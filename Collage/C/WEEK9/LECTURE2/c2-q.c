//finding area of cicle by using pointers

#include <stdio.h>

int main()
{
    double area, radius;
    double *parea, *pradius;
    parea = &area;
    pradius = &radius;
    printf("Enter Radius of circle: ");
    scanf("%lf", pradius);
    *parea = 3.14 * (*pradius) * (*pradius);
    printf("area of circle = %lf", *parea);
}
