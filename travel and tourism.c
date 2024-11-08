// header files...
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// functions...
void Heading();
void Welcome();
void menu(char []);
void addPackage(char []); 
void viewPackages(char []);
void updatePackage(char []); 
void deletePackage(char []);


				// structure of travelling package.
typedef struct travelpackage{
	int id;
	char firstname[20];
	char lastname[20];
	char password[20];
	char email[40];
	int number[15];
    char destination[50];
    char vehicles;
}Travelling_data;

			// main() function...
int main(){
	char username[30];
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
		printf("login successfully\n\n\tprocessing");
		menu(username);		// adding menu function...
	}
	else
	{
		int i;
		printf("\n\n\n\t\t\t");
		printf("--- invalid password sorry ---");
		printf("\n\t\t");
		printf("  press any key to exit ....\n\n");
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
        printf("\n\tEnter your choice:");
        retry:
        printf("\n\t  >>  ");
        scanf("%d", &choice);
        switch(choice){
        	case 1: addPackage(username); break;
        	case 2: viewPackages(username); break;
        	case 3: updatePackage(username); break;
        	case 4: deletePackage(username); break;
        	case 5:	exit(0); break;
		}
		if(choice>5){
			printf("\n\tThe option is not here....! [retry]");
        	goto retry;
		}
}

				// adding package
void addPackage(char username[]) {
    Travelling_data pkg;
     FILE *file = fopen("Tourism.txt", "a+");
    if(file == NULL) {
        printf("Unable to open the file!\n");
        return;
    }
    int id;
    int chose;
    system("cls");
    Heading();
    retry:
    printf("\n\n\t\tEnter id for new package:  ");
    scanf("%d",&id);
    while(fscanf(file, "%d %s %s %s %s %d %s\n", &pkg.id, pkg.firstname, pkg.lastname, pkg.password, pkg.email, &pkg.number, pkg.destination) != EOF){
    	if(id == pkg.id){ 		
	printf("\t\t\t The ID has been already used. \n");
	printf("\t\t\t PLEASE TRY ANOTHER ID....");		
	goto retry;
		}else{
			pkg.id = id;
		}
	}
    printf("\t\tEnter your First name:  ");
    scanf("%s", pkg.firstname);
    printf("\t\tEnter your Last name:  ");
    scanf("%s", pkg.lastname);
    printf("\n\t\tEnter your Password:  ");
    scanf("%s",pkg.password);
	printf("\t\tEnter your Email:  ");
	scanf("%s", pkg.email);
	printf("\t\tEnter your Number:  ");
	scanf("%d", pkg.number);
    printf("\n\t\tEnter Destination: ");
    scanf("%s", pkg.destination);
    
	 fprintf(file, "%d %s %s %s %s %d %s\n",pkg.id, pkg.firstname, pkg.lastname, pkg.password, pkg.email, pkg.number, pkg.destination);
    fclose(file);
    printf("\n\tPackage added successfully!\n");
    again:
    	printf("Enter [1] for (add another package)       Enter [2] for (menu)        Enter [3] for (exit):");
    	printf("\n\t  >> ");
    	scanf("%d",&chose);
    	switch(chose){
    	case 1: addPackage(username); break;
    	case 2: menu(username); break;
    	case 3: exit(0);
    	}
    	if(chose < 3){
		printf("Invalid option ...! [retry]");
		goto again;
		}	
}

				// adding viewpackages() function...
void viewPackages(char username[]) {
    Travelling_data pkg;
    int chose;
    int display = 0;
    FILE *file = fopen("Tourism.txt", "r");
    if(file == NULL) {
        printf("\n\nUnable to open the file!\n");
    }
	system("cls");
    printf("\n\t\t\t===== All Traveling Packages =====\n\n");
    while(fscanf(file, "%d %s %s %s %s %d %s\n", &pkg.id, pkg.firstname, pkg.lastname, pkg.password, pkg.email, &pkg.number, pkg.destination) != EOF) {
    	printf("\n\tid:\t\t %d\n\tname: \t%s %s \n\tpassword: %s \n\temail:\t %s \n\tnumber: %d \n\tdestination: %s\n",pkg.id ,pkg.firstname, pkg.lastname, pkg.password, pkg.email, pkg.number, pkg.destination);
    	display++;
    }
    fclose(file);
    if(display == 0){
    	printf("\n\tNon of the record has been added.\n");
    	goto again;
	}
    fclose(file);
    again:{
    	printf("\n\n\tEnter [1] for (menu)        Enter [2] for (exit):");
    	printf("\n\t  >> ");
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
		printf("\n\t\tUnable to open the file!\n");
	}
	printf("\n\tEnter the id to update:  ");
	scanf("%d",&id);
	while(fscanf(file, "%d %s %s %s %s %d %s\n", &pkg.id, pkg.firstname, pkg.lastname, pkg.password, pkg.email, &pkg.number, pkg.destination) != EOF){
		if(pkg.id == id){
			printf("\n\tEnter the first name:  ");
			scanf("%s",pkg.firstname);
			printf("\n\tEnter the last name:  ");
			scanf("%s",pkg.lastname);
			printf("\n\tEnter the new password:  ");
			scanf("%s",pkg.password);
			printf("\n\tEnter the new email:  ");
			scanf("%s",pkg.email);
			printf("\n\tEnter the new number:  ");
			scanf("%d",&pkg.number);
			printf("\n\tEnter the new destination:  ");
			scanf("%s",pkg.destination);
		}
		fprintf(temp, "%d %s %s %s %s %d %s\n",pkg.id, pkg.firstname, pkg.lastname, pkg.password, pkg.email, pkg.number, pkg.destination);
	}
	fclose(file);
	fclose(temp);
	
	if(found){
		remove("Tourism.txt");
		rename("temp.txt", "Tourism.txt");
	}
	else{
		printf("Sorry!! Id not found...");
		remove("temp.txt");
	}
	again:
    	printf("\n\tEnter [1] for (menu)        Enter [2] for (exit):");
    	printf("\n\t  >> ");
    	scanf("%d",&chose);
    	switch(chose){
    	case 1: menu(username); return;
    	case 2: exit(0);
		}
	if(chose < 2){
		printf("Invalid option ...! [retry]");
		goto again;
	}
}

void deletePackage(char username[]){
	Travelling_data pkg;
	int id, found = 0, chose;
	FILE*file = fopen("Tourism.txt", "r");
	FILE*temp = fopen("temp.txt", "w");
	if(file == NULL || temp == NULL){
		printf("\n\t\tUnable to open the file!\n");
		return;
	}
	
	printf("\t\tEnter the id of package to delete:  ");
	scanf("%d",&id);
	
	while(fscanf(file, "%d %s %s %s %s %d %s\n", &pkg.id, pkg.firstname, pkg.lastname, pkg.password, pkg.email, &pkg.number, pkg.destination) != EOF){
		if(pkg.id != id){
			fprintf(temp, "%d %s %s %s %s %d %s\n", pkg.firstname, pkg.lastname, pkg.password, pkg.email, pkg.number, pkg.destination);
		}
		else{
			found = 1;
		}
	}
	
	fclose(file);
	fclose(temp);
	if(found){
		remove("Tourism.txt");
		rename("temp.txt", "Tourism.txt");
		printf("\n\t   ---Package removed successfully.---\n");
	}else{
		remove("temp.txt");
		printf("\n\t\tId not found.\n");
	}
    	printf("\n\tEnter [1] for (menu)        Enter [2] for (exit):");
    	again:{
    	printf("\n\t  >> ");
    	scanf("%d",&chose);
    	switch(chose){
    	case 1: menu(username); break;
    	case 2: exit(0);
    	}
		if(chose < 2){
			printf("\n\t   Invalid option ...! [retry]");
			goto again;
		}	
	}
}
