/*Write a Program To check For a Perfect Number
A perfect Number is a Number whose factor's Sum is equal to the number itself
excluding the number itself from its factors*/
#include<stdio.h>
int main()
{
    int i,n,sum=0;
    printf("Enter the number u want to check for :");
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        if(n%i==0)
        {
            sum+=i;
        }
    }
    if(n==sum)
    {
        printf("Entered number %d is a perfect number ",n);
    }
    else
    {
        printf("Entered number %d is not a perfect number ",n);
    }
}