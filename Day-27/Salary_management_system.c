#include <stdio.h>
#include <string.h>
typedef struct
{
    int employee_id;
    char Name[100];
    int age;
    char Department[50];
    char Gender;
    float basic_salary;
    float bonus;
    float deduction;
    float net_salary;
} Employee;
void add_Employee(Employee *s);
void display_Employees();
void search_Employee();
void update_Employee_record();
void delete_Employee_record();
int main()
{
    Employee s;
    int choice = 0;
    printf("====================== Menu Options =======================\n");
    printf("Option                   |         Choice          |       Function     \n");
    printf("------------------------------------------------------------------------\n");
    printf("Add Employee             |         Press 1         |  To add Employees in records\n");
    printf("Display All Employee     |         Press 2         |  To show all Employees in records\n");
    printf("Search Employee          |         Press 3         |  To search Employees by Employee id\n");
    printf("Update Employee Record   |         Press 4         |  To update any Employee record\n");
    printf("Delete Employee Record   |         Press 5         |  To Delete Employee from record\n");
    printf("Exit                     |         Press 6         |  To exit from Employee Management System\n");
    printf("------------------------------------------------------------------------------------------------\n");
    while (choice != 6)
    {
        while (1)
        {
            printf("Enter your Choice : ");
            scanf("%d", &choice);
            if (choice > 0 && choice < 7)
            {
                break;
            }
            printf("Choice Should be within the number range [1-6]\n");
        }
        switch (choice)
        {
        case 1:
            add_Employee(&s);
            break;
        case 2:
            display_Employees();
            break;
        case 3:
            search_Employee();
            break;
        case 4:
            update_Employee_record();
            break;
        case 5:
            delete_Employee_record();
            break;
        }
        printf("Press Enter to Continue : ");
        getchar();
        getchar();
    }
    printf("Salary Management System Logged out successfully !\n");
    return 0;
}
void add_Employee(Employee *s)
{
    int number_of_record_added = 0;
    char Answer = 'Y';
    FILE *Fp;
    Fp = fopen("Employees.dat", "ab");
    if (Fp == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }
    while (Answer == 'Y' || Answer == 'y')
    {
        printf("Enter Employee ID :");
        scanf("%d", &s->employee_id);
        getchar();
        printf("Enter Employee Name :");
        fgets(s->Name, sizeof(s->Name), stdin);
        s->Name[strcspn(s->Name, "\n")] = '\0';
        printf("Enter Employee age :");
        scanf("%d", &s->age);
        getchar();
        printf("Enter Employee Department :");
        fgets(s->Department, sizeof(s->Department), stdin);
        s->Department[strcspn(s->Department, "\n")] = '\0';
        printf("Enter Employee Gender :");
        scanf(" %c", &s->Gender);
        printf("Enter Basic Salary : ");
        scanf("%f", &s->basic_salary);

        printf("Enter Bonus : ");
        scanf("%f", &s->bonus);

        printf("Enter Deduction : ");
        scanf("%f", &s->deduction);

        s->net_salary = s->basic_salary + s->bonus - s->deduction;
        fwrite(s, sizeof(Employee), 1, Fp);
        printf("Do u want to enter more records?\nPress 'Y' or 'y' for Yes and 'N' or 'n' for No :");
        while (1)
        {
            scanf(" %c", &Answer);
            if (Answer == 'Y' || Answer == 'y' || Answer == 'N' || Answer == 'n')
            {
                break;
            }
            printf("Enter input among 'y','Y','N','n' : ");
        }
        number_of_record_added++;
    }
    printf("%d records Added successfully ", number_of_record_added);
    fclose(Fp);
}
void display_Employees()
{
    Employee s;
    int i = 1;
    FILE *fp = fopen("Employees.dat", "rb");
    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }
    while (fread(&s, sizeof(Employee), 1, fp) == 1)
    {
        printf("===========[Employee %d]==========\n", i);
        printf("Employee ID          :-%d\n", s.employee_id);
        printf("Employee Name        :- %s\n", s.Name);
        printf("Employee Age         :- %d\n", s.age);
        printf("Employee Department  :- %s\n", s.Department);
        printf("Employee Gender      :- %c\n", s.Gender);
        printf("Basic Salary :- %.2f\n", s.basic_salary);
        printf("Bonus        :- %.2f\n", s.bonus);
        printf("Deduction    :- %.2f\n", s.deduction);
        printf("Net Salary   :- %.2f\n", s.net_salary);
        printf("----------------\n");
        i++;
    }
    fclose(fp);
}
void search_Employee()
{
    Employee s;
    FILE *fp = fopen("Employees.dat", "rb");
    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }
    int employee_id, found = 0;
    printf("Enter Employee ID whose Data u want to search :- \n");
    scanf("%d", &employee_id);
    while (fread(&s, sizeof(Employee), 1, fp) == 1)
    {
        if (employee_id == s.employee_id)
        {
            found = 1;
            printf("\n[Employee Found Successfully]\n");
            printf("Employee ID          :-%d\n", s.employee_id);
            printf("Employee Name        :- %s\n", s.Name);
            printf("Employee Age         :- %d\n", s.age);
            printf("Employee Department  :- %s\n", s.Department);
            printf("Employee Gender      :- %c\n", s.Gender);
            printf("Basic Salary :- %.2f\n", s.basic_salary);
            printf("Bonus        :- %.2f\n", s.bonus);
            printf("Deduction    :- %.2f\n", s.deduction);
            printf("Net Salary   :- %.2f\n", s.net_salary);
            printf("----------------\n");
            break;
        }
    }
    if (!found)
    {
        printf("Entered Employee ID not found \n");
    }
    fclose(fp);
}
void update_Employee_record()
{
    Employee s;
    int employee_id, choice, employee_id_found = 0;
    char reply = 'y';
    FILE *fp = fopen("Employees.dat", "rb");
    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }
    FILE *fp1 = fopen("temp.dat", "wb");
    if (fp1 == NULL)
    {
        printf("Unable to create temporary file.\n");
        fclose(fp);
        return;
    }
    printf("Enter the Employee ID whose data u want to modify : ");
    scanf("%d", &employee_id);
    while (fread(&s, sizeof(Employee), 1, fp) == 1)
    {
        reply = 'Y';
        if (employee_id == s.employee_id)
        {
            employee_id_found = 1;
            while (reply == 'Y' || reply == 'y')
            {
                printf("What is the field u want to modify :\n ");
                printf("1 Age\n");
                printf("2 Employee id\n");
                printf("3 Department\n");
                printf("4 Name\n");
                printf("5 Gender\n");
                printf("6 Basic Salary\n");
                printf("7 Bonus\n");
                printf("8 Deduction\n");
                printf("Enter your choice : ");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    printf("Enter the New Age: ");
                    scanf("%d", &s.age);
                    break;
                case 2:
                    printf("Enter the New Employee ID : ");
                    scanf("%d", &s.employee_id);
                    break;
                case 3:
                    printf("Enter the New Department : ");
                    getchar();
                    fgets(s.Department, sizeof(s.Department), stdin);
                    s.Department[strcspn(s.Department, "\n")] = '\0';
                    break;
                case 4:
                    printf("Enter the New Name : ");
                    getchar();
                    fgets(s.Name, sizeof(s.Name), stdin);
                    s.Name[strcspn(s.Name, "\n")] = '\0';
                    break;
                case 5:
                    printf("Enter the correct Gender : ");
                    scanf(" %c", &s.Gender);
                    break;
                case 6:
                    printf("Enter New Basic Salary : ");
                    scanf("%f", &s.basic_salary);
                    break;

                case 7:
                    printf("Enter New Bonus : ");
                    scanf("%f", &s.bonus);
                    break;

                case 8:
                    printf("Enter New Deduction : ");
                    scanf("%f", &s.deduction);
                    break;
                default:
                    printf("Invalid Choice entered \n");
                    break;
                }
                s.net_salary = s.basic_salary + s.bonus - s.deduction;
                printf("Do you Want to modify another field of the same Employee ?[Y/N] :");
                scanf(" %c", &reply);
            }
        }
        fwrite(&s, sizeof(Employee), 1, fp1);
    }
    fclose(fp);
    fclose(fp1);
    if (employee_id_found)
    {
        remove("Employees.dat");
        rename("temp.dat", "Employees.dat");
        printf("Employee record updated successfully.\n");
    }
    else
    {
        remove("temp.dat");
        printf("Employee ID not found.\n");
    }
}
void delete_Employee_record()
{
    Employee s;
    int employee_id, employee_id_found = 0;
    FILE *fp = fopen("Employees.dat", "rb");
    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }
    FILE *fp1 = fopen("temp.dat", "wb");
    if (fp1 == NULL)
    {
        printf("Unable to create temporary file.\n");
        fclose(fp);
        return;
    }
    printf("Enter the Employee ID whose record u want to delete : ");
    scanf("%d", &employee_id);
    while (fread(&s, sizeof(Employee), 1, fp) == 1)
    {
        if (employee_id == s.employee_id)
        {
            employee_id_found = 1;
            continue;
        }
        fwrite(&s, sizeof(Employee), 1, fp1);
    }
    fclose(fp);
    fclose(fp1);
    if (employee_id_found)
    {
        remove("Employees.dat");
        rename("temp.dat", "Employees.dat");
        printf("Employee record deleted successfully.\n");
    }
    else
    {
        remove("temp.dat");
        printf("Employee ID not found.\n");
    }
}