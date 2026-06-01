/*Write a Program to find the larest prime factor of a given number */
#include<stdio.h>
#include<stdbool.h>
bool isprime(int a);
int main()
{
    int n,i,largest_prime_fact;
    printf("Enter the number u want to find largest prime factor of ");
    scanf("%d",&n);
    if(n==0||n==1)
    {
        printf("The number 0 & 1 doesn't have any prime factor ");
    }
    else
    {
        for(i=2;i<=n;i++)
        {
            if((n%i==0)&&(isprime(i)))
            {
                largest_prime_fact=i;
            }
        }
        printf("Largest Prime factor of the entered number %d is %d",n,largest_prime_fact);
    }
}
bool isprime(int a)
{
    int i;
    if(a<=1)
    {
        return false;
    }
    for(i=2;i<a;i++)
    {
        if(a%i==0)
        {
            return false;
        }

    }
    return true;

}