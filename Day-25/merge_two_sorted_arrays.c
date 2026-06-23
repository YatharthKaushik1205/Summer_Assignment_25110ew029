/*Write a program to merge two sorted arrays */
#include <stdio.h>
int main()
{
    int i = 0, j = 0, k = 0, n1, n2;
    printf("Enter the number of elements of your first array :- ");
    scanf("%d", &n1);
    printf("Enter the number of elements of your second array :- ");
    scanf("%d", &n2);
    int sorted_Array1[n1], sorted_Array2[n2], merged_sprted_array[n1 + n2];
    for (i = 0; i < n1; i++)
    {
        printf("Enter [%d] element of first array : ", i + 1);
        scanf("%d", &sorted_Array1[i]);
    }
    for (i = 0; i < n2; i++)
    {
        printf("Enter [%d] element of Second array : ", i + 1);
        scanf("%d", &sorted_Array2[i]);
    }
    i = j = k = 0;
    while (i < n1 && j < n2)
    {
        if (sorted_Array1[i] < sorted_Array2[j])
        {
            merged_sprted_array[k] = sorted_Array1[i];
            i++;
            k++;
        }
        else
        {
            merged_sprted_array[k] = sorted_Array2[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        merged_sprted_array[k++] = sorted_Array1[i++];
    }
    while(j<n2)
    {
        merged_sprted_array[k++] = sorted_Array2[j++];
    }
    printf("Sorted Array after merging is :- \n");
    printf("[");
    for (i = 0; i < n1 + n2; i++)
    {
        printf("%d", merged_sprted_array[i]);
        if((n1+n2-i)>1)
        {
            printf(",");
        }
    }
    printf("]");
    return 0;
}
