//File Handling
// Reading char by char
// Read and write char into file and prints them
// EOF -> end of file

#include <stdio.h>
int main()
{
    FILE *fp;
    char c;
    int a = 100;
    fp = fopen("a1.txt", "r");
    if (fp == NULL)
    {
        printf("\nFile doesn't exsit");
    }
    printf("Reading....\n");
    while((c = getc(fp)) != EOF) 
    {
        printf("%c", c);
    }
    fclose(fp);
    return 0;
}