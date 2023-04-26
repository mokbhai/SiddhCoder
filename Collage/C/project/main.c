#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERMS 100

struct MedicalTerm {
    char name[50];
    char definition[200];
    char subfield[50];
};

void addRecord(struct MedicalTerm term, FILE *file) {
    fprintf(file, "%s,%s,%s\n", term.name, term.definition, term.subfield);
    printf("Record added successfully.\n");
}

void displayAllTerms(FILE *file) {
    rewind(file);
    struct MedicalTerm term;
    printf("All terms in alphabetical order:\n");
    while (fscanf(file, "%[^,],%[^,],%[^\n]\n", term.name, term.definition, term.subfield) != EOF) {
        printf("%s - %s (%s)\n", term.name, term.definition, term.subfield);
    }
}

void updateDefinition(char termName[], FILE *file) {
    rewind(file);
    struct MedicalTerm term;
    int found = 0;
    while (fscanf(file, "%[^,],%[^,],%[^\n]\n", term.name, term.definition, term.subfield) != EOF) {
        if (strcmp(term.name, termName) == 0) {
            printf("Current definition: %s\n", term.definition);
            printf("Enter new definition: ");
            getchar();
            gets(term.definition);
            fseek(file, -strlen(term.definition)-2, SEEK_CUR); // move file pointer back to start of current line
            fprintf(file, "%s,%s,%s\n", term.name, term.definition, term.subfield);
            printf("Definition updated successfully.\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Term not found.\n");
    }
}

void searchTerm(char termName[], FILE *file) {
    rewind(file);
    struct MedicalTerm term;
    int found = 0;
    while (fscanf(file, "%[^,],%[^,],%[^\n]\n", term.name, term.definition, term.subfield) != EOF) {
        if (strcmp(term.name, termName) == 0) {
            printf("%s - %s (%s)\n", term.name, term.definition, term.subfield);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Term not found.\n");
    }
}

void deleteRecord(char termName[], FILE *file) {
    rewind(file);
    FILE *tempFile = fopen("temp.txt", "w");
    struct MedicalTerm term;
    int found = 0;
    while (fscanf(file, "%[^,],%[^,],%[^\n]\n", term.name, term.definition, term.subfield) != EOF) {
        if (strcmp(term.name, termName) == 0) {
            printf("Record deleted.\n");
            found = 1;
        } else {
            fprintf(tempFile, "%s,%s,%s\n", term.name, term.definition, term.subfield);
        }
    }
    fclose(file);
    fclose(tempFile);
    remove("medical_terms.txt");
    rename("temp.txt", "medical_terms.txt");
    if (!found) {
        printf("Term not found.\n");
    }
}

int main() 
{
    FILE *file = fopen("medical_terms.txt", "a+");
    if (file == NULL) 
    {
        printf("Error: Unable to open file.\n");
        exit(1);
    }
    int choice;
    do
    {
        printf("\nMedical Terminology Dictionary Management\n");
        printf("1. Add term\n");
        printf("2. Display all terms\n");
        printf("3. Update definition\n");
        printf("4. Search term\n");
        printf("5. Delete record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: {
                struct MedicalTerm term;
                printf("Enter term name: ");
                scanf("%s", term.name);
                printf("Enter definition: ");
                getchar();
                gets( term.definition);
                printf("Enter subfield: ");
                scanf("%s", term.subfield);
                addRecord(term, file);
                break;
            }
            case 2: {
                displayAllTerms(file);
                break;
            }
            case 3: {
                char termName[50];
                printf("Enter term name: ");
                scanf("%s", termName);
                updateDefinition(termName, file);
                break;
            }
            case 4: {
                char termName[50];
                printf("Enter term name: ");
                scanf("%s", termName);
                searchTerm(termName, file);
                break;
            }
            case 5: {
                char termName[50];
                printf("Enter term name: ");
                scanf("%s", termName);
                deleteRecord(termName, file);
                break;
            }
            case 6: {
                printf("Exiting program.\n");
                break;
            }
            default: {
                printf("Invalid choice. Try again.\n");
                break;
            }
        }
    }
    while (choice != 6);
    fclose(file);
    return 0;
}