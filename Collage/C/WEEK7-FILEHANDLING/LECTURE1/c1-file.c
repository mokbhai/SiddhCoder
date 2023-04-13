//File Handling
#include <stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("a.txt", "w");
    if (fp == NULL)
    {
        printf("\nFile doesn't exsit");
    }
    else
    {
        printf("\nfile Created");
    }
}