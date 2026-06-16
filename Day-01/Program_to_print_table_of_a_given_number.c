/*Write a program to Print multiplication table of a given number */
#include<stdio.h>
int main()
{
    int n,i;
    printf("Enter the number of which you want to print the table for : ");
    scanf("%d",&n);
    for(i=1;i<=10;i++)
    {
        printf("%d x %d = %d\n",n,i,n*i);
    }
}