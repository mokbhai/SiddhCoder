#include <stdio.h>

struct Patient_Details
{
    char paitent_name[50];
    char disease[50];
    int ward_no;
    float total_expence;
};

void Enter_Details(struct Patient_Details p[], int n);
void Print_Details(struct Patient_Details p[], int n);

int main()
{
    struct Patient_Details p[100];
    int n;
    printf("Enter number of Patients: ");
    scanf("%d", &n);
    Enter_Details(p, n);
    Print_Details(p, n);
}

void Enter_Details(struct Patient_Details p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter Patient Name: ");
        scanf("%s",p[i].paitent_name);
        printf("Enter Disease Name: ");
        scanf("%s", p[i].disease);
        printf("Enter Ward Number: ");
        scanf("%d", &p[i].ward_no);
        printf("Enter Totel Expences: ");
        scanf("%f", &p[i].total_expence);
    }
}

void Print_Details(struct Patient_Details p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Patient Number: %d\n", i + 1);
        printf("Patient Name: %s\n",p[i].paitent_name);
        printf("Disease Name: %s\n", p[i].disease);
        printf("Ward Number: %d\n", p[i].ward_no);
        printf("Totel Expences: %.2f\n", p[i].total_expence);
    }
}