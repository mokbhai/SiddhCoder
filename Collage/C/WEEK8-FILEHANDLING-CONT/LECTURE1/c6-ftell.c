// ftell -> tell us that current location of file pointer in file
// ftell(fptr)

#include<stdio.h>

int main()
{
	FILE *fp = fopen("num.txt","r");

	char string[20];
	fscanf(fp,"%s",string);

	printf("%ld", ftell(fp));
	return 0;
}
