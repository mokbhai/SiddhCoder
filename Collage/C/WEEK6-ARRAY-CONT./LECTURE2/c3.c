// structure as an array
#include <stdio.h>

void display(char name[], int uid, float salary, int rating);

struct teacher
{
    char name[100];
    int uid;
    float salary;
    int rating;
};

int main(void)
{
    int n;
    printf("Enter How Many Teachers: ");
    scanf("%i", &n);
    struct teacher t[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter Details of %d teacher.\n", i + 1);
        printf("Enter Teacher Name: ");
        scanf("%s", &t[i].name);
        printf("Enter Teacher Uid: ");
        scanf("%d", &t[i].uid);
        printf("Enter Teacher Salary: ");
        scanf("%f", &t[i].salary);
        printf("Enter Teacher Rating: ");
        scanf("%s", &t[i].rating);
    }
    printf("Display Deatils\n");
    for (int i = 0; i < n; i++)
    {
        printf("Displaying Details of %d Teacher\n", i + 1);
        display(t[i].name, t[i].uid, t[i].salary, t[i].rating);
    }
}

void display(char name[], int uid, float salary, int rating)
{
    printf("Name = %s\nUid = %d\nSalary = %f\nRating = %d\n", name, uid, salary, rating);
}