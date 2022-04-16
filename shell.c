#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int loop = 1;

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

void mkdir_c(char flags[10], int f_size, char name[128], int n_size){
	char dir[PATH_MAX]; // PATH_MAX - defines the longest path a direcotry can be
	getcwd(dir, sizeof(dir)); // getcwd - gives us the absolute pathname of the current working directory

	char slash[129] = "/"; // creates a new string slighty bigger than name
	strcat(slash,name); // in order to concatenate res -> /name_of_our_new_dir
	slash[strcspn(slash, "\n")] = 0;
	if(name[0] != '\n'){ // prevents creating a '' named directory

		mkdir(strcat(dir,slash), 0777); // make the dir with mkdir function
		//0777 -> -rwxrwxrwx read,write & execute for owner, group and others

	}


	for( int i = 0;i < f_size;i++){
		if(flags[i] == 'v'){
			name[strlen(name)-1] = '\'';
			printf("mkdir: created directory '%s\n", name);
		}
		if(flags[i] == 'h'){
			printf("Usage mkdir [OPTION] ... DIRECTORY...\n");
			printf("Create the DIRECTORY, if they do not already exist\n");
			printf("-v print a message for a created directory\n");
			printf("-V print the current version\n");
			printf("-h show the help page\n");
		}
		if(flags[i] == 'V'){
			printf("current version mkdir : v0.0.1\n");
		}
	}	
}

void ls(char flags[10], int f_size){
	DIR* dir = opendir(".");

	if(dir == NULL){
		return;
	}
	
	struct dirent* entity;
	entity = readdir(dir);
	
	while(entity != NULL){
		if(f_size == 0){
		printf("%s\n", entity->d_name);
		entity = readdir(dir);
		}

		for(int i = 0; i < f_size; i++){
			if(flags[i] == 'c'){
				if(entity->d_type == DT_DIR){
					purple();
					printf("%s\n", entity->d_name);
					reset();
				}

				else if(entity->d_type == DT_REG){
					green();
					printf("%s\n", entity->d_name);
					reset();	
				}
			}
		entity = readdir(dir);
		}
	}
	closedir(dir);

	for(int i = 0; i < f_size; i++){
		if(flags[i] == 'h'){
			printf("Usage ls [OPTION]... [FILE]...\n");
			printf("List FILEs in current directory\n");
			printf("-c add color to the output (directories - purple, files - green\n");
			printf("-v print the current version\n");
			printf("-h show the help page\n");
		}
		if(flags[i] == 'v'){
			printf("current version ls : v0.0.1\n");
		}
	}
}

void uptime(){

}

void sl(){

}
/**
 * Function used for routing user input
*/
void router(char input[1024]){

	char function[10] = "";
	char flags[10] = "";
	int output;
	char file_name[128] = "";
	int fun_counter = 0;
	int flag_counter = 0;
	int name_counter = 0;

	for(int i = 0; i < strlen(input); i++){
		if(input[i] != ' ' || (int)input[i] == 0 ){
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

	for(int i = fun_counter + 2*flag_counter + 1; i < strlen(input); i++){
		if(input[i] == '>'){
			output = 1;
		}
		if(input[i] != '>' && (input[i] != ' ' || (int)input[i] == 0)){
			file_name[name_counter] = input[i];
			name_counter++;
		}
	}

	if(output == 1){
		// handle redirecting to file
		// todo
	}

	function[strcspn(function, "\n")] = 0;

	if(strcmp(function, "mkdir") ==  0){
		mkdir_c(flags, flag_counter, file_name, name_counter);
	}

	else if(strcmp(function, "ls") == 0){
		ls(flags, flag_counter);
	}

	else if(strcmp(function, "uptime") == 0){
		uptime(1);
	}

	else if(strcmp(function, "sl") == 0){
		sl();
	}

	else if(strcmp(function, "clear") == 0){
		system("clear");
	}

	else if(strcmp(function, "exit") == 0){
		loop = 0;
	}
	else if((int)function[0] != 0){ // tests if the first entered char is not a new line 
		printf("%s: command not found\n", function);
	}

}
int main(void){
	printf("%c]0;%s%c", '\033', "Medo", '\007');
	/*
	* The system("clear") is included in stdlib.h and works only in Linux based systems
	*/

	system("clear");
	/*
	* The input char array for storing user input
	*/
	char input[1024];

	while(loop){

	username_hostname();

	/*
	* Even if user outputs is larger than the array size, fgets will handle the overflow properly
	*/
	fgets(input, 1024, stdin);

	router(input);
	}
	return 0;
}

