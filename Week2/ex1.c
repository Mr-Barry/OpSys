#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>

int main() {
	int i = INT_MAX;
	float f = FLT_MAX;
	double d = DBL_MAX;
	printf("int i = %d, size %ld\n", i, sizeof(i));
	printf("float f = %f, size %ld\n", f, sizeof(f));
	printf("double d = %f, size %ld\n", d, sizeof(d));
	
	return 0;
}
