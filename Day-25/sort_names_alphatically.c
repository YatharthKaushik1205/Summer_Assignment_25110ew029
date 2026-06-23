/*Write a program to sort the given names Alphabetically*/
#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j;
    printf("How much names u want to enter : ");
    scanf("%d", &n);
    getchar();
    char names_array[n][60];
    for (i = 0; i < n;i++)
    {
        printf("Enter name %d : ", i + 1);
        fgets(names_array[i], sizeof(names_array[i]), stdin);
        names_array[i][strcspn(names_array[i], "\n")] = '\0';
    }
    for (i = 0; i < n-1;i++)
    {
        for (j = 0; j < n - i - 1;j++)
            if (strcmp(names_array[j], names_array[j + 1])>0)
            {
                char temp[60];
                strcpy(temp, names_array[j]);
                strcpy(names_array[j], names_array[j + 1]);
                strcpy(names_array[j + 1], temp);
            }
    }
    printf("Alphabetical order of the given names is as follows :\n");
    for (i = 0; i < n;i++)
    {
        printf("%s\n", names_array[i]);
    }
    return 0;
}