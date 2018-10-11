#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{
	int tenmb = 10 * 1024 * 1024;
	for (int i = 0; i < 10; i++) {
		int* ptr = malloc(tenmb);
		memset(ptr, 0, tenmb);

		struct rusage usage;
		int error = getrusage(RUSAGE_SELF, &usage);
		printf("--------------------------------------------------");
		if (!error) {
			printf("utime   = %ld\n",usage.ru_utime.tv_usec);
			printf("stime   = %ld\n", usage.ru_stime.tv_usec);
			printf("maxrss   = %ld\n", usage.ru_maxrss);
			printf("ixrss    = %ld\n", usage.ru_ixrss);
			printf("idrss    = %ld\n", usage.ru_idrss);
			printf("isrss    = %ld\n", usage.ru_isrss);
			printf("minflt   = %ld\n", usage.ru_minflt);
			printf("majflt   = %ld\n", usage.ru_majflt);
			printf("nswap    = %ld\n", usage.ru_nswap);
			printf("inblock  = %ld\n", usage.ru_inblock);
			printf("oublock  = %ld\n", usage.ru_oublock);
			printf("msgsnd   = %ld\n", usage.ru_msgsnd);
			printf("msgrcv   = %ld\n", usage.ru_msgrcv);
			printf("nsignals = %ld\n", usage.ru_nsignals);
			printf("nvcsw    = %ld\n", usage.ru_nvcsw);
			printf("nivcsw   = %ld\n", usage.ru_nivcsw);	
		}
		sleep(1);
	}
}
