/*Write a program to maximum frequency element in an array */
#include <stdio.h>
int main()
{
    int n,i,j,max_frequency=0,max_frequency_element;
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
        max_frequency_element = arr[0];
        for (i = 0; i < n;i++)
        {
            int frequency = 0;
            for (j = 0; j < n;j++)
            {
                if(arr[i]==arr[j])
                {
                    frequency++;
                }
            }
            if(frequency>max_frequency)
            {
                max_frequency = frequency;
                max_frequency_element = arr[i];
            }
        }
        printf("Maximum frequency element is :");
        printf("%d", max_frequency_element);
    }
    return 0;
}