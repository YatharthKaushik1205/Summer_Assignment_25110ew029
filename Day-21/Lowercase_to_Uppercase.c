/*Write a program to convert lowercase to uppercase */
#include<stdio.h>
#include<string.h>
int main()
{
    int i,length;
    char str[100];
    printf("Enter the string : ");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str, "\n")] = '\0';
    length = strlen(str);
    for (i = 0; i < length;i++)
    {
        if(str[i]>='a'&&str[i]<='z')
        {
            str[i] = str[i] - 32;
        }
    }
    printf("%s", str);
    return 0;
}