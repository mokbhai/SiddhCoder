// fseek -> used to seting the file position of specific syntx
// fseek(FILE *fp, ofo  )

#include <stdio.h>

int main()
{
    FILE *fp;
    char temp, name[50], y = 'y';
    fp = fopen("a.txt", "r+");
    while ((temp = getc(fp)) != EOF)
    {
        if (temp == 'x')
        {
            fseek(fp, -1, 1);
            putc(y, fp);
        }
    }
    fclose(fp);
}