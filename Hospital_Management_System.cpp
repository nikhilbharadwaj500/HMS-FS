//HEADER FILES
#include<stdio.h>//Use for standard I/O Operation
#include<windows.h>
#include<conio.h>//Use for delay(),getch(),gotoxy(),etc.
#include<ctype.h>//se for toupper(), tolower(),etc
#include<string.h>//Use for strcmp(),strcpy(),strlen(),etc
#include<stdlib.h>

char ans=0; 
int ok;
int b, valid=0;
//FUNCTION DECLERATION
void WelcomeScreen(void);//WelcomeScreen function decleration
void Title(void);//Title function decleration
void MainMenu(void);//MainMenu function decleration
void PatientMenu(void);//PaitentMenu function declaration
void DoctorMenu(void);//DoctorMenu function declaration
void NurseMenu(void);//NurseMenu function declaration
void ReciptMenu(void);//ReciptMenu function declaration
void LoginScreen(void);//LoginScreen function decleration
void Add_rec(void);//Add_rec function declaration
void func_list();//function to list the patient details 
void Search_rec(void);//Search_rec function declaration
void Edit_rec(void);//Edit_rec function declaration
void Dlt_rec(void);//Dlt_rec function declaration
void Add_Doctor(void);//Add_Doctor function declaration
void List_Doctor(void);//List_Doctor function declaration
void Search_Doctor(void);//Search_Doctor function declaration
void Edit_Doctor(void);//Edit_Doctor function declaration
void Delete_Doctor(void);//Delete_Doctor function declaration
void Add_Nurse(void);//Add_Nurse function declaration
void List_Nurse(void);//List_Nurse function declaration
void Search_Nurse(void);//Search_Nurse function declaration
void Edit_Nurse(void);//Edit_Nurse function declaration
void Delete_Nurse(void);//Delete_Nurse function declaration
void Add_Recipt(void);//Add_Recipt function declaration
void List_Recipt(void);//List_Recipt function declaration
void Search_Recipt(void);//Search_Recipt function declaration
void Edit_Recipt(void);//Edit_Recipt function declaration
void Delete_Recipt(void);//Delete_Recipt function declaration

void ex_it(void);//exit function declaration
//Defines gotoxy() for ANSI C compilers.
void gotoxy(short x, short y) {
COORD pos = {x, y};//sets co-ordinates in (x,y).
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

struct patient//list of global variable
{
	int age;
	char Gender;
	char First_Name[20];
	char Last_Name[20]; 
	char Contact_no[15];
	char Address[30];
	char Email[30];
	char Problem[20];
};

struct patient  p,temp_c;

struct doctor
{
	int age;
	char fname[20];
	char lname[20];
	char gender;
	char specialist[20];
	char phone[20];
	char email[30];
}d;

struct nurse
{
	int age;
	char gender;
	char fname[20];
	char lname[20];
	char phone[20];
	char email[20];
}n;

struct recipt
{
	int no;
	char p_fname[20];
	char p_lname[20];
	char d_fname[20];
	char d_lname[20];
	char cost[20];
}r;

main(void)
{
	
    WelcomeScreen();//Use to call WelcomeScreen function
    system("cls");
	Title();//Use to call Title function
	LoginScreen();//Use to call Menu function
}
/* ************************************************* Welcome Screen ********************************************* */
void WelcomeScreen(void) //function for welcome screen
{
	
	gotoxy(25,6);
	printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
	gotoxy(25,7);
	printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
	gotoxy(25,8);
	printf("        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	gotoxy(25,9);
	printf("        =                 WELCOME                   =");
	gotoxy(25,10);
	printf("        =                   TO                      =");
	gotoxy(25,11);
	printf("        =                  EWIT                     =");
	gotoxy(25,12);
	printf("        =                HOSPITAL                   =");
	gotoxy(25,13);
	printf("        =               MANAGEMENT                  =");
	gotoxy(25,14);
	printf("        =                 SYSTEM                    =");
	gotoxy(25,15);
	printf("        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	gotoxy(25,16);
	printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
	gotoxy(25,17);
	printf("  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
	gotoxy(28,22);
	printf(" Enter any key to continue.....");
	getch();
	
	
}
/* ************************************************* Title Screen ********************************************* */
void Title(void)//function for title screen
{
	printf("\n\n\t\t----------------------------------------------------------------------------------");
	printf("\n\t\t\t\t\t       EWIT  HOSPITAL         ");
	printf("\n\t\t----------------------------------------------------------------------------------");
}
/* ************************************************* Main Menu ********************************************* */
void MainMenu(void)//function decleration
{
	system("cls");
	int choose;
	Title();// call Title function
	printf("\n\n\n\n\n\t\t\t\t1. Patients Information\n");
	printf("\n\t\t\t\t2. Doctors Information\n");
	printf("\n\t\t\t\t3. Nurse Information\n");
	printf("\n\t\t\t\t4. Recipt\n");	
	printf("\n\t\t\t\t5. Exit\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 5:");
	scanf("%i", &choose);
	
	switch(choose)//switch to differeht case
	{
	
	case 1:
			PatientMenu();//PatientMenu function is called
    		break;
    case 2:
    		DoctorMenu();//DoctorMenu function is called
    		break;
	case 3: 
			NurseMenu();//Nurse_Menu function is call
    		break;
	case 4: 
			ReciptMenu();//Recipt_Menu function is call
    		break;

	case 5: 
			ex_it();//ex_it function is call
    		break;

	default:
		printf("\t\t\tInvalid entry. Please enter right option :)");
		getch();//holds screen
	}//end of switch
		
	
}

/* ************************************************* Patients Menu ********************************************* */
void PatientMenu(void)//function decleration
{
	system("cls");
	int choose;
	Title();// call Title function
	printf("\n\n \t\t\t\t\t PATIENTS INFORMATION ");
	printf("\n\n\n\n\n\t\t\t\t1. Add Patients Record\n");
	printf("\n\t\t\t\t2. List Patients Record\n");
	printf("\n\t\t\t\t3. Search Patients Record\n");
	printf("\n\t\t\t\t4. Edit Patients Record\n");
	printf("\n\t\t\t\t5. Delete Patients Record\n");
	printf("\n\t\t\t\t6. Back to Main Menu\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 6:");
	scanf("%i", &choose);
	
	switch(choose)//switch to differeht case
	{
	
	case 1:
			Add_rec();//Add_rec function is called
    		break;
    case 2:
    		func_list();//View_rec function is call
    		break;
	case 3:
			Search_rec();//Search_rec function is call
    		break;
	case 4:
			Edit_rec();//Edit_rec function is call
			break;
	case 5:
			Dlt_rec();//Dlt_rec function is call
			break;
	case 6:
			MainMenu();//MainMenu function is call
    		break;
	
	default:
		printf("\t\t\tInvalid entry. Please enter right option :)");
		getch();//holds screen
	}//end of switch
		
	
}
/* **************************************ADD PATIENTS*******************************************/

void Add_rec(void)
{
	system("cls");
	Title();// call Title function
	//list of variables
	char ans;
	FILE*ek;//file pointer
	ek=fopen("Record.txt","a");//open file in write mode
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Add Patients Record !!!!!!!!!!!!!\n");
	
	/* **************************First Name*********************************** */
	A:
	printf("\n\t\t\tFirst Name: ");
	scanf("%s",p.First_Name);
	p.First_Name[0]=toupper(p.First_Name[0]);
	if(strlen(p.First_Name)>20||strlen(p.First_Name)<2)
	{
		printf("\n\t Invalid :( \t The max range for first name is 20 and min range is 2 :)");
		goto A;
	}
	else
	{
		for (b=0;b<strlen(p.First_Name);b++)
		{
			if (isalpha(p.First_Name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t First name contain Invalid character :(  Enter again :)");
			goto A;
		}
	}
	
	/* ********************************************** Last name ************************************************ */
	
	printf("\n\t\t\tLast Name: ");
    scanf("%s",p.Last_Name);
    
/* ******************************************* Gender ************************************************************** */	    
	do
	{
	    printf("\n\t\t\tGender[F/M]: ");
		scanf(" %c",&p.Gender);
		if(toupper(p.Gender)=='M'|| toupper(p.Gender)=='F')
		{
			ok =1;
		}
		else 
		{
		ok =0;
		}
        if(!ok)
	    {
	    	printf("\n\t\t Gender contain Invalid character :(  Enter either F or M :)");
    	}
	 }	while(!ok);
/* ***************************************** Age ********************************************************************** */	
    printf("\n\t\t\tAge:");
    scanf(" %i",&p.age);
/* **************************************** Address ******************************************************************* */    
    do
    {
    C:
    printf("\n\t\t\tAddress: ");
    scanf("%s",p.Address);
    p.Address[0]=toupper(p.Address[0]);
    if(strlen(p.Address)>20||strlen(p.Address)<4)
	{
		printf("\n\t Invalid :( \t The max range for address is 20 and min range is 4 :)");
		goto C;
	}
	
}while(!valid);
/* ******************************************* Contact no. ***************************************** */
do
{
	D:
    printf("\n\t\t\tContact no: ");
    scanf("%s",p.Contact_no);
    if(strlen(p.Contact_no)>10||strlen(p.Contact_no)!=10)
	{
		printf("\n\t Sorry :( Invalid. Contact no. must contain 10 numbers. Enter again :)");
		goto D;
	}
	else
	{
		for (b=0;b<strlen(p.Contact_no);b++)
		{
			if (!isalpha(p.Contact_no[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Contact no. contain Invalid character :(  Enter again :)");
			goto D;
		}
	}
}while(!valid);
/* ************************************************** Email ******************************************** */
do
{
    printf("\n\t\t\tEmail: ");
    scanf("%s",p.Email);
    if (strlen(p.Email)>30||strlen(p.Email)<8)
    {
       printf("\n\t Invalid :( \t The max range for email is 30 and min range is 8 :)");	
	}
}while(strlen(p.Email)>30||strlen(p.Email)<8);
/* ********************************************************* Problem *********************************************** */
    E:
    printf("\n\t\t\tProblem: ");
    scanf("%s",p.Problem);
    p.Problem[0]=toupper(p.Problem[0]);
    if(strlen(p.Problem)>15||strlen(p.Problem)<3)
	{
		printf("\n\t Invalid :( \t The max range for first name is 15 and min range is 3 :)");
		goto E;
	}
	else
	{
		for (b=0;b<strlen(p.Problem);b++)
		{
			if (isalpha(p.Problem[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Problem contain Invalid character :(  Enter again :)");
			goto E;
		}
	}
    
    fprintf(ek," %s %s %c %i %s %s %s %s \n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    Add_Recipt();
    fclose(ek);//ek file is closed
    sd:
    getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
	{
    	Add_rec();
	}
    else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
    	getch();
    	PatientMenu();
	}
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto sd;
    }
}
/* **************************************VIEW PATIENTS*******************************************/
void func_list()
{
	int row;
	system("cls");
	Title();
	FILE *ek;
	ek=fopen("Record.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! List Patients Record !!!!!!!!!!!!!\n");
		gotoxy(1,15);
		printf("Full Name");
		gotoxy(20,15);
		printf("Gender");
		gotoxy(27,15);
		printf("Age");
		gotoxy(31,15);
		printf("Address");
		gotoxy(48,15);
		printf("Contact No.");
		gotoxy(60,15);
		printf("Email");
		gotoxy(90,15);
		printf("Problem");
		gotoxy(1,16);
		printf("=======================================================================================================================");
		row=17;
		while(fscanf(ek,"%s %s %c %i %s %s %s %s \n", p.First_Name, p.Last_Name,&p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem)!=EOF)
		{
			gotoxy(1,row);
			printf("%s %s",p.First_Name, p.Last_Name);
			gotoxy(20,row);
			printf("%c",p.Gender);
			gotoxy(27,row);
			printf("%i",p.age);
			gotoxy(31,row);
			printf("%s",p.Address);
			gotoxy(48,row);
			printf("%s",p.Contact_no);
			gotoxy(60,row);
			printf("%s",p.Email);
			gotoxy(90,row);
			printf("%s",p.Problem);
			row++;
		}
		fclose(ek);
		getch();
		PatientMenu();
}
/* **************************************SEARCH PATIENTS*******************************************/
void Search_rec(void)
{
	int row;
	char name[20];
	system("cls");
	Title();// call Title function
	FILE *ek;
	ek=fopen("Record.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Search Patients Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Patient Name to be viewed:");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	while(fscanf(ek,"%s %s %c %i %s %s %s %s \n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem)!=EOF)
	{
		if(strcmp(p.First_Name,name)==0)
		{
			gotoxy(1,15);
			printf("Full Name");
			gotoxy(20,15);
			printf("Gender");
			gotoxy(27,15);
			printf("Age");
			gotoxy(31,15);
			printf("Address");
			gotoxy(48,15);
			printf("Contact No.");
			gotoxy(60,15);
			printf("Email");
			gotoxy(90,15);
			printf("Problem");
			gotoxy(1,16);
			printf("=======================================================================================================================");
			row=17;
			gotoxy(1,row);
			printf("%s %s",p.First_Name, p.Last_Name);
			gotoxy(20,row);
			printf("%c",p.Gender);
			gotoxy(27,row);
			printf("%i",p.age);
			gotoxy(31,row);
			printf("%s",p.Address);
			gotoxy(48,row);
			printf("%s",p.Contact_no);
			gotoxy(60,row);
			printf("%s",p.Email);
			gotoxy(90,row);
			printf("%s",p.Problem);
			printf("\n");
			break;
		}
	   }
	   if(strcmp(p.First_Name,name)!=0)
	   {
		gotoxy(5,10);
		printf("Record not found!");
		getch();
	   }
	fclose(ek);
	L:
	getch();
	printf("\n\n\t\t\tDo you want to view more[Y/N]??");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        Search_rec();
    }
	else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
    	getch();
		PatientMenu();
    }
	else
    {
    	printf("\n\tInvalid Input.\n");
    	goto L;
    }
}
/* **************************************EDIT PATIENTS*******************************************/
void Edit_rec(void)
{
	FILE *ek, *ft;
  int i,b, valid=0;
  char ch;
  char name[20];

  system("cls");
  	Title();// call Title window
 		ft=fopen("temp2.dat","w+");
	   ek=fopen("Record.txt","r");
	   if(ek==NULL)
	   {
		printf("\n\t Can not open file!! ");
		getch();
		PatientMenu();
	   }
       	printf("\n\n\t\t\t!!!!!!!!!!!!!! Edit Patients Record !!!!!!!!!!!!!\n");
	   	gotoxy(12,13);
	   	printf("Enter the First Name of the Patient : ");
	   	scanf(" %s",name);
	   	fflush(stdin);
	   	name[0]=toupper(name[0]);
		gotoxy(12,15);
		
		if(ft==NULL)
		{
			printf("\n Can not open file");
			getch();
			PatientMenu();
		}
		while(fscanf(ek,"%s %s %c %i %s %s %s %s \n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem)!=EOF)
		{
			if(strcmp(p.First_Name, name)==0)
			{
				valid=1;
				gotoxy(25,17);
				printf("*** Existing Record ***");
				gotoxy(10,19);
				printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Contact_no,p.Email,p.Problem);
				gotoxy(12,22);	
				printf("Enter New First Name: ");
				scanf("%s",p.First_Name);    
				gotoxy(12,24);
				printf("Enter Last Name: ");
				scanf("%s",p.Last_Name);
				gotoxy(12,26);
				printf("Enter Gender: ");
				scanf(" %c",&p.Gender);
				p.Gender=toupper(p.Gender);
				gotoxy(12,28);
				printf("Enter age: ");
				scanf(" %i",&p.age);
				gotoxy(12,30);
				printf("Enter Address: ");
				scanf("%s",p.Address);
				p.Address[0]=toupper(p.Address[0]);
				gotoxy(12,32);
				printf("Enter Contact no: ");
				scanf("%s",p.Contact_no);
				gotoxy(12,34);
				printf("Enter New email: ");
				scanf("%s",p.Email);
			    gotoxy(12,36);
				printf("Enter Problem: ");
				scanf("%s",p.Problem);
				p.Problem[0]=toupper(p.Problem[0]);
	
			    printf("\nPress U charecter for the Updating operation : ");
				ch=getche();
				if(ch=='u' || ch=='U')
				{
				fprintf(ft,"%s %s %c %i %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Contact_no,p.Email,p.Problem);
				printf("\n\n\t\t\tPatient record updated successfully...");
				}					
			}
			else
			{
			fprintf(ft,"%s %s %c %i %s %s %s %s \n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Contact_no,p.Email,p.Problem);	
			}
		 }
		 if(!valid) printf("\n\t\tNO RECORD FOUND...");
	   fclose(ft);
	   fclose(ek);
	   remove("Record.txt");
   	   rename("temp2.dat","Record.txt");
		getch();
		PatientMenu();		
}
/* **************************************DELETE PATIENTS*******************************************/
void Dlt_rec()
{
	char name[20];
	int found=0;
	system("cls");
	Title();// call Title function
	FILE *ek, *ft;
	ft=fopen("temp.txt","w+");
	ek=fopen("Record.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Delete Patients Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Patient Name to delete: ");
	fflush(stdin);
	gets(name);
	name[0]=toupper(name[0]);
	
	while (fscanf(ek,"%s %s %c %i %s %s %s %s ", p.First_Name, p.Last_Name, &p.Gender,&p.age, p.Address, p.Contact_no, p.Email, p.Problem)!=EOF)
	{
		if (strcmp(p.First_Name,name)!=0)
		fprintf(ft,"%s %s %c %i %s %s %s %s \n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem);
		else 
		{
			printf("%s %s %c %i %s %s %s %s \n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem);
			found=1;
		}
	}//while loop ends
	if(found==0)
	{
		printf("\n\n\t\t\t Record not found....");
		getch();
		PatientMenu();
	}
	else
	{
		fclose(ek);
		fclose(ft);
		remove("Record.txt");
		rename("temp.txt","Record.txt");
		printf("\n\n\t\t\t Record deleted successfully :) ");
		getch();
		PatientMenu();
	}
}
/* ************************************************* Doctors Menu ********************************************* */
void DoctorMenu(void)//function decleration
{
	system("cls");
	int choose;
	Title();// call Title function
	printf("\n\n \t\t\t\t\t DOCTORS INFORMATION ");
	printf("\n\n\n\n\n\t\t\t\t1. Add Doctors\n");
	printf("\n\t\t\t\t2. List Doctors \n");
	printf("\n\t\t\t\t3. Search Doctors\n");
	printf("\n\t\t\t\t4. Edit Doctors Record\n");
	printf("\n\t\t\t\t5. Delete Doctors Record\n");
	printf("\n\t\t\t\t6. Back to Main Menu\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 6:");
	scanf("%i", &choose);
	
	switch(choose)//switch to differeht case
	{
	
	case 1:
			Add_Doctor();//Add_Doctor function is called
    		break;
    case 2:
    		List_Doctor();//List_Doctor function is called
    		break;
	case 3:
			Search_Doctor();//Search_Doctor function is call
    		break;
	case 4:
			Edit_Doctor();//Edit_Doctor function is call
			break;
	case 5:
			Delete_Doctor();//Delete_Doctor function is call
			break;
	case 6:
			MainMenu();//MainMenu function is call
    		break;

	default:
		printf("\t\t\tInvalid entry. Please enter right option :)");
		getch();//holds screen
	}//end of switch
		
	
}

/* **************************************ADD DOCTOR*******************************************/

void Add_Doctor(void)
{
	system("cls");
	Title();// call Title function
	//list of variables
	char ans;
	FILE*ek;//file pointer
	ek=fopen("doctor.txt","a");//open file in write mode
	printf("\n\n\t\t\t\t!!!!!!!!!!!!!! Add Doctor !!!!!!!!!!!!!\n");
	
	/* **************************First Name*********************************** */
	A:
	printf("\n\t\t\tFirst Name: ");
	scanf("%s",d.fname);
	d.fname[0]=toupper(d.fname[0]);
	if(strlen(d.fname)>20||strlen(d.fname)<2)
	{
		printf("\n\t Invalid :( \t The max range for first name is 20 and min range is 2 :)");
		goto A;
	}
	else
	{
		for (b=0;b<strlen(d.fname);b++)
		{
			if (isalpha(d.fname[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t First name contain Invalid character :(  Enter again :)");
			goto A;
		}
	}
	
	/* ********************************************** Last name ************************************************ */

	printf("\n\t\t\tLast Name: ");
    scanf("%s",d.lname);
   
/* ******************************************* Gender ************************************************************** */	    
	do
	{
	    printf("\n\t\t\tGender[F/M]: ");
		scanf(" %c",&d.gender);
		if(toupper(d.gender)=='M'|| toupper(d.gender)=='F')
		{
			ok =1;
		}
		else 
		{
		ok =0;
		}
        if(!ok)
	    {
	    	printf("\n\t\t Gender contain Invalid character :(  Enter either F or M :)");
    	}
	 }	while(!ok);
/* ***************************************** Age ********************************************************************** */	
    printf("\n\t\t\tAge:");
    scanf(" %i",&d.age);
/* **************************************** Specialization ******************************************************************* */    
    do
    {
    C:
    printf("\n\t\t\tSpecialization: ");
    scanf("%s",d.specialist);
    d.specialist[0]=toupper(d.specialist[0]);
    if(strlen(d.specialist)>20||strlen(d.specialist)<2)
	{
		printf("\n\t Invalid :( \t The max range for address is 20 and min range is 2 :)");
		goto C;
	}
	
}while(!valid);
/* ******************************************* Contact no. ***************************************** */
do
{
	D:
    printf("\n\t\t\tContact no: ");
    scanf("%s",d.phone);
    if(strlen(d.phone)>10||strlen(d.phone)!=10)
	{
		printf("\n\t Sorry :( Invalid. Contact no. must contain 10 numbers. Enter again :)");
		goto D;
	}
	else
	{
		for (b=0;b<strlen(d.phone);b++)
		{
			if (!isalpha(d.phone[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Contact no. contain Invalid character :(  Enter again :)");
			goto D;
		}
	}
}while(!valid);
/* ************************************************** Email ******************************************** */
do
{
    printf("\n\t\t\tEmail: ");
    scanf("%s",d.email);
    if (strlen(d.email)>30||strlen(d.email)<8)
    {
       printf("\n\t Invalid :( \t The max range for email is 30 and min range is 8 :)");	
	}
}while(strlen(d.email)>30||strlen(d.email)<8);
    
    fprintf(ek," %s %s %c %i %s %s %s \n",d.fname,d.lname,d.gender,d.age,d.specialist,d.phone,d.email);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(ek);//ek file is closed
    sd:
    getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
	{
    	Add_Doctor();
	}
    else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
    	getch();
    	DoctorMenu();
	}
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto sd;
    }
}

/* **************************************VIEW DOCTORS*******************************************/
void List_Doctor()
{
	int row;
	system("cls");
	Title();
	FILE *ek;
	ek=fopen("doctor.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! List Doctors !!!!!!!!!!!!!\n");
		gotoxy(1,15);
		printf("Full Name");
		gotoxy(21,15);
		printf("Gender");
		gotoxy(30,15);
		printf("Age");
		gotoxy(38,15);
		printf("Specialization");
		gotoxy(62,15);
		printf("Contact No.");
		gotoxy(78,15);
		printf("Email");
		gotoxy(1,16);
		printf("=======================================================================================================================");
		row=17;
		while(fscanf(ek,"%s %s %c %i %s %s %s \n",d.fname,d.lname,&d.gender,&d.age,d.specialist,d.phone,d.email)!=EOF)
		{
			gotoxy(1,row);
			printf("%s %s",d.fname,d.lname);
			gotoxy(21,row);
			printf("%c",d.gender);
			gotoxy(30,row);
			printf("%i",d.age);
			gotoxy(38,row);
			printf("%s",d.specialist);
			gotoxy(62,row);
			printf("%s",d.phone);
			gotoxy(78,row);
			printf("%s",d.email);
			row++;
		}
		fclose(ek);
		getch();
		DoctorMenu();
}

/* **************************************SEARCH DOCTORS*******************************************/
void Search_Doctor(void)
{
	int row;
	char name[20];
	system("cls");
	Title();// call Title function
	FILE *ek;
	ek=fopen("doctor.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Search Doctors !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Doctor Name to be searched:");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	while(fscanf(ek,"%s %s %c %i %s %s %s \n", d.fname,d.lname,&d.gender,&d.age,d.specialist,d.phone,d.email)!=EOF)
	{
		if(strcmp(d.fname,name)==0)
		{
			gotoxy(1,15);
			printf("Full Name");
			gotoxy(21,15);
			printf("Gender");
			gotoxy(30,15);
			printf("Age");
			gotoxy(38,15);
			printf("Specialization");
			gotoxy(62,15);
			printf("Contact No.");
			gotoxy(78,15);
			printf("Email");
			gotoxy(1,16);
			printf("=======================================================================================================================");
			row=17;
			gotoxy(1,row);
			printf("%s %s",d.fname,d.lname);
			gotoxy(21,row);
			printf("%c",d.gender);
			gotoxy(30,row);
			printf("%i",d.age);
			gotoxy(38,row);
			printf("%s",d.specialist);
			gotoxy(62,row);
			printf("%s",d.phone);
			gotoxy(78,row);
			printf("%s",d.email);
			printf("\n");
			break;
		}
	   }
	   if(strcmp(d.fname,name)!=0)
	   {
		gotoxy(5,10);
		printf("Record not found!");
		getch();
	   }
	fclose(ek);
	L:
	getch();
	printf("\n\n\t\t\tDo you want to Search more[Y/N]??");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        Search_Doctor();
    }
	else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
    	getch();
		DoctorMenu();
    }
	else
    {
    	printf("\n\tInvalid Input.\n");
    	goto L;
    }
}

/* **************************************EDIT DOCTORS*******************************************/
void Edit_Doctor(void)
{
	FILE *ek, *ft;
  int i,b, valid=0;
  char ch;
  char name[20];

  system("cls");
  	Title();// call Title window
 		ft=fopen("temp2.dat","w+");
	   ek=fopen("doctor.txt","r");
	   if(ek==NULL)
	   {
		printf("\n\t Can not open file!! ");
		getch();
		DoctorMenu();
	   }
       	printf("\n\n\t\t\t!!!!!!!!!!!!!! Edit Doctors Record !!!!!!!!!!!!!\n");
	   	gotoxy(12,13);
	   	printf("Enter the First Name of the Doctor : ");
	   	scanf(" %s",name);
	   	fflush(stdin);
	   	name[0]=toupper(name[0]);
		gotoxy(12,15);
		
		if(ft==NULL)
		{
			printf("\n Can not open file");
			getch();
			DoctorMenu();
		}
		while(fscanf(ek,"%s %s %c %i %s %s %s \n",d.fname,d.lname,&d.gender,&d.age,d.specialist,d.phone,d.email)!=EOF)
		{
			if(strcmp(d.fname, name)==0)
			{
				valid=1;
				gotoxy(25,17);
				printf("*** Existing Record ***");
				gotoxy(10,19);
				printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \n",d.fname,d.lname,d.gender,d.age,d.specialist,d.phone,d.email);
				gotoxy(12,22);	
				printf("Enter New First Name: ");
				scanf("%s",d.fname);    
				gotoxy(12,24);
				printf("Enter Last Name: ");
				scanf("%s",d.lname);
				gotoxy(12,26);
				printf("Enter Gender: ");
				scanf(" %c",&d.gender);
				p.Gender=toupper(p.Gender);
				gotoxy(12,28);
				printf("Enter age: ");
				scanf(" %i",&d.age);
				gotoxy(12,30);
				printf("Enter Specialization: ");
				scanf("%s",d.specialist);
				d.specialist[0]=toupper(d.specialist[0]);
				gotoxy(12,32);
				printf("Enter Contact no: ");
				scanf("%s",d.phone);
				gotoxy(12,34);
				printf("Enter New email: ");
				scanf("%s",d.email);
			    printf("\nPress U charecter for the Updating operation : ");
				ch=getche();
				if(ch=='u' || ch=='U')
				{
				fprintf(ft,"%s %s %c %i %s %s %s \n",d.fname,d.lname,d.gender,d.age,d.specialist,d.phone,d.email);
				printf("\n\n\t\t\tInformation updated successfully...");
				}					
			}
			else
			{
			fprintf(ft,"%s %s %c %i %s %s %s \n",d.fname,d.lname,d.gender,d.age,d.specialist,d.phone,d.email);	
			}
		 }
		 if(!valid) printf("\n\t\tNO RECORD FOUND...");
	   fclose(ft);
	   fclose(ek);
	   remove("doctor.txt");
   	   rename("temp2.dat","doctor.txt");
		getch();
		DoctorMenu();		
}

/* **************************************DELETE DOCTORS*******************************************/
void Delete_Doctor()
{
	char name[20];
	int found=0;
	system("cls");
	Title();// call Title function
	FILE *ek, *ft;
	ft=fopen("temp.txt","w+");
	ek=fopen("doctor.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Delete Doctors Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Doctor Name to delete: ");
	fflush(stdin);
	gets(name);
	name[0]=toupper(name[0]);
	
	while (fscanf(ek,"%s %s %c %i %s %s %s ",d.fname,d.lname,&d.gender,&d.age,d.specialist,d.phone,d.email)!=EOF)
	{
		if (strcmp(d.fname,name)!=0)
		fprintf(ft,"%s %s %c %i %s %s %s ",d.fname,d.lname,d.gender,d.age,d.specialist,d.phone,d.email);
		else 
		{
			printf("%s %s %c %i %s %s %s ",d.fname,d.lname,d.gender,d.age,d.specialist,d.phone,d.email);
			found=1;
		}
	}//while loop ends
	if(found==0)
	{
		printf("\n\n\t\t\t Record not found....");
		getch();
		DoctorMenu();
	}
	else
	{
		fclose(ek);
		fclose(ft);
		remove("doctor.txt");
		rename("temp.txt","doctor.txt");
		printf("\n\n\t\t\t Record deleted successfully :) ");
		getch();
		DoctorMenu();
	}
}

/* ************************************************* Nurse Menu ********************************************* */
void NurseMenu(void)//function decleration
{
	system("cls");
	int choose;
	Title();// call Title function
	printf("\n\n \t\t\t\t\t NURSE INFORMATION ");
	printf("\n\n\n\n\n\t\t\t\t1. Add Nurse Record\n");
	printf("\n\t\t\t\t2. List Nurse Record\n");
	printf("\n\t\t\t\t3. Search Nurse Record\n");
	printf("\n\t\t\t\t4. Edit Nurse Record\n");
	printf("\n\t\t\t\t5. Delete Nurse Record\n");
	printf("\n\t\t\t\t6. Back to Main Menu\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 6:");
	scanf("%i", &choose);
	
	switch(choose)//switch to differeht case
	{
	
	case 1:
			Add_Nurse();//Add_Nurse function is called
    		break;
    case 2:
    		List_Nurse();//View_Nurse function is call
    		break;
	case 3:
			Search_Nurse();//Search_Nurse function is call
    		break;
	case 4:
			Edit_Nurse();//Edit_Nurse function is call
			break;
	case 5:
			Delete_Nurse();//Delete_Nurse function is call
			break;
	case 6:
			MainMenu();//MainMenu function is call
    		break;
	
	default:
		printf("\t\t\tInvalid entry. Please enter right option :)");
		getch();//holds screen
	}//end of switch
		
	
}
/* **************************************ADD NURSE*******************************************/

void Add_Nurse(void)
{
	system("cls");
	Title();// call Title function
	//list of variables
	char ans;
	FILE*ek;//file pointer
	ek=fopen("nurse.txt","a");//open file in write mode
	printf("\n\n\t\t\t\t!!!!!!!!!!!!!! Add Nurse !!!!!!!!!!!!!\n");
	
	/* **************************First Name*********************************** */
	A:
	printf("\n\t\t\tFirst Name: ");
	scanf("%s",n.fname);
	n.fname[0]=toupper(n.fname[0]);
	if(strlen(n.fname)>20||strlen(n.fname)<2)
	{
		printf("\n\t Invalid :( \t The max range for first name is 20 and min range is 2 :)");
		goto A;
	}
	else
	{
		for (b=0;b<strlen(n.fname);b++)
		{
			if (isalpha(n.fname[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t First name contain Invalid character :(  Enter again :)");
			goto A;
		}
	}
	
	/* ********************************************** Last name ************************************************ */

	printf("\n\t\t\tLast Name: ");
    scanf("%s",n.lname);
   
/* ******************************************* Gender ************************************************************** */	    
	do
	{
	    printf("\n\t\t\tGender[F/M]: ");
		scanf(" %c",&n.gender);
		if(toupper(n.gender)=='M'|| toupper(n.gender)=='F')
		{
			ok =1;
		}
		else 
		{
		ok =0;
		}
        if(!ok)
	    {
	    	printf("\n\t\t Gender contain Invalid character :(  Enter either F or M :)");
    	}
	 }	while(!ok);
/* ***************************************** Age ********************************************************************** */	
    printf("\n\t\t\tAge:");
    scanf(" %i",&n.age);
/* ******************************************* Contact no. ***************************************** */
do
{
	D:
    printf("\n\t\t\tContact no: ");
    scanf("%s",n.phone);
    if(strlen(n.phone)>10||strlen(n.phone)!=10)
	{
		printf("\n\t Sorry :( Invalid. Contact no. must contain 10 numbers. Enter again :)");
		goto D;
	}
	else
	{
		for (b=0;b<strlen(n.phone);b++)
		{
			if (!isalpha(n.phone[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Contact no. contain Invalid character :(  Enter again :)");
			goto D;
		}
	}
}while(!valid);
/* ************************************************** Email ******************************************** */
do
{
    printf("\n\t\t\tEmail: ");
    scanf("%s",n.email);
    if (strlen(n.email)>30||strlen(n.email)<8)
    {
       printf("\n\t Invalid :( \t The max range for email is 30 and min range is 8 :)");	
	}
}while(strlen(n.email)>30||strlen(n.email)<8);
    
    fprintf(ek," %s %s %c %i %s %s  \n",n.fname,n.lname,n.gender,n.age,n.phone,n.email);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(ek);//ek file is closed
    sd:
    getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
	{
    	Add_Nurse();
	}
    else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
    	getch();
    	NurseMenu();
	}
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto sd;
    }
}

/* **************************************VIEW NURSE*******************************************/
void List_Nurse()
{
	int row;
	system("cls");
	Title();
	FILE *ek;
	ek=fopen("nurse.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! List Nurse !!!!!!!!!!!!!\n");
		gotoxy(1,15);
		printf("Full Name");
		gotoxy(21,15);
		printf("Gender");
		gotoxy(30,15);
		printf("Age");
		gotoxy(50,15);
		printf("Contact No.");
		gotoxy(65,15);
		printf("Email");
		gotoxy(1,16);
		printf("=======================================================================================================================");
		row=17;
		while(fscanf(ek,"%s %s %c %i %s %s  \n",n.fname,n.lname,&n.gender,&n.age,n.phone,n.email)!=EOF)
		{
			gotoxy(1,row);
			printf("%s %s",n.fname,n.lname);
			gotoxy(21,row);
			printf("%c",n.gender);
			gotoxy(30,row);
			printf("%i",n.age);
			gotoxy(50,row);
			printf("%s",n.phone);
			gotoxy(65,row);
			printf("%s",n.email);
			row++;
		}
		fclose(ek);
		getch();
		NurseMenu();
}

/* **************************************SEARCH NURSE*******************************************/
void Search_Nurse(void)
{
	int row;
	char name[20];
	system("cls");
	Title();// call Title function
	FILE *ek;
	ek=fopen("nurse.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Search Nurse !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Nurse Name to be searched:");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	while(fscanf(ek,"%s %s %c %i %s %s  \n", n.fname,n.lname,&n.gender,&n.age,n.phone,n.email)!=EOF)
	{
		if(strcmp(n.fname,name)==0)
		{
			gotoxy(1,15);
			printf("Full Name");
			gotoxy(21,15);
			printf("Gender");
			gotoxy(30,15);
			printf("Age");
			gotoxy(50,15);
			printf("Contact No.");
			gotoxy(65,15);
			printf("Email");
			gotoxy(1,16);
			printf("=======================================================================================================================");
			row=17;
			gotoxy(1,row);
			printf("%s %s",n.fname,n.lname);
			gotoxy(21,row);
			printf("%c",n.gender);
			gotoxy(30,row);
			printf("%i",n.age);
			gotoxy(50,row);
			printf("%s",n.phone);
			gotoxy(65,row);
			printf("%s",n.email);
			printf("\n");
			break;
		}
	   }
	   if(strcmp(n.fname,name)!=0)
	   {
		gotoxy(5,10);
		printf("Record not found!");
		getch();
	   }
	fclose(ek);
	L:
	getch();
	printf("\n\n\t\t\tDo you want to Search more[Y/N]??");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        Search_Nurse();
    }
	else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
    	getch();
		NurseMenu();
    }
	else
    {
    	printf("\n\tInvalid Input.\n");
    	goto L;
    }
}

/* **************************************EDIT NURSE*******************************************/
void Edit_Nurse(void)
{
	FILE *ek, *ft;
  int i,b, valid=0;
  char ch;
  char name[20];

  system("cls");
  	Title();// call Title window
 		ft=fopen("temp2.dat","w+");
	   ek=fopen("nurse.txt","r");
	   if(ek==NULL)
	   {
		printf("\n\t Can not open file!! ");
		getch();
		NurseMenu();
	   }
       	printf("\n\n\t\t\t!!!!!!!!!!!!!! Edit Nurse Record !!!!!!!!!!!!!\n");
	   	gotoxy(12,13);
	   	printf("Enter the First Name of the Nurse : ");
	   	scanf(" %s",name);
	   	fflush(stdin);
	   	name[0]=toupper(name[0]);
		gotoxy(12,15);
		
		if(ft==NULL)
		{
			printf("\n Can not open file");
			getch();
			NurseMenu();
		}
		while(fscanf(ek,"%s %s %c %i %s %s  \n",n.fname,n.lname,&n.gender,&n.age,n.phone,n.email)!=EOF)
		{
			if(strcmp(n.fname, name)==0)
			{
				valid=1;
				gotoxy(25,17);
				printf("*** Existing Record ***");
				gotoxy(10,19);
				printf("%s \t%s \t%c \t%i \t%s \t%s  \n",n.fname,n.lname,n.gender,n.age,n.phone,n.email);
				gotoxy(12,22);	
				printf("Enter New First Name: ");
				scanf("%s",n.fname);    
				gotoxy(12,24);
				printf("Enter Last Name: ");
				scanf("%s",n.lname);
				gotoxy(12,26);
				printf("Enter Gender: ");
				scanf(" %c",&n.gender);
				n.gender=toupper(n.gender);
				gotoxy(12,28);
				printf("Enter age: ");
				scanf(" %i",&n.age);
				gotoxy(12,30);
				printf("Enter Contact no: ");
				scanf("%s",n.phone);
				gotoxy(12,32);
				printf("Enter New email: ");
				scanf("%s",n.email);
			    printf("\nPress U charecter for the Updating operation : ");
				ch=getche();
				if(ch=='u' || ch=='U')
				{
				fprintf(ft,"%s %s %c %i %s %s  \n",n.fname,n.lname,n.gender,n.age,n.phone,n.email);
				printf("\n\n\t\t\tInformation updated successfully...");
				}					
			}
			else
			{
			fprintf(ft,"%s %s %c %i %s %s  \n",n.fname,n.lname,n.gender,n.age,n.phone,n.email);	
			}
		 }
		 if(!valid) printf("\n\t\tNO RECORD FOUND...");
	   fclose(ft);
	   fclose(ek);
	   remove("nurse.txt");
   	   rename("temp2.dat","nurse.txt");
		getch();
		NurseMenu();		
}

/* **************************************DELETE NURSE*******************************************/
void Delete_Nurse()
{
	char name[20];
	int found=0;
	system("cls");
	Title();// call Title function
	FILE *ek, *ft;
	ft=fopen("temp.txt","w+");
	ek=fopen("nurse.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Delete Nurse Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Nurse Name to delete: ");
	fflush(stdin);
	gets(name);
	name[0]=toupper(name[0]);
	
	while (fscanf(ek,"%s %s %c %i %s %s  ",n.fname,n.lname,&n.gender,&n.age,n.phone,n.email)!=EOF)
	{
		if (strcmp(n.fname,name)!=0)
		fprintf(ft,"%s %s %c %i %s %s  ",n.fname,n.lname,n.gender,n.age,n.phone,n.email);
		else 
		{
			printf("%s %s %c %i %s %s  ",n.fname,n.lname,n.gender,n.age,n.phone,n.email);
			found=1;
		}
	}//while loop ends
	if(found==0)
	{
		printf("\n\n\t\t\t Record not found....");
		getch();
		NurseMenu();
	}
	else
	{
		fclose(ek);
		fclose(ft);
		remove("nurse.txt");
		rename("temp.txt","nurse.txt");
		printf("\n\n\t\t\t Record deleted successfully :) ");
		getch();
		NurseMenu();
	}
}

/* ************************************************* RECIPT Menu ********************************************* */
void ReciptMenu(void)//function decleration
{
	system("cls");
	int choose;
	Title();// call Title function
	printf("\n\n \t\t\t\t\t RECEIPT INFORMATION ");
	printf("\n\n\n\n\n\t\t\t\t1. List Receipt Record\n");
	printf("\n\t\t\t\t2. Search Receipt Record\n");
	printf("\n\t\t\t\t3. Delete Receipt Record\n");
	printf("\n\t\t\t\t4. Back to Main Menu\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 4:");
	scanf("%i", &choose);
	
	switch(choose)//switch to differeht case
	{
	
    case 1:
    		List_Recipt();//View_Recipt function is call
    		break;
	case 2:
			Search_Recipt();//Search_Recipt function is call
    		break;
	case 3:
			Delete_Recipt();//Delete_Recipt function is call
			break;
	case 4:
			MainMenu();//MainMenu function is call
    		break;
	
	default:
		printf("\t\t\tInvalid entry. Please enter right option :)");
		getch();//holds screen
	}//end of switch
		
	
}
/* **************************************ADD RECIPT*******************************************/

void Add_Recipt(void)
{
	system("cls");
	Title();// call Title function
	//list of variables
	char ans;
	FILE*ek;//file pointer
	ek=fopen("receipt.txt","a");//open file in write mode
	printf("\n\n\t\t\t\t!!!!!!!!!!!!!! Add Receipt !!!!!!!!!!!!!\n");
	
/* ***************************************** Receipt No. ********************************************************************** */	
    printf("\n\t\t\tReceipt Number:");
    scanf(" %i",&r.no);
/* ****************************************Patient First Name ************************************************************************ */
	A:
	printf("\n\t\t\tPatients First Name: ");
	scanf("%s",r.p_fname);
	r.p_fname[0]=toupper(r.p_fname[0]);
	if(strlen(r.p_fname)>20||strlen(r.p_fname)<2)
	{
		printf("\n\t Invalid :( \t The max range for first name is 20 and min range is 2 :)");
		goto A;
	}
	else
	{
		for (b=0;b<strlen(r.p_fname);b++)
		{
			if (isalpha(r.p_fname[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t First name contain Invalid character :(  Enter again :)");
			goto A;
		}
	}
/* **********************************************Patients Last name ************************************************ */

	printf("\n\t\t\tPatients Last Name: ");
    scanf("%s",r.p_lname);

/* ****************************************Doctors First Name ************************************************************************ */
	B:
	printf("\n\t\t\tDoctors First Name: ");
	scanf("%s",r.d_fname);
	r.d_fname[0]=toupper(r.d_fname[0]);
	if(strlen(r.d_fname)>20||strlen(r.d_fname)<2)
	{
		printf("\n\t Invalid :( \t The max range for first name is 20 and min range is 2 :)");
		goto B;
	}
	else
	{
		for (b=0;b<strlen(r.d_fname);b++)
		{
			if (isalpha(r.d_fname[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t First name contain Invalid character :(  Enter again :)");
			goto B;
		}
	}
/* **********************************************Doctors Last name ************************************************ */

	printf("\n\t\t\tDoctors Last Name: ");
    scanf("%s",r.d_lname);
   
/* ************************************************** Cost ******************************************** */
do
{
    printf("\n\t\t\tCost: ");
    scanf("%s",r.cost);
    if (strlen(r.cost)>8||strlen(r.cost)<2)
    {
       printf("\n\t Invalid :( \t The max range for cost is 8 and min range is 2 :)");	
	}
}while(strlen(r.cost)>8||strlen(r.cost)<2);
    
    fprintf(ek," %i %s %s %s %s %s  \n",r.no,r.p_fname,r.p_lname,r.d_fname,r.d_lname,r.cost);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(ek);//ek file is closed
    sd:
    getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
	{
    	Add_Recipt();
	}
    else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
    	getch();
    	ReciptMenu();
	}
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto sd;
    }
}

/* **************************************VIEW RECIPT*******************************************/
void List_Recipt()
{
	int row;
	system("cls");
	Title();
	FILE *ek;
	ek=fopen("receipt.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! List Receipt !!!!!!!!!!!!!\n");
		gotoxy(1,15);
		printf("Receipt No.");
		gotoxy(20,15);
		printf("Patient Name");
		gotoxy(50,15);
		printf("Doctor Name");
		gotoxy(80,15);
		printf("Cost");
		gotoxy(1,16);
		printf("=======================================================================================================================");
		row=17;
		while(fscanf(ek,"%i %s %s %s %s %s  \n",&r.no,r.p_fname,r.p_lname,r.d_fname,r.d_lname,r.cost)!=EOF)
		{
			gotoxy(1,row);
			printf("%i",r.no);
			gotoxy(20,row);
			printf("%s %s",r.p_fname,r.p_lname);
			gotoxy(50,row);
			printf("%s %s",r.d_fname,r.d_lname);
			gotoxy(80,row);
			printf("%s",r.cost);
			row++;
		}
		fclose(ek);
		getch();
		ReciptMenu();
}

/* **************************************SEARCH RECIPT*******************************************/
void Search_Recipt(void)
{
	int row;
	char name[20];
	system("cls");
	Title();// call Title function
	FILE *ek;
	ek=fopen("receipt.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Search Receipt !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Patient Name to be searched:");
	scanf("%s",name);
	fflush(stdin);
	name[0]=toupper(name[0]);
	while(fscanf(ek,"%i %s %s %s %s %s  \n",&r.no,r.p_fname,r.p_lname,r.d_fname,r.d_lname,r.cost)!=EOF)
	{
		if(strcmp(r.p_fname,name)==0)
		{
			gotoxy(1,15);
			printf("Receipt No.");
			gotoxy(20,15);
			printf("Patient Name");
			gotoxy(50,15);
			printf("Doctor Name");
			gotoxy(80,15);
			printf("Cost");
			gotoxy(1,16);
			printf("=======================================================================================================================");
			row=17;
			gotoxy(1,row);
			printf("%i",r.no);
			gotoxy(20,row);
			printf("%s %s",r.p_fname,r.p_lname);
			gotoxy(50,row);
			printf("%s %s",r.d_fname,r.d_lname);
			gotoxy(80,row);
			printf("%s",r.cost);
			printf("\n");
			break;
		}
	   }
	   if(strcmp(r.p_fname,name)!=0)
	   {
		gotoxy(5,10);
		printf("Record not found!");
		getch();
	   }
	fclose(ek);
	L:
	getch();
	printf("\n\n\t\t\tDo you want to Search more[Y/N]??");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        Search_Recipt();
    }
	else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
    	getch();
		ReciptMenu();
    }
	else
    {
    	printf("\n\tInvalid Input.\n");
    	goto L;
    }
}


/* **************************************DELETE RECIPT*******************************************/
void Delete_Recipt()
{
	char name[20];
	int found=0;
	system("cls");
	Title();// call Title function
	FILE *ek, *ft;
	ft=fopen("temp.txt","w+");
	ek=fopen("receipt.txt","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Delete Receipt Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("\n Enter Patient Name to delete: ");
	fflush(stdin);
	gets(name);
	name[0]=toupper(name[0]);
	
	while (fscanf(ek,"%i %s %s %s %s %s  \n",&r.no,r.p_fname,r.p_lname,r.d_fname,r.d_lname,r.cost)!=EOF)
	{
		if (strcmp(r.p_fname,name)!=0)
		fprintf(ft,"%i %s %s %s %s %s  \n",r.no,r.p_fname,r.p_lname,r.d_fname,r.d_lname,r.cost);
		else 
		{
			printf("%i %s %s %s %s %s  \n",r.no,r.p_fname,r.p_lname,r.d_fname,r.d_lname,r.cost);
			found=1;
		}
	}//while loop ends
	if(found==0)
	{
		printf("\n\n\t\t\t Record not found....");
		getch();
		ReciptMenu();
	}
	else
	{
		fclose(ek);
		fclose(ft);
		remove("receipt.txt");
		rename("temp.txt","receipt.txt");
		printf("\n\n\t\t\t Record deleted successfully :) ");
		getch();
		ReciptMenu();
	}
}

/* ************************************************* Exit Screen ********************************************* */
void ex_it(void)//function to exit
{
	system("cls");
	Title();// call Title function
	printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING :)");
	getch();//holds screen
	
}
/* ************************************************* Login Screen ********************************************* */
void LoginScreen(void)//function for login screen
{
//list of variables	
int e=0,i=0;
char Username[15];
char Password[15];
char c=' ';
char original_Username[25]="ewit";
char original_Password[15]="ewit";

do
{
	printf("\n\n\n\n\t\t\t\tEnter your Username and Password :)");
	printf("\n\n\n\t\t\t\t\tUSERNAME:");
	scanf("%s",&Username);
	
	printf("\n\n\t\t\t\t\tPASSWORD:");
		while(i<10)
	{
	    Password[i]=getch();
	    c=Password[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	Password[i]='\0';
	
	if (strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0)
	{
		printf("\n\n\n\t\t\t\t\t...Login Successfull...");
		
		
		getch();
		MainMenu();//call MainMenu function
		break;
	}
	else
	{
		printf("\n\t\t\tPassword in incorrect:( Try Again :)");
		system("cls");
		LoginScreen();
		e++;
		getch();
	}

}
while(e<=2);
	if(e>2)
	{
	printf("You have cross the limit. You cannot login. :( :(");
	getch();
    ex_it();
	}
 
system("cls");
}



 
