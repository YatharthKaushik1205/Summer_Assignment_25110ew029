/*Write a program to write function for fibonacci series upto given term */
#include<stdio.h>
void fibonacci(int n);
int main()
{
    int n;
    printf("Enter the number upto which u want to print the fibonacci series :");
    scanf("%d",&n);
    printf("I am considering the fibonacci sequence whose first term is 0 and 2nd term is 1 \n");
    fibonacci(n);
    return 0;
}
void fibonacci(int n)
{
/* In this sequence first term is 0 and 2nd term is 1 as per original sequence */
    int a=0,b=1,c,i;
    if(n==1)
    {
        printf("%d",a);
    }
    else if(n==2)
    {
        printf("%d\n",a);
        printf("%d",b);
    }
    else
    {
        printf("%d\n",a);
        printf("%d\n",b);
        for(i=3;i<=n;i++)
        {
            c=a+b;
            printf("%d\n",c);
            a=b;
            b=c;
        }
    }
}