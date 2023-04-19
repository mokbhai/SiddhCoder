// fread -> used to read a block {array or a stucture} from a file
// fread([adrress of array or struct], [srtct of arr/stuct], [no. of arr/struct], [file_pointer])
// fwite > write a block(array or a structure) from a file
// fwrite(&st, sizeof(st), 1, fptr)

#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct employee
    {
        int emp_code;
        char name[20];
        int hra;
        int da;
        int ta;
    };

    FILE *fp;
    struct employee e[5];
    int i, x;

    fp = fopen("Employee1.txt", "wb");

    if (fp == NULL)
    {
        printf("\n Error Opening file");
        exit(1);
    }

    printf("\n Enter the details:");

    //Writing
    for (i = 0; i < 2; i++)
    {
        printf("\n\n Enter the employee code:");
        scanf("%d", &e[i].emp_code);
        printf("\n\n Enter the name of the employee:");
        fflush(stdin);
        scanf("%[^\n]%*c",e[i].name);
        fflush(stdin);
        printf("\n\n Enter the HRA,DA and TA:");
        scanf("%d%d%d", &e[i].hra, &e[i].da, &e[i].ta);
        x = fwrite(&e[i], sizeof(e[i]), 1, fp);
        printf("\n%d", x);
    }
    // Reading
    struct employee e1;
    printf("\n THE DETAILS OF THE EMPLOYEE ARE:");
    while (1)
    {
        fread(&e1, sizeof(e1), 1, fp);
        if (feof(fp))
            break;
        printf("\n\n Employee Code:%d", e1.emp_code);
        printf("\n\n Name:%s", e1.name);
        printf("\n\n HRA,DA and TA:%d %d %d", e1.hra, e1.da, e1.ta);
    }
    fclose(fp);
    return 0;
}