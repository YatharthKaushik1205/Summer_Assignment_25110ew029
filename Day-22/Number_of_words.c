/*Write a program to find the number of words in a sentence*/
#include<stdio.h>
#include<string.h>
int main()
{
    char string[100];
    printf("Enter the sentence : ");
    fgets(string,sizeof(string),stdin);
    string[strcspn(string, "\n")] = '\0';
    int i, word_count = 0;
    for (i = 0;string[i]!='\0';i++)
    {
        if((string[i]!=' ' && i==0)||(i>0 && string[i]!=' '&& string[i-1]==' '))
        {
            word_count++;
        }
    }
    printf("Number of words in the entered sentence is : %d", word_count);
    return 0;
}