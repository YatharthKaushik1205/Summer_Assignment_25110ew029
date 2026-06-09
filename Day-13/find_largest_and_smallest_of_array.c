/*Write a Program to find the largest and smallest number of an array */
#include <stdio.h>
int main()
{
    int n, i, largest, smallest;
    printf("What should be the size of your array :");
    scanf("%d", &n);
    if (n == 0 || n < 0)
    {
        printf("Pls enter appropriate value ");
    }
    else
    {
        int arr[n];
        for (i = 1; i <= n; i++)
        {
            printf("Enter the [%d] element of array :", i);
            scanf("%d", &arr[i - 1]);
        }
        largest = arr[0];
        smallest = arr[0];
        for (i = 1; i < n; i++)
        {
            if (largest < arr[i])
            {
                largest = arr[i];
            }
            else if (smallest > arr[i])
            {
                smallest = arr[i];
            }
        }
        printf("Largest element of the given array is : %d \n", largest);
        printf("Smallest element of the given array is : %d", smallest);
    }
    return 0;
}