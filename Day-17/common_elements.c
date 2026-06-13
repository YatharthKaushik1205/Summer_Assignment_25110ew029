/*Write a program to find the common elements of two arrays */
#include <stdio.h>
int main()
{
    int i,j,n1, n2;
    printf("Enter the size of your 1st array :");
    scanf("%d", &n1);
    int arr[n1];
    for (i = 0; i < n1; i++)
    {
        printf("Enter the [%d] element of the 1st array :", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Enter the size of 2nd array :");
    scanf("%d", &n2);
    int arr2[n2];
    for (i = 0; i < n2; i++)
    {
        printf("Enter the [%d] element of the 2nd array :", i + 1);
        scanf("%d", &arr2[i]);
    }
    printf("Common elements of arrays is :\n");
    printf("[");
    int count = 0;
    for (i = 0; i < n1;i++)
    {
        for (j = 0; j < n2;j++)
        {
            if(arr[i]==arr2[j])
            {
                if(count>0)
                {
                    printf(",");
                }
                printf("%d", arr[i]);
                count++;
                break;
            }
        }
    }
    printf("]");
    return 0;
}
