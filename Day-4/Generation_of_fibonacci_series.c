/*Write a program to generate Fibonacci Series*/
#include<stdio.h>
int main()
{
    int a=0,b=1,c,n,i;
    printf("Enter the term upto which u want to print fibonacci series :");
    scanf("%d",&n);
    if(n==1)
    {
        printf("%d",a);
    }
    else if(n==2)
    {
        printf("%d",b);
    }
    else
    {
        printf("%d\n",a);
        printf("%d\n",b);
        for(i=3;i<=n;i++)
        {
            c=a+b;
            printf("%d\n",c);
            a=b;
            b=c;
        }
    }
}