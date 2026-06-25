/*ATM Simulation Program */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void create_account(int account_number);
int check_Balance(char filename[]);
void Deposit_money(char filename[], char transaction_file[]);
void withdraw_money(char filename[], char transaction_file[]);
int Transfer_money(char filename[], char transaction_file[]);
void change_pin(char filename[], char transaction_file[]);
void account_details(char filename[]);
void mini_statement(char transaction_file[]);
void update_balance(char filename[], int balance);
void add_transaction(char transaction_file[], char type[], int amount);
int main()
{

    int choice = 0, account_number, Entered_PIN, matched = 0;
    char filename[100], line[100], answer;
    printf("Provide your account number to continue :");
    scanf("%d", &account_number);
    sprintf(filename, "account_%d.txt", account_number);
    FILE *Fp;
    Fp = fopen(filename, "r");
    if (Fp == NULL)
    {
        printf("No as such account exist : you want to create your account?\n");
        printf("Press 'Y' or 'y' for yes and 'N' or 'n' For No : ");
        scanf(" %c", &answer);
        if (answer == 'Y' || answer == 'y')
        {
            create_account(account_number);
        }
        else
        {
            printf("| ATM simulation is Terminated |");
            return 0;
        }
        Fp = fopen(filename, "r");
        if (Fp == NULL)
        {
            printf("Unable to open account file.\n");
            return 1;
        }
    }
    if (Fp != NULL)
    {
        char transaction_file[100];
        sprintf(transaction_file, "transactions_%d.txt", account_number);
        for (int i = 0; i < 3; i++)
        {
            int Stored_PIN = -1;
            rewind(Fp);
            printf("Enter ATM PIN :");
            scanf("%d", &Entered_PIN);
            while (fgets(line, sizeof(line), Fp))
            {
                if (strncmp(line, "PIN:", 4) == 0)
                {
                    sscanf(line, "PIN:%d", &Stored_PIN);
                }
            }
            if (Stored_PIN == Entered_PIN)
            {
                matched = 1;
                printf("Login Successfully !\n");
                printf("=================ATM Simulation ==================\n");
                printf("-------------- Menu -------------------\n");
                printf("Services         |   Key Bind     | Function\n");
                printf("---------------------------------------\n");
                printf("Check Balance    |   Press 1       | Display Current Account Balance\n");
                printf("Deposit Money    |   Press 2       | Add Money to the Account\n");
                printf("Withdraw Money   |   Press 3       | Remove Money if Sufficient balance exists\n");
                printf("Transfer Money   |   Press 4       | Transfer Money to another Account (simulated)\n");
                printf("Change Pin       |   Press 5       | Change Pin of your account\n");
                printf("Mini Statement   |   Press 6       | Show recent transactions\n");
                printf("Account Details  |   Press 7       | Display account details \n");
                printf("Exit             |   Press 8       | Terminate the program \n");
                while (choice != 8)
                {
                    printf("Enter your choice : ");
                    scanf("%d", &choice);
                    switch (choice)
                    {
                    case 1:
                        printf("Current Balance is : %d\n", check_Balance(filename));
                        add_transaction(transaction_file, "Balance Check", 0);
                        break;
                    case 2:
                        Deposit_money(filename, transaction_file);
                        break;
                    case 3:
                        withdraw_money(filename, transaction_file);
                        break;
                    case 4:
                        Transfer_money(filename, transaction_file);
                        break;
                    case 5:
                        change_pin(filename, transaction_file);
                        break;
                    case 6:
                        mini_statement(transaction_file);
                        break;
                    case 7:
                        account_details(filename);
                        break;
                    case 8:
                        printf("Thank you for using ATM Simulation.\n");
                        choice = 8;
                        break;
                    default:
                        printf("Invalid Input entered by user\n");
                    }
                }
                break;
            }
            else
            {
                printf("Entered PIN is incorrect \n");
                printf("%d attempts left \n", 2 - i);
            }
        }
        if (matched == 0)
        {
            printf("All attempts are incorrect .Pls Try again later for Security reasons\n");
        }
    }
    if (Fp != NULL)
    {
        fclose(Fp);
    }
    return 0;
}
void account_details(char filename[])
{
    FILE *Fp;
    char string[100];
    Fp = fopen(filename, "r");
    if (Fp == NULL)
    {
    printf("Unable to open account file\n");
    return;
    }
    printf("=========Account Details =========\n");
    while (fgets(string, sizeof(string), Fp))
    {
        printf("%s", string);
    }
    printf("\n");
    fclose(Fp);
}
void change_pin(char filename[], char transaction_file[])
{
    int new_pin, Account_number, Balance, confirm_pin;
    char Name[100], line[100];
    FILE *Fp;
    Fp = fopen(filename, "r");
    if (Fp == NULL)
    {
    return;
    }
    while (fgets(line, sizeof(line), Fp))
    {
        if (strncmp(line, "Name:", 5) == 0)
        {
            sscanf(line, "Name:%[^\n]", Name);
        }
        if (strncmp(line, "Account Number:", 15) == 0)
        {
            sscanf(line, "Account Number:%d", &Account_number);
        }
        if (strncmp(line, "Balance:", 8) == 0)
        {
            sscanf(line, "Balance:%d", &Balance);
        }
    }
    while (1)
    {
        printf("Enter new PIN :");
        scanf("%d", &new_pin);
        printf("Confirm New PIN : ");
        scanf("%d", &confirm_pin);
        if ((new_pin < 1000 || new_pin > 9999) || (confirm_pin < 1000 || confirm_pin > 9999))
        {

            printf("A PIN must be of 4 digits Re-enter the PIN\n");
            continue;
        }
        else if (confirm_pin != new_pin)
        {
            printf("PIN's didn't matched \n");
        }
        else
        {
            break;
        }
    }
    fclose(Fp);
    Fp = fopen(filename, "w");
    if (Fp == NULL)
    {
    printf("Error updating PIN\n");
    return;
    }
    fprintf(Fp, "Name:%s\n", Name);
    fprintf(Fp, "Account Number:%d\n", Account_number);
    fprintf(Fp, "PIN:%d\n", new_pin);
    fprintf(Fp, "Balance:%d\n", Balance);
    printf("<PIN changed successfully >\n");
    add_transaction(transaction_file, "PIN Changed", 0);
    fclose(Fp);
}
void withdraw_money(char filename[], char transaction_file[])
{
    int balance, withdrawal_amount;
    balance = check_Balance(filename);
    while (1)
    {
        printf("Enter the withdrawal amount : ");
        scanf("%d", &withdrawal_amount);
        if (withdrawal_amount <= 0)
        {
            printf("Enter Valid withdrawal amount\n");
        }
        else if (withdrawal_amount > balance)
        {
            printf("Insufficient balance for withdrawal\n");
        }
        else
        {
            break;
        }
    }
    balance -= withdrawal_amount;
    update_balance(filename, balance);
    printf("< Amount withdrawn successfully >\n");
    printf("updated balance : %d\n", balance);
    add_transaction(transaction_file, "Withdrawal", withdrawal_amount);
}
void create_account(int account_number)
{
    FILE *Fp;

    int PIN = 0, Current_Balance = 0, temp_PIN = 1;
    char Name[100], filename[100];
    sprintf(filename, "account_%d.txt", account_number);
    Fp = fopen(filename, "w");
    if (Fp != NULL)
    {
        printf("Enter Account Holder Name : ");
        getchar();
        fgets(Name, sizeof(Name), stdin);
        Name[strcspn(Name, "\n")] = '\0';
        fprintf(Fp, "Name:%s\n", Name);
        fprintf(Fp, "Account Number:%d\n", account_number);
        while (1)
        {
            printf("Enter PIN :");
            scanf("%d", &PIN);
            printf("Confirm PIN :");
            scanf("%d", &temp_PIN);
            if (PIN < 1000 || PIN > 9999)
            {
                printf("PIN must be a 4-digit number !\n");
            }
            else if (PIN != temp_PIN)
            {
                printf("PIN's do not match\n");
            }
            else
            {
                fprintf(Fp, "PIN:%d\n", PIN);
                break;
            }
        }
        printf("Enter initial deposit amount : ");
        scanf("%d", &Current_Balance);
        while (Current_Balance < 0)
        {
            printf("Enter Valid Balance : ");
            scanf("%d", &Current_Balance);
        }
        fprintf(Fp, "Balance:%d\n", Current_Balance);
        printf("Account created successfully !\n");
        char transaction_file[100];
        sprintf(transaction_file, "transactions_%d.txt", account_number);
        FILE *Temp_point;
        Temp_point = fopen(transaction_file, "w");
        if (Temp_point != NULL)
        {
            fprintf(Temp_point, "Account Created || Initial Deposit : %d\n", Current_Balance);
            fclose(Temp_point);
        }
        fclose(Fp);
    }
    else
    {
        printf("Error in creating file !"); 
    }
}
int check_Balance(char filename[])
{
    FILE *Fp;
    char line[100];
    int balance = 0;
    Fp = fopen(filename, "r");
    if (Fp == NULL)
    {
    return 0;
    }
    while (fgets(line, sizeof(line), Fp))
    {
        if (strncmp(line, "Balance:", 8) == 0)
        {
            sscanf(line, "Balance:%d\n", &balance);
        }
    }
    fclose(Fp);
    return balance;
}
void update_balance(char filename[], int balance)
{
    char Name[100], line[100];
    int Account_number, PIN, Balance;
    FILE *Fp;
    Fp = fopen(filename, "r");
    if (Fp == NULL)
    {
    return;
    }
    while (fgets(line, sizeof(line), Fp))
    {
        if (strncmp(line, "Name:", 5) == 0)
        {
            sscanf(line, "Name:%[^\n]", Name);
        }
        if (strncmp(line, "Account Number:", 15) == 0)
        {
            sscanf(line, "Account Number:%d", &Account_number);
        }
        if (strncmp(line, "PIN:", 4) == 0)
        {
            sscanf(line, "PIN:%d", &PIN);
        }
        if (strncmp(line, "Balance:", 8) == 0)
        {
            sscanf(line, "Balance:%d", &Balance);
        }
    }
    Balance = balance;
    fclose(Fp);
    Fp = fopen(filename, "w");
    if (Fp == NULL)
    {
    printf("Error updating balance\n");
    return;
    }
    fprintf(Fp, "Name:%s\n", Name);
    fprintf(Fp, "Account Number:%d\n", Account_number);
    fprintf(Fp, "PIN:%d\n", PIN);
    fprintf(Fp, "Balance:%d\n", Balance);
    fclose(Fp);
}
void Deposit_money(char filename[], char transaction_file[])
{
    int deposit_money = 0, balance;
    while (1)
    {
        printf("Enter How much money u want to deposit : ");
        scanf("%d", &deposit_money);
        if (deposit_money > 0)
        {
            break;
        }
        printf("Invalid Deposit money. Enter again\n");
    }
    balance = check_Balance(filename);
    balance += deposit_money;
    update_balance(filename, balance);
    printf(" < Amount Deposited Successfully >\n");
    printf("Updated Balance %d\n", balance);
    add_transaction(transaction_file, "Deposit", deposit_money);
}
int Transfer_money(char filename[], char transaction_file[])
{
    FILE *Fp2 = NULL;

    int balance1, balance2, transfer_amount, receiver_account, receiver_found = 0;
    char receiver_file[100];
    balance1 = check_Balance(filename);
    while (1)
    {
        receiver_found = 0;
        for (int i = 0; i < 3; i++)
        {
            printf("Enter the Account number in which u want to transfer money :");
            scanf("%d", &receiver_account);
            sprintf(receiver_file, "account_%d.txt", receiver_account);
            if (strcmp(filename, receiver_file) == 0)
            {
                printf("Cannot transfer money to your own account\n");
                i--;
                continue;
            }
            Fp2 = fopen(receiver_file, "r");
            if (Fp2 == NULL)
            {
                printf("Receiver file not found \n");
                printf("Only %d attempts left \n", 2 - i);
                printf("Re-enter receiver account number\n");
            }
            if (Fp2 != NULL)
            {
                receiver_found = 1;
                fclose(Fp2);
                break;
            }
        }
        if (receiver_found == 1)
        {
            printf("How much amount u want to transfer :");
            scanf("%d", &transfer_amount);
            if (transfer_amount <= 0)
            {
                printf("Enter Appropriate transfer amount \n");
            }
            else if (balance1 < transfer_amount)
            {
                printf("Balance is insufficient to transfer \n");
            }
            else
            {
                break;
            }
        }
        else
        {
            printf("Unable to transfer Money [Receiver account not detected]\n");
            return 1;
        }
    }
    balance2 = check_Balance(receiver_file);
    balance2 += transfer_amount;
    update_balance(receiver_file, balance2);
    balance1 -= transfer_amount;
    update_balance(filename, balance1);
    printf("Amount transferred successfully :\n");
    printf("Updated Sender Balance : %d\n", balance1);
    add_transaction(transaction_file, "Transfer Sent", transfer_amount);
    char receiver_transaction_file[100];
    sprintf(receiver_transaction_file, "transactions_%d.txt", receiver_account);
    add_transaction(receiver_transaction_file, "Transaction Received", transfer_amount);
    return 0;
}
void add_transaction(char transaction_file[], char type[], int amount)
{
    FILE *Fp;

    Fp = fopen(transaction_file, "a");

    if (Fp == NULL)
    {
        printf("Unable to update transaction history.\n");
        return;
    }

    fprintf(Fp, "%s : %d\n", type, amount);

    fclose(Fp);
}
void mini_statement(char transaction_file[])
{
    FILE *Fp = fopen(transaction_file, "r");
    char string[100];
    if (Fp == NULL)
    {
    printf("No transaction history found.\n");
    return;
    }
    printf("=========Mini Statements =========\n");
    while (fgets(string, sizeof(string), Fp))
    {
        printf("%s", string);
    }
    printf("\n");
    fclose(Fp);
}