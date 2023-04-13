// priint all types oof chararter
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    char ch, w[100], s[100], g;
    scanf("%c\n%s", &ch, w);
    scanf("%c", &g);
    scanf("%[^\n]%*c", s);
    printf("%c\n%s\n%s", ch, w, s);

    return 0;
}   