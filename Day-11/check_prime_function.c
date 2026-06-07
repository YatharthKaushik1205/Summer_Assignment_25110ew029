/*Write a program to check for prime number using user-defined function */
#include<stdio.h>
void check_prime(int a);
int main()
{
    int n;
    printf("Enter the number u want to check for :");
    scanf("%d",&n);
    printf("Entered number %d is ",n);
    check_prime(n);
}
void check_prime(int a)
{
    int i;
    if(a==0 || a== 1)
    {
        printf("not prime");
        return;
    }
    else
    {
        for(i=2;i<a;i++)
        {
            if(a%i==0)
            {
                printf("not prime");
                return;
            }
        }
        printf("prime");
    }
}