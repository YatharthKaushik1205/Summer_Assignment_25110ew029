/*Write a program to sort the given words by their length*/
#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j;
    printf("How much Words u want to enter : ");
    scanf("%d", &n);
    getchar();
    char word_array[n][60];
    for (i = 0; i < n;i++)
    {
        printf("Enter word %d : ", i + 1);
        fgets(word_array[i], sizeof(word_array[i]), stdin);
        word_array[i][strcspn(word_array[i], "\n")] = '\0';
    }
    for (i = 0; i < n-1;i++)
    {
        for (j = 0; j < n - i - 1;j++)
            if (strlen(word_array[j])>strlen(word_array[j + 1]))
            {
                char temp[60];
                strcpy(temp, word_array[j]);
                strcpy(word_array[j], word_array[j + 1]);
                strcpy(word_array[j + 1], temp);
            }
    }
    printf("Words order | Word length \n");
    for (i = 0; i < n;i++)
    {
        printf("%-15s |%zu\n", word_array[i],strlen(word_array[i]));
    }
    return 0;
}