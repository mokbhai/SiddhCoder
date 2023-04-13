// undifined functions are those who does not require conversion syntax (%d, %c, etc.)
#include<stdio.h>

int main(void)
{
    char d;
    // getchar() use to take input from user
    d = getchar();
    // printf("You entered = %c", d);

    // instead of using prinf() we will use putchar()
    putchar(d); // you cant define any string in it
}