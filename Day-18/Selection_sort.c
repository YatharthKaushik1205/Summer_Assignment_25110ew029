/*Write a program to perform Selection sort technique */
#include <stdio.h>
int main()
{
    int n, i, j, temp,smallest,largest;
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
                smallest = i;
                for (j = i+1; j < n; j++)
                {
                    if (arr[smallest] >arr[j])
                    {
                        smallest = j;
                    }
                }
                temp = arr[smallest];
                arr[smallest] = arr[i];
                arr[i] = temp;
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
                largest = i;
                for (j = i+1; j < n; j++)
                {
                    if (arr[largest] <arr[j])
                    {
                        largest = j;
                    }
                }
                temp = arr[largest];
                arr[largest] = arr[i];
                arr[i] = temp;
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