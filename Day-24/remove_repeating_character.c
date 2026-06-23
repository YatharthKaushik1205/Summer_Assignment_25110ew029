/*Write a program to remove duplicate character from the given string */
#include <stdio.h>
#include <string.h>
int main()
{
    char string[100];
    printf("Enter the string u want to remove duplicate characters from : ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';
    int i = 0, j = 0, k;
    for (i = 0; string[i] != '\0'; i++)
    {
        int is_found = 0;
        for (k = 0; k < i; k++)
        {
            if (string[i] == string[k])
            {
                is_found = 1;
                break;
            }
        }
        if ( is_found == 0)
        {
            string[j++] = string[i];

        }
    }
    string[j] = '\0';
    printf("String after removing duplicates is :-> %s", string);
}