/*Write a program to find the common character in a given string */
#include <stdio.h>
#include <string.h>
int main()
{
    char string1[100], string2[100];
    int is_found, i;
    printf("Enter the first String : ");
    fgets(string1, sizeof(string1), stdin);
    string1[strcspn(string1, "\n")] = '\0';
    printf("Enter the Second String : ");
    fgets(string2, sizeof(string2), stdin);
    string2[strcspn(string2, "\n")] = '\0';
    printf("Common character in the Strings are: ");
    for (i = 0; string1[i] != '\0'; i++)
    {
        int is_found = 0;
        for (int k = 0; k < i; k++)
        {
            if (string1[i] == string1[k])
            {
                is_found = 1;
                break;
            }
        }
        if (is_found == 0)
        {
            for (int j = 0; string2[j] != '\0'; j++)
            {
                if (string1[i] == string2[j])
                {
                    printf("%c", string2[j]);
                    break;
                }
            }
        }
    }
    return 0;
}