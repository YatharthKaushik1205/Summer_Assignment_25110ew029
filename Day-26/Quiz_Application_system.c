#include <stdio.h>
#include <string.h>
typedef struct
{
    char question[280];
    char Option[4][200];
    char explanation[300];
    int Answer;
    int user_answer;
    int skip;
} Question;
int main()
{
    Question quiz[10];
    quiz[0].skip = 0;
    quiz[1].skip = 0;
    quiz[2].skip = 0;
    quiz[3].skip = 0;
    quiz[4].skip = 0;
    quiz[5].skip = 0;
    quiz[6].skip = 0;
    quiz[7].skip = 0;
    quiz[8].skip = 0;
    quiz[9].skip = 0;
    int User_answer;
    char Skip, response;
    strcpy(quiz[0].question, "Which function serves as the mandatory execution entry point for every standalone C program?");
    strcpy(quiz[0].Option[0], "Option 1: start()");
    strcpy(quiz[0].Option[1], "Option 2: system()");
    strcpy(quiz[0].Option[2], "Option 3: main()");
    strcpy(quiz[0].Option[3], "Option 4:printf()");
    quiz[0].Answer = 3;
    strcpy(quiz[0].explanation, "Explanation: The main() function is the predefined entry point where the operating system starts executing any standard C application.");
    // Question 2//
    strcpy(quiz[1].question, "What is the primary purpose of the #include <stdio.h> preprocessor directive?");
    strcpy(quiz[1].Option[0], "Option 1: To allocate dynamic memory for variables.");
    strcpy(quiz[1].Option[1], "Option 2: To link standard input and output function declarations like printf and scanf");
    strcpy(quiz[1].Option[2], "Option 3: To define the main execution loop of the program.");
    strcpy(quiz[1].Option[3], "Option 4: To declare custom user-defined data structures.");
    quiz[1].Answer = 2;
    strcpy(quiz[1].explanation, "Explanation: stdio.h stands for 'Standard Input Output header' and contains prototypes for basic system communication functions.");
    // Question 3//
    strcpy(quiz[2].question, "Which of the following is NOT a built-in primary data type in the C programming language?");
    strcpy(quiz[2].Option[0], "Option 1: int");
    strcpy(quiz[2].Option[1], "Option 2: float");
    strcpy(quiz[2].Option[2], "Option 3: string");
    strcpy(quiz[2].Option[3], "Option 4: char");
    quiz[2].Answer = 3;
    strcpy(quiz[2].explanation, "Explanation: Unlike modern languages, C does not have a native string data type; strings are handled as arrays of char terminated by a null character.");
    // Question 4//
    strcpy(quiz[3].question, "What is the fundamental difference between declaring a variable and initializing a variable?");
    strcpy(quiz[3].Option[0], "Option 1: Declaration assigns a final value; initialization sets the data type.");
    strcpy(quiz[3].Option[1], "Option 2: Declaration specifies the name and data type; initialization assigns an initial value to it.");
    strcpy(quiz[3].Option[2], "Option 3: Declaration allocates hardware registers; initialization deletes garbage values.");
    strcpy(quiz[3].Option[3], "Option 4: Declaration happens at runtime; initialization happens during compilation.");
    quiz[3].Answer = 2;
    strcpy(quiz[3].explanation, "Explanation: int x; is a declaration (telling the compiler x exists), while x = 10; (or int x = 10;) is the initialization.");
    // Question 5//
    strcpy(quiz[4].question, "Given the expression int result = 15 % 4;, what value is stored in the variable result?");
    strcpy(quiz[4].Option[0], "Option 1: 3");
    strcpy(quiz[4].Option[1], "Option 2: 75");
    strcpy(quiz[4].Option[2], "Option 3: 1");
    strcpy(quiz[4].Option[3], "Option 4: 0");
    quiz[4].Answer = 1;
    strcpy(quiz[4].explanation, "Explanation: The '%' operator is the modulus operator, which computes the integer remainder of a division. 15 ÷ 4 = 3 with a remainder of 3.");
    // Question 6//
    strcpy(quiz[5].question, "Which C operator evaluates a conditional expression and returns one of two values based on whether the condition is true or false?");
    strcpy(quiz[5].Option[0], "Option 1: &&");
    strcpy(quiz[5].Option[1], "Option 2: ?:");
    strcpy(quiz[5].Option[2], "Option 3: !=");
    strcpy(quiz[5].Option[3], "Option 4: sizeof");
    quiz[5].Answer = 2;
    strcpy(quiz[5].explanation, "Explanation: The ?: symbol is C's conditional or ternary operator, acting as a compact, inline version of an if-else statement.");
    // Question 7//
    strcpy(quiz[6].question, "What is the key operational difference between a while loop and a do-while loop?");
    strcpy(quiz[6].Option[0], "Option 1: A while loop always runs at least once, whereas a do-while loop might not run at all.");
    strcpy(quiz[6].Option[1], "Option 2: A do-while loop checks the condition first, while a while loop checks it at the end.");
    strcpy(quiz[6].Option[2], "Option 3: A while loop checks the condition first, whereas a do-while loop executes the body at least once before checking the condition. ");
    strcpy(quiz[6].Option[3], "Option 4: There is no operational difference; they are completely interchangeable.");
    quiz[6].Answer = 3;
    strcpy(quiz[6].explanation, "Explanation: A do-while loop is an exit-controlled loop, ensuring its inner code block executes at least one time before checking the truth value.");
    // Question 8//
    strcpy(quiz[7].question, "Which statement is used to immediately exit an entire loop or switch structure prematurely?");
    strcpy(quiz[7].Option[0], "Option 1: continue");
    strcpy(quiz[7].Option[1], "Option 2: return");
    strcpy(quiz[7].Option[2], "Option 3: break");
    strcpy(quiz[7].Option[3], "Option 4: exit");
    quiz[7].Answer = 3;
    strcpy(quiz[7].explanation, "Explanation: The break keyword instantly breaks out of the innermost enclosing loop or terminates a switch case line.");
    // Question 9//
    strcpy(quiz[8].question, "What character is automatically appended to the end of a string literal in C to signify its termination?");
    strcpy(quiz[8].Option[0], "Option 1: \\n");
    strcpy(quiz[8].Option[1], "Option 2: \\0");
    strcpy(quiz[8].Option[2], "Option 3: \\t");
    strcpy(quiz[8].Option[3], "Option 4: ;");
    quiz[8].Answer = 2;
    strcpy(quiz[8].explanation, "Explanation: C uses the null terminator character (\\0) to signal the official ending point of string arrays in memory.");
    // Question 10//
    strcpy(quiz[9].question, "If you declare an array as int scores[5];, what are the exact index numbers used to access the first and last elements?");
    strcpy(quiz[9].Option[0], "Option 1: 1 and 5");
    strcpy(quiz[9].Option[1], "Option 2: 0 and 5");
    strcpy(quiz[9].Option[2], "Option 3: 0 and 4");
    strcpy(quiz[9].Option[3], "Option 4: 1 and 4");
    quiz[9].Answer = 3;
    strcpy(quiz[9].explanation, "Explanation: C utilizes zero-based indexing. For an array size of N, elements start at index 0 and end at index N-1.");
    printf("Do u want to start the quiz ?\nPress 'y' or 'Y' to Start Quiz and 'N' or 'n' to Exit Quiz : ");
    while (1)
    {
        scanf(" %c", &response);
        if (response == 'Y' || response == 'y' || response == 'N' || response == 'n')
        {
            break;
        }
        printf("Enter Only among 'Y','y','N','n' :");
    }
    if (response == 'Y' || response == 'y')
    {
        for (int i = 0; i < 10; i++)
        {
            printf("Question-%d\n", i + 1);
            printf("____________");
            printf("\n%s\n", quiz[i].question);
            printf("%s\n", quiz[i].Option[0]);
            printf("%s\n", quiz[i].Option[1]);
            printf("%s\n", quiz[i].Option[2]);
            printf("%s\n", quiz[i].Option[3]);
            printf("Want to skip this question [Y/N]: ");
            scanf(" %c", &Skip);
            if (Skip == 'Y' || Skip == 'y')
            {
                quiz[i].skip = 1;
                continue;
            }
            while (1)
            {
                printf("Enter your Answer : ");
                if (scanf("%d", &User_answer) != 1)
                {
                    printf("Enter Valid Input [1-4]\n");
                    while (getchar() != '\n')
                        ;
                    continue;
                }
                if (User_answer <= 0 || User_answer > 4)
                {
                    printf("Invalid option chosen.\n");
                }

                else
                {
                    break;
                }
            }
            quiz[i].user_answer = User_answer;
        }
        int score = 0;
        int correct_answer = 0;
        int skip_count = 0;
        char reply;
        for (int i = 0; i < 10; i++)
        {
            if (quiz[i].user_answer == quiz[i].Answer)
            {
                score += 10;
                correct_answer++;
            }
            if (quiz[i].skip == 1)
            {
                skip_count++;
            }
        }
        printf("================ Result Evaluation ==========\n");
        printf("Quiz Completed Successfully\n");
        if (score >= 90 && score <= 100)
        {
            printf("Excellent Work\n");
        }
        else if (score >= 75 && score <= 89)
        {
            printf("Good work\n");
        }
        else if (score >= 50 && score <= 74)
        {
            printf("Average work !! keep growing \n");
        }
        else
        {
            printf("Need Improvement\n");
        }
        printf("Your Score is : %d/100\n", score);
        printf("Number of correct Answers : %d\n", correct_answer);
        printf("Number of incorrect Answers : %d\n", 10 - correct_answer - skip_count);
        printf("Number of questions Skipped : %d\n", skip_count);
        printf("Accuracy :- %.2f\n", (correct_answer / 10.0) * 100);
        printf("============================================\n");
        printf("Do you want to check your incorrect Answer's Review ?\nPress 'y' or 'Y' for Yes and 'N' or 'n' for No.");
        while (1)
        {
            scanf(" %c", &reply);
            if (reply == 'Y' || reply == 'y' || reply == 'n' || reply == 'N')
            {
                break;
            }
            printf("Enter Only among 'Y','y','N','n' :");
        }
        if (reply == 'y' || reply == 'Y')
        {
            printf("---------Review of Incorrect Answer's------------\n");
            for (int i = 0; i < 10; i++)
            {
                if ((quiz[i].Answer != quiz[i].user_answer) && (quiz[i].skip == 0))
                {
                    printf("\nQuestion No. : %d \nQuestion :- %s\n", i + 1, quiz[i].question);
                    printf("%s\n", quiz[i].Option[0]);
                    printf("%s\n", quiz[i].Option[1]);
                    printf("%s\n", quiz[i].Option[2]);
                    printf("%s\n", quiz[i].Option[3]);
                    printf("Choosen Option :- \n Option : %s\n", quiz[i].Option[quiz[i].user_answer - 1]);
                    printf("Correct Option :- \n Option : %s\n", quiz[i].Option[quiz[i].Answer - 1]);
                    printf("\n%s\n", quiz[i].explanation);
                }
            }
        }
        printf("==================Grade Distribution==============\n");
        printf("90-100 -> Excellent\n75-89  -> Good\n50-74  -> Average\nBelow 50 -> Needs Improvement");
        printf("*******************Quiz is Finished***************");
    }
    else
    {
        printf("Come again next time \n");
        return 0;
    }
    return 0;
}