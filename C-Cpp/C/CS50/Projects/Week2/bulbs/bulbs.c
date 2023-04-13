#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string chr = get_string("Message: ");
    int len = strlen(chr);
	// array to store binary number
	// int binaryNum[] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int k = 0; k < len; k++)
    {
       	int binaryNum[] = {0, 0, 0, 0, 0, 0, 0, 0};
        int  n = chr[k];
	    // counter for binary array
	    int i = 0;
	    while (n > 0) {
	    	// storing remainder in binary array
	    	binaryNum[i] = n % 2;
	    	n = n / 2;
	    	i++;
	    }

	    // printing binary array in reverse order
	    for (int j = 7; j >= 0; j--)
        {
		    print_bulb(binaryNum[j]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

