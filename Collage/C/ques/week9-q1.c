#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct student
{
    int age, standard;
    char first_name[50], last_name[50];
    
};

int main() {
    struct student s1;
    scanf("%d %s %s %d", &s1.age, s1.first_name, s1.last_name, &s1.standard);
    printf("%d %s %s %d", s1.age, s1.first_name, s1.last_name, s1.standard);
    return 0;
}
