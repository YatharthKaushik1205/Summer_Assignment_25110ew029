/*Write a program to find sum and average of an array */
#include <stdio.h>
int main()
{
    int n, i, sum = 0;
    printf("What should be the size of your array :");
    scanf("%d", &n);
    int arr[n];
    if (n == 0 || n < 0)
    {
        printf("Pls enter appropriate value ");
    }
    else
    {
        for (i = 1; i <= n; i++)
        {
            printf("Enter the [%d] element of array :", i);
            scanf("%d", &arr[i - 1]);
            sum = sum + arr[i - 1];
        }
        printf("Sum of the array is : %d\n", sum);
        printf("Average of the array is : %.2f", (float)sum / n);
    }
    return 0;
}