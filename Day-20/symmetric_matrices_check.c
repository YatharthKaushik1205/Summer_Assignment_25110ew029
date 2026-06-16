/*Write a program to check for symmetric matrix */
#include <stdio.h>
int main()
{
    int rows, column, i, j;
    printf("Enter number of rows for matrices (Number should be a positive number >0):");
    scanf("%d", &rows);
    printf("Enter the number of column of matrices (Number should be a positive number >0):");
    scanf("%d", &column);
    if ((rows <= 0 || column <= 0))
    {
        printf("Invalid matrix dimensions.\n");
        return 1;
    }
    if(rows!=column)
    {
        printf("Entered matrix is not a square matrix.\n");
        printf("A symmetric matrix must be a square matrix\n");
        return 1;
    }
    else
    {
        int matrix[rows][column];
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < column; j++)
            {
                printf("Enter the [%d][%d] element of first matrix :", i + 1, j + 1);
                scanf("%d", &matrix[i][j]);
            }
        }
        for (i = 0; i < rows;i++)
        {
            for (j = i+1; j < column;j++)
            {
                if(matrix[i][j]!=matrix[j][i])
                {
                    printf("[Entered matrix is not a symmetric matrix]");
                    return 1;
                }

            }
        }
        printf("Entered matrix is a symmetric matrix ");
        return 0;
    }
}