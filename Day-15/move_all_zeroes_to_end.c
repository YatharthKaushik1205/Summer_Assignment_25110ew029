/*Write a program to move all zeroes to end in an array */
#include<stdio.h>
void move_all_zeroes_to_end(int arr[], int a);
int main()
{
    int n,i;
    printf("Enter the size of the array :");
    scanf("%d", &n);
    int arr[n],original_arr[n];
    for (i = 0; i < n;i++)
    {
        printf("Enter the [%d] element of the array :", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Original array is :\n");
    printf("[");
    for (i = 0; i < n;i++)
    {
        original_arr[i] = arr[i];
        printf("%d",original_arr[i]);
        if((n-i)>1)
        {
            printf(",");
        }
    }
    printf("]");
    printf("Required array is :\n");
    printf("[");
    move_all_zeroes_to_end(arr, n);
    printf("]");
    return 0;
}
void move_all_zeroes_to_end(int arr[], int n)
{
    int i,count = 0,temp;
    for (i = 0; i < n;i++)
    {
        if(arr[i]!=0)
        {
            temp = arr[count];
            arr[count] = arr[i];
            arr[i] = temp;
            count++;
        }
    }
    for (i = 0; i < n;i++)
    {
        printf("%d", arr[i]);
        if((n-i)>1)
        {
            printf(",");
        }
    }
    return 0;
}
