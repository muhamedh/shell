#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

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

int main(void){
	char input[1024];

	while(1){

	username_hostname();
	fgets(input, 1024, stdin);

	}
	return 0;
}

