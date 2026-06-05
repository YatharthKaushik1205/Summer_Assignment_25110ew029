/*Write a program to print repeated character triangle */
#include<stdio.h>
int main()
{
    int i,j,n;
    printf("Enter the number of rows u want to print : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf("%c",65+i);
        }
        printf("\n");
    }
    return 0;
}