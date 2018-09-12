#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h> 

int main(void) {
	int n = 101;
	int pid = fork();
	if(pid == 0){
		printf("Hello from Child[%d-%d]\n", pid, n);
	}else{
		printf("Hello from Parent[%d-%d]\n", pid, n);
	}
	return 0;
}

