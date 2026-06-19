/*Write a program to find first repeating character in the given string*/
#include<stdio.h>
#include<string.h>
int main()
{
    char string[100];
    int i,j;
    printf("Enter the string u want to find a repeating character for : ");
    fgets(string,sizeof(string),stdin);
    string[strcspn(string, "\n")] = '\0';
    for (i = 0;string[i]!='\0';i++)
    {
        int is_found = 0;
        for (j = 0; string[j]!='\0';j++)
        {
            if(string[i]==string[j])
            {
                is_found++;
            }
        }
        if(is_found>1)
        {
            printf("first repeating character is :- %c", string[i]);
            return 0;
        }
    }
    printf("No repeating character is found ");
    return 0;
}