// #include <cs50.h>
// #include <stdio.h>
// #include <ctype.h>

// int main(int argc, string argv[])
// {
//     if (argc != 2)
//     {

//     }
// }
// void is_26(string abc)
// {
//     int len = strlen(abc)
//     for (int i = 0; i < len; i++)
//     {
//         if (! isalpha(abc[i]))
//         {
//             return false;
//         }
//     }
//     return true;
// }
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int only_abc(string a);
// main funcion
int main(int argc, string argv[])
{
    // entered value must be string (abcd)
    // checking
    // bool f = only_abc(argv[1]);
    if (strlen(argv[1]) != 26 && argc == 2 && ! only_abc(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if (argc != 2 || only_abc(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // number must be equals 26


    string txt = get_string("plaintext: ");
    int lent = strlen(txt);
    // main work encoding
    int place = 0;
    for (int i = 0; i < lent; i++)
    {
        if (isalpha(txt[i]))
        {
            if (islower(txt[i]))
            {
                place = txt[i] - 97;
                txt[i] = tolower(argv[1][place]);
            }
            else if (isupper(txt[i]))
            {
                place = txt[i] - 65;
                txt[i] = toupper(argv[1][place]);
            }
        }
    }
    // printing o/p
    printf("ciphertext: %s\n", txt);
}
// function for checking enterd digit is only number
int only_abc(string a)
{
    int lena = strlen(a);
    for (int i = 0; i < lena; i++)
    {
        if (! isalpha(a[i]))
        {
            return true;
        }
    }
    return false;
}