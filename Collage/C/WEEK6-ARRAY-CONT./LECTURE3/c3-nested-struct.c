// nested struct possible - yes
// dot operator used twice in it
// two ways
// 1. declar 2 diffrent struct
// 2. embeded struct

struct Date
{
    int dd, mm, yy;
};
// main struct
struct student
{
    char *name;
    int roll_num;
    // nesed diffrent struct
    struct Date dob;
};

// or By struct within struct

struct student1
{
    char *name;
    int roll_num;
    // inside struct
    struct Date1
    {
        int dd, mm, yy;
    }dob1;
}s1 = {"Mokshit", 122, {10, 02, 2004}};

#include <stdio.h>

int main()
{
    struct student s;
    s.dob.dd = 10;
    s.dob.mm = 02;
    s.dob.yy = 2004;
    s.name = "Mokshit";
    s.roll_num = 32;
    printf("%s %d-%d-%d\n", s.name, s.dob.dd, s.dob.mm, s.dob.yy);
    printf("%s %d-%d-%d", s1.name, s1.dob1.dd, s1.dob1.mm, s1.dob1.yy);
    return 0;
}
