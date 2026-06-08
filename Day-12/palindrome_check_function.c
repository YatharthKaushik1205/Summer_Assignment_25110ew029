/*Write a program to write function for a palindrome number */
#include<stdio.h>
void palindrome(int a);
int main()
{
    int n;
    printf("Enter the number u want to check for :");
    scanf("%d",&n);
    palindrome(n);
    return 0;
}
void palindrome(int a)
{
    int reverse=0,n2=a,remainder;
    if(a==0)
    {
        printf("0 is a palindrome number");
    }
    else
    {
        while(a!=0)
        {
            remainder=a%10;
            reverse=reverse*10+remainder;
            a/=10;
        }
        if(n2==reverse)
        {
            printf("Entered number %d is palindrome number ",n2);
        }
        else
        {
            printf("Entered number %d is not a palindrome number",n2);
        }
    }
}