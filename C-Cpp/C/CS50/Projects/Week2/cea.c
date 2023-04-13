#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int only_digit(string a);
// main funcion
int main(int argc, string argv[])
{
    // entered value must be number
    // checking
    if (argc == 1 || argc > 2 || only_digit(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // number must be less than or equals 26
    int num = atoi(argv[1]);
    string txt = get_string("plaintext: ");
    int lent = strlen(txt);
    for (int i = 0; num > 26; i++)
    {
        num -= 26;
    }
    // main work encoding
    for (int i = 0; i < lent; i++)
    {
        if (isalpha(txt[i]))
        {
            if (islower(txt[i]) && txt[i] + num > 'z')
            {
                txt[i] += num - 26;
            }
            else if (isupper(txt[i]) && txt[i] + num > 'Z')
            {
                txt[i] += num - 26;
            }
            else
            {
                txt[i] += num;
            }
        }
    }
    // printing o/p
    printf("ciphertext: %s\n", txt);
}
// function for checking enterd digit is only number
int only_digit(string a)
{
    int lena = strlen(a);
    for (int i = 0; i < lena; i++)
    {
        if (! isdigit(a[i]))
        {
            return true;
        }
    }
    return false;
}