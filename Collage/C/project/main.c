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


int main()
{
    FILE *dict;
    dict = fopen("dictionary.txt", "a");
    add_record();
    return 0;
}

void add_record()
{

}