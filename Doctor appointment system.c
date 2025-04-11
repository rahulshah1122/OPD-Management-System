//Header File Declare

#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Functions prototype declare
void signup();
void signin();
void WelcomeScreen ();
void MainMenu ();
void doctor_information ();
void add_appointment ();
void patient_profile ();
int Exit ();
void Exit2 ();
void Back1 ();
void Back2 ();
void Fever ();
void Cancer ();
void Thyroid ();
void Diabetes ();
void Heart_problem ();
void Fever1 ();
void Cancer1 ();
void Thyroid1 ();
void Diabetes1 ();
void Heart_problem1 ();
void Search_patient_record ();
void Edit_appointment ();
void Cancel_appointment ();


//Declaring Global Variables

char result = 0;
int temp;
int count = 0;
int i, j, num;

//Point Global File Name

FILE *file;
FILE *temporary_file;
FILE *signUp;


//co-ordinates sets in (x,y)

void
gotoxy (short x, short y)
{
  COORD pos = { x, y };
  SetConsoleCursorPosition(GetStdHandle (STD_OUTPUT_HANDLE), pos);

}
void coord_xy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// structure for patient profile

typedef struct
{
  int age;
  char Gender;
  char First_Name[20];
  char Last_Name[20];
  char Phone_Number[15];
  char Address[30];
  char Email[30];
  char Doctor_Name[30];
  char Problem[20];


} info_patient;


//structure for Login

typedef struct
{

  char first_name[20];
  char last_name[20];
  char username[20];
  char password[20];

} login_screen;


//Global variable declare for patient

info_patient person;

//Global variable declare for login screen

login_screen p;



void rectangle_box() {
    int x,y;
    coord_xy(5,2);
    coord_xy(1,1);
    printf("%c\n",201);
    for(y=2;y<25;y++){
        coord_xy(1,y);
        printf("%c\n",186);
    }
    coord_xy(1,25);
    printf("%c",200);
    for(x=2;x<110;x++){
        coord_xy(x,y);
        printf("%c",205);
    }
    printf("%c\n",188);
    for(y=24;y>=2;y--){
        coord_xy(110,y);
        printf("%c\n",186);
    }
    coord_xy(110,1);
    printf("%c",187);
    for(x=109;x>1;x--){
        coord_xy(x,y);
        printf("%c",205);
    }
    printf("%c\n", 187);

     //Printing the bigger smaller rectangle
    coord_xy(3, 2); // adjust the position for the output
    printf("%c",201);
    for(x=4;x<107;x++){
        coord_xy(x, 2);
        printf("%c",205);
    }
    printf("%c\n", 187);
    for(y=3;y<24;y++){
        coord_xy(3,y);
        printf("%c\n",186);
        coord_xy(107,y);
        printf("%c\n",186);
    }
    coord_xy(3,24);
    printf("%c",200);
    for(x=4;x<107;x++){
        coord_xy(x,24);
        printf("%c",205);
    }
    printf("%c\n", 188);
//    printf("%c\n", 187);
    coord_xy(10, 4); // adjust the position for the output
    
}


//starting main
int
main ()
{
	rectangle_box();
	coord_xy(5, 4);
  WelcomeScreen ();		//call welcome screen

//////Title(); // Call the hospital title name

  int choice;
rectangle_box();
  printf ("\n\n\t                   1.Sigh Up");
  printf ("\n\n\t                   2.Sigh In\n\n\n");

  printf ("\t                  Choose Option: ");
  scanf ("%d", &choice);


  switch (choice)
    {

    case 1:
      system ("cls");
      //Title ();
     signup();
 //       MainMenu();
      break;


    case 2:
      system ("cls");
     // Title ();
      signin ();
      break;


    default:
      system ("cls");
     // Title ();
      printf ("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEntered Wrong Key!!!");
      break;
    }


  getch ();			// To stuck the screen and wait for the key




}






void
WelcomeScreen ()
{
//  system ("COLOR OF");
  Sleep (1000);			// using for stop few moments
  printf 
    ("\t                                            WELCOME                             \n");
printf 
    ("\t                                              TO                            \n");
  printf 
    ("\t                                    DOCTOR APPOINTMENT SYSTEM                           ");
  Sleep (1000);
  //system ("COLOR 04");
  system("COLOR 0B");
  printf
    ("\n\t***********************************************************************************************\n");
  printf
    ("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf ("\n\n\tEnter any key: ");


  getch ();			// to stuck the screen and wait for any key
  system ("cls");		// using for clear the console or the output

}

void signup()
{    
      system("cls");
      rectangle_box();
      signUp=fopen("SignUp file.txt","w");
      
      printf("\n\n\t\t\t                            SIGNUP");

      printf("\n\t                                    Set user name and password");
        printf
    ("\n\t***********************************************************************************************\n");
  printf
    ("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

      printf("\n\t\t\tEnter First Name  : ");
      fflush(stdin);
      gets(p.first_name);


      printf("\n\t\t\tEnter Last Name  : ");
      fflush(stdin);
      gets(p.last_name);

      printf("\n\n\t\t\tEnter User Name  : ");
      scanf("%s",p.username);

    printf("\n\n\t\t\tEnter Password  : ");
      scanf("%s",p.password);

      fwrite(&p,sizeof(p), 1,signUp);

      fclose(signUp);

      printf("\n\n\n\t\t\tLoading..............");
      Sleep(2000);

      signin();
}



 //Function to sign in
void signin()
{
system("cls");
rectangle_box();
// Title();
char username[20];
char password[20];
char ch;
int i = 0;
  printf("\n\t\t\t                          Sign In \n");
    printf("\n\t***********************************************************************************************\n");
  printf
    ("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("\n\n\t\t\tEnter User Name: ");
  fflush(stdin);
  gets(username);
  
  printf("\n\n\t\t\tEnter Password: ");
  while (i < 20) {
      ch = getch();
      if (ch == 13) { // Enter key
          password[i] = '\0';
          break;
      } else if (ch == 8) { // Backspace
          if (i > 0) {
              i--;
              printf("\b \b"); // Move cursor back and overwrite with space
          }
      } else {
          password[i] = ch;
          i++;
          printf("*");
      }
  }
  
  signUp = fopen("SignUp file.txt", "r");
  
  while (fread(&p, sizeof(p), 1, signUp))
  {
      for (i = 2; i >= 1; i--)
      {
          if (strcmp(username, p.username) == 0 && strcmp(password, p.password) == 0)
          {
              printf("\n\n\n\t\t\tLoading.............");
              Sleep(2000);
              system("cls");
              rectangle_box();
              //  Title();
              printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tSuccessfull Login \n\n\n\n\n");
              Sleep(2000);
              MainMenu();
              break;
          }
          else
          {
              system("cls");
              //  Title();
              
              temp = i;
              
              printf("\n\n\n\n\n\t\t\t\t\tWrong Password !!! \n\n");
              printf("\n\n\n\n\n\t\t\t%d Chance's Left !! \n \n\n", temp);
              
              printf("\n\n\t\t\tEnter User Name: ");
              gets(username);
              
              printf("\n\n\t\t\tEnter Password: ");
              i = 0;
              while (i < 20) {
                  ch = getch();
                  if (ch == 13) { // Enter key
                      password[i] = '\0';
                      break;
                  } else if (ch == 8) { // Backspace
                      if (i > 0) {
                          i--;
                          printf("\b \b"); // Move cursor back and overwrite with space
                      }
                  } else {
                      password[i] = ch;
                      i++;
                      printf("*");
                  }
              }
          }
          
          // If user did not enter right password within 3 times then code will enter this block
      }
      
      if (i <= 0)
      {
          system("cls");
          //  Title();
          printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tFaild To Login \n\n\n\n\n");
          getch();
          
      }
  }
  fclose(signUp);
}




   // This function is used to go back to the main menu
void
Back1 ()
{
  MainMenu ();

}

//Back in the docyor information
void
Back2 ()
{
  doctor_information ();
}


//   this function is for section selection according to viewer requirement

void
MainMenu ()
{
  int choice;
  system ("cls");
  rectangle_box();
  FILE *menu_file;
  //menu_file = fopen ("Main Menu.txt", "r");
  printf("\t                                   Main Menu   \n");
   printf("\n\t***********************************************************************************************\n");
  printf
    ("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
  printf("\t               1. Doctor Information   \n");
  printf("\t               2. Add Appointment   \n");
  printf("\t               3. Patient Profile   \n");
  printf("\t               4. Search Patient Record   \n");
  printf("\t               5. Edit Appointment   \n");
  printf("\t               6. Cancel Appointment   \n");
  printf("\t               7. Exit   \n");
    printf
    ("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
     printf("\n\t***********************************************************************************************\n");
//  char ch;
//
//  while (!feof (menu_file))
//    {
//      ch = fgetc (menu_file);
//      printf ("%c", ch);
//
//    }
//
//  fclose (menu_file);

  printf ("\n\t\t\tWhich section do you want ? \n");
  printf ("\t\t\tChoose Number :  ");
  scanf ("%d", &choice);

  switch (choice)
    {

    case 1:
      doctor_information ();
      break;


    case 2:
      add_appointment ();
      break;

    case 3:
      patient_profile ();
      break;

    case 4:
      Search_patient_record ();
      break;

    case 5:

      Edit_appointment ();
      break;

    case 6:
      Cancel_appointment ();
      break;

    case 7:
      Exit ();
      break;



    default:
      system ("cls");
      printf ("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEntered Wrong Key!!!");
      printf ("\n\n\t\t\t\tTry Again.........!!!");
      Sleep (3000);
      MainMenu ();

      break;
    }


}

// This function is for showing dctor information

void
doctor_information ()
{
  int choice;
  system ("cls");

  FILE *diseases_file;
  diseases_file = fopen ("Diseases name.txt", "r");
  char ch;

  while (!feof (diseases_file))
    {

      ch = fgetc (diseases_file);
      printf ("%c", ch);


    }
  fclose (diseases_file);

  printf
    ("\n\n\n Which department doctor do you want to see choose by your own disease  :");
  scanf ("%d", &choice);


  switch (choice)
    {

    case 1:
      Fever ();
      break;


    case 2:
      Cancer ();
      break;

    case 3:
      Thyroid ();
      break;

    case 4:
      Diabetes ();
      break;

    case 5:

      Heart_problem ();
      break;

    case 6:
      Back1 ();
      break;

    case 7:
      Exit ();
      break;



    default:
      system ("cls");
      printf ("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEntered Wrong Key!!!");
      printf ("\n\n\t\t\t\tTry Again.........!!!");
      Sleep (1000);
      doctor_information ();

      break;
    }

}

//****************** Functions for all the diseases and it will work according to the user choice ***********

void
Fever ()
{
  system ("cls");

  FILE *fever;
  fever = fopen ("1. Doctor info of - Fever.txt", "r");

  if (fever == NULL)
    {

      system ("cls");
      printf ("\n\n\n\t\t\t   File not found..\n\n");

    }

  else
    {

      system ("cls");

      char ch;
      ch = fgetc (fever);
      while (!feof (fever))
	{

	  printf ("%c", ch);
	  ch = fgetc (fever);

	}

    }

  fclose (fever);

  // This block is usung for returning to the main menu and doctor info menu

  int n;
  printf ("\n\n 1.Main Menu\n");
  printf ("\n 2.Back\n");
  printf ("\n 3.Exit\n\n");
  printf ("Which section do you want to return? :");
  scanf ("%d", &n);

  switch (n)
    {
    case 1:
      Back1 ();
      break;

    case 2:
      Back2 ();

    case 3:
      Exit ();
      break;

    default:
      system ("cls");
      printf ("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEntered Wrong Key!!!");
      printf ("\n\n\t\t\t\tTry Again.........!!!");
      Sleep (2000);
      Fever ();

      break;
    }

}




void
Cancer ()
{
  system ("cls");

  FILE *cancer;
  cancer = fopen ("1. Doctor info of - cancer.txt", "r");

  if (cancer == NULL)
    {

      system ("cls");
      printf ("\n\n\n\t\t\t   File not found..\n\n");

    }

  else
    {

      system ("cls");

      char ch;
      ch = fgetc (cancer);
      while (!feof (cancer))
	{

	  printf ("%c", ch);
	  ch = fgetc (cancer);

	}

    }

  fclose (cancer);

  // This block is usung for returning to the main menu and doctor info menu

  int n;
  printf ("\n\n 1.Main Menu\n");
  printf ("\n 2.Back\n");
  printf ("\n 3.Exit\n\n");
  printf ("Which section do you want to return? :");
  scanf ("%d", &n);

  switch (n)
    {
    case 1:
      Back1 ();
      break;

    case 2:
      Back2 ();

    case 3:
      Exit ();
      break;

    default:
      system ("cls");
      printf ("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEntered Wrong Key!!!");
      printf ("\n\n\t\t\t\tTry Again.........!!!");
      Sleep (2000);
      Cancer ();

      break;
    }

}




void
Thyroid ()
{
  system ("cls");

  FILE *thyroid;
  thyroid = fopen ("1. Doctor info of - Thyroid.txt", "r");

  if (thyroid == NULL)
    {

      system ("cls");
      printf ("\n\n\n\t\t\t   File not found..\n\n");

    }

  else
    {

      system ("cls");

      char ch;
      ch = fgetc (thyroid);
      while (!feof (thyroid))
	{

	  printf ("%c", ch);
	  ch = fgetc (thyroid);

	}

    }

  fclose (thyroid);

  // This block is usung for returning to the main menu and doctor info menu

  int n;
  printf ("\n\n 1.Main Menu\n");
  printf ("\n 2.Back\n");
  printf ("\n 3.Exit\n\n");
  printf ("Which section do you want to return? :");
  scanf ("%d", &n);

  switch (n)
    {
    case 1:
      Back1 ();
      break;

    case 2:
      Back2 ();

    case 3:
      Exit ();
      break;

    default:
      system ("cls");
      printf ("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEntered Wrong Key!!!");
      printf ("\n\n\t\t\t\tTry Again.........!!!");
      Sleep (2000);
      Thyroid ();

      break;
    }

}






void
Diabetes ()
{
  system ("cls");

  FILE *diabetes;
  diabetes = fopen ("1. Doctor info of - diabetes.txt", "r");

  if (diabetes == NULL)
    {

      system ("cls");
      printf ("\n\n\n\t\t\t   File not found..\n\n");

    }

  else
    {

      system ("cls");

      char ch;
      ch = fgetc (diabetes);
      while (!feof (diabetes))
	{

	  printf ("%c", ch);
	  ch = fgetc (diabetes);

	}

    }

  fclose (diabetes);

  // This block is usung for returning to the main menu and doctor info menu

  int n;
  printf ("\n\n 1.Main Menu\n");
  printf ("\n 2.Back\n");
  printf ("\n 3.Exit\n\n");
  printf ("Which section do you want to return? :");
  scanf ("%d", &n);

  switch (n)
    {
    case 1:
      Back1 ();
      break;

    case 2:
      Back2 ();

    case 3:
      Exit ();
      break;

    default:
      system ("cls");
      printf ("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEntered Wrong Key!!!");
      printf ("\n\n\t\t\t\tTry Again.........!!!");
      Sleep (2000);
      Diabetes ();

      break;
    }

}




void
Heart_problem ()
{
  system ("cls");

  FILE *heart_problem;
  heart_problem = fopen ("1. Doctor info of - Heart Problem.txt", "r");

  if (heart_problem == NULL)
    {

      system ("cls");
      printf ("\n\n\n\t\t\t   File not found..\n\n");

    }

  else
    {

      system ("cls");

      char ch;
      ch = fgetc (heart_problem);
      while (!feof (heart_problem))
	{

	  printf ("%c", ch);
	  ch = fgetc (heart_problem);

	}

    }

  fclose (heart_problem);

  // This block is usung for returning to the main menu and doctor info menu

  int n;
  printf ("\n\n 1.Main Menu\n");
  printf ("\n 2.Back\n");
  printf ("\n 3.Exit\n\n");
  printf ("Which section do you want to return? :");
  scanf ("%d", &n);

  switch (n)
    {
    case 1:
      Back1 ();
      break;

    case 2:
      Back2 ();

    case 3:
      Exit ();
      break;

    default:
      system ("cls");
      printf ("\n\n\n\n\n\n\n\t\t\t\t\t\t\tEntered Wrong Key!!!");
      printf ("\n\n\t\t\t\tTry Again.........!!!");
      Sleep (2000);
      Heart_problem ();

      break;
    }

}


	//  Doctor selection section

void
Fever1 ()
{
  FILE *fever;
  fever = fopen ("1. Doctor info of - Fever.txt", "r");

  if (fever == NULL)
    {
      system ("cls");
      printf ("\n\n\n\t\t\t  File is not found..\n\n");

    }

  else
    {
      system ("cls");

      char ch;
      ch = fgetc (fever);
      while (!feof (fever))
	{

	  printf ("%c", ch);
	  ch = fgetc (fever);
	}
    }

  fclose (fever);
  printf ("\n\n\n\t\t\tWhich doctor do you want  ?");
  printf ("\n\n\n\t\t\tWrite his/her name :");
  fflush (stdin);
  gets (person.Doctor_Name);
  person.Doctor_Name[0] = toupper (person.Doctor_Name[0]);
}


void
Cancer1 ()
{
  FILE *cancer;
  cancer = fopen ("1. Doctor info of - cancer.txt", "r");

  if (cancer == NULL)
    {
      system ("cls");
      printf ("\n\n\n\t\t\t  File is not found..\n\n");

    }

  else
    {
      system ("cls");

      char ch;
      ch = fgetc (cancer);
      while (!feof (cancer))
	{

	  printf ("%c", ch);
	  ch = fgetc (cancer);
	}
    }

  fclose (cancer);
  printf ("\n\n\n\t\t\tWhich doctor do you want  ?");
  printf ("\n\n\n\t\t\tWrite his/her name :");
  fflush (stdin);
  gets (person.Doctor_Name);
  person.Doctor_Name[0] = toupper (person.Doctor_Name[0]);
}


void
Thyroid1 ()
{
  FILE *thyroid;
  thyroid = fopen ("1. Doctor info of - Thyroid.txt", "r");

  if (thyroid == NULL)
    {
      system ("cls");
      printf ("\n\n\n\t\t\t  File is not found..\n\n");

    }

  else
    {
      system ("cls");

      char ch;
      ch = fgetc (thyroid);
      while (!feof (thyroid))
	{

	  printf ("%c", ch);
	  ch = fgetc (thyroid);
	}
    }

  fclose (thyroid);
  printf ("\n\n\n\t\t\tWhich doctor do you want  ?");
  printf ("\n\n\n\t\t\tWrite his/her name :");
  fflush (stdin);
  gets (person.Doctor_Name);
  person.Doctor_Name[0] = toupper (person.Doctor_Name[0]);
}



void
Diabetes1 ()
{
  FILE *diabetes;
  diabetes = fopen ("1. Doctor info of - Diabetes.txt", "r");

  if (diabetes == NULL)
    {
      system ("cls");
      printf ("\n\n\n\t\t\t  File is not found..\n\n");

    }

  else
    {
      system ("cls");

      char ch;
      ch = fgetc (diabetes);
      while (!feof (diabetes))
	{

	  printf ("%c", ch);
	  ch = fgetc (diabetes);
	}
    }

  fclose (diabetes);
  printf ("\n\n\n\t\t\tWhich doctor do you want  ?");
  printf ("\n\n\n\t\t\tWrite his/her name :");
  fflush (stdin);
  gets (person.Doctor_Name);
  person.Doctor_Name[0] = toupper (person.Doctor_Name[0]);
}


void
Heart_problem1 ()
{
  FILE *heart_problem;
  heart_problem = fopen ("1. Doctor info of - Heart Problem.txt", "r");

  if (heart_problem == NULL)
    {
      system ("cls");
      printf ("\n\n\n\t\t\t  File is not found..\n\n");

    }

  else
    {
      system ("cls");

      char ch;
      ch = fgetc (heart_problem);
      while (!feof (heart_problem))
	{

	  printf ("%c", ch);
	  ch = fgetc (heart_problem);
	}
    }

  fclose (heart_problem);
  printf ("\n\n\n\t\t\tWhich doctor do you want  ?");
  printf ("\n\n\n\t\t\tWrite his/her name :");
  fflush (stdin);
  gets (person.Doctor_Name);
  person.Doctor_Name[0] = toupper (person.Doctor_Name[0]);
}


//******************** Function for Adding Appointment ********************************************

void add_appointment ()
{

  system ("cls");
//  rectangle_box();

    printf
    ("\t                                         Add Patient Appointment                                          \n");
      printf
    ("\t************************************************************************************************************\n");
      printf
    ("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

  char ans;
  file = fopen ("Patient File.txt", "a");	//  open file in append mode

  // *********************** this portion for first name ******************************

A:
  printf ("\n\t\t\tFirst Name: ");
  fflush (stdin);
  gets (person.First_Name);
  person.First_Name[0] = toupper (person.First_Name[0]);
  if (strlen (person.First_Name) > 20 || strlen (person.First_Name) < 2)
    {

      printf ("\n\n\t Invalid First Name !!!");
      printf
	("\n\n\t The First Name range should be maximum 20 and minimum 2 \n\n");
      goto A;

    }

  else
    {
      for (i = 0; i < strlen (person.First_Name); i++)
	{
	  if (isalpha (person.First_Name[i]))
	    {
	      count = 1;
	    }

	  else
	    {
	      count = 0;
	      break;
	    }
	}

      if (!count)
	{
	  printf
	    ("\n\n\t\t First name contain Invalid character !!! \n\n\t\tPlease try again.....");
	  goto A;
	}
    }

  // This portion is for last name

B:
  printf ("\n\t\t\tLast Name: ");
  fflush (stdin);
  gets (person.Last_Name);
  person.Last_Name[0] = toupper (person.Last_Name[0]);
  if (strlen (person.Last_Name) > 20 || strlen (person.Last_Name) < 2)
    {

      printf ("\n\n\t Invalid Last Name !!!");
      printf
	("\n\n\t The Last Name range should be maximum 20 and minimum 2 \n\n");
      goto B;

    }

  else
    {
      for (i = 0; i < strlen (person.Last_Name); i++)
	{
	  if (isalpha (person.Last_Name[i]))
	    {
	      count = 1;
	    }

	  else
	    {
	      count = 0;
	      break;
	    }
	}

      if (!count)
	{
	  printf
	    ("\n\n\t\t Last name contain Invalid character !!! \n\n\t\tPlease try again.....");
	  goto B;
	}
    }

// ************************* This portion for Gender ************************************

  do
    {
      printf ("\n\t\t\tGender(F/M): ");
      scanf ("%c", &person.Gender);

      if (toupper (person.Gender) == 'M' || toupper (person.Gender) == 'F')
	{
	  temp = 1;
	}
      else
	{
	  temp = 0;
	}
      if (!temp)
	{
	  printf
	    ("\n\t\t Gender contain Invalid character !!! \n\n\t\t Enter either(F / M)......");

	}


    }
  while (!temp);

  /* ******************************************** This portion for age ******************************* */

  printf ("\n\t\t\tAge: ");
  scanf ("%i", &person.age);


  /* ***************************** This portion is for Address ************************************ */

  do
    {

    C:
      printf ("\n\t\t\tAddress:  ");
      fflush (stdin);
      gets (person.Address);
      person.Address[0] = toupper (person.Address[0]);
      if (strlen (person.Address) > 20 || strlen (person.Address) < 4)
	{

	  printf
	    ("\n\t Invalid !!! \n\n\t\t The max range for address is 20 and min range is 4");
	  goto C;
	}
    }
  while (!count);
  /* ******************************************* This portion for phone number *********************************** */

  do
    {

    D:
      printf ("\n\t\t\tContact no: ");
      scanf ("%s", person.Phone_Number);
      if (strlen (person.Phone_Number) > 10
	  || strlen (person.Phone_Number) != 10)
	{
	  printf
	    ("\n\t Invalid Phone number !!! \n\n\t\t Must contain 10 numbers !!! \n\t\t\tPlease Try Again...........");
	  goto D;
	}
      else
	{
	  for (i = 0; i < strlen (person.Phone_Number); i++)
	    {
	      if (!isalpha (person.Phone_Number[i]))
		{
		  count = 1;
		}
	      else
		{
		  for (i = 0; i < strlen (person.Phone_Number); i++)
		    {
		      if (isalpha (person.Phone_Number[i]))
			{
			  count = 1;

			}
		      else
			{
			  count = 0;
			  break;
			}
		    }
		  if (!count)
		    {
		      printf
			("\n\t\t Phone number contain Invalid Character !!! \n\t\t\tPlease Try Again..........");
		      goto D;
		    }
		}
	    }
  }
    }
	  while (!count);


      /* ***************This portion if for email *************************** */
      do
	{

	  printf ("\n\t\t\tEmail: ");
	  fflush (stdin);
	  gets (person.Email);
	  if (strlen (person.Email) > 30 || strlen (person.Email) < 8)
	    {
	      printf
		("\n\t Invalid Email Address !!! \n\n\t\t The max range for email is 30 and min range is 8");
	    }
	}
      while (strlen (person.Email) > 30 || strlen (person.Email) < 8);



		/****************************  This portion is for patient problem ***********************/
      do
	{

	E:
	  printf ("\n\t\t\tProblem: ");
	  fflush (stdin);
	  gets (person.Problem);
	  person.Problem[0] = toupper (person.Problem[0]);

	  // here user will give their disease name and this section will provide them doctor as they want

	  if (strcmp (person.Problem, "Fever") == 0)
	    {
	      system ("cls");
	      Fever1 ();
	    }

	  if (strcmp (person.Problem, "Cancer") == 0)
	    {
	      system ("cls");
	      Cancer1 ();
	    }

	  if (strcmp (person.Problem, "Thyroid") == 0)
	    {
	      system ("cls");
	      Thyroid1 ();
	    }

	  if (strcmp (person.Problem, "Diabetes") == 0)
	    {
	      system ("cls");
	      Diabetes1 ();
	    }


	  if (strcmp (person.Problem, "Heart") == 0)
	    {
	      system ("cls");
	      Heart_problem1 ();
	    }

	  fprintf (file, "%s %s %c %i %s %s %s %s %s\n", person.First_Name,
		   person.Last_Name, person.Gender, person.age,
		   person.Address, person.Phone_Number, person.Email,
		   person.Problem, person.Doctor_Name);

	  fclose (file);	//file is closed
	  // when appointment will successfully done then this section will work


	  Sleep (2000);
	  system ("cls");
	  rectangle_box();
	  printf
	    ("\n\n\n\n\n\n\n\n\t\t\t    Congratulations Your Appointment Is Made!!!!!\n\n");
	  Sleep (4000);
	  system ("cls");
	  Exit2 ();
	  getch ();


}while (!count);
}

// This function is for showing patient profile

      void patient_profile (void)
      {

	int row;
	system ("cls");
//	rectangle_box();
	FILE *ek;
	ek= fopen ("Patient File.txt", "r");

	printf
	  ("\t\t***************************** Patient profile ******************************");
	gotoxy (3, 5);
	printf ("Patient Name:");
	gotoxy (20, 5);
	printf ("Gender:");
	gotoxy (32, 5);
	printf ("Age:");
	gotoxy (37, 5);
	printf ("Address:");
	gotoxy (49, 5);
	printf ("Phone Number:");
	gotoxy (64, 5);
	printf ("Email:");
	gotoxy (88, 5);
	printf ("Problem:");
	gotoxy (100, 5);
	printf ("Doctor Name:");
	printf
	  ("\n==================================================================================================================");
	row = 7;

	while(fscanf
	       (ek, "%s %s %c %i %s %s %s %s %s\n", person.First_Name,
		   person.Last_Name, &person.Gender, &person.age,
		   person.Address, person.Phone_Number, person.Email,
		   person.Problem, person.Doctor_Name)!= EOF)
	  {

	    gotoxy (3, row);
	    printf ("%s %s", person.First_Name, person.Last_Name);
	    gotoxy (20, row);
	    printf ("%c", toupper(person.Gender));
	    gotoxy (32, row);
	    printf ("%i", person.age);
	    gotoxy (37, row);
	    printf ("%s", person.Address);
	    gotoxy (49, row);
	    printf ("%s ", person.Phone_Number);
	    gotoxy (64, row);
	    printf ("%s", person.Email);
	    gotoxy (88, row);
	    printf ("%s", person.Problem);
	    gotoxy (100, row);
	    printf ("%s", person.Doctor_Name);
	    row++;
	  }
	fclose(ek);
	printf("\n\n\tEnter any key: ");
	getch ();
	Sleep (2000);
	Exit2 ();


      }



//************************* Function For Search Appointment Record **************************

      void Search_patient_record (void)
      {
	char person_name[20];
	system ("cls");
//	rectangle_box();
	file = fopen ("Patient File.txt", "r");
	printf
	  ("\n\n\n\t\t\t\t  **************  Search Patients Appointments Record *****************\n\n");

	printf ("\n Enter Patient First Name to be viewed: ");
	scanf ("%s", person_name);
	fflush (stdin);
	person_name[0] = toupper (person_name[0]);

	while (fscanf
	       (file, "%s %s %c %i %s %s %s %s %s\n", person.First_Name,
		person.Last_Name, &person.Gender, &person.age, person.Address,
		person.Phone_Number, person.Email, person.Problem,
		person.Doctor_Name) != EOF)
	  {
	    if (strcmp (person.First_Name, person_name) == 0)
	      {
		gotoxy (5, 15);
		printf ("Patient Name:");
		gotoxy (25, 15);
		printf ("Gender:");
		gotoxy (32, 15);
		printf ("Age:");
		gotoxy (37, 15);
		printf ("Address:");
		gotoxy (52, 15);
		printf ("Phone Number:");
		gotoxy (64, 15);
		printf ("Email:");
		gotoxy (80, 15);
		printf ("Problem:");
		gotoxy (95, 15);
		printf ("Doctor Name:");
		printf
		  ("\n\t==========================================================================================================");

		gotoxy (3, 18);
		printf ("%s %s", person.First_Name, person.Last_Name);
		gotoxy (25, 18);
		printf ("%c", person.Gender);
		gotoxy (32, 18);
		printf ("%i", person.age);
		gotoxy (37, 18);
		printf ("%s", person.Address);
		gotoxy (52, 18);
		printf ("%s ", person.Phone_Number);
		gotoxy (64, 18);
		printf ("%s", person.Email);
		gotoxy (80, 18);
		printf ("%s", person.First_Name, person.Problem);
		gotoxy (90, 18);
		printf ("%s", person.Doctor_Name);
		printf ("\n");
		break;

	      }
	  }

	if (strcmp (person.First_Name, person_name) != 0)
	  {
	    gotoxy (5, 8);
	    printf ("Patient Appointment Record Not Found......");
	    getch ();
	  }

	fclose (file);

      L:
	getch ();
	gotoxy (20, 20);
	printf ("\n\n\t\t\tDo you want to view more ( y/ n )?? :");
	scanf ("%c", &result);

	if (toupper (result) == 'Y')
	  {
	    Search_patient_record ();

	  }
	else if (toupper (result) == 'N')
	  {
	    printf ("\n\t\t\t Thank You !!! \n");
	    getch ();
	    MainMenu ();
	  }
	else
	  {
	    printf ("\n\n\t\t\t Invalid Input !!!\n\n");
	    goto L;
	  }
      }

//***************************   Function for editing patient appointment *****************************************

void Edit_appointment (void)
{
    int valid = 0;
    char ch;
    char name[20];

    system ("cls");
//    rectangle_box();

    temporary_file = fopen ("temporary File.txt", "w+");
    file = fopen ("Patient File.txt", "r");


    if (file == NULL)
    {
        printf ("\n\t Can not open File!!!");
        getch ();
        MainMenu ();
    }

    printf("\n\n\n\t\t\t\t               Edit Patients Record \n");
            printf
    ("\t************************************************************************************************************\n");
      printf
    ("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    gotoxy (12, 13);
    printf ("Enter the First Name of The Patient : ");
    scanf ("%s", name);
    fflush (stdin);
    name[0] = toupper (name[0]);

    gotoxy (12, 15);
    if (temporary_file == NULL)
    {
        printf ("\n Can not open file");
        getch ();
        MainMenu ();
    }

    while (fscanf(file, "%s %s %c %i %s %s %s %s %s\n", person.First_Name, person.Last_Name, &person.Gender, &person.age, person.Address, person.Phone_Number, person.Email, person.Problem, person.Doctor_Name) != EOF)
    {

        if (strcmp (person.First_Name, name) == 0)
        {
            valid = 1;
//            gotoxy (25, 17);
            printf ("                                       Existing Record \n");
               printf
    ("\t************************************************************************************************************\n");
      printf
    ("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            gotoxy (10, 19);
            printf ("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s\n",
                person.First_Name, person.Last_Name, person.Gender,
                person.age, person.Address, person.Phone_Number,
                person.Email, person.Problem, person.Doctor_Name);

            gotoxy (12, 22);
            printf ("Enter New First Name: ");
            scanf ("%s", person.First_Name);

            gotoxy (12, 24);
            printf ("Enter New Last Name: ");
            scanf ("%s", person.Last_Name);

            gotoxy (12, 26);
            printf ("Enter Gender: ");
            scanf (" %c", &person.Gender);
            person.Gender = toupper (person.Gender);

            while (person.Gender != 'M' && person.Gender != 'F')
            {
                printf("\nInvalid input. Please enter M or F.\n");
                printf ("Enter Gender: ");
                scanf (" %c", &person.Gender);
                person.Gender = toupper (person.Gender);
            }

            gotoxy (12, 28);
            printf ("Enter Age: ");
            scanf ("%i", &person.age);

            gotoxy (12, 30);
            printf ("Enter Address: ");
            scanf ("%s", person.Address);
            person.Address[0] = toupper (person.Address[0]);

            gotoxy (12, 32);
            printf ("Enter Contact Number: ");
            scanf ("%s", person.Phone_Number);

            gotoxy (12, 34);
            printf ("Enter New Email: ");
            scanf ("%s", person.Email);

            gotoxy (12, 36);
            printf ("Enter Problem: ");
            scanf ("%s", person.Problem);
            person.Problem[0] = toupper (person.Problem[0]);

 gotoxy (12, 38);
		printf ("Enter Doctor: ");
		scanf ("%s", person.Doctor_Name);
		person.Doctor_Name[0] = toupper (person.Doctor_Name[0]);
		printf ("\nPress Y key for Updating Information:  ");
		ch = getche ();
		if (ch == 'y' || ch == 'y')
		  {
		    fprintf (temporary_file, "%s %s %c %i %s %s %s %s %s\n",
			     person.First_Name, person.Last_Name,
			     person.Gender, person.age, person.Address,
			     person.Phone_Number, person.Email,
			     person.Problem, person.Doctor_Name);
		    printf
		      ("\n\n\t\t\tPatient record updated successfully...");
		  }
	      }
	    else
	      {
		fprintf (temporary_file, "%s %s %c %i %s %s %s %s %s\n",
			 person.First_Name, person.Last_Name, person.Gender,
			 person.age, person.Address, person.Phone_Number,
			 person.Email, person.Problem, person.Doctor_Name);
	      }
	  }
	if (!valid)
	  {
	    gotoxy (5, 8);
	    printf ("No Record Is Found In This Name  !!!\n");
	  }
	fclose (temporary_file);
	fclose (file);
	remove ("Patient File.txt");
	rename ("temporary File.txt", "Patient File.txt");
	getch ();
	MainMenu ();
      }





// ***************************** Function For cancelling Patient Appointment *********************************    
      
      void Cancel_appointment ()
{
    char name[20];
    int found = 0;
    system ("cls");
//    rectangle_box();

    FILE* temporary_file = fopen ("temporary_File.txt", "w+");
    FILE* file = fopen ("Patient File.txt", "r");
    printf("\n\n\n\t\t\t  ***************** Cancel Appointment Record ************************");
    printf("\n\nEnter Patient Name To Cancel Appointment: ");
    fflush(stdin);
    gets(name);
    name[0] = toupper(name[0]);

    while (fscanf(file, "%s %s %c %i %s %s %s %s %s\n", person.First_Name,
            person.Last_Name, &person.Gender, &person.age, &person.Address,
            &person.Phone_Number, &person.Email, &person.Problem,
            &person.Doctor_Name) != EOF)
    {
        if (strcmp(person.First_Name, name) != 0)
        {
            fprintf(temporary_file, "%s %s %c %i %s %s %s %s %s\n",
                    person.First_Name, person.Last_Name, person.Gender,
                    person.age, person.Address, person.Phone_Number,
                    person.Email, person.Problem, person.Doctor_Name);
        }
        else
        {
            found = 1;
            printf("\n\n%s %s %c %i %s %s %s %s %s\n", person.First_Name,
                    person.Last_Name, person.Gender, person.age,
                    person.Address, person.Phone_Number, person.Email,
                    person.Problem, person.Doctor_Name);
        }
    }

    if (found == 0)
    {
        printf("No Record Found In This Name !!! \n");
        getch();
        MainMenu();
    }
    else
    {
        fclose(file);
        fclose(temporary_file);
        remove("Patient File.txt");
        rename("temporary_File.txt", "Patient File.txt");
        printf("\n\n\t\t\t Successfully Canceled The Appointment !!!");
        getch();
        MainMenu();
    }
}



//***************************************** This function is for exit screen ***********************/
 int Exit()
      {
	system ("cls");
	rectangle_box();
	printf
	  ("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tFor Visiting :D :D !!!!!!!!!\n\n");

	getch ();
	return 0;
      }

// This function is for exit screen and also asks for back main menu

      void Exit2 ()
      {
	system ("cls");
	rectangle_box();
	printf ("\n\n\n\t\t\tDo you want to go Back Main Menu ? ");
	printf ("\n\n\t\t\tPress ( y / n) : ");

	char ch;
	scanf("%s", &ch);
	switch (tolower (ch))
	  {
	  case 'y':
	    Sleep (1000);
	    Back1 ();
	    break;

	  case 'n':
	    system ("cls");
	    rectangle_box();
	    printf
	      ("\n\n\n\n\n\n\n\n\n\n\t\t\t\tFor Visiting :D :D !!!!!!!\n\n");
	    break;
}

      }

