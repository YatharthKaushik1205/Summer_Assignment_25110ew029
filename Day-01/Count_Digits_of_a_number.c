/*Write a Program to count digits of a number */
#include<stdio.h>
int main()
{
    int n,count=0,n1;
    printf("Enter the number of which u want to count the digits : ");
    scanf("%d",&n);
    n1=n;
    while(n1!=0)
    {
        count=count+1;
        n1=n1/10;
    }
    printf("The number of digits of the given number is : %d",count);
    return 0;
}