#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_funct(void* i)
{
	int *n = (int*) i;
    printf("Message from Thread %d \n", *n);
    pthread_exit(NULL);
}

int main(int argc, char * argv[])
{
	int N;
	sscanf(argv[1], "%d", &N);
    	pthread_t thread_id[N];
    	for(int i = 0; i<N; i++){
    		pthread_create(&thread_id[i], NULL, thread_funct, (void*)&i);
    		pthread_join(thread_id[i], NULL);
    		printf("Thread %d\n", i);
	}
    	exit(0);
}

