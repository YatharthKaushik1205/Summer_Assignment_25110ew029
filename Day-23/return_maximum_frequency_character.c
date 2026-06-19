/*Write a program to find maximum frequency character */
#include <stdio.h>
#include <string.h>
int main()
{
    char string[100];
    int i, freq[256] = {0};
    printf("Enter the string : ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';
    if (string[0] == '\0')
    {
        printf("String is empty");
        return 0;
    }
    for (i = 0; string[i] != '\0'; i++)
    {
        freq[(unsigned char)string[i]]++;
    }
    int max_frequency = 0;
    char max_frequency_character = '\0';
    for (i = 0; i < 256; i++)
    {
        if (freq[i] > max_frequency)
        {
            max_frequency = freq[i];
            max_frequency_character = i;
        }
    }
    printf("Maximum frequency character is '%c' with frequency of %d", max_frequency_character, max_frequency);
    return 0;
}
