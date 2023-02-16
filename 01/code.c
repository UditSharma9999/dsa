#include <stdlib.h>
#include <stdio.h>
int main()
{
    int row, col, k, a[10][10], b[10][10], sum[10][10], result[10][10], i, j;
    printf("Enter the number of rows (between 1 and 10): ");
    scanf("%d", &row);
    printf("Enter the number of columns (between 1 and 10): ");
    scanf("%d", &col);

    printf("\nEnter elements of 1st matrix:\n");
    for (i = 0; i < row; ++i)
        for (j = 0; j < col; ++j)
        {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }

    printf("Enter elements of 2nd matrix:\n");
    for (i = 0; i < row; ++i)
        for (j = 0; j < col; ++j)
        {
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }

    // adding two matrices
    for (i = 0; i < row; ++i)
        for (j = 0; j < col; ++j)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    printf("Sum of the two matrices: \n");
    for (i = 0; i < row; ++i){
        for (j = 0; j < col; ++j)
        {
            printf("%d ", sum[i][j]);
        }
        printf("\n\n");
    }

    // multiplication of two matrix
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            for (int k = 0; k < col; ++k)
            {
                result[i][j] = a[i][k] * b[k][j];
            }
        }
    }
    printf("\nOutput Matrix:\n");
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            printf("%d  ", result[i][j]);
            if (j == col - 1)
                printf("\n");
        }
    }

    return 0;
}
