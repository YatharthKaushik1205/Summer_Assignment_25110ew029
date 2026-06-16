/*Write a program to find recursive factorial */
#include<stdio.h>
int factorial(int a);
int main()
{
    int n;
    printf("Enter the number u want to find factorial of :");
    scanf("%d",&n);
    printf("Factorial of the given number %d is %d",n,factorial(n));
    return 0;
}
int factorial(int a)
{
    int product;
    if (a==0)
    {
        return 1;
    }
    else
    {
        return a*factorial(a-1);
    }
}