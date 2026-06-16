/*Write a Program to convert Decimal number to Binary number */
#include<stdio.h>
void fractional_part(float a);
int main()
{
    float n,fract_part;
    int i=0,n1,r,arr[50];
    printf("Enter the decimal number to convert it into Binary number :");
    scanf("%f",&n);
    n1=(int)n;
    printf("Binary number is : \n");
    if(n1==0)
    {
        printf("0");
    }
    else
    {
        while(n1!=0)
        {
            r=n1%2;
            arr[i]=r;
            i=i+1;
            n1=n1/2;
        }
        for(int j=i-1;j>=0;j--)
        {
            printf("%d",arr[j]);
        }
    }
    fract_part= n-(int)n;
    if(fract_part!=0)
    {
        printf(".");
        fractional_part(fract_part);
    }
    return 0;
}
void fractional_part(float a)
{
    int i;
    for(i=0;i<4;i++)
    {
        if (a==0)
        {
            break;
        }
        else
        {
            a=a*2;
            int bit = (int)a;
            printf("%d",bit);
            a=a-bit;
        }
    }
}