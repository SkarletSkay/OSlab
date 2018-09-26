#include <stdio.h>
#include <string.h>
#include<unistd.h> 
#include<sys/wait.h> 


int main()
{
	int pid  = fork();
	if(pid>0){
		sleep(10);
		kill(pid, SIGTERM);
	}else{
		while(1){
			printf("I'm alive\n");
		}
	}
}

