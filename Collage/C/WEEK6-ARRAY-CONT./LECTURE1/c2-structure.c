// how to access struct
#include <stdio.h>

struct kocck
{
    int roll_no;
    long int reg_no;
    char *name;
    float cgpa;
};

int main(void)
{
    struct kocck kocck;
    kocck.roll_no = 1;
    kocck.reg_no = 12223;
    kocck.name = "mokshit";
    kocck.cgpa = 9.6;
    printf("%s", kocck.name);
}