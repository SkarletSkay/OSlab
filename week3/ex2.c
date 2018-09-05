#include <stdio.h>

void bubble_sort(int size, int a[]) {
	int t;
	for(int i = size; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(a[j] > a[j+1]){
				t = a[j+1];
				a[j+1] = a[j];
				a[j] = t;
			}
		}
	}
}

int main(){
	int N;
	scanf("%d",&N);
	int arr[N];
	for(int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	bubble_sort(N, arr);
	for(int i = 0; i < N; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
