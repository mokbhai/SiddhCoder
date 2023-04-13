// 2d aray from user and display it
#include<stdio.h>
int main(void)
{
    int m, n;
    // printf("Enter M&N: ");
    // scanf("%d\n%d", &m, &n);
    m = n = 3;
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
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

}