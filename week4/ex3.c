#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
	bool flag = 1;
	char command[10];
	while(flag){
		printf("$ ");
		scanf("%s", command);
		system(command);
		printf("\n");
	}
}

