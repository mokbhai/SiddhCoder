// to find a addion of digonal matrix
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
    // Sum Of Digonal
    printf("Matrix's Digonal Sum\n");
    int digo1 = a[0][0];
    for (int i = 1; i < m; i++)
    {
        digo1 += a[i][i];
    }
    printf("Sum of digonal of a matrix is %d", digo1);
}