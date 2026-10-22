// Admin Dashboard
void adminDashboard()
{
    int choice;     //used to store the options entered by the user
    do{            //print title and divider of the admin control panel
        printf("\n==============================\n");
        printf("                          ADMIN DASHBOARD                  \n");
        printf("==============================\n");

        printf("1. Add New Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Enter Marks & Grades\n");
        printf("7. Attendance Management\n");
        printf("8. View Reports\n");
        printf("9. Save / Load Data\n");
        printf("10. Logout\n");        //exit the admin panel and return to the main menu

        printf("Enter your choice: ");     //prompt the user to input the option
        scanf("%d", &choice);               //read user selection
        switch(choice)          //execute corresponding function based on user selection
        {
            case 1: addnewStudent(); break;           //invoking this function
            case 2: viewallStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: enterMarksGrades(); break;
            case 7: attendanceManagement(); break;
            case 8: viewReports(); break;
            case 9: saveLoadData(); break;
            case 10: printf("\nLogging out to Main Menu.\n"); pressContinue(); break;        //exit the panel
            default: printf("Invalid choice!\n"); pressContinue(); break;     //if the input number isn't within the range of 1 to 10, that the selection is valid
        }
    }while(choice!=10);       // in a loop, the loop will continue if the user does not select 10,they will remain stay in the admin dashboard
}



