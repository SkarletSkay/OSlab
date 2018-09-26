#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void message_stop(){
	printf("Program has stopped!\n");
	exit(0);
}

void message_kill(){
	printf("Program has killed!\n");
	exit(0);
}

void message_usr1(){
	printf("Program get signal usr1!\n");
	exit(0);
}


int main(){
	signal(SIGSTOP, message_stop);
	signal(SIGKILL, message_kill);
	signal(SIGUSR1,  message_usr1);
	while(1){}
}
