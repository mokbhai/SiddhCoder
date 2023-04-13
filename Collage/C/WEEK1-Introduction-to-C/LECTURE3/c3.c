// Write a program to fin simple intrest P*R*T/100
#include<stdio.h>
int main(void){
    float p = scanf("Principal amount %f", p);
    float r = scanf("Rate intrest %f", r);
    float t = scanf("Time Duration %f", t);
    float si = p*r*t/100;
    printf("Your principal amount is %g, Intrest rate is %g, Time perod is %g,and Simple intrest %g",p,r,t,si);
}