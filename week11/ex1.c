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
	char* str = "This is a nice day";
	int f = open("ex1.txt", O_RDWR);

	struct stat st;
	fstat(f, &st);

	char *map = (char*) mmap(NULL, st.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, f, 0);

	memcpy(map, str, strlen(str));
	
	munmap(map,  st.st_size);

	ftruncate(f, strlen(str));
	close(f);

}

