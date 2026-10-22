void studentDashboard(int studentID)          //student panel function,receiving parameter,student id:the id of the currently logged-in student
{
    int choice;                        //used to store the menu options entered by the students
    do
    {                                                                              //print the divider line
        printf("\n==============================\n");
        printf("                        STUDENT DASHBOARD                 \n");
        printf("==============================\n");
        //menu options
        printf("1. View My Information\n");
        printf("2. View My Marks & Result\n");
        printf("3. View My Attendance\n");
        printf("4. Change Password\n");
        printf("5. Logout\n");

        printf("Enter your choice: ");           //prompt the user to make a selection by inputting
        scanf("%d", &choice);                    //read the input options and store them in the variable choice

        int position = -1;                         //the variable is used to store the index of the found student. An initial value of -1 indicates that the student has not been found yet
        for(int i=0; i<totalStudent; i++){               //iterate through all students and search for the student whose id matches the provided login information
            if(student[i].id==studentID){                //determine whether the id currently being processed is equal to the student id passed in for login
                position = i;                //found, save the array index to the variable "position"
                break;          //once found,immediately exit the loop
            }
        }
        if(position==-1){             //if the loop ends and is still -1,it was not found
            printf("Student not found!\n");
            return;                  //if it's not found,immediately exit this function
        }
        switch(choice)           //according to the menu option input by the user,execute the corresponding function
        {
            case 1: printf("\nID: %d  |  Name: %s  |  Dept: %s\n", student[position].id, student[position].name, student[position].dept);
            pressContinue();              //pause, press any key to continue
            break;                  //exit the current switch,end this case, return to the menu loop

            case 2: float t = student[position].cprog + student[position].math + student[position].eng;        //total marks
            float a = t / 3;          //average marks
            char grade;                 //storage level
            char result;                  //storage tag
            if(a>=80)             //determine the grade based on the average score
                grade = 'A';
            else if(a>=70)
                grade = 'B';
            else if(a>=60)
                grade = 'C';
            else if(a>=50)
                grade = 'D';
            else{
                grade = 'F';
            }
            if(a>=50)
            result = 'P';
            else
            result = 'F';

            printf("Total: %.2f\n", t);
            printf("Average: %.2f\n", a);
            printf("Grade: %c\n", grade);
            if(result=='P')
            printf("Result: Pass\n");
            else
            printf("Result: Fail\n");
            pressContinue(); break;

            case 3: float percentage = (float)student[position].present / (student[position].present+student[position].absent) * 100;         //calculate attendance rate, (float)to prevent integer division errors
            printf("Present: %d     Absent: %d\n", student[position].present, student[position].absent);
            printf("Attendance Percentage: %.2f%%\n", percentage);
            pressContinue(); break;

            case 4:
            printf("Enter new password: ");
            scanf("%s", student[position].password);        //read the new password and overwrite the original one
            printf("Password changed successfully!\n");
            pressContinue(); break;

            case 5:
            printf("Loggint out...\n");
            pressContinue(); break;

            default: printf("Invalid option.\n");
            pressContinue();
            }
    }while(choice!=5);                  //if it's not option 5 to exit, the menu will be displayed again in a loop
}

