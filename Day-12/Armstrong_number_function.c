/*Write a program to write function for a Armstrong number */
#include<stdio.h>
#include<math.h>
void armstrong(int a);
int main()
{
    int n;
    printf("Enter the number u want to check for :");
    scanf("%d",&n);
    armstrong(n);
    return 0;
}
void armstrong(int a)
{
    int sum=0,n2=a,digits=0,remainder,n3=a;
    if(a==0)
    {
        printf("0 is an Armstrong number");
    }
    else if(a<0)
    {
        printf("Pls Enter appropriate values (Negative numbers are not Armstrong numbers )");
    }
    else
    {
        while(a!=0)
        {
            digits+=1;
            a/=10;
        }
        while(n2!=0)
        {
            remainder=n2%10;
            sum+=(int)round(pow(remainder,digits));
            n2/=10;
        }
        if(n3==sum)
        {
            printf("Entered number %d is an Armstrong number ",n3);
        }
        else
        {
            printf("Entered number %d is not an Armstrong number",n3);
        }
    }
}