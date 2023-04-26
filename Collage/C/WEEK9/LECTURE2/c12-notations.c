#include<stdio.h>
int main()
{
	int a[]={1,2,3,4,5};
	int *p=a;
	// Different notations with pointer to an array for displaying second element
    // Same terminology can be used to display any element
    // All will display 2 on screen
	printf("\n%d",*(p+1));
	printf("\n%d",*(a+1));
	printf("\n%d",p[1]);
	printf("\n%d",1[p]);
	printf("\n%d",1[a]);
	return 0;
}

