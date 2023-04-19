// concept of fscanf
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char name[80];
    int roll_no, x;

    fp = fopen("student.txt", "r");
    if (fp == NULL)
    {
        printf("\nFile couldn't be opened");
        exit(1);
    }
    x = fscanf(fp, "%s%d", name, &roll_no);
    printf("\nName = %s\nRoll Number = %d", name, roll_no);
    printf("\n%i", x);
    fclose(fp);
}