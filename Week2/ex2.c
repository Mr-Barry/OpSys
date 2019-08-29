#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, size=0;
	char *A;
	printf("Length of string?\n");
	scanf("%d", &size);
	
	A = (char*)malloc(size);
	for (i=0; i <= size; i++) scanf("%c", &A[i]);
	
	for (i=size; i>=0; i--) printf("%c", A[i]);
	
	return 0;
}
