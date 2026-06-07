/*Write a program to find the factorial of a given number usin user-defined function */
#include<stdio.h>
int factorial(int a);
int main()
{
    int n;
    printf("Enter the number u want to find the factorial of :");
    scanf("%d",&n);
    printf("Factorial of entered number %d is %d ",n,factorial(n));
}
int factorial(int a)
{
    int i,fact=1;
    if(a==0)
    {
        return 1;
    }
    else 
    {
        for(i=1;i<=a;i++)
        {
            fact=fact*i;
        }
        return fact;
    }
}