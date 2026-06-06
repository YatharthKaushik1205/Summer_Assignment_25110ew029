/*Write a program to print a star pyramid */
#include<stdio.h>
int main()
{
    int i,j,n;
    printf("Enter the number of rows u want to print :");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n+i-1;j++)
        {
            if(j<=n-i)
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}