#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(int len, string text);
int count_words(int len, string text);
int count_sentance(int len, string text);
float per_100(int a, int b);

int main(void)
{
    //index = 0.0588 * L - 0.296 * S - 15.8
    string text = get_string("Text: ");
    int len = strlen(text);
    int letters = count_letters(len, text);
    int words = count_words(len, text);
    int sentance = count_sentance(len, text);
    float l = per_100(letters, words) / 100;
    float s = per_100(sentance, words) / 100;
    // printf("L: %g S: %g\n", l, s);
    // printf("0.0588 * l: %f\n", 0.0588 * l);
    // printf("0.296 * s : %f\n", 0.296 * s);
    float index = 0.0588 * l - 0.296 * s - 15.8;
    index = round(index);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %g\n", index);
    }
}

int count_letters(int len, string text)
{
    int letters = 0;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    // printf("%i letters\n", letters);
    return letters;
}

int count_words(int len, string text)
{
    int words = 1;
    for (int i = 0; i < len; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    // printf("%i words\n", words);
    return words;
}

int count_sentance(int len, string text)
{
    int sentance = 0;
    for (int i = 0; i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!'|| text[i] == '?')
        {
            sentance++;
        }
    }
    // printf("%i sentances\n", sentance);
    return sentance;
}
float per_100(int a, int b)
{
    float per100 = (float) a / (float) b * 100;
    return round(per100 * 100);
}