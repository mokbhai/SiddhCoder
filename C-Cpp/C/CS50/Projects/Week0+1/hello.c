#include<stdio.h>
#include"cs50.h"
int main(void)
{
    // char fullName[30];
    // printf("Type your full name: ");
    // fgets(fullName, sizeof(fullName), stdin);
    // printf("Hello!, %s",fullName);

    string answer = get_string("Whats your name? ");
    printf("Hello, %s\n", answer);
}
// code hello.c     => for making c file
// make hello       => for making binary file of c code