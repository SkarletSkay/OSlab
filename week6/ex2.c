#include <stdio.h>
#include <string.h>
#include<unistd.h> 
#include<sys/wait.h> 

#define SIZE 100

int main()
{
	char* str1;
	char str2[SIZE];
	str1 = "test text";
	int fd[2];
	if(pipe(fd)==0){
		int pid  = fork();
		if(pid==0){
			write(fd[1], str1, strlen(str1)+1);
			close(fd[1]);
			wait(NULL);
			fflush(stdout);
		}else{
			read(fd[0], str2, SIZE);
			close(fd[0]);
			printf("%s\n", str2);
		}
	}
}
