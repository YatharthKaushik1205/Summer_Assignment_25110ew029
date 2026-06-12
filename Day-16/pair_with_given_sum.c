/*Write a program to print the pair with the given sum */
#include<stdio.h>
int main()
{
    int i, j,n,sum;
    printf("Enter the size of your array :");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n;i++)
    {
        printf("Enter the [%d] element of the array :", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the sum u want to check for :");
    scanf("%d", &sum);
    for (i = 0; i < n;i++)
    {
        for (j = i; j < n;j++)
        {
            if((arr[j]+arr[i]==sum)&&(j!=i))
            {
                printf("(%d,%d)\n", arr[i], arr[j]);
            }
        }
    }
    return 0;
}