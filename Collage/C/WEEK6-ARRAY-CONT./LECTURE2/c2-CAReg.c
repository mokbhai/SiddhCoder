// str car; data menber of car are car mname price and numer of seats
#include <stdio.h>

struct car
{
    char car_name[100];
    float price;
    int seats;
};
void display_Car(char [], float price, int seats);

int main(void)
{
    struct car c1, c2, c3;
    printf("Enter car name: ");
    scanf("%s", &c1.car_name);
    printf("Enter price: ");
    scanf("%f", &c1.price);
    printf("Enter seats: ");
    scanf("%d", &c1.seats);
    display_Car(c1.car_name, c1.price, c1.seats);
}

void display_Car(char car_name[], float price, int seats)
{
    printf("Car Name: %s\nPrice: %.2f\nSeats: %d", car_name, price, seats);
}