//File Handling
// Writing char by char.
// Read and write char into file and prints them
#include <stdio.h>

int main()
{
    FILE *fp;
    char c;
    int a = 100;
    fp = fopen("a1.txt", "a");
    if (fp == NULL)
    {
        printf("\nFile doesn't exsit");
    }
    else
    {
        printf("\nfile Created\n");
    }
    printf("Enter the line of text, press ctr + z to stop\n");
    while(a) // EOF -> end of file
    {
        c = getchar();
        putc(c, fp);
        a--;
    }
    fclose(fp);
    return 0;
}