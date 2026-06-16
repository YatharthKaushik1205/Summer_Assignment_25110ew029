/*Write a Program to convert Binary number to Decimal number
this code only works for numbers having 19 digits without any decimal(.) in it */
#include<stdio.h>
#include<math.h>
int main()
{
    long long n,n1;
    int i=0,r,int_sum=0;
    printf("Enter the binary number to convert it into decimal number :");
    scanf("%lld",&n);
    n1=n;
    if(n1==0)
    {
        printf("0");
    }
    else
    {
        while(n1!=0)
        {
            r=n1%10;
            if(r!=0&&r!=1)
            {
                printf("Pls enter valid number");
                return 0;
            }
            else
            {
                int_sum+= r*pow(2,i);
                i=i+1;
                n1=n1/10;
            }
        }
        printf("Decimal number is : \n");
        printf("%d",int_sum);
    }
}
