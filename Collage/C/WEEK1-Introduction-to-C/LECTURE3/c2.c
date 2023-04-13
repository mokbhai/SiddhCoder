 #include<stdio.h>
int main(void){
    int a = 10;
    int b = 10;
    printf("%d + %d = %d\n",a,b,a+b);
    printf("%d - %d = %d\n",a,b,a-b);
    printf("%d * %d = %d\n",a,b,a*b);
    printf("%d / %d = %f\n",a,b,(float)a/(float)b);
    printf("%d %% %d = %f\n",a,b,a%b);
}