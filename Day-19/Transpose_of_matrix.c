/*Write a program to print transpose of matrix */
#include <stdio.h>
int main()
{
    int rows, column, i, j;
    printf("Enter number of rows for matrices (Number should be a positive number >0):");
    scanf("%d", &rows);
    printf("Enter the number of column of matrices (Number should be a positive number >0):");
    scanf("%d", &column);
    if (rows <= 0 || column <= 0)
    {
        printf("Invalid matrix dimensions.\n");
        return 1;
    }
    else
    {
        int matrix1[rows][column];
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < column; j++)
            {
                printf("Enter the [%d][%d] element of first matrix :", i + 1, j + 1);
                scanf("%d", &matrix1[i][j]);
            }
        }
        printf("Entered matrix is :\n");
        for (i = 0; i < rows; i++)
        {
            printf(" |");
            for (j = 0; j < column; j++)
            {
                printf("%4d", matrix1[i][j]);
            }
            printf("|\n");
        }
        printf("Transpose of the entered matrix is :\n");
        for (i = 0; i < column; i++)
        {
            printf(" |");
            for (j = 0; j < rows; j++)
            {
                printf("%4d", matrix1[j][i]);
            }
            printf("|\n");
        }
    }
    return 0;
}