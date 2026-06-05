/*Write a Program to print reverse star pattern */
#include<stdio.h>
int main()
{
    int i,j,n;
    printf("Enter the number of rows u want to print : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<(n-i);j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}