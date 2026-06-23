/*Write a program to compress a string */
#include <stdio.h>
#include <string.h>
int main()
{
    char main_string[100];
    int i, count;
    printf("Enter the string u want to compress :");
    fgets(main_string, sizeof(main_string), stdin);
    main_string[strcspn(main_string, "\n")] = '\0';
    printf("Compresses string is : ");
    for (i = 0; main_string[i] != '\0';i++)
    {
        count = 1;
        while(main_string[i]==main_string[i+1])
        {
            i++;
            count++;
        }
        printf("%c%d", main_string[i], count);
    }
    return 0;
}