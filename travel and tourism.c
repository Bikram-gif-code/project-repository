// header files...
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
// functions...
void Heading();
void Welcome();
void addPackage(); 
void viewPackages();
void updatePackage();
void deletePackage(); 
void menu();
				// structure of travelling package.
typedef struct travelpackage{
	int id;
	char firstname[20];
	char lastname[20];
	char password[20];
	char email[30];
	int number[15];
	char vehicles;
    char destination[50];
}Travelling_data;

int main(){
	char username[20];
	int password;        	
	
	
				// for wellcome interface.
	Welcome();	
	
				// User Authentication.
	printf("\n\n\n\t\tEnter your name:  ");
	scanf("%[^\n]%*c", username);
	printf("\n\t\tEnter login password:  ");
	scanf("%d",&password);
	if(password == 12345)			// Password is set as 12345.
	{
		printf("\n\n\n\t\t\t");
		printf("login successfull\n\n\tprocessing");
		int i;
		for(i=1; i<=3; i++){
			sleep(1);
			printf(".");
		}
		system("cls");
		menu(username);		// adding menu function...
	}
	else
	{
		int i;
		printf("\n\n\n\t\t\t");
		printf("Processing");
		for(i=1; i<=2; i++){
			sleep(1);
			printf(".");
		}
		printf("\n\n\n\t\t\t");
		printf("--- invalid password sorry ---");
		printf("\n\t\t");
		printf("press any key to exit ....");
		while(i<5){
			printf("\n");
			i++;
		}
	}
	return 0;
}

				// Wellcone interface.
void Welcome(){
	int i;
	printf("\n\t\t\t");
	for(i=1;i<10;i++){
		printf(".");
	}
	printf(" Wellcome to our Travel and Tourism management system ");
	for(i=1;i<10;i++){
		printf(".");
	}
}

				// headline of travel management system.
void Heading(){
	int n=1;
	printf("\n\t\t\t");
	while(n<79){
		printf("=");
		n++;
	}
	printf("\n\t\t\t");
	n=1;
	while(n<20){
		printf("*");
		n++;
	}
	printf(" [TRAVEL AND TOURISM MANAGEMENT SYSTEM] ");
	n=1;
	while(n<20){
		printf("*");
		n++;
	}
	n=1;
	printf("\n\t\t\t");
	while(n<79){
		printf("=");
		n++;
	}
}

				// menu options
void menu(char username[]) {
    int choice;
    system("cls");
       Heading();
        printf("\n\n\n\tHello %s",username);
        printf("\n\tPlease chose the following options.");
        printf("\n\n\t\t1. Add New Travel Package\n");
        printf("\t\t2. View All Travel Packages\n");
        printf("\t\t3. Update Travel Package\n");
        printf("\t\t4. Delete Travel Package\n");
        printf("\t\t5. Exit\n");
        printf("\n\tEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
        	case 1: addPackage(username); break;
        	case 5:	exit(0); break;
		}
}

				// adding package
void addPackage(char username[]) {
    Travelling_data pkg;
     FILE *file = fopen("Tourism.txt", "a");
    if(file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    int chose;
    char pass[20];
    system("cls");
    printf("\t\tEnter your first name:  ");
    scanf("%s", pkg.firstname);
    printf("\t\tEnter your last name:  ");
    scanf("%s", pkg.lastname);
    printf("\nEnter your password:  ");
    scanf("%s",pkg.password);
	printf("Enter your email:  ");
	scanf("%s", pkg.email);
	printf("Enter your number:  ");
	scanf("%d", pkg.number);
    printf("\n\t\tEnter destination: ");
    scanf("%s", pkg.destination);
    again:{
    	printf("Enter [1] for (add another package),   Enter [2] for (menu) and   Enter [3] for (exit).");
    	scanf("%d",&chose);
    	switch(chose){
    	case 1: addPackage(username); break;
    	case 2: menu(username); return;
    	case 3: exit(0);
    	defult: 
		printf("Invalid option ...! [retry]");
		goto again;
		}	
	}
	 fprintf(file, "%d %s %.2f %d\n", pkg.id, pkg.firstname, pkg.lastname, pkg.password, pkg.email, pkg.number pkg.destination);
    fclose(file);
    printf("\n\tPackage added successfully!\n");
}
