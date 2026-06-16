/*Write a program to find row wise sum of matrix */
#include <stdio.h>
void display_matrix(int a, int b, int arr[a][b]);
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
        int matrix[rows][column];
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < column; j++)
            {
                printf("Enter the [%d][%d] element of first matrix :", i + 1, j + 1);
                scanf("%d", &matrix[i][j]);
            }
        }
        printf("Entered matrix is :\n");
        display_matrix(rows, column, matrix);
        for (i = 0; i < rows;i++)
        {
            int sum = 0;
            for (j = 0; j < column;j++)
            {
                sum += matrix[i][j];
            }
            printf("Sum of Row %d is -> %d\n", i + 1, sum);
        }
    }
    return 0;
}
void display_matrix(int a, int b,int arr[a][b])
{
    int i, j;
    for (i = 0; i < a;i++)
    {
        printf("| ");
        for (j = 0; j < b;j++)
        {
            printf("%4d ", arr[i][j]);
        }
        printf("|\n");
    }
}