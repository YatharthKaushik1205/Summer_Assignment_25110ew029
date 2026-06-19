/*Write a program to check for Anagram strings */
#include <stdio.h>
#include <string.h>
int main()
{
    char string1[100], string2[100];
    int i, freq[256] = {0};
    printf("Enter the first string : ");
    fgets(string1, sizeof(string1), stdin);
    string1[strcspn(string1, "\n")] = '\0';
    printf("Enter the Second string : ");
    fgets(string2, sizeof(string2), stdin);
    string2[strcspn(string2, "\n")] = '\0';
    if (strlen(string1) != strlen(string2))
    {
        printf("Entered strings are not Anagrams ");
        return 0;
    }
    for (i = 0; string1[i] != '\0'; i++)
    {
        freq[(unsigned char)string1[i]]++;
    }
    for (i = 0; string2[i] != '\0'; i++)
    {
        freq[(unsigned char)string2[i]]--;
    }
    for (i = 0; i < 256; i++)
    {
        if (freq[i] != 0)
        {
            printf("Entered strings are not Anagrams ");
            return 0;
        }
    }
    printf("Entered string are Anagrams ");
    return 0;
}
