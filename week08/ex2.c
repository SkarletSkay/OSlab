#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int tenmb = 10 * 1024 * 1024;
	for (int i = 0; i < 10; i++) {
		int* ptr = malloc(tenmb);
		memset(ptr, 0, tenmb);
		sleep(1);
	}
	return 0;
}
