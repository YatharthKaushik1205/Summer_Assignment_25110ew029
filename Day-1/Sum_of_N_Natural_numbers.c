/*Write a program to Calculate sum of first n natural numbers*/
#include<stdio.h>
int main()
{
    int n,i,sum=0;
    printf("Entered number should be a natural number : (>0)&(Should not be a fractional number)\n");
    printf("Enter the number :");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum=sum+i;
    }
    printf("Sum of first n natural numbers is : %d",sum);
}