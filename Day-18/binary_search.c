/*Write a program to perform binary search technique */
#include <stdio.h>
int main()
{
    int n, i, j, element, mid, low_index = 0, high_index, found = 0;
    char answer;
    printf("What should be the size of your array :");
    scanf("%d", &n);
    high_index = n-1;
    if (n <= 0)
    {
        printf("Pls Enter appropriate value ");
        return 0;
    }
    else
    {
        int arr[n];
        for (i = 0; i < n; i++)
        {
            printf("Enter the [%d] element of array :", i + 1);
            scanf("%d", &arr[i]);
        }
        printf("In which order u have you have your array sorted\n[A or a for ascending ]\n[D or d for descending] :");
        scanf(" %c", &answer);
        printf("Which element u want to search :");
        scanf("%d", &element);
        if ((answer == 'A') || (answer == 'a'))
        {
            while (low_index <= high_index)
            {
                mid = (low_index + high_index) / 2;
                if (arr[mid] == element)
                {
                    printf("Element found at %d location", mid + 1);
                    found = 1;
                    break;
                }
                else if (arr[mid] > element)
                {
                    high_index = mid - 1;
                }
                else if (arr[mid] < element)
                {
                    low_index = mid + 1;
                }
            }
            if (found == 0)
            {
                printf("Element not found ");
            }
        }
        else if ((answer == 'D') || (answer == 'd'))
        {
            while (low_index <= high_index)
            {
                mid = (low_index + high_index) / 2;
                if (arr[mid] == element)
                {
                    printf("Element found at %d location", mid + 1);
                    found = 1;
                    break;
                }
                else if (arr[mid] < element)
                {
                    high_index = mid - 1;
                }
                else if (arr[mid] > element)
                {
                    low_index = mid + 1;
                }
            }
            if(found==0)
            {
                printf("Element not found");
            }
        }
        else
        {
            printf("Pls enter correct input ");
        }
    }
    return 0;
}