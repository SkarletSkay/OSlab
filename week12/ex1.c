#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	char symbols[21];
	int f = open("/dev/random", O_RDWR);
	symbols[20] = '\0';
	read(f, symbols, 20);

	int out =open("ex1.txt", O_RDWR);

	write(out, symbols,  sizeof(symbols));
	
	close(f);
	close(out);
}
