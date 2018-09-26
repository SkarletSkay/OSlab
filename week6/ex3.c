#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void message_interrupt(){
	printf("Program has interrupted!\n");
	exit(0);
}

int main(){
	signal(SIGINT, message_interrupt);
	while(1){}
}
