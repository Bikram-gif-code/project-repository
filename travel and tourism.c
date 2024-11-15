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
	long int number;
    char destination[50];
    char vehicles[10];
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
        printf("\n  ->\t");
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
    int vehicles;
     FILE *file = fopen("Tourism.txt", "a+");
     system("cls");
     
    if(file == NULL) {
    	printf("\n\t\t\t===== add travelling Package =====\n\n");
        printf("\tUnable to open the file!\n");
        return;
    }
    int id;
    int chose;
    Heading();
    retry:
    	fseek(file, 0 ,SEEK_SET);  //reset the file pointer to the beginning.
    printf("\n\n\t\tEnter id for new package:  ");
    scanf("%d",&id);
    while(fscanf(file, "%d %s %s %s %s %ld %s %s\n", &pkg.id, pkg.firstname, pkg.lastname, pkg.password, pkg.email, pkg.number, pkg.destination, pkg.vehicles) != EOF){
    	if(pkg.id == id){ 		
	printf("\t\t\t The ID has been already used. \n");
	printf("\t\t\t PLEASE TRY ANOTHER ID....");		
	goto retry;
		}else{
			pkg.id = id;
		}
	}
    printf("\n\t\tEnter your First name:  ");
    scanf("%s", pkg.firstname);
    printf("\t\tEnter your Last name:  ");
    scanf("%s", pkg.lastname);
    printf("\n\t\tEnter your Password:  ");
    scanf("%s",pkg.password);
	printf("\n\t\tEnter your Email:  ");
	scanf("%s", pkg.email);
	printf("\n\t\tEnter your Number:  ");
	scanf("%ld", &pkg.number);
    printf("\n\t\tEnter your Destination: ");
    scanf("%s", pkg.destination);
     printf("\n\t\tchose vehicle:  ");
     printf("\n\t\t\t1. Motercycle    (Rs 10 per km)");
     printf("\n\t\t\t2. Bus           (Rs 20 per km)");
     printf("\n\t\t\t3. Car           (Rs 50 per km)");
     printf("\n\t\t\t4. Airplane      (Rs 100 per km)");
	 re:
	 scanf("%d",&vehicles);
	 switch(vehicles){
		case 1: strcpy(pkg.vehicles, "Motorcycle"); break;
		case 2: strcpy(pkg.vehicles, "Bus");		break;
		case 3: strcpy(pkg.vehicles, "Car");		break;
		case 4: strcpy(pkg.vehicles, "Airplane");	break;
				}
	if(vehicles > 4){
		printf("Invalid option ...! [retry]");
		goto re;
	}
	 fprintf(file, "%d %s %s %s %s %ld %s %s\n",pkg.id, pkg.firstname, pkg.lastname, pkg.password, pkg.email, pkg.number, pkg.destination, pkg.vehicles);
    fclose(file);
    printf("\n\tPackage added successfully!\n");
    again:
    	printf("\tEnter [1] for (add another package)       Enter [2] for (menu)        Enter [3] for (exit):");
    	printf("\n  ->\t");
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
    
    system("cls");
    printf("\n\t\t\t===== All Travelling Packages =====\n\n");
    if(file == NULL) {
        printf("\tUnable to open the file!\n");
        return;
    }
    fseek(file, 0, SEEK_SET);
    while(fscanf(file, "%d %s %s %s %s %ld %s %s\n", &pkg.id, pkg.firstname, pkg.lastname, pkg.password, pkg.email, &pkg.number, pkg.destination, pkg.vehicles) != EOF) {
    	printf("\n\tid:            %d\n\tname:          %s %s \n\tpassword:      %s \n\temail:         %s \n\tnumber:        %ld \n\tdestination:   %s\n\tVehicle:       %s",pkg.id ,pkg.firstname, pkg.lastname, pkg.password, pkg.email, pkg.number, pkg.destination, pkg.vehicles);
    	display++;
    }
    fclose(file);
    if(display == 0){
    	printf("\n\tNon of the record has been added.\n");
	}
    fclose(file);
   while (1) {
        printf("\n\n\tEnter [1] for (menu) or [2] for (exit): ");
        printf("\n  ->\t ");
        scanf("%d", &chose);

        if (chose == 1) {
            menu(username); 
            return;
        } else if (chose == 2) {
            exit(0);
        } else {
            printf("Invalid option ...! [retry]\n");
        }
    }
}

				// adding updatePackage() function....
void updatePackage(char username[]){
    Travelling_data pkg;
    int vehicles;
    int id, chose;
    char pass[20];
    int found = 0; 	
    FILE *file = fopen("Tourism.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    system("cls");

	printf("\n\t\t\t===== Update Travelling Package =====\n\n");
    if (file == NULL || temp == NULL) {
        printf("\tUnable to open the file!\n");
        return;
    }
	fseek(file, 0, SEEK_SET);
    printf("\n\tEnter the id to update:  ");
    scanf("%d", &id);

    while (fscanf(file, "%d %s %s %s %s %ld %s %s\n", &pkg.id, pkg.firstname, pkg.lastname, pkg.password, pkg.email, &pkg.number, pkg.destination, pkg.vehicles) != EOF) {
        if (pkg.id == id) {
        	printf("\n\tEnter the password:  ");
    		scanf("%s", pass);
            if (strcmp(pass, pkg.password) == 0) {
                found = 1; 	
                system("cls");

				printf("\n\t\t\t===== Update Travelling Package =====\n\n");
                printf("\n\tEnter the First name:  ");
                scanf("%s", pkg.firstname);
                printf("\n\tEnter the Last name:  ");
                scanf("%s", pkg.lastname);
                printf("\n\tEnter the new Password:  ");
                scanf("%s", pkg.password);
                printf("\n\tEnter the new Email:  ");
                scanf("%s", pkg.email);
                printf("\n\tEnter the new Number:  ");
                scanf("%ld", &pkg.number);
                printf("\n\tEnter the new Destination:  ");
                scanf("%s", pkg.destination);
                printf("\n\tchose vehicle:  ");
                printf("\n\t\t1. Motercycle    (Rs 10 per km)");
                printf("\n\t\t2. Bus           (Rs 20 per km)");
                printf("\n\t\t3. Car           (Rs 50 per km)");
                printf("\n\t\t4. Airplane      (Rs 100 per km)");
			    re:
			    scanf("%d",&vehicles);
			    switch(vehicles){
					case 1: strcpy(pkg.vehicles, "Motorcycle"); break;
					case 2: strcpy(pkg.vehicles, "Bus");		break;
					case 3: strcpy(pkg.vehicles, "Car");		break;
					case 4: strcpy(pkg.vehicles, "Airplane");	break;
						}
				if(vehicles > 4){
					printf("Invalid option ...! [retry]");
					goto re;
				}
                
                fprintf(temp, "%d %s %s %s %s %ld %s %s\n", pkg.id, pkg.firstname, pkg.lastname, pkg.password, pkg.email, pkg.number, pkg.destination, pkg.vehicles);
                
            } else {
                found = 2;  	
                printf("\n\n\tYou entered the wrong password!!!\n");
                fprintf(temp, "%d %s %s %s %s %ld %s %s\n", pkg.id, pkg.firstname, pkg.lastname, pkg.password, pkg.email, pkg.number, pkg.destination, pkg.vehicles);
            }
        } else {
            fprintf(temp, "%d %s %s %s %s %ld %s %s\n", pkg.id, pkg.firstname, pkg.lastname, pkg.password, pkg.email, pkg.number, pkg.destination, pkg.vehicles);
        }
    }

    fclose(file);
    fclose(temp);

    if (found == 1) {
        remove("Tourism.txt");
        rename("temp.txt", "Tourism.txt");
        printf("\n\t   ---Package updated successfully.---\n");
    } else if (found == 0) {
        printf("\n\tSorry!! ID not found...\n\n");
        remove("temp.txt"); 
    }
again:
    printf("\n\tEnter [1] for (menu)        Enter [2] for (exit):");
    printf("\n  ->\t");
    scanf("%d", &chose);
    switch (chose) {
        case 1: menu(username); return;
        case 2: exit(0);
        default:
            printf("\n\tInvalid option ...! [retry]");
            goto again;
    }
}




void deletePackage(char username[]) {
    Travelling_data pkg;
    char pass[20];
    int id, found = 0, chose;
    FILE *file = fopen("Tourism.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    system("cls");
    printf("\n\t\t\t===== Delete Travelling Package =====\n\n");
    if (file == NULL || temp == NULL) {
        printf("\tUnable to open the file!\n");
        return;
    }
	fseek(file, 0, SEEK_SET);
    printf("\tEnter the ID of the package to delete: ");
    scanf("%d", &id);

    while (fscanf(file, "%d %s %s %s %s %ld %s %s\n", &pkg.id, pkg.firstname, pkg.lastname, pkg.password, pkg.email, &pkg.number, pkg.destination, pkg.vehicles) != EOF) {
        if (pkg.id != id) {
            fprintf(temp, "%d %s %s %s %s %ld %s %s\n", pkg.id, pkg.firstname, pkg.lastname, pkg.password, pkg.email, pkg.number, pkg.destination, pkg.vehicles);
        } else {
            printf("\n\t\tEnter the password: ");
            scanf("%s", pass);
            if (strcmp(pass, pkg.password) == 0) {
                found = 1;
            } else {
                found = 2;
                fprintf(temp, "%d %s %s %s %s %ld %s %s\n", pkg.id, pkg.firstname, pkg.lastname, pkg.password, pkg.email, pkg.number, pkg.destination, pkg.vehicles);
                printf("\n\tYou entered the wrong password!!!\n");
            }
        }
    }

    fclose(file);
    fclose(temp);

    if (found == 1) {
        remove("Tourism.txt");
        rename("temp.txt", "Tourism.txt");
        printf("\n\t   ---Package removed successfully.---\n");
    } else if (found == 0) {
        remove("temp.txt");
        printf("\n\tSorry!! ID not found...\n");
    } else {
        remove("temp.txt");
    }

    do {
        printf("\n\tEnter [1] for (menu)        Enter [2] for (exit): ");
        printf("\n  ->\t ");
        scanf("%d", &chose);
        switch (chose) {
            case 1: menu(username); break;
            case 2: exit(0); break;
            default: printf("\n\t   Invalid option ...! [retry]"); break;
        }
    } while (chose != 1 && chose != 2);
}

