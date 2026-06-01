/*Write a Program to check Strong number 
A strong number is a number that is equal to the sum of factorials of it own digits */
#include<stdio.h>
int factorial(int a);
int main()
{
    int n,digit,n1,sum=0;
    printf("Enter the number u want to check for : ");
    scanf("%d",&n);
    n1=n;
    
    while(n1!=0)
    {
        digit=n1%10;
        sum+=factorial(digit);
        n1/=10;
    }
    if((sum==n)&&(n!=0))
    {
        printf("Entered number %d is a Strong number ",n);
    }
    else
    {
        printf("Entered number %d is not a Strong number ",n);
    }
}
int factorial(int a)
{
    int i,fact=1;
    for(i=1;i<=a;i++)
    {
        fact=fact*i;
    }
    return fact;
}