#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include<sys/wait.h>

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

void ls(){

}

void uptime(){

}

void sl(){

}

void fork_c(){

	int rc = fork();
	
	if(rc != 0 && rc != -1){
		printf("I am a parent waiting for my child to wake up\n");
		wait(NULL);
		printf("I am a parent and my child has woken up\n");
	}
	if(rc == 0){
		/*
		* The first argument is the location
		* The second argument is the actual arguments which go to the main function of sleep.c
		*/
		/*
		 * Usually the exec family of functions, overwrites the currently executing program, and does not return
		 * to the caller program. But because we are executing the execl function on top of a child process
		 * the child gets overwriten and we return to our parent (init) process and continue the execution of our shell
		 */

		execl("./sleep", "./sleep", NULL );

		kill(getpid(), SIGINT); 
		/*
		* We have to make the child process kill itself, because if we don't, the child process will never end
		* And the parent will wait forever. 
		* if we dont kill the child process it will finish this function, finish in the router function
		* and at last it will finish in the while(1) in the main function
		* effectively having two processes, where one does not do anything and eats up memory.
		*/
	}
}

void vfork_c(){

	int shared_variable = 100;
	
	/***
	 * In vfork the child process halts the parent process until the child is done executing
	 * In vfork the child process has the same memory scope as the parent process
	 * The changes done in the child process will reflect the parent's memory
	 * Here we have declared the variable shared_variable = 100
	 * The child process increments it by one, then the child process is killed same reason as for fork_c()
	 * The changes are reflected in the parent process memory space.
	 */
	int pid_id = vfork();

	if(pid_id == 0){

		printf("I am a child and I share parent's variables\n");
		printf("Our variable before modifying in child process : %d\n", shared_variable);
		shared_variable++;
		printf("Our variable after modifying in child process : %d\n", shared_variable);

		kill(getpid(), SIGINT);

	}else{
		printf("I am a parent and the variable is now : %d\n", shared_variable);
	}
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
		ls();
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
	
	else if(strcmp(function,"fork") == 0){
		fork_c();
	}

	else if(strcmp(function,"vfork") == 0){
		vfork_c();
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

