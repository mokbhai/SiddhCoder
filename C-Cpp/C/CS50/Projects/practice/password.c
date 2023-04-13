// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int a = 0;
    int slen = strlen(password);
    for (int i = 0; i < slen; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            a++;
            printf("%c\n", password[i]);
            break;
        }
    }
    for (int i = 0; i < slen; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z')
        {
            a++;
            printf("%c\n", password[i]);

            break;
        }
    }
    for (int i = 0; i < slen; i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            printf("%c\n", password[i]);
            a++;
            break;
        }
    }
    for (int i = 0; i < slen; i++)
    {
        if (password[i] >= 33 && password[i] <= 47)
        {
            printf("%c\n", password[i]);
            a++;
            break;
        }
        else if (password[i] >= 58 && password[i] <= 64)
        {
            printf("%c\n", password[i]);
            a++;
            break;
        }
        else if (password[i] >= 91 && password[i] <= 96)
        {
            printf("%c\n", password[i]);
            a++;
            break;
        }
    }
    if (a == 4)
        return true;
    return false;
}
