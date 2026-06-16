#include<stdio.h>
int main()
{
    int n,i,count=0;
    printf("Enter the number u want to check for prime :");
    scanf("%d",&n);
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
            count+=1;
        }
    }
    if((count)||(n==1))
    {
        printf("Entered number %d is not a prime number",n);
    }
    else
    {
        printf("Entered number %d is a prime number",n);
    }
}