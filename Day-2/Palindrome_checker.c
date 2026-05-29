/* Checking Whether a number is a palindrome or not */
#include<stdio.h>
int main()
{
    int n,n1,reverse=0,r;
    printf("Enter the number :");
    scanf("%d",&n);
    n1=n;
    while (n1!=0)
    {
        r=n1%10;
        reverse=reverse*10+r;
        n1=n1/10;
    }
    if(reverse==n)
    {
        printf("Entered number %d is a palindrome number",n);
    }
    else
    {
        printf("Entered number %d is not a palindrome number",n);
    }
}