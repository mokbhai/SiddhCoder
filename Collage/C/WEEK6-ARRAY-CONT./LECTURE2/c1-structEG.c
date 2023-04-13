#include <stdio.h>

struct teacher
{
    char name[100];
    char coursename[100];
    int uid;
    float salary;
};

int main(void)
{
    struct teacher t1 = {"ABS", "CLang", 24621, 54846};
    printf("Display Detalis\n");
    printf("%s %s %d %f", t1.name, t1.coursename, t1.uid, t1.salary);
}

// void teach(char name[], char coursename[], int uid, int salary)
// {
//     printf("%s %s %d %f", name, coursename, uid, salary);
// }