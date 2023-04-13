#include <stdio.h>

struct car
{
    char name[50];
    int seats;
    float price;
};

int main()
{
    struct car c = {"CAR", 4, 12.23}, *ptr;
    ptr = &c;
    printf("%s %d %f", ptr->name, ptr->seats, ptr->price);
}