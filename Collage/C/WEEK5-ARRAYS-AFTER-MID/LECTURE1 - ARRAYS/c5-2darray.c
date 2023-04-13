// 2d aray from user and display it
#include<stdio.h>
int main(void)
{
    int m, n;
    printf("Enter M&N: ");
    scanf("%d\n%d", &m, &n);
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter row = %d column = %d: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("Traversing\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}