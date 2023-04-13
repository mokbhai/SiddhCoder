// incomplete
#include <stdio.h>

int main()
{
    char name[50];
    int sal;
    FILE *fp;
    fp = fopen("a.txt", "r");
    fscanf(fp, "%s %d", name, &sal);
}