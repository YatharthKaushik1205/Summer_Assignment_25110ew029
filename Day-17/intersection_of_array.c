/*Write a program to find the intersection of two arrays */
#include <stdio.h>
int remove_duplicates(int arr[], int n);
int main()
{
    int i,j,n1, n2,newsize_1,newsize_2;
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
    newsize_1= remove_duplicates(arr, n1);
    newsize_2 = remove_duplicates(arr2, n2);
    printf("Intersection of arrays is :\n");
    printf("[");
    int count = 0;
    for (i = 0; i < newsize_1;i++)
    {
        for (j = 0; j < newsize_2;j++)
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
int remove_duplicates(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] == arr[i])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[n - 1];
                arr[n - 1] = temp;
                n--;
                j--;
            }
        }
    }
    return n;
}
