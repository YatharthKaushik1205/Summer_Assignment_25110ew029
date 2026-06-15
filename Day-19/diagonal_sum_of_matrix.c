/*Write a program to find sum of diagonal element of matrix */
#include <stdio.h>
int main()
{
    int rows, column, i, j,diagonal_sum=0;
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
        int matrix[rows][column];
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < column; j++)
            {
                printf("Enter the [%d][%d] element of first matrix :", i + 1, j + 1);
                scanf("%d", &matrix[i][j]);
                if(i==j)
                {
                    diagonal_sum += matrix[i][j];
                }
            }
        }
        printf("Entered matrix is :\n");
        for (i = 0; i < rows; i++)
        {
            printf(" |");
            for (j = 0; j < column; j++)
            {
                printf("%4d", matrix[i][j]);
            }
            printf("|\n");
        }
        printf("Sum of its diagonal elements is : %d", diagonal_sum);
    }
    return 0;
}