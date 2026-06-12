/*Write a program to find missing element of an array */
#include<stdio.h>
int main()
{
    int i, j,n;
    printf("Enter the size of array :");
    scanf("%d",&n);
    int arr[n];
    for (i = 0; i < n;i++)
    {
        printf("Enter the [%d] of the array :", i + 1);
        scanf("%d",&arr[i]);
    }
    int max = arr[0];
    for (i = 0; i < n;i++)
    {
        if(max<arr[i])
        {
            max = arr[i];
        }
    }
        printf("Missing numbers are :\n");
    for (i = 1; i < max;i++)
    {
        int found = 0;
        for (j = 0; j <n; j++)
        {
            if(arr[j]==i)
            {
                found = 1;
                break;
            }
        }
        if(found==0)
        {
            printf("%d ", i);
        }
    }
    return 0;
}