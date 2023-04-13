#include <cs50.h>
#include <stdio.h>
#include <math.h>

long get_num();
void is_valid(long num, int size);
void card_name(long num, int size);

// main function
int main(void)
{
    long num = get_num();
    // length of credit_num entered
    int size = floor(log10(num) + 1);
    is_valid(num, size);
}



// getting card number from user
long get_num()
{
    long credit;
    int size;
    do
    {
        credit = get_long("Number: ");
    }
    while (credit < 0);
    return credit;
}

// checking is card number valid or not
void is_valid(long num, int size)
{
    int sum = 0;
    int digit;
    long credit_num = num;
    for (int i = 1; i < size + 1; i++)
    {
        digit = num % 10;
        if (i % 2 == 0)
        {
            digit = digit * 2;
            sum = sum + digit % 10 + digit / 10;
        }
        else
        {
            sum = sum + digit;
        }
        num = num / 10;
    }
    if (sum % 10 == 0)
    {
        card_name(credit_num, size);
    }
    else
    {
        printf("INVALID\n");
    }
}

// checking card name i.e.  visa mastercard amex.
void card_name(long num, int size)
{
    size = size - 2;
    num = num / (pow(10, size));
    if (num == 51 || num == 52 || num == 53 || num == 54 || num == 55)
    {
        printf("MASTERCARD\n");
    }
    else if (num == 34 || num == 37)
    {
        printf("AMEX\n");
    }
    else if (num / 10 == 4 && size > 10)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}