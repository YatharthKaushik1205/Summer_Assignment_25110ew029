/*Write a program to merge two arrays */
#include<stdio.h>
int main()
{
    int n1,n2,i;
    printf("Enter the size of the first array :");
    scanf("%d", &n1);
    int arr[n1];
    for (i = 0; i < n1;i++)
    {
        printf("Enter the [%d] element of the array :",i+1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the size of array u want to merge :");
    scanf("%d", &n2);
    int merging_arr[n2];
    for (i = 0; i < n2;i++)
    {
        printf("Enter the [%d] element of the merging array : ",i+1);
        scanf("%d", &merging_arr[i]);
    }
    int n = n1 + n2;
    int merged_arr[n];
    printf("First array is : \n");
    printf("[");
    for (i = 0; i < n1;i++)
    {
        printf("%d", arr[i]);
        if((n1-i)>1)
        {
            printf(",");
        }
        merged_arr[i] = arr[i];
    }
    printf("]\n");
    printf("Merging array is :\n");
    printf("[");
    for (i = 0; i < n2;i++)
    {
        printf("%d", merging_arr[i]);
        if((n2-i)>1)
        {
            printf(",");
        }
        merged_arr[n1 + i] = merging_arr[i];
    }
    printf("]\n");
    printf("]");
    return 0;
}