#include <stdio.h>
#include <string.h>

int main(){
	char str[128];
	scanf("%s", str);
	int len = strlen(str);
	char strout[len+1];
	for(int i = 0; i < len; i++){
		strout[i] = str[len-1-i];
	}
	strout[len] ='\0';
	printf("\n%s\n", strout);
}
