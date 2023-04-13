// 
#include<stdio.h>

int main()
{
    int day;
    printf("Enter the number of days between 0 to 6: ");
    scanf("%i", &day);
    switch (day)
    {
    case 0:
        printf("Sunday");
        break;
    case 1:
        printf("Monday");
        break;
    case 2:
        printf("Tuesday");
        break;
    case 3:
        printf("Wednusday");
        break;
    case 4:
        printf("Thrusday");
        break;
    case 5:
        printf("Friday");
        break;
    case 6:
        printf("Saturday");
        break;
    default:
        printf("error");
        break;
    }
    return 0;
}