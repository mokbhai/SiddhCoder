#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

// Structure to represent a medical terminology record
typedef struct {
    char term_name[50];
    char definition[100];
    char subfield[50];
} Record;

// Function prototypes
void add_record(Record records[], int *num_records);
void display_records(Record records[], int num_records);
void update_definition(Record records[], int num_records);
void search_term(Record records[], int num_records);
void delete_record(Record records[], int *num_records);

int main() {
    Record records[MAX_RECORDS];
    int num_records = 0;

    while (1) {
        printf("1. Add record\n");
        printf("2. Display records\n");
        printf("3. Update definition\n");
        printf("4. Search term\n");
        printf("5. Delete record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record(records, &num_records);
                break;
            case 2:
                display_records(records, num_records);
                break;
            case 3:
                update_definition(records, num_records);
                break;
            case 4:
                search_term(records, num_records);
                break;
            case 5:
                delete_record(records, &num_records);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }

        printf("\n");
    }

    return 0;
}

// Function to add a record to the file
void add_record(Record records[], int *num_records) {
    if (*num_records == MAX_RECORDS) {
        printf("Maximum number of records reached\n");
        return;
    }

    Record record;

    printf("Enter term name: ");
    char g;
    scanf("%c", &g);
    scanf("%[^\n]%*c", record.term_name);

    printf("Enter definition: ");
    scanf("%[^\n]%*c", record.definition);

    printf("Enter subfield: ");
    scanf("%[^\n]%*c", record.subfield);

    records[*num_records] = record;
    (*num_records)++;

    printf("Record added successfully\n");
}

// Function to display all the terms in alphabetical order
void display_records(Record records[], int num_records) {
    // Sort the records in alphabetical order based on term name
    for (int i = 0; i < num_records - 1; i++) {
        for (int j = 0; j < num_records - i - 1; j++) {
            if (strcmp(records[j].term_name, records[j+1].term_name) > 0) {
                Record temp = records[j];
                records[j] = records[j+1];
                records[j+1] = temp;
            }
        }
    }

    // Display the sorted records
    for (int i = 0; i < num_records; i++) {
        printf("%s: %s (%s)\n", records[i].term_name, records[i].definition, records[i].subfield);
    }
}

// Function to update the definition of a term
void update_definition(Record records[], int num_records) {
    char term_name[50];

    printf("Enter term name to update: ");
    scanf("%s", term_name);

    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].term_name, term_name) == 0) {
            printf("Enter new definition: ");
            scanf("%s", records[i].definition);
        printf("Definition updated successfully\n");
        return;
    }
}

printf("Term not found\n");
}

// Function to search for a term by its name
void search_term(Record records[], int num_records) 
{
char term_name[50];
printf("Enter term name to search: ");
scanf("%s", term_name);

for (int i = 0; i < num_records; i++) {
    if (strcmp(records[i].term_name, term_name) == 0) {
        printf("%s: %s (%s)\n", records[i].term_name, records[i].definition, records[i].subfield);
        return;
    }
}

printf("Term not found\n");
}

// Function to delete a record from the file
void delete_record(Record records[], int *num_records) {
char term_name[50];
printf("Enter term name to delete: ");
scanf("%s", term_name);

for (int i = 0; i < *num_records; i++) {
    if (strcmp(records[i].term_name, term_name) == 0) {
        // Shift all records after the deleted record one position to the left
        for (int j = i; j < *num_records - 1; j++) {
            records[j] = records[j+1];
        }

        (*num_records)--;
        printf("Record deleted successfully\n");
        return;
    }
}

printf("Term not found\n");
}
