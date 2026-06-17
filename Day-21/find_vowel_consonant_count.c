/*Write a program to find the number of vowels and consonants in the given string*/
#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,vowel_count=0,consonant_count=0;
    char str[100],vowel_string[]={"aeiouAEIOU"};
    printf("Enter the string : ");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str, "\n")] = '\0';
    for(i=0;i<strlen(str);i++)
    {
        if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
        {
            int is_vowel = 0;
            for (j = 0; j < 10;j++)
            {
                if(str[i]==vowel_string[j])
                {
                    vowel_count++;
                    is_vowel = 1;
                    break;
                }
            }
            if(!is_vowel)
            {
                consonant_count++;
            }
        }
    }
    printf("Number of Vowels -> %d\n", vowel_count);
    printf("Number of Consonants -> %d", consonant_count);
}