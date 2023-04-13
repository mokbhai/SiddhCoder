// Error Code

#include<stdio.h>
int main (){
    int x,i;
    char a[100]; 
    
    scanf("%d",&x);
    for (i=0;i<x;i++){
      scanf("%s",&a[i]);
       
    }
    
    int n = sizeof(a)/sizeof(a[0]);
    for(i=0;i<n;i++){
        printf("%s",a[i]);
    }
}