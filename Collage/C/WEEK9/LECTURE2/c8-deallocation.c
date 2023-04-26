// Deallocating a memory pointed by ptr causes
// dangling pointer
#include <stdlib.h>
#include <stdio.h>
int main()
{
    
	int n=1;
	int *ptr = (int *)malloc(n*sizeof(int));
	*ptr=6;    
    printf("%d",*ptr);//6 is printed
    printf("\n%d",ptr);//Printing address hold by pointer before deallocation
    free(ptr); 
    printf("\n%d",ptr);//Same address will be printed(Dangling pointer)
   //SOLUTION
   ptr = NULL;//Pointer is now changed to NULL pointer
   printf("\n%d",ptr);//0 will be printed
   return 0;
}
