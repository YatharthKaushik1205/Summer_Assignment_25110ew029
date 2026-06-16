/*Write a program to find the sum of digits of a number using recursion */
#include<stdio.h>
int sum_of_digits(int a);
int main()
{
    int n;
    printf("Enter the number u want to find the sum of digits :");
    scanf("%d",&n);
    printf("Sum of digits of entered number %d is %d",n,sum_of_digits(n));
    return 0;
}
int sum_of_digits(int a)
{
    if (a<10)
    {
        return a;
    }
    else
    {
        return (a%10)+sum_of_digits(a/10);
    }
}