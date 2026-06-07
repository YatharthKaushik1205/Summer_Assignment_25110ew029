/*Write a program to find the sum of two numbers using user-defined function */
#include<stdio.h>
int sum(int a,int b);
int main()
{
    int n1,n2;
    printf("Enter the first number :");
    scanf("%d",&n1);
    printf("Enter the second number :");
    scanf("%d",&n2);
    printf("Sum of two numbers %d and %d is %d",n1,n2,sum(n1,n2));
    return 0;    
}
int sum(int a,int b)
{
    int c;
    c=a+b;
    return c;
}