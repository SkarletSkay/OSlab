#include <stdio.h>
#include <string.h>
#include<unistd.h> 
#include<sys/wait.h> 

int main()
{
	int fd[2];
	int pid2;
	if(pipe(fd)==0){
		int pid1  = fork();
		if(pid1 > 0 ){
			printf("Process 1 has created - PID1: %d\n", pid1);
			pid2 = fork();
			if(pid2 > 0){
				printf("Process 2 has created - PID2: %d\n", pid2);
				write(fd[1], &pid2, sizeof(pid2));
				close(fd[1]);
				printf("PID2 has written in pipe\n");
			}
			if(pid2 == 0){
				int i = 0;
				while(1){
					if(i == 0){
						i++;
						printf("Process 2 has started to work\n");
					}
				}
			}
			
		}
		if(pid1 == 0){
			waitpid(0 , NULL, 0);
			printf("Process 1 starts to read the pipe\n");
			read(fd[0], &pid2, sizeof(pid2));
			close(fd[0]);
			printf("Process 1 finish to read the pipe: PID2 is %d\n", pid2);
			waitpid(pid2 , NULL, 0);
			printf("Process 2 is not changing its state\n");
			sleep(2);
			printf("Ready to stop Process 2\n");
			kill(pid2, SIGSTOP);
			printf("Process 2 has stopped\n");
			printf("Process 1 has finished\n");
		}
	}
}

