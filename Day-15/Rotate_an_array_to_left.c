/*Write a program to rotate an array to left */
#include<stdio.h>
int main()
{
    int n,i,temp;
    printf("Enter the size of the array :");
    scanf("%d", &n);
    int arr[n],original_arr[n];
    for (i = 0; i < n;i++)
    {
        printf("Enter the [%d] element of the array :", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Original array is :\n");
    printf("[");
    for (i = 0; i < n;i++)
    {
        original_arr[i] = arr[i];
        printf("%d",original_arr[i]);
        if((n-i)>1)
        {
            printf(",");
        }
    }
    printf("]\n");
    for (i = 0; i < n - 1; i++)
    {
        temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
    printf("Left Rotated array is :\n");
    printf("[");
    for (i = 0; i < n;i++)
    {
        printf("%d", arr[i]);
        if((n-i)>1)
        {
            printf(",");
        }
    }
    printf("]");
    return 0;
}