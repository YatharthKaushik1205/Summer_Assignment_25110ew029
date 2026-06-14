/*Write a program to perform bubble sort technique */
#include <stdio.h>
int main()
{
    int n, i, j, temp;
    char answer;
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
        printf("In which order u want to sort the array\n[A or a for ascending ]\n[D or d for descending] :");
        scanf(" %c", &answer);
        if ((answer == 'A') || (answer== 'a'))
        {
            for (i = 0; i < n - 1; i++)
            {
                for (j = 0; j < n-i-1; j++)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        temp = arr[j + 1];
                        arr[j + 1] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            printf("Array sorted in ascending order given as : \n");
            printf("[");
            for (i = 0; i < n; i++)
            {
                printf("%d", arr[i]);
                if((n-i>1))
                {
                    printf(",");
                }
            }
            printf("]");
            return 0;
        }
        else if ((answer == 'D') || (answer== 'd'))
        {
            for (i = 0; i < n - 1; i++)
            {
                for (j = 0; j < n-i-1; j++)
                {
                    if (arr[j] < arr[j + 1])
                    {
                        temp = arr[j + 1];
                        arr[j + 1] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            printf("Array sorted in descending order given as : \n");
            printf("[");
            for (i = 0; i < n; i++)
            {
                printf("%d", arr[i]);
                if((n-i>1))
                {
                    printf(",");
                }
            }
            printf("]");
            return 0;
        }
        else
        {
            printf("Pls enter correct input ");
        }
    }
    return 0;
}