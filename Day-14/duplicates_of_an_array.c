/*Write a program to find duplicates in an array */
#include <stdio.h>
int main()
{
    int n, already_seen, i, j;
    printf("What should be the size of your array :");
    scanf("%d", &n);
    if (n <= 0)
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
        printf("Repeated numbers are :\n");
        for (i = 0; i < n; i++)
        {
            already_seen = 0;
            for (j = 0; j < i; j++)
            {
                if (arr[i] == arr[j])
                {
                    already_seen = 1;
                    break;
                }
            }
            if (already_seen)
            {
                continue;
            }
            for (j = i + 1; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    printf("%d,", arr[j]);
                    break;
                }
            }
        }
    }
    return 0;
}