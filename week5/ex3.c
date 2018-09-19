#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include<stdbool.h>
#include <stdlib.h>

#define N 8

int buffer[N];

int count = 0;

bool producer_asleep = 0;
bool consumer_asleep = 0;


void *produce(void *arg)
{
	
	int i = 0;
	while (1){
        	i++;
		if(i>1000000){
			i = 0;
		}

        	if (count == N) 
        	{
 			producer_asleep = 1;
			while(producer_asleep){
				 sleep(5);
			}
        	}

        	buffer[count] = i;
        	count = count + 1;

        	if (count == 1) 
        	{
           		consumer_asleep = 0;
        	}	
		printf("Printed number %d \n", i);
		sleep(60);
  	}
}



void *consume(void *arg)
{
	int i;
	while (1) 
    	{

	        if (count == 0) 
	        {
	        	consumer_asleep = 1;
			while(consumer_asleep){
				sleep(5);
			}
	        }
	
	        count = count - 1;
		i = buffer[count];
	
	        if (count == N - 1) 
	        {
	            producer_asleep = 0;
        	}
   	 }
}

int main()
{

	pthread_t producer, consumer;

	int stat1, stat2;
	stat1 = pthread_create(&producer, NULL, produce, NULL);
	
	stat2 = pthread_create(&consumer, NULL, consume, NULL);
	
	if (stat1 ) {
		printf("Error %d\n", stat1);
	}
	if (stat2) {
		printf("Error %d\n", stat2);
	}
	
	while(1){
		fflush(stdout);
	}
	
	return 0;

}





