// concept of fprintf -> taking input and saving/printing in file
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int i;
    char name[80];
    float salary;

    fp = fopen("Details.txt", "w");
    if (fp == NULL)
    {
        printf("\nFile couldn't be opened");
        exit(1);
    }

    for (i = 0; i < 3; i++)
    {
        puts("\nEnter your name");
        // gets(name);
        scanf("%[^\n]%*c", name);
        fflush(stdin);
        puts("\nEnter your salary");
        scanf("%f", &salary);
        fprintf(fp, "%s \t %.2f\n", name, salary);
        fflush(stdin);
    }
    fclose(fp);
}