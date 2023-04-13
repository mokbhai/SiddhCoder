#include <stdio.h>
int main()
{
    printf("Enter any character: ");
    getche(); // take i/p as well as show o/p
    char ch = getch(); // takes i/p only
    putch(ch);
    return 0;
}