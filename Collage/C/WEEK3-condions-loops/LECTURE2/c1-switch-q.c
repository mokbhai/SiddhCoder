#include<stdio.h>
int main (void)
{
    int month;
    scanf("%i", &month);
    switch (month)
    {
    case 1:
        printf("Janvary");
        break;
    case 2:
        printf("Febury");
        break;
    case 3:
        printf("March");
        break;
    case 4:
        printf("April");
        break;
    case 5:
        printf("May");
        break;
    case 6:
        printf("June");
        break;
    case 7:
        printf("July");
        break;
    case 8:
        printf("August");
        break;
    case 9:
        printf("Septemer");
        break;
    case 10:
        printf("Octomber");
        break;
    case 11:
        printf("November");
        break;
    case 12:
        printf("December");
        break;
    
    default:
    printf("Invalid");
        break;
    }
}