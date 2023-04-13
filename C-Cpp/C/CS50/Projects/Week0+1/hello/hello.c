#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Getting name from user.
    string name = get_string("Your name: ");
    // Saying hello to user.
    printf("hello, %s\n", name);
}
