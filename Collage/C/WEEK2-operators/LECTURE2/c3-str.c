#include<stdio.h>
int main(void)
{
    // char str[100] = "Mokshit Jain";
    // printf("%s",str);
    char str[100];
    printf("Enter name: ");
    // scanf("%s", &str);
    // printf("%s\n", str);
    scanf("%[^\n]%*c", &str);
    printf("%s\n", str);

}