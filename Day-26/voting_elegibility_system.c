/*Write a program to create a voting eligibility systerm */
#include<stdio.h>
#include<string.h>
int main()
{
    char name[50],voter_id[10],citizenship[10];
    int age;
    printf("Enter your Name : ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("Enter your Age : ");
    scanf("%d", &age);
    getchar();
    printf("Do you have Voter Id issued to you ? Type Yes or N/A(Not applicable) :");
    fgets(voter_id, sizeof(voter_id), stdin);
    voter_id[strcspn(voter_id, "\n")] = '\0';
    printf("Are you a citizen of India ? Type Yes or N/A(Not applicable) :");
    fgets(citizenship, sizeof(citizenship), stdin);
    citizenship[strcspn(citizenship, "\n")] = '\0';
    if(age>=18 && (strcmp(voter_id,"Yes")==0||strcmp(voter_id,"yes")==0) && (strcmp(citizenship,"Yes")==0||strcmp(citizenship,"yes")==0))
    {
        printf(" You are eliible to vote !");
        return 0;
    }
    else
    {
        printf("No you are not Eliible to vote !!\n");
        printf("===Reasons===\n");
        if(age<18)
        {
            printf("%s , Your age is less than 18\n",name);
        }
        if(strcmp(citizenship,"Yes")!=0&&strcmp(citizenship,"yes")!=0)
        {
            printf(" %s , You are not a citizen of India\n ", name);
        }
        if(strcmp(voter_id,"Yes")!=0&&strcmp(voter_id,"yes")!=0)
        {
            printf(" %s , You don't have any voter id\n", name);
        }
    }
    return 0;
}