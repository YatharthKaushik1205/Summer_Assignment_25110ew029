/*Write a program to find recursive fibonacci */
#include<stdio.h>
int fibonacci(int a);
int main()
{
    int n,i;
    printf("Enter the number u want to print fibonacci series");
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        printf("%d",fibonacci(i));
    }
    return 0;
}
int fibonacci(int n)
{
    if (n==1)
    {
        return 0 ;
    }
    else if(n==2)
    {
        return 1 ;
    }
    else
    {
        return fibonacci(n-1)+fibonacci(n-2);
    }
}