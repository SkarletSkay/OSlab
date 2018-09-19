#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h> 

bool message_thread = 0;

void *thread_funct(void* i)
{
	int *n = (int*) i;
	while(!message_thread){}
    	printf("Message from Thread %d \n", *n);
	message_thread = 0;
	pthread_exit(NULL);
}

int main(int argc, char * argv[])
{
	int N;
	sscanf(argv[1], "%d", &N);
    	pthread_t thread_id[N];
    	for(int i = 0; i<N; i++){
    		pthread_create(&thread_id[i], NULL, thread_funct, (void*)&i);
    		printf("Thread %d created \n", i);
		message_thread = 1;
		pthread_join(thread_id[i], NULL);
		while(message_thread){ printf("Kek");}
	}
    	exit(0);
}

