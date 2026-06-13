/*Write a program to find union of two arrays */
#include <stdio.h>
int main()
{
    int n1, n2, i, j;
    printf("Enter the size of the first array :");
    scanf("%d", &n1);
    int arr[n1];
    for (i = 0; i < n1; i++)
    {
        printf("Enter the [%d] element of the array :", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the size of second array :");
    scanf("%d", &n2);
    int arr2[n2];
    for (i = 0; i < n2; i++)
    {
        printf("Enter the [%d] element of the 2nd array : ", i + 1);
        scanf("%d", &arr2[i]);
    }
    int n = n1 + n2;
    int union_arr[n];
    int union_size = 0;
    printf("First array is : \n");
    printf("[");
    for (i = 0; i < n1; i++)
    {
        printf("%d", arr[i]);
        if ((n1 - i) > 1)
        {
            printf(",");
        }
    }
    printf("]\n");
    printf("Second array is :\n");
    printf("[");
    for (i = 0; i < n2; i++)
    {
        printf("%d", arr2[i]);
        if ((n2 - i) > 1)
        {
            printf(",");
        }
    }
    printf("]\n");
    for (i = 0; i < n1; i++)
    {
        int found = 0;
        for (j = 0; j < union_size; j++)
        {
            if (union_arr[j] == arr[i])
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            union_arr[union_size] = arr[i];
            union_size++;
        }
    }
    for (i = 0; i < n2; i++)
    {
        int found = 0;
        for (j = 0; j < union_size; j++)
        {
            if (union_arr[j] == arr2[i])
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            union_arr[union_size] = arr2[i];
            union_size++;
        }
    }
    printf("Union array is :\n");
    printf("[");
    for (i = 0; i < union_size; i++)
    {
        printf("%d", union_arr[i]);
        if((union_size-i)>1)
        {
            printf(",");
        }
    }
    printf("]");
    return 0;
}