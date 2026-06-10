/*Write a program to perform linear search on an array */
#include <stdio.h>
int main()
{
    int n, required_element, i;
    printf("What should be the size of your array :");
    scanf("%d", &n);
    if (n == 0 || n < 0)
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
        printf("What element u want to search in this array :");
        scanf("%d", &required_element);
        for (i = 0; i < n; i++)
        {
            if (arr[i] == required_element)
            {
                printf("Element found at %d position", i + 1);
                return 0;
            }
        }
        printf("Element not found in the given array ");
    }
    return 0;
}