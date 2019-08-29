#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap( int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}

int main() {
	int  a1, a2;
	printf("Enter 2 numbers:\n");
	scanf("%d %d", &a1, &a2);
	printf("a1 is %d, a2 is %d\n", a1, a2);
	swap(&a1, &a2);
	printf("Now a1 is %d, a2 is %d\n", a1, a2);
	return 0;
}
