#include <stdlib.h>
#include <stdio.h>


int main(){

	int N;
	scanf("%d",&N);

	int* arr = malloc(N * sizeof(int));
	for(int i=0; i< N; i++){
		arr[i] = i;
	}

	for(int i=0; i< N; i++){
		printf("a[%d] = %d ", i, arr[i]);
	}

	free(arr);
	return 0;
}