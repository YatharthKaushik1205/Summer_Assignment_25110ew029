/* Write a Program to Find factorial of a number */
#include<stdio.h>
int main()
{
  int n,fact=1,i;
  printf("Enter the number of which u want to find factorial of : ");
  scanf("%d",&n);
  if(n==0)
  {
    printf("Factorial of %d is 1",n);
  }
  else
  {
    for(i=0;(n-i)>0;i++)
    {
        fact=fact*(n-i);
    }
    printf("Factorial of %d is %d",n,fact);
  }
}