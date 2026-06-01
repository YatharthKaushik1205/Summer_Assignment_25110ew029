/*Write a Program to print factors of the given number */
#include<stdio.h>
int main()
{
    int n,i;
    printf("Enter the number u want to find factors of ");
    scanf("%d",&n);
    if(n==0)
    {
        printf("The number 0 has its only factor as 0 ");
    }
    else
    {
        printf("Factors of the given number %d is : ",n);
        for(i=1;i<=n;i++)
        {
            if(n%i==0)
            {
                printf("%d\n",i);
            }
        }
    }
}