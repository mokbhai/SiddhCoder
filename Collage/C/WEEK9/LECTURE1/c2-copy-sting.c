#include <stdio.h>

int main()
{
    char src[100], dest[100];
    scanf("%s", src);
    // dest = src;
    int i = 0;
    while (src[i] != "\0")
    {
        dest[i] = src[i];
        i++;
    }
    printf("%s", dest);
}