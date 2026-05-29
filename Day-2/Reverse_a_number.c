/* Sir/Mam This code is mine but it is too complicate for a normal task
 thats why I asked Chatgpt to tell how this code is bad So, i am pasting my code in comment and new modified code together
 
#include<stdio.h>
#include<math.h>
int main()
{
    int n,count=0,reverse=0,r,n1,n2;
    printf("Enter the number whose reverse u want to print : ");
    scanf("%d",&n);
    n1=n;
    n2=n;
    while(n1!=0)
    {
        count=count+1;
        n1=n1/10;
    }
    while(n2!=0)
    {
        count=count-1;
        r=n2%10;
        reverse = reverse + (r*pow(10,count));
        n2=n2/10;
    }
    printf("Reverse of the number %d is : %d",n,reverse); 
}*/
/* Write a program to reverse a number */
#include<stdio.h>

int main()
{
    int n, reverse = 0, r;

    printf("Enter the number whose reverse u want to print : ");
    scanf("%d", &n);

    while(n != 0)
    {
        r = n % 10;
        reverse = reverse * 10 + r;
        n = n / 10;
    }

    printf("Reverse of the number is : %d", reverse);

    return 0;
}