#include <stdio.h>
int main(void)
{
    char name[30];
    scanf("%s", &name);
    printf("name = %s", name);
    // gets(name); // full string input
    // puts(name); // full string output
}