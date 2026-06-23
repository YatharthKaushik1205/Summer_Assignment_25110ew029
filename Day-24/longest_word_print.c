/*Write a program to find the longest word in a given sentence */
#include <stdio.h>
#include <string.h>
int main()
{
    char string[100], word[100], longest[100];
    int i = 0, j = 0, max_word_length = 0;
    printf("Enter the sentence : ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';
    word[0] = '\0';
    longest[0] = '\0';
    while (1)
    {
        if (string[i] != ' ' && string[i] != '\0')
        {
            word[j++] = string[i];
        }
        else
        {
            word[j] = '\0';
            if (j > max_word_length)
            {
                max_word_length = j;
                strcpy(longest, word);
            }
            j = 0;
        }
        if (string[i] == '\0')
        {
            break;
        }
        i++;
    }
    printf("Longest Word is %s\n", longest);
    printf("Longest word length %d", max_word_length);
}