// sum of didgits of 5 digit number
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    int sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < 5; i++)
    {
        sum += n % 10;
        n /= 10;
    }
    printf("%i", sum);
    return 0;
}