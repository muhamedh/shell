#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

void red(){
	printf("\033[1;31m");
}

void yellow(){
  printf("\033[1;33m");
}

void green(){
	printf("\033[0;32m");
}

void purple(){
	printf("\033[0;35m");
}

void cyan(){
	printf("\033[0;36m");
}

void reset(){
	printf("\033[0m");
}

void username_hostname(){
	char *username;
	char hostname[HOST_NAME_MAX +1];
	
	username = getlogin();
	gethostname(hostname, HOST_NAME_MAX + 1);
	
	red();
	printf("[");

	yellow();
	printf("%s", username);

	green();
	printf("@");

	purple();
	printf("%s", hostname);

	cyan();
	printf(" ~");

	red();
	printf("]");

	reset();

	printf("$ ");
}
void router(char input[1024]){
	char function[10];
	char flags[10];
	int output;
	char file_name[128];
	int fun_counter = 0;
	int flag_counter = 0;

	for(int i = 0; i < strlen(input); i++){
		if(input[i] != ' '){
			function[fun_counter] = input[i];
			fun_counter++;
		}
		else{
			break;
		}
	}
	
	for(int i = fun_counter; i < strlen(input); i++){
		if(input[i] == '-'){
			flags[flag_counter] = input[i + 1];
			flag_counter++;
		}
	}
	
	switch (function){
		case "mkdir":
			mkdir();
			break;

		case "ls":
			ls();
			break;

		case "uptime":
			uptime();
			break;

		case "sl":
			sl();
			break;

		default:
			printf("%s: command not found\n", function);
			break;
}
int main(void){
	printf("%c]0;%s%c", '\033', "Medo", '\007');
	
	system("clear");

	char input[1024];
	int loop = 1;
	while(loop){

	username_hostname();
	fgets(input, 1024, stdin);
	
	router(input);
	}
	return 0;
}

