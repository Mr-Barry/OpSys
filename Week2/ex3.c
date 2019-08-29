#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int currlen( int n) {
	return 1 + (n-1)*4;
}

void printSpaces(int len) {
	int i;
	for (i=0; i < len; i++) printf(" ");
}

int main(int argc, char** argv) {
	int i, n=0,s=0, maxlen;
	char A[10];
	sscanf(argv[1],"%s",A);
	s = strlen(A);
	
	for (i=0; i < s; i++) {
		n = n*10 + (A[i] - '0');
	}
	maxlen = currlen(n);
	for (i=0; i < n; i++) {
		printSpaces( (maxlen-currlen(i)) / 2);
		for (s=0; s < 2*i - 1; s++) printf("* ");
		printSpaces( (maxlen-currlen(i)) / 2 - 1);
		printf("\n");
	}
	return 0;
}
