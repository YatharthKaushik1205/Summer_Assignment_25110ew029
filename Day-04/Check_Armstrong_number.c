/* Write a Program to check Armstrong Number 
An armstrong number is the number that is equal to the sum of its own digits , with each digit raised to the
power of the total number of digits*/
#include<stdio.h>
#include<math.h>
int main()
{
    int n,r,n1,n2,digit_count=0,sum_of_digits=0;
    printf("Enter the number u want to check for : ");
    scanf("%d",&n);
    n1=n;
    n2=n;
    if(n==0)
    {
        digit_count=1;
    }
    else
    {
        while(n!=0)
        {
            digit_count+=1;
            n=n/10;
        }
    } 
    
    while(n1!=0)
    {
        r=n1%10;
        sum_of_digits = sum_of_digits+ (int)round(pow(r,digit_count));
        n1=n1/10;
    }
    if(n2==sum_of_digits)
    {
        printf("Entered number %d is an Armstrong number ",n2);
    }
    else
    {
        printf("Entered number %d is not an Armstrong number ",n2);
    }
}