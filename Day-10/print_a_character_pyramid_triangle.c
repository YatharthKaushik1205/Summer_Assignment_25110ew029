/*Write a program to print the palindromic character pyramid triangle*/
#include<stdio.h>
int main()
{
    int i,j,k,n,t;
    printf("Enter the number of rows u want to print :");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            printf(" ");
        }
        for(k=1;k<=i;k++)
        {
            printf("%c",64+k);
        }
        for(t=i-1;t>=1;t--)
        {
            printf("%c",64+t);
        }
        printf("\n");
    }
    return 0;
}