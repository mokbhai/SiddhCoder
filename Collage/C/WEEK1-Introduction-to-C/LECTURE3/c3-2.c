#include<stdio.h>
int main(){
int t;
float p,r,si;
printf("Enter the Principle Value: ");
scanf("%f",&p);
printf("Enter the Time: ");
scanf("%d",&t);
printf("Enter the Rate: ");
scanf("%f",&r);
si=(p*r*t)/100;
printf("Simple Interest is %g whose principle value is %g and the rate is %g,and the time is %g",si,p,r,t);
return 0;
}