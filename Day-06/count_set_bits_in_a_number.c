/*Write a Program to count set bits in a number 
Set bits are "1" in the binary representation of that number  */
#include<stdio.h>
int fractional_part(float a);
int main()
{
    float n,fract_part;
    int i=0,j,n1,r,arr[50],count=0,m=0;
    printf("Enter the decimal number to count set bits :");
    scanf("%f",&n);
    n1=(int)n;
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
        for(j=0;j<=i-1;j++)
        {
            if(arr[j]==1)
            {
                count+=1;
            }
        }
    }
    fract_part= n-(int)n;
    if(fract_part!=0)
    {
        m=fractional_part(fract_part);
    }
    printf("Number of set bits in given decimal number is %d",count+m);
    return 0;
}
int fractional_part(float a)
{
    int i,count=0;
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
            if(bit==1)
            {
                count+=1;
            }
            a=a-bit;
        }
    }
    return count;
}