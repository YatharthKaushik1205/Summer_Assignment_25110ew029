/*Write a Program to create a Number Guessing Game */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    printf("\n=======================Number Guessing Game =======================\n");
    srand(time(NULL));
    int random_number, i, total_wins = 0, total_games_played = 0;
    char answer, answer1;
    printf("In this game You have to guess a number between 1 to 100 in the limited 10 guesses\nI will help you but the final blow is upto you to lend\n!!Good Luck!!\n");
    printf("Shall we Start the game : Press 'Y' or 'y' for Yes and 'N' or 'n' for No :-> ");
    scanf(" %c", &answer);
    while (answer == 'Y' || answer == 'y')
    {
        total_games_played++;
        int entered_number, current_win = 0;
        random_number = rand() % 100 + 1;
        for (i = 0; i < 10; i++)
        {
            printf("Try Attempt %d : ", i + 1);
            scanf("%d", &entered_number);
            if (entered_number > random_number)
            {
                if (entered_number - random_number <= 10)
                {
                    printf("Bro, u are close but high!!\n");
                }
                else if (entered_number - random_number > 10)
                {
                    printf("Bro, u are very high !!\n");
                }
            }
            else if (entered_number < random_number)
            {
                if (random_number - entered_number <= 10)
                {
                    printf("Bro, u are close but low!!\n");
                }
                else if (random_number - entered_number > 10)
                {
                    printf("Bro, u are very low !!\n");
                }
            }
            else if (entered_number == random_number)
            {
                printf("Congratulations !! you have successfully found the number in %d attempts \n", i + 1);
                current_win = 1;
                total_wins++;
                break;
            }
        }
        if (!current_win)
        {
            printf("Better luck next time bro !! Number was %d\n", random_number);
        }
        printf("\n--------------------------------------------------------------------------\n");
        printf("Do you want to play more? : Press 'Y' or 'y' for Yes and 'N' or 'n' for No :");
        scanf(" %c", &answer);
    }
    printf("Do u want to know the statistics ?\n Press 'Y' or 'y' for Yes and 'N' or 'n' for No :");
    scanf(" %c", &answer1);
    if (answer1 == 'Y' || answer1 == 'y')
    {
        printf("\n================ Statistics ================\n");
        printf("Total Games Played : %d\n", total_games_played);
        printf("Total Games Won    : %d\n", total_wins);
        printf("Games Lost         : %d\n",
               total_games_played - total_wins);
    }
    return 0;
}