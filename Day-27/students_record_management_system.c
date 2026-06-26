#include <stdio.h>
#include <string.h>
typedef struct
{
    int roll_no;
    char Name[100];
    int age;
    char Class[20];
    char Gender;
    float marks;
} Student;
void add_student(Student *s);
void display_student();
void search_student();
void update_student_record();
void delete_student_record();
int main()
{
    Student s;
    int choice=0;
    printf("====================== Menu Options =======================\n");
    printf("Option                  |         Choice          |       Function     \n");
    printf("------------------------------------------------------------------------\n");
    printf("Add Student             |         Press 1         |  To add Students in records\n");
    printf("Display All Student     |         Press 2         |  To show all Students in records\n");
    printf("Search Student          |         Press 3         |  To search Students by Roll No.\n");
    printf("Update Student Record   |         Press 4         |  To update any Student record\n");
    printf("Delete Student Record   |         Press 5         |  To Delete Student from record\n");
    printf("Exit                    |         Press 6         |  To exit from Student Management System\n");
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
            add_student(&s);
            break;
        case 2:
            display_student();
            break;
        case 3:
            search_student();
            break;
        case 4:
            update_student_record();
            break;
        case 5:
            delete_student_record();
            break;
        }
        printf("Press Enter to Continue : ");
        getchar();
        getchar();
    }
    printf("Student Record Management System Logged out successfully !\n");
    return 0;
}
void add_student(Student *s)
{
    int number_of_record_added = 0;
    char Answer = 'Y';
    FILE *Fp;
    Fp = fopen("students.dat", "ab");
    if (Fp == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }
    while (Answer == 'Y' || Answer == 'y')
    {
        printf("Enter Student Roll No. :");
        scanf("%d", &s->roll_no);
        getchar();
        printf("Enter Student Name :");
        fgets(s->Name, sizeof(s->Name), stdin);
        s->Name[strcspn(s->Name, "\n")] = '\0';
        printf("Enter Student age :");
        scanf("%d", &s->age);
        getchar();
        printf("Enter Student Class :");
        fgets(s->Class, sizeof(s->Class), stdin);
        s->Class[strcspn(s->Class, "\n")] = '\0';
        printf("Enter Student Gender :");
        scanf(" %c", &s->Gender);
        printf("Enter student Marks : ");
        scanf("%f", &s->marks);
        fwrite(s, sizeof(Student), 1, Fp);
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
void display_student()
{
    Student s;
    int i = 1;
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }
    while (fread(&s, sizeof(Student), 1, fp) == 1)
    {
        printf("===========[Student %d]==========\n", i);
        printf("Student Roll No. :-%d\n", s.roll_no);
        printf("Student Name     :- %s\n", s.Name);
        printf("Student Age      :- %d\n", s.age);
        printf("Student Class    :- %s\n", s.Class);
        printf("Student Gender   :- %c\n", s.Gender);
        printf("Student Marks    :- %.2f\n", s.marks);
        printf("----------------\n");
        i++;
    }
    fclose(fp);
}
void search_student()
{
    Student s;
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }
    int roll_no,found=0;
    printf("Enter Student Roll Number whose Data u want to search :- \n");
    scanf("%d", &roll_no);
    while (fread(&s, sizeof(Student), 1, fp) == 1)
    {
        if (roll_no == s.roll_no)
        {
            found = 1;
            printf("\n[Student Found Successfully]\n");
            printf("Student Roll No. :-%d\n", s.roll_no);
            printf("Student Name     :- %s\n", s.Name);
            printf("Student Age      :- %d\n", s.age);
            printf("Student Class    :- %s\n", s.Class);
            printf("Student Gender   :- %c\n", s.Gender);
            printf("Student Marks :- %.2f\n", s.marks);
            printf("----------------\n");
            break;
        }
    }
    if(!found)
    {
        printf("Entered Roll No. not found \n");
    }
    fclose(fp);
}
void update_student_record()
{
    Student s;
    int roll_number, choice, roll_no_found = 0;
    char reply = 'y';
    FILE *fp = fopen("students.dat", "rb");
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
    printf("Enter the roll number of Student whose data u want to modify : ");
    scanf("%d", &roll_number);
    while (fread(&s, sizeof(Student), 1, fp) == 1)
    {
        reply = 'Y';
        if (roll_number == s.roll_no)
        {
            roll_no_found = 1;
            while (reply == 'Y' || reply == 'y')
            {
                printf("What is the field u want to modify :\n ");
                printf("1 Age\n");
                printf("2 Roll No.\n");
                printf("3 Class\n");
                printf("4 Name\n");
                printf("5 Gender\n");
                printf("6 Marks\n");
                printf("Enter your choice : ");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    printf("Enter the New Age: ");
                    scanf("%d", &s.age);
                    break;
                case 2:
                    printf("Enter the New Roll No. : ");
                    scanf("%d", &s.roll_no);
                    break;
                case 3:
                    printf("Enter the New Class : ");
                    scanf("%s", s.Class);
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
                    printf("Enter updated marks of student : ");
                    scanf("%f", &s.marks);
                    break;
                default:
                    printf("Invalide Choice entered \n");
                    break;
                }
                printf("Do you Want to modify another field of the same student ?[Y/N] :");
                scanf(" %c", &reply);
            }
        }
        fwrite(&s, sizeof(Student), 1, fp1);
    }
    fclose(fp);
    fclose(fp1);
    if (roll_no_found)
    {
        remove("students.dat");
        rename("temp.dat", "students.dat");
        printf("Student record updated successfully.\n");
    }
    else
    {
        remove("temp.dat");
        printf("Roll number not found.\n");
    }
}
void delete_student_record()
{
    Student s;
    int roll_number,roll_no_found = 0;
    FILE *fp = fopen("students.dat", "rb");
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
    printf("Enter the roll number of Student whose record u want to delete : ");
    scanf("%d", &roll_number);
    while (fread(&s, sizeof(Student), 1, fp) == 1)
    {
        if (roll_number == s.roll_no)
        {
            roll_no_found = 1;
            continue;
        }
        fwrite(&s, sizeof(Student), 1, fp1);
    }
    fclose(fp);
    fclose(fp1);
    if (roll_no_found)
    {
        remove("students.dat");
        rename("temp.dat", "students.dat");
        printf("Student record deleted successfully.\n");
    }
    else
    {
        remove("temp.dat");
        printf("Roll number not found.\n");
    }
}