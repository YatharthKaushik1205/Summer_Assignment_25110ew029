/*Write a program to print Multiplication of matrices */
#include <stdio.h>
void display_matrix( int a, int b,int arr[a][b]);
int main()
{
    int r1, c1, r2, c2, i, j, k, sum;
    printf("Enter number of rows for matrix A (Number should be a positive number >0):");
    scanf("%d", &r1);
    printf("Enter the number of column for matrix A (Number should be a positive number >0):");
    scanf("%d", &c1);
    printf("Enter the number of rows for matrix B :");
    scanf("%d", &r2);
    printf("Enter the number of columns for matrix B :");
    scanf("%d", &c2);
    if (r1 <= 0 || c1 <= 0)
    {
        printf("Invalid matrix dimensions of matrix A.\n");
        return 1;
    }
    else if (r2 <= 0 || c2 <= 0)
    {
        printf("Invalid matrix dimension of matrix B.\n");
        return 1;
    }
    else
    {
        int matrix1[r1][c1], matrix2[r2][c2],result_matrix[r1][c2];
        if (c1 == r2)
        {
            for (i = 0; i < r1; i++)
            {
                for (j = 0; j < c1; j++)
                {
                    printf("Enter the [%d][%d] element of matrix A:", i + 1, j + 1);
                    scanf("%d", &matrix1[i][j]);
                }
            }
            for (i = 0; i < r2; i++)
            {
                for (j = 0; j < c2; j++)
                {
                    printf("Enter the [%d][%d] element of matrix B:", i + 1, j + 1);
                    scanf("%d", &matrix2[i][j]);
                }
            }
            printf("Matrix A is :\n");
            display_matrix(r1, c1, matrix1);
            printf("Matrix B is :\n");
            display_matrix(r2, c2, matrix2);
            for (i = 0; i < r1;i++)
            {
                for (j = 0; j < c2;j++)
                {
                    sum = 0;
                    for (k = 0; k < c1;k++)
                    {
                        sum += matrix1[i][k] * matrix2[k][j];
                    }
                    result_matrix[i][j] = sum;
                }
            }
            printf("Multiplication of matrix A & B is (A.B) :\n");
            display_matrix(r1, c2, result_matrix);
        }
        else
        {
            printf("Entered order of matrix is not suitable for multiplication pls check again !!");
        }
    }
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