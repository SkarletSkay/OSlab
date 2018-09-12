#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int flag = 1;
	char command[50];
	char param[50];
	
	printf("$ ");
	//Need to write path such as /bin/ls
	scanf("%s", command);
	scanf("%s", param);
	int pid  = fork();
	if(pid>0){
		char* const params[] = {command, param, 0};
    		char *env[] = {0};
		execve(command,params, env);
		printf("\n");
	}
	
}
