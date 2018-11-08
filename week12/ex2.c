#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>


int main(int argc, char *argv[])
{
	if(argc > 1){
		int n = 1;
		bool flag_add_to_file = 0;
		
		if(argv[n][0] ==  '-' && argv[n][1] ==  'a' )
		{
			flag_add_to_file =1;
			n++;
		}
		
		int files_num = (argc-n);
		int files[files_num];
		for(int i = 0; i < files_num; i++){
			if(flag_add_to_file){
				files[i] = open(argv[n], O_RDWR |O_APPEND);
				struct stat buf;
				fstat(files[i], &buf);
				lseek(files[i], buf.st_size, SEEK_SET);
			}else{
				files[i] = open(argv[n], O_RDWR);
			}
			n++;
		}
		
		char ch;
		int size = 0;
		while(read(STDIN_FILENO, &ch, 1) > 0) {
			printf("%c", ch);
			for(int i = 0; i <  files_num; i++){
				write(files[i], &ch, sizeof(ch));
			}
			size ++;
		}

		for(int i = 0; i <  files_num; i++){
			if(!flag_add_to_file) ftruncate(files[i], size);
			close(files[i]);
		}
	}
}
