#include<stdio.h>
int main()
{
    int n,product=1,r,n1;
    printf("Enter the number whose digit's sum u want to find : ");
    scanf("%d",&n);
    n1=n;
    while (n1!=0)
    {
        r=n1%10;
        product=product*r;
        n1=n1/10;
    }
    printf("Product of digits of the number %d is : %d",n,product); 
}