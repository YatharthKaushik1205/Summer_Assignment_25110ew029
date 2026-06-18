/*Write a program to check for palindrome string*/
#include<stdio.h>
#include<string.h>
int main()
{
    char string[100], reverse_string[100];
    printf("Enter the string u want to check for : ");
    fgets(string,sizeof(string),stdin);
    int a = strlen(string),i,is_palindrome;
    if (a>0 && string[a - 1] == '\n')
    {
        string[a - 1] = '\0';
        a--;
    }
    for (i = a-1; i >= 0;i--)
    {
        reverse_string[a -1- i] = string[i];
    }
    reverse_string[a] = '\0';
    is_palindrome = strcmp(string, reverse_string);
    if(is_palindrome==0)
    {
        printf("So,Entered string is a palindrome string");
    }
    else
    {
        printf("So,Entered string is not a palindrome string");
    }
    return 0;
}