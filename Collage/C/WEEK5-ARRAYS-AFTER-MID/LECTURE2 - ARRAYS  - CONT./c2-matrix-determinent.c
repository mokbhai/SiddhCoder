// 2d aray from user and display it
#include<stdio.h>
int main(void)
{
    int m = 3, n = 3;
    // printf("Enter M&N: ");
    // scanf("%d\n%d", &m, &n);
    int a[m][n];
    for (int i = 0; i < m; i++) // For Rows
    {
        for (int j = 0; j < n; j++) // For Columns
        {
            printf("Enter row = %d column = %d: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("Matrix Determinent\n");
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("a[%d][%d]{a[%d][%d] x a[%d][%d] - a[%d][%d] x a[%d][%d]}", a[i][j]);
            sum += a[i][j];
        }
        printf("\n");
    }
}