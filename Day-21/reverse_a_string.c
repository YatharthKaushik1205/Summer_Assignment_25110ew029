/*Write a program to reverse a string*/
#include<stdio.h>
#include<string.h>
int main()
{
    char string[100], reverse_string[100];
    printf("Enter the string u want to reverse : ");
    fgets(string,sizeof(string),stdin);
    int a = strlen(string),i;
    if (string[a - 1] == '\n')
    {
        string[a - 1] = '\0';
        a--;
    }
    printf("Reverse of the string is :\n");
    for (i = a-1; i >= 0;i--)
    {
        reverse_string[a -1- i] = string[i];
    }
    reverse_string[a] = '\0';
    printf("%s", reverse_string);
    return 0;
}