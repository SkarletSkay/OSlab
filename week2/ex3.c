#include <stdio.h>

int main(int argc, char *argv[])
{
	int n;
	sscanf(argv[1], "%d", &n);
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
