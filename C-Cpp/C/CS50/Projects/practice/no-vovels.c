// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
char replace(int len, char str);
int main(int argc, string argv[])
{
    string str = argv[1];
    int a = strlen(str);
    // printf("strlen = %i %s\n", a, argv[1]);
    for (int i = 0; i < a; i++)
    {
        // printf("str[%i] = %c\n", i, str[i]);
        str[i] = replace(argc, str[i]);
        // printf("str[%i] = %c\n", i, str[i]);
    }
    printf("%s", str);
}

char replace(int len, char str)
{
    switch (str)
    {
        case 'a':
            return '6';
            break;
        case 'e':
            return '3';
            break;
        case 'i':
            return '1';
            break;
        case 'o':
            return '0';
            break;
        default:
            return str;
            break;
    }
}