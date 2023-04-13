// e materix sum
#include<stdio.h>
int main(void)
{
    int m = 3, n = 3;
    // printf("Enter M&N: ");
    // scanf("%d\n%d", &m, &n);
    int a[m][n], b[m][n];
    for (int i = 0; i < m; i++) // For Rows
    {
        for (int j = 0; j < n; j++) // For Columns
        {
            // printf("Enter row = %d column = %d: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("Traversing\n");
    printf(" _");
    for (int i = 0; i < m; i++)
    {
        if (i == 0 || i == m)
        {
            printf("\t_\n");
        }
        printf("| ");
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }

        printf("|");
        printf("\n");
    }
    printf(" _ \t_\n");

    printf("Matrix's Transpose\n");

    printf(" _");
    for (int i = 0; i < m; i++)
    {
        if (i == 0 || i == m)
        {
            printf("\t_\n");
        }
        printf("| ");
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[j][i]);
        }

        printf("|");
        printf("\n");
    }
    printf(" _ \t_");
}