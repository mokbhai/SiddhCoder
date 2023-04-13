// Error
// Do by dinamic value of m and n
// matrix multiply
#include<stdio.h>
int main(void)
{
    int m = 2, n = 3;
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
    for (int i = 0; i < n; i++) // For Rows
    {
        for (int j = 0; j < m; j++) // For Columns
        {
            // printf("Enter row = %d column = %d: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }
    printf("Matrixs Multiply\n");
    int sum = 0;
    int i = 0, j = 0, k = 0;
    // for (int k = 0; k < m; k++)
    // {
        for (i; i  < m; i++)
        {
            sum = 0;
            for (j; j < n; j++)
            {
                sum += a[i][j] * b[j][i];
                // printf("%d\t", a[i][j] * b[j][i]);
            }
            printf("%d\t", sum);
        }
        printf("\n");
    // }
}