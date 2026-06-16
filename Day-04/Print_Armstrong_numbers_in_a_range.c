/* Write a Program to print Armstrong number within a range 
An armstrong number is the number that is equal to the sum of its own digits , with each digit raised to the
power of the total number of digits*/
#include<stdio.h>
#include<math.h>
int main()
{
    int n,m,i,r,n1,n3,digit_count=0,sum_of_digits=0;
    printf("Enter the Starting number of the range :");
    scanf("%d",&n);
    printf("Enter the Stopping point for the range :");
    scanf("%d",&m);
    for(i=n;i<=m;i++)
    {
        n1=i;
        n3=i;
        digit_count=0;
        if(n3==0)
        {
            digit_count=1;
        }
        else
        {
            while(n3!=0)
            {
                digit_count+=1;
                n3=n3/10;
            }
        }
        sum_of_digits=0;
        while(n1!=0)
        {
            r=n1%10;
            sum_of_digits = sum_of_digits+ (int)round(pow(r,digit_count));
            n1=n1/10;
        }
        if(i==sum_of_digits)
        {
        printf("%d\n",i);
        }
    }
}