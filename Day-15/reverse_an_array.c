/*Write a program to reverse an array */
#include<stdio.h>
int main()
{
    int n,i;
    printf("Enter the size of the array ");
    scanf("%d", &n);
    int arr[n], reversed_arr[n];
    for (i = 0; i < n;i++)
    {
        printf("Enter the [%d] element of the array :", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Reversed array is :\n");
    printf("[");
    for (i = 0; i<n;i++)
    {
        reversed_arr[i] = arr[n-1-i];
        printf("%d", reversed_arr[i]);
        if(n-i>1)
        {
            printf(",");
        }
    }
    printf("]");
    return 0;
}