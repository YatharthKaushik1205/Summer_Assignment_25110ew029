/*Write a program to remove the space from the given string*/
#include<stdio.h>
#include<string.h>
int main()
{
    char string[100],str[100];
    printf("Enter the string to remove spaces from it : ");
    fgets(string,sizeof(string),stdin);
    string[strcspn(string, "\n")] = '\0';
    int i,j=0,a=strlen(string);
    for (i = 0; i<a;i++)
    {
            if(string[i]!=' ')
            {
                str[j] = string[i];
                j++;
            }
    }
    str[j] = '\0';
    printf("%s", str);
}