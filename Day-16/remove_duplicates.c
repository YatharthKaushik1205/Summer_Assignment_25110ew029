/*Write a program to remove duplicates from the given array */
#include<stdio.h>
int main()
{
    int i, j,n;
    printf("Enter the size of your array :");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n;i++)
    {
        printf("Enter the [%d] element of the array :", i + 1);
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n;i++)
    {
        for (j = i+1; j < n;j++)
        {
            if(arr[j]==arr[i])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[n-1];
                arr[n - 1] = temp;
                n--;
                j--;
            }
        }
    }
    printf("New array is :");
    printf("[");
    for (i = 0;i<n;i++)
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