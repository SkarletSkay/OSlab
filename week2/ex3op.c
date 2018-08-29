#include <stdio.h>

void pyramid(int n){

	int width = n*2 - 1;
	int shift = n-1;
	int a = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < width; j++){
			if(j>=shift && j<shift+a){
				 printf("*");
			}else { printf(" "); }
		}
		printf("\n");
		shift--;
		a = a + 2;
	}
}

void halfp(int n){
	for(int i=1; i<= n; i++){
		for(int j = 0; j < i; j++ ){
			printf("*");
		}
		printf("\n");
	}
}

void rect(int n){
	for(int i=0; i < n; i++){
		for(int j=0; j<n; j++){
			printf("*");
		}
		printf("\n");
	}
}

void hromb(int n){
	int midi =  (n-1)/2;
	int midd = (n)/2;
	int l = 0;
	for(int i =0; i<n; i++){
		if(i<=midi) l++;
		else if(i>midd) l--;
		for(int j = 0; j < l; j++){
			printf("*");
		}
		printf("\n");
	}
}

int main(int argc, char* argv[]){
	int n;
	sscanf(argv[1], "%d", &n);
	pyramid(n);
	halfp(n);
	hromb(n);
	rect(n);
}
