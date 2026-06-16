/*Write a program to reverse the number using recursion */
#include<stdio.h>
int reverse(int a,int b);
int main()
{
    int n;
    printf("Enter the number u want to find the sum of digits :");
    scanf("%d",&n);
    printf("Reverse of the entered number %d is %d",n,reverse(n,0));
    return 0;
}
int reverse(int n,int rev)
{
    if(n==0)
    {
        return rev;
    }
    return reverse(n/10,rev*10+n%10);
}