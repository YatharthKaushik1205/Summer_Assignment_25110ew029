/*Write a program to find nth term of Fibonacci Series*/
#include<stdio.h>
int main()
{
/* In this sequence first term is 0 and 2nd term is 1 as per original sequence */
    int a=0,b=1,c,m,i;
    printf("Enter the term u want to find out :");
    scanf("%d",&m);
    if(m==1)
    {
        printf("%d",a);
    }
    else if(m==2)
    {
        printf("%d",b);
    }
    else
    {
        for(i=3;i<=m;i++)
        {
            c=a+b;
            if(i==m)
            {
                printf("%d\n",c);
            }
            a=b;
            b=c;
        }
    }
}