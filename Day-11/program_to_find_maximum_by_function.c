/*Write a program to find the maximum among numbers using user-defined function */
#include<stdio.h>
int maximum(int a,int b,int c);
int main()
{
    int n1,n2,n3;
    printf("Enter the first number :");
    scanf("%d",&n1);
    printf("Enter the second number :");
    scanf("%d",&n2);
    printf("Enter the third number :");
    scanf("%d",&n3);    
    printf("Maximum among the numbers %d,%d and %d is %d",n1,n2,n3,maximum(n1,n2,n3));
    return 0;    
}
int maximum(int a,int b,int c)
{
    int max;
    return max=(a>b)?(a>c)?a:c:(b>c)?b:c;
}