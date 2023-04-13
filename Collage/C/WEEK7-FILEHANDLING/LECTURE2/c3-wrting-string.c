#include <stdio.h>

int main()
{
    FILE *fptr;
    char name[20], arr[50];
    printf("Enter the File name: ");
    scanf("%s", name);
    fptr = fopen(name, "w");
    if (fptr == NULL)
    {
        printf("File Cannot be opened\n");
    }
    else
    {
        int a = 100;
        printf("the string is: ");
        while (a)
        {
        scanf("%s", arr);
        fputs(arr, fptr);
        a--;
        }
    }
    fclose(fptr);
    return 0;
}