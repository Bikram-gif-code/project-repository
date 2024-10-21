#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

void Heading();
void Welcome();
int main(){
	char username[20];
	int password;        		// Password is set as 12345.
	
	
	//for wellcome interface.
	Welcome();	
	
	
	printf("\n\n\n\t\tEnter your name:  ");
	scanf("%s", username);
	printf("\t\tEnter login password:  ");
	scanf("%d",&password);
	if(password == 12345)
	{
		printf("\n\n\t\t\t");
		printf("login successfull\n\n\tprocessing");
		int i;
		for(i=1; i<=3; i++){
			sleep(1);
			printf(".");
		}
		system("cls");
		Heading();
	}
	else
	{
		printf("\n\n\t\t\t");
		printf("--- invalid password sorry ---");
	}
	return 0;
}
void Welcome(){
	int i;
	printf("\n\t\t\t");
	for(i=1;i<10;i++){
		printf(".");
	}
	printf(" wellcome to our Travel and Tourism management system ");
	for(i=1;i<10;i++){
		printf(".");
	}
}
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
