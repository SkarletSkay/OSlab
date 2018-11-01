#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>


int main() 
{ 
	char *str = "Hello";
	int i;
	for (i = 0; i < strlen(str); i++) {
		printf("%c", str[i]);
		sleep(1);
	}
}