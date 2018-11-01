#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int main(int argc, char *argv[])
{
	int fdin, fdout; 
	char *src, *dst; 
	struct stat st; 
	 
 	fdin = open("ex1.txt",O_RDWR);
	fdout = open("ex1.memcpy.txt", O_RDWR );
	fstat(fdin, &st);
	ftruncate(fdout, st.st_size);
	
	src = (char*) mmap(0, st.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fdin, 0);
	dst = (char*) mmap(0, st.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fdout, 0);
	    
	 int i;
	 for (i = 0; i < st.st_size; i++) {
	  	 dst[i] = src[i];
	 }
	
	munmap(src ,st.st_size);
	munmap(dst, st.st_size);
	
	close(fdin);
  	close(fdout);
}
