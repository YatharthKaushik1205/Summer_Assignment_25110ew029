/*Write a program to print frequency of an element in an array */
#include <stdio.h>
int main()
{
    int n, required_element,frequency=0,i;
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
        printf("Which element frequency u want to print in this array :");
        scanf("%d", &required_element);
        for (i = 0; i < n; i++)
        {
            if (arr[i] == required_element)
            {
                frequency += 1;
            }
        }
        printf("Number of time %d present in this array is %d", required_element, frequency);
    }
    return 0;
}