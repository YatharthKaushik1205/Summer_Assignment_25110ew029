/*Write a program to perform addition of matrices */
void display_matrix( int a, int b,int arr[a][b]);
#include<stdio.h>
int main()
{
    int rows, column, i, j;
    printf("Enter number of rows for matrices (Number should be a positive number >0):");
    scanf("%d", &rows);
    printf("Enter the number of column of matrices (Number should be a positive number >0):");
    scanf("%d", &column);
    int matrix1[rows][column], matrix2[rows][column],Sum_matrix[rows][column];
    for (i = 0; i < rows;i++)
    {
        for (j = 0; j < column;j++)
        {
            printf("Enter the [%d][%d] element of first matrix :", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("First matrix is entered successfully \n");
    for (i = 0; i < rows;i++)
    {
        for (j = 0; j < column;j++)
        {
            printf("Enter the [%d][%d] element of Second matrix :", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
            Sum_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("First matrix is :\n");
    display_matrix(rows, column, matrix1);
    printf("Second matrix is :\n");
    display_matrix(rows, column, matrix2);
    printf("Sum matrix is :\n");
    display_matrix(rows, column, Sum_matrix);
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