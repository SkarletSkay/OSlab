#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct frame_struct {
	int reference;
	int lifespan;
	int page_number;
} Frame;


int main(){
	
	printf("Fill the number of frames: ");
	int frame_n;
	scanf("%d",&frame_n);
	
	Frame pages[frame_n];
	for(int i = 0; i < frame_n; i++){
		pages[i].reference = -1;
		pages[i].lifespan = 0;
	}

	FILE *f = fopen("./input.txt", "r");
	int reference;
	
	int id= -1;
	bool space = 0;
	bool in_mem = 0;

	int miss = 0;
	int hit = 0;
	
	while(fscanf(f, "%d", &reference) > 0) {
		in_mem = 0;
		space = 0;
		id = -1;
		for(int i  = 0; i < frame_n; i++){
			pages[i].lifespan = (pages[i].lifespan/2);
			if(pages[i].reference == reference){
				in_mem = 1;
				id = i;
			}
			if(!space){
				if(pages[i].reference == -1){
					space = 1;
					id = i;
				}
				if( id == -1 || pages[i].lifespan < pages[id].lifespan){
					id = i;
				}
			}
		}

		if(!in_mem)
		{	
			pages[id].reference = reference;
			pages[id].lifespan = 0;
			miss = miss + 1;
		}else{
			hit = hit + 1;	
		}
		pages[id].lifespan =  INT_MAX/2;
	}

	printf("Hit/Miss: %d / %d \n", hit, miss);

}