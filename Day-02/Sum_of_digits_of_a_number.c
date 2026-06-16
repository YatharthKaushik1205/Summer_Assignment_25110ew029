#include<stdio.h>
int main()
{
    int n,sum=0,r,n1;
    printf("Enter the number whose digit's sum u want to find : ");
    scanf("%d",&n);
    n1=n;
    while (n1!=0)
    {
        r=n1%10;
        sum=sum+r;
        n1=n1/10;
    }
    printf("Sum of digits of the number %d is : %d",n,sum); 
}