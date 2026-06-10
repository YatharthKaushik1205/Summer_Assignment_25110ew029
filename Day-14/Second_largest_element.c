/*Write a Program to find the second largest element in the given array */
#include <stdio.h>
int main()
{
    int n,i,second_largest,largest;
    printf("What should be the size of your array :");
    scanf("%d", &n);
    if (n<=0)
    {
        printf("Pls Enter appropriate value ");
    }
    else
    {
        int arr[n];
        for (i = 0; i < n; i++)
        {
            printf("Enter the [%d] element of array :", i + 1);
            scanf("%d", &arr[i]);
        }
        largest = arr[0];
        for (i = 0; i < n;i++)
        {
            if(arr[i]>largest)
            {
                largest = arr[i];
            }
        }
        for (i = 0; i < n;i++)
        {
            if(arr[i]<largest)
            {
                second_largest = arr[i];
            }
        }
        printf("Second largest element of given array is %d", second_largest);
    }
    return 0;
}