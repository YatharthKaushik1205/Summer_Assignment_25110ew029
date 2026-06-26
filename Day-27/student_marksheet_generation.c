#include <stdio.h>
#include <string.h>

typedef struct
{
    int roll_no;
    char Name[100];
    int age;
    char Class[20];
    char Gender;
    float English;
    float Hindi;
    float Maths;
    float Science;
    float Social_Science;
    float Total;
    float Percentage;
    char Grade;
} Student;

void add_student(Student *s);
void display_student();
void search_student();
void update_student_record();
void delete_student_record();
void generate_marksheet();

int main()
{
    Student s;
    int choice = 0;

    printf("====================== Menu Options =======================\n");
    printf("Option                       |         Choice          |       Function\n");
    printf("-----------------------------------------------------------------------------------------\n");
    printf("Add Student Record           |         Press 1         |  To add Student Marksheet Record\n");
    printf("Display All Records          |         Press 2         |  To display all Student Records\n");
    printf("Search Student Record        |         Press 3         |  To search Student by Roll No.\n");
    printf("Update Student Record        |         Press 4         |  To update Student Record\n");
    printf("Delete Student Record        |         Press 5         |  To delete Student Record\n");
    printf("Generate Student Marksheet   |         Press 6         |  To generate Student Marksheet\n");
    printf("Exit                         |         Press 7         |  To exit from Marksheet Generation System\n");
    printf("-----------------------------------------------------------------------------------------\n");

    while (choice != 7)
    {
        while (1)
        {
            printf("Enter your Choice : ");
            scanf("%d", &choice);

            if (choice > 0 && choice < 8)
            {
                break;
            }

            printf("Choice Should be within the number range [1-7]\n");
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

        case 6:
            generate_marksheet();
            break;
        }

        if (choice != 7)
        {
            printf("Press Enter to Continue : ");
            getchar();
            getchar();
        }
    }

    printf("Marksheet Generation System Logged out successfully !\n");

    return 0;
}

void add_student(Student *s)
{
    int number_of_record_added = 0;
    char Answer = 'Y';

    FILE *Fp;
    Fp = fopen("marksheet.dat", "ab");

    if (Fp == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }

    while (Answer == 'Y' || Answer == 'y')
    {
        printf("Enter Student Roll No. : ");
        scanf("%d", &s->roll_no);

        getchar();

        printf("Enter Student Name : ");
        fgets(s->Name, sizeof(s->Name), stdin);
        s->Name[strcspn(s->Name, "\n")] = '\0';

        printf("Enter Student Age : ");
        scanf("%d", &s->age);

        getchar();

        printf("Enter Student Class : ");
        fgets(s->Class, sizeof(s->Class), stdin);
        s->Class[strcspn(s->Class, "\n")] = '\0';

        printf("Enter Student Gender : ");
        scanf(" %c", &s->Gender);

        printf("Enter English Marks : ");
        scanf("%f", &s->English);

        printf("Enter Hindi Marks : ");
        scanf("%f", &s->Hindi);

        printf("Enter Maths Marks : ");
        scanf("%f", &s->Maths);

        printf("Enter Science Marks : ");
        scanf("%f", &s->Science);

        printf("Enter Social Science Marks : ");
        scanf("%f", &s->Social_Science);

        s->Total = s->English + s->Hindi + s->Maths + s->Science + s->Social_Science;

        s->Percentage = s->Total / 5.0;

        if (s->Percentage >= 90)
        {
            s->Grade = 'A';
        }
        else if (s->Percentage >= 75)
        {
            s->Grade = 'B';
        }
        else if (s->Percentage >= 60)
        {
            s->Grade = 'C';
        }
        else if (s->Percentage >= 40)
        {
            s->Grade = 'D';
        }
        else
        {
            s->Grade = 'F';
        }

        fwrite(s, sizeof(Student), 1, Fp);

        printf("Do u want to enter more records?\nPress 'Y' or 'y' for Yes and 'N' or 'n' for No : ");

        while (1)
        {
            scanf(" %c", &Answer);

            if (Answer == 'Y' || Answer == 'y' || Answer == 'N' || Answer == 'n')
            {
                break;
            }

            printf("Enter input among 'Y','y','N','n' : ");
        }

        number_of_record_added++;
    }

    printf("%d records Added successfully.\n", number_of_record_added);

    fclose(Fp);
}
void display_student()
{
    Student s;
    int i = 1;

    FILE *fp = fopen("marksheet.dat", "rb");

    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }

    while (fread(&s, sizeof(Student), 1, fp) == 1)
    {
        printf("=================[Student %d]=================\n", i);
        printf("Student Roll No.        :- %d\n", s.roll_no);
        printf("Student Name            :- %s\n", s.Name);
        printf("Student Age             :- %d\n", s.age);
        printf("Student Class           :- %s\n", s.Class);
        printf("Student Gender          :- %c\n", s.Gender);
        printf("English Marks           :- %.2f\n", s.English);
        printf("Hindi Marks             :- %.2f\n", s.Hindi);
        printf("Maths Marks             :- %.2f\n", s.Maths);
        printf("Science Marks           :- %.2f\n", s.Science);
        printf("Social Science Marks    :- %.2f\n", s.Social_Science);
        printf("Total Marks             :- %.2f\n", s.Total);
        printf("Percentage              :- %.2f%%\n", s.Percentage);
        printf("Grade                   :- %c\n", s.Grade);
        printf("----------------------------------------------\n");

        i++;
    }

    fclose(fp);
}

void search_student()
{
    Student s;

    FILE *fp = fopen("marksheet.dat", "rb");

    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }

    int roll_no, found = 0;

    printf("Enter Student Roll Number whose Data u want to search :- ");
    scanf("%d", &roll_no);

    while (fread(&s, sizeof(Student), 1, fp) == 1)
    {
        if (roll_no == s.roll_no)
        {
            found = 1;

            printf("\n========== Student Found Successfully ==========\n");
            printf("Student Roll No.        :- %d\n", s.roll_no);
            printf("Student Name            :- %s\n", s.Name);
            printf("Student Age             :- %d\n", s.age);
            printf("Student Class           :- %s\n", s.Class);
            printf("Student Gender          :- %c\n", s.Gender);
            printf("English Marks           :- %.2f\n", s.English);
            printf("Hindi Marks             :- %.2f\n", s.Hindi);
            printf("Maths Marks             :- %.2f\n", s.Maths);
            printf("Science Marks           :- %.2f\n", s.Science);
            printf("Social Science Marks    :- %.2f\n", s.Social_Science);
            printf("Total Marks             :- %.2f\n", s.Total);
            printf("Percentage              :- %.2f%%\n", s.Percentage);
            printf("Grade                   :- %c\n", s.Grade);
            printf("------------------------------------------------\n");

            break;
        }
    }

    if (!found)
    {
        printf("Entered Roll No. not found.\n");
    }

    fclose(fp);
}
void update_student_record()
{
    Student s;

    int roll_number, choice, roll_no_found = 0;
    char reply = 'Y';

    FILE *fp = fopen("marksheet.dat", "rb");

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

    printf("Enter the Roll Number of Student whose data u want to modify : ");
    scanf("%d", &roll_number);

    while (fread(&s, sizeof(Student), 1, fp) == 1)
    {
        reply = 'Y';

        if (roll_number == s.roll_no)
        {
            roll_no_found = 1;

            while (reply == 'Y' || reply == 'y')
            {
                printf("\n========== Update Menu ==========\n");
                printf("1 Roll No.\n");
                printf("2 Name\n");
                printf("3 Age\n");
                printf("4 Class\n");
                printf("5 Gender\n");
                printf("6 English Marks\n");
                printf("7 Hindi Marks\n");
                printf("8 Maths Marks\n");
                printf("9 Science Marks\n");
                printf("10 Social Science Marks\n");

                printf("Enter your Choice : ");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    printf("Enter New Roll No. : ");
                    scanf("%d", &s.roll_no);
                    break;

                case 2:
                    printf("Enter New Name : ");
                    getchar();
                    fgets(s.Name, sizeof(s.Name), stdin);
                    s.Name[strcspn(s.Name, "\n")] = '\0';
                    break;

                case 3:
                    printf("Enter New Age : ");
                    scanf("%d", &s.age);
                    break;

                case 4:
                    printf("Enter New Class : ");
                    getchar();
                    fgets(s.Class, sizeof(s.Class), stdin);
                    s.Class[strcspn(s.Class, "\n")] = '\0';
                    break;

                case 5:
                    printf("Enter Correct Gender : ");
                    scanf(" %c", &s.Gender);
                    break;

                case 6:
                    printf("Enter Updated English Marks : ");
                    scanf("%f", &s.English);
                    break;

                case 7:
                    printf("Enter Updated Hindi Marks : ");
                    scanf("%f", &s.Hindi);
                    break;

                case 8:
                    printf("Enter Updated Maths Marks : ");
                    scanf("%f", &s.Maths);
                    break;

                case 9:
                    printf("Enter Updated Science Marks : ");
                    scanf("%f", &s.Science);
                    break;

                case 10:
                    printf("Enter Updated Social Science Marks : ");
                    scanf("%f", &s.Social_Science);
                    break;

                default:
                    printf("Invalid Choice entered.\n");
                    break;
                }

                s.Total = s.English + s.Hindi + s.Maths + s.Science + s.Social_Science;

                s.Percentage = s.Total / 5.0;

                if (s.Percentage >= 90)
                {
                    s.Grade = 'A';
                }
                else if (s.Percentage >= 75)
                {
                    s.Grade = 'B';
                }
                else if (s.Percentage >= 60)
                {
                    s.Grade = 'C';
                }
                else if (s.Percentage >= 40)
                {
                    s.Grade = 'D';
                }
                else
                {
                    s.Grade = 'F';
                }

                printf("Do you Want to modify another field of the same student ? [Y/N] : ");
                scanf(" %c", &reply);
            }
        }

        fwrite(&s, sizeof(Student), 1, fp1);
    }

    fclose(fp);
    fclose(fp1);

    if (roll_no_found)
    {
        remove("marksheet.dat");
        rename("temp.dat", "marksheet.dat");
        printf("Student Record updated successfully.\n");
    }
    else
    {
        remove("temp.dat");
        printf("Roll Number not found.\n");
    }
}

void delete_student_record()
{
    Student s;

    int roll_number, roll_no_found = 0;

    FILE *fp = fopen("marksheet.dat", "rb");

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

    printf("Enter the Roll Number of Student whose record u want to delete : ");
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
        remove("marksheet.dat");
        rename("temp.dat", "marksheet.dat");
        printf("Student Record deleted successfully.\n");
    }
    else
    {
        remove("temp.dat");
        printf("Roll Number not found.\n");
    }
}
void generate_marksheet()
{
    Student s;

    int roll_no, found = 0;

    FILE *fp = fopen("marksheet.dat", "rb");

    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }

    printf("Enter Student Roll Number : ");
    scanf("%d", &roll_no);

    while (fread(&s, sizeof(Student), 1, fp) == 1)
    {
        if (roll_no == s.roll_no)
        {
            found = 1;

            printf("\n");
            printf("=============================================================\n");
            printf("                 STUDENT MARKSHEET\n");
            printf("=============================================================\n");
            printf("Student Name        : %s\n", s.Name);
            printf("Roll Number         : %d\n", s.roll_no);
            printf("Age                 : %d\n", s.age);
            printf("Class               : %s\n", s.Class);
            printf("Gender              : %c\n", s.Gender);
            printf("-------------------------------------------------------------\n");
            printf("Subject                     Marks Obtained\n");
            printf("-------------------------------------------------------------\n");
            printf("English                  %.2f\n", s.English);
            printf("Hindi                    %.2f\n", s.Hindi);
            printf("Maths                    %.2f\n", s.Maths);
            printf("Science                  %.2f\n", s.Science);
            printf("Social Science           %.2f\n", s.Social_Science);
            printf("-------------------------------------------------------------\n");
            printf("Total Marks              %.2f / 500\n", s.Total);
            printf("Percentage               %.2f%%\n", s.Percentage);
            printf("Grade                    %c\n", s.Grade);

            if (s.Grade == 'F')
            {
                printf("Result                   FAIL\n");
            }
            else
            {
                printf("Result                   PASS\n");
            }

            printf("=============================================================\n");

            break;
        }
    }

    if (!found)
    {
        printf("Entered Roll Number not found.\n");
    }

    fclose(fp);
}