/*Write a Program to find x^n without pow() */
#include<stdio.h>
#include<stdlib.h>
int main()
{
    double x,value=1;
    int n,i;
    printf("Enter the value of x upto 4 decimal places:");
    scanf("%lf",&x);
    printf("Enter the value of n only integer value:");
    scanf("%d",&n);
    if((x==0)&&(n<=0))
    {
        printf("Value of %.4f^%d is undefined ",x,n);
    }
    else
    {
        for (i = 0; i < abs(n); i++)
        {
            value *= x;
        }
        if (n >= 0)
        {
            printf("Value of %.4f^%d is %.4f", x, n, value);
        }
        else
        {

            printf("Value of %.4f^%d is %.4f", x, n, 1 / value);
        }
    }
    return 0;
}