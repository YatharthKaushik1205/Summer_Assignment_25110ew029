#include<stdio.h>
int main()
{
    int GCD=1,n,m,i,j,LCM;
    printf("Enter the first number : ");
    scanf("%d",&n);
    printf("Enter the second number : ");
    scanf("%d",&m);
    for(i=2;i<=n;i++)
    {
        for(j=2;j<=m;j++)
        {
            if((n%i==0)&&(m%j==0)&&(i==j))
            {
                GCD=i;
            }
        }
    }
    LCM=(n*m)/GCD;
    printf("LCM of the given numbers is : %d",LCM);
}