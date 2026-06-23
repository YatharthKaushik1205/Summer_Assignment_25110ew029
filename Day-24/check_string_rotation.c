/*Write a program to check for string rotation */
#include <stdio.h>
#include <string.h>
int main()
{
    char string1[100], string2[100],tempstr[200];
    printf("Enter the first string : ");
    fgets(string1, sizeof(string1), stdin);
    string1[strcspn(string1, "\n")] = '\0';
    printf("Enter the Second string : ");
    fgets(string2, sizeof(string2), stdin);
    string2[strcspn(string2, "\n")] = '\0';
    tempstr[0] = '\0';
    strcat(tempstr, string1);
    strcat(tempstr, string1);
    if(strlen(string1)!=strlen(string2))
    {
        printf("Entered string is not the rotated version of first string ");
        return 0;
    }
    if(strstr(tempstr,string2)!=NULL)
    {
        printf("Entered string is a rotated version of first string ");
    }
    else
    {
        printf("Entered string is not the rotated version of first string ");
    }
    return 0;
}
