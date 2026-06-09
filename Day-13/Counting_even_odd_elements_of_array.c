/*Write a program to count even or oddd elements of an array */
#include <stdio.h>
int main()
{
    int n, i, even_count = 0, odd_count = 0;
    printf("What should be the size of your array :");
    scanf("%d", &n);
    if (n == 0 || n < 0)
    {
        printf("Pls enter appropriate value ");
    }
    else
    {
        int arr[n];
        for (i = 0; i < n; i++)
        {
            printf("Enter the [%d] element of array :", i + 1);
            scanf("%d", &arr[i]);
            if (arr[i] % 2 == 0)
            {
                even_count += 1;
            }
            else
            {
                odd_count += 1;
            }
        }
        printf("Number of even elements in a given array is %d \n", even_count);
        printf("Number of odd elements in a given array is %d \n", odd_count);
        return 0;
    }
}