#include<stdio.h>
int main()
{
    int n,i,m,j,count;
    printf("Enter the number as a start point if range : ");
    scanf("%d",&m);
    printf("Enter the number as a end point if range : ");
    scanf("%d",&n);
    for(i=m;i<=n;i++)
    {
        count=0;
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            {
                count+=1;
            }  
        }
        if(count==0)
        {
            printf("%d\n",i);
        }
    }
}