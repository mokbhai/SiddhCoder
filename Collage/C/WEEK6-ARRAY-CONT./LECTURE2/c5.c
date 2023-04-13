// Coping Stucture

#include <stdio.h>

struct teacher
{
    int uid;
    float salary;
};

int main()
{
    struct teacher t1 = {212, 800000};
    printf("%d %.1f\n", t1.uid, t1.salary);
    struct teacher t2 = t1;
    printf("%d %.1f\n", t2.uid, t2.salary);
}