#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	int i;
	float f;
	double d;

	i = INT_MAX;
	f = FLT_MAX;
	d = DBL_MAX;

	printf("Integer: value = %d  size = %lu\n", i, sizeof(i));
	printf("Float: value = %f  size = %lu\n", f, sizeof(f));
	printf("Double: value = %f size = %lu\n", d, sizeof(d));
}
