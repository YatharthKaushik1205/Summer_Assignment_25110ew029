/*Write a program to find the length of string withouut strleng()*/
#include<stdio.h>
int main()
{
    int length=0;
    char string[100];
    printf("Enter the string u want to find the length of : ");
    fgets(string,sizeof(string),stdin);
    while (string[length]!='\0')
    {
        length++;
    }
    printf("Length of the entered string is -> %d",length);
    return 0;
}