#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks;
    printf("Number of weeks taking CS50: ");
    scanf("%i", &weeks);
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        printf("Week %i HW Hours: ", i);
        scanf("%i", &hours[i]);
        // hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        printf("Enter T for total hours, A for average hours per week: ");
        scanf("%c", &output);
        output = toupper(output);
        // output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    float at = 0;
    if (output == 'T')
    {
        for (int i = 0; i < weeks; i++)
        {
            at += hours[i];
        }
    }
    else if (output == 'A')
    {
        for (int i = 0; i < weeks; i++)
        {
            at += hours[i];
        }
        at /= weeks;
    }
    return at;
}