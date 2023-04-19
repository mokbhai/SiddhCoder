#include <stdio.h>

void add_record();
void display_trems();
void update_def();
void search_by_Name();
void delete_record();

struct dictionary
{
    char *term;
    char *definition;
    char *subfeild
};


FILE *dict;

int main()
{
    printf("1. Add record\n");
    printf("2. Display terms in alphabatical order\n");
    printf("3. Update definition\n");
    printf("4. Search term\n");
    printf("5. Delete record\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        add_record();
        break;
    case 2:
        display_trems();
        break;
    default:
        return 0;
        break;
    }

    return 0;
}

void add_record()
{
    struct dictionary d;
    dict = fopen("dictionary.txt", "a");
    getchar();

    printf("Term Name: ");
    scanf("%[^\n]%*c", d.term);
    fputs(d.term, dict);
    fprintf(dict, " = ");
    printf("Term Defination: ");
    scanf("%[^\n]%*c", d.definition);
    fputs(d.definition, dict);
    fprintf(dict, " (");
    printf("Term Subfeild: ");
    scanf("%[^\n]%*c", d.subfeild);
    fputs(d.subfeild, dict);
    fprintf(dict, ")\n");

    fclose(dict);
}

void display_terms()
{
    dict = fopen("dictionary.txt", "w");   
    // fgets;
    

    fclose(dict);
}