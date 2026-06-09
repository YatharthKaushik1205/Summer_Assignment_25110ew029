/*Write a program to input and display array */
#include <stdio.h>
int main()
{
    int n, i;
    printf("What should be the size of your array :");
    scanf("%d", &n);
    if (n == 0 || n < 0)
    {
        printf("Pls Enter appropriate value ");
    }
    else
    {
        int arr[n];
        for (i = 1; i <= n; i++)
        {
            printf("Enter the [%d] element of array :", i);
            scanf("%d", &arr[i - 1]);
        }
        printf(" Array is : [");
        for (i = 0; i < n; i++)
        {
            printf("%d", arr[i]);
            if (i < n - 1)
            {
                printf(",");
            }
        }
        printf("]");
    }
    return 0;
}