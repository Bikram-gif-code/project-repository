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
    char destination[50];
    char vehicles;
}Travelling_data;
			// main() function...
int main(){
	char username[20];
	int password;        	
	
	
				// for wellcome interface.
	Welcome();	
	
				// User Authentication.
	printf("\n\n\n\t\tEnter your name:  ");
	scanf("%[^\n]%*c", username);
	printf("\n\t\tEnter our login password:  ");
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
		menu(username);		// adding menu function...
	}
	else
	{
		int i;
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
        printf("\n\n\n\tHello, %s",username);
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
        	case 2: viewPackages(username); break;
        	case 3: updatePackage(); break;
        	case 4: deletePackage(); break;
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
    printf("Enter id for new package:  ");
    scanf("%d",&pkg.id);
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
	 fprintf(file, " %s %s %s %s %d %s\n", pkg.firstname, pkg.lastname, pkg.password, pkg.email, pkg.number, pkg.destination);
    fclose(file);
    	printf("Enter [1] for (add another package)       Enter [2] for (menu)        Enter [3] for (exit)");
    	scanf("%d",&chose);
    	switch(chose){
    	case 1: addPackage(username); break;
    	case 2: menu(username); break;
    	case 3: exit(0);
    	defult: 
		printf("Invalid option ...! [retry]");
		goto again;
		}	
	}
    printf("\n\tPackage added successfully!\n");
}

				// adding viewpackages() function...
void viewPackages(char username[]) {
    Travelling_data pkg;
    int chose;
    int display = 0;
    FILE *file = fopen("Tourism.txt", "r");
    if(file == NULL) {
        printf("Error opening file or file is empty!\n");
    }
	system("cls");
    printf("\n\t\t\t===== All Travel Packages =====\n");
    while(fscanf(file, "%d %s %s %s %s %d %s\n", pkg.id, pkg.firstname, pkg.lastname, pkg.password, pkg.email, pkg.number, pkg.destination) != EOF) {
    	printf("\n\tid: %d\tname: %s %s \n\tpassword: %s \n\temail: %s \n\tnumber: %d \n\tdestination: %s\n",pkg.id ,pkg.firstname, pkg.lastname, pkg.password, pkg.email, pkg.number, pkg.destination);
    	display++;
    }
    fclose(file);
    if(display == 0){
    	printf("Non of the record has been added.");
	}
    fclose(file);
    again:{
    	printf("Enter [1] for (menu)        Enter [2] for (exit)");
    	scanf("%d",&chose);
    	switch(chose){
    	case 1: menu(username); return;
    	case 2: exit(0);
    	defult: 
		printf("Invalid option ...! [retry]");
		goto again;
		}	
	}
}

				// adding updatePackage() function....
void updatePackage(char username[]){
	Travelling_data pkg;
	int id, chose ;
	int found = 0;
	FILE *file = fopen("Tourism.txt", "r");
	FILE *temp = fopen("temp.txt", "w");
	if(file == NULL || temp == NULL){
		printf("\n\t\tunable to open the file\n");
	}
	printf("Enter the id to update:  ");
	scanf("%d",&id);
	while(fscanf(file, "%d %s %s %s %s %d %s\n", pkg.firstname, pkg.lastname, pkg.password, pkg.email, pkg.number, pkg.destination) != EOF){
		if(pkg.id == id){
			printf("Enter the first name:  ");
			scanf("%s",pkg.firstname);
			printf("Enter the last name:  ");
			scanf("%s",pkg.lastname);
			printf("Enter the new password:  ");
			scanf("%s",pkg.password);
			printf("Enter the new email:  ");
			scanf("%s",pkg.email);
			printf("Enter the new number");
			scanf("%d",&pkg.number);
			printf("Enter the new destination");
			scanf("%s",pkg.destination);
		}
		fprintf(temp, "%d %s %s %s %s %d %s\n", pkg.firstname, pkg.lastname, pkg.password, pkg.email, pkg.number, pkg.destination);
	}
	fclose(file);
	fclose(temp);
	
	if(found){
		remove("Tourism.txt");
		rename("temp.txt", "Tourism");
	}
	else{
		printf("Sorry!! Id not found...");
		remove("temp.txt");
	}
	again:{
    	printf("Enter [1] for (menu)        Enter [2] for (exit)");
    	scanf("%d",&chose);
    	switch(chose){
    	case 1: menu(username); return;
    	case 2: exit(0);
    	defult: 
		printf("Invalid option ...! [retry]");
		goto again;
		}	
	}
}

void deletePackage(char username[]){
	Travelling_data pkg;
	int id, found = 0, chose;
	FILE*file = fopen("Traveling.txt", "r");
	FILE*temp = fopen("temp.txt", "w");
	if(file == NULL || temp == NULL){
		printf("\n\t\tUnable to open the file.\n");
		return;
	}
	while(fscanf(file, "%d %s %s %s %s %d %s\n", pkg.firstname, pkg.lastname, pkg.password, pkg.email, pkg.number, pkg.destination) != EOF){
		if(pkg.id != id){
			fprintf(temp, "%d %s %s %s %s %d %s\n", pkg.firstname, pkg.lastname, pkg.password, pkg.email, pkg.number, pkg.destination);
		}
		else{
			found = 1;
		}
	}
	if(found){
		remove("Traveling.txt");
		rename("temp.txt", "Traveling.txt");
		printf("\n---Package removed successfully.---\n");
	}else{
		remove("temp.txt");
		printf("\n\t\tId not found.\n");
	}
	again:{
    	printf("Enter [1] for (menu)        Enter [2] for (exit)");
    	scanf("%d",&chose);
    	switch(chose){
    	case 1: menu(username); return;
    	case 2: exit(0);
    	defult: 
		printf("Invalid option ...! [retry]");
		goto again;
		}	
	}
}
