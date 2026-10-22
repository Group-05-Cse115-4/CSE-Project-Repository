#include<stdio.h>
#include<string.h>


//Function Declarations.


void headdash()
{
    printf("====================================\n");
}

 /*The block of code contains the code of main menu*/

int mainmenu()//Starting the code of main menu.
{
    int choose;

    headdash();//Recall a function
    printf("Welcome to Student Management System\n");
    headdash();//Recall a function//Recall a function
    printf("\n1.Admin Login Page\n");
    printf("2.Student Login Page\n");
    printf("3.Exit\n");
    printf("Choose you option :");
    scanf("%d",&choose);
    return choose;
}//End of main menu.


//Function-Student Login System.
struct Account//Starting the Student login system.
{
    char Username[50];
    char Password[80];
};
void studentLogin()
{
    struct Account account;
    char Username[50];
    char Password[70];
    int found=0;
    while(1)
    {
        headdash();//Recall a function
        printf("    Student Log In          \n");
        headdash();//Recall a function
        printf("\nUsername :");
        scanf("%49s", &Username);
        printf("Password :");
        scanf("%79s",&Password);
        FILE *fileofstd=
        fopen("student.txt","r");

        if(fileofstd == NULL)
            {
                printf("Something Went Wrong.\nError\n");
        return 1;
        }

        found=0;
        while(fscanf(fileofstd, "%49s %79s", account.Username, account.Password) ==2)
        {
            if(strcmp(Username, account.Username)==0 && strcmp(Password, account.Password)==0)
            {
                found=1;
                break;
            }
        }
        fclose(fileofstd);
        if(found){
            printf("\nLogin Succesful!\n");
            printf("Welcome %s!\n",Username);break;
        }
        else
        {
            printf("Incorrect Username or Password!\n");
            printf("Try Again.\n");
        }
    }

    return 0;
}//Ending of student login System




//Function of Admin Loging System

//Starting of Admin-Login System.
void AdminLogin()
{
    struct Account account;
    char Username[50];
    char Password[70];
    int found=0;
    while(1)
    {
        headdash();
        printf("        Admin Log In          \n");
        headdash();
        printf("\nUsername :");
        scanf("%49s", &Username);
        printf("Password :");
        scanf("%69s",&Password);
        FILE *fileofadm=
        fopen("admin.txt","r");

        if(fileofadm == NULL)
            {
                printf("Something Went Wrong.\nError\n");
        return 1;
        }

        found=0;
        while(fscanf(fileofadm, "%49s %69s", account.Username, account.Password) ==2)
        {
            if(strcmp(Username, account.Username)==0 && strcmp(Password, account.Password)==0)
            {
                found=1;
                break;
            }
        }
        fclose(fileofadm);
        if(found){
            printf("\nLogin Succesful!\n");
            printf("Welcome %s!\n",Username);break;
        }
        else
        {
            printf("Incorrect Username or Password!\n");
            printf("Try Again.\n");
        }
    }

    return 0;
}
int main()
{
    int choose=mainmenu();
    switch(choose)
    {
        case 1:AdminLogin();
        break;
        case 2:studentLogin();
        break;
        case 3:
            printf("\nThanks for Coming.\n");
            printf("Exiting.......\n");
            break;
            default: printf("Invalid option! Please choose 1, 2, or 3.\n ");

    }
    return 0;
}
