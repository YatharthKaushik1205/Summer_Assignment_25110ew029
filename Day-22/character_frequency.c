/*Write a program to find the entered character frequency in a given string or sentence*/
#include<stdio.h>
#include<string.h>
int main()
{
    char string[100],character;
    printf("Enter the string or sentence : ");
    fgets(string,sizeof(string),stdin);
    printf("Enter the character whose frequency u want to check :");
    scanf(" %c", &character);
    string[strcspn(string, "\n")] = '\0';
    int i, frequency = 0;
    for (i = 0;string[i]!='\0';i++)
    {
        if(string[i]==character)
        {
            frequency++;
        }
    }
    printf("%d", frequency);
}