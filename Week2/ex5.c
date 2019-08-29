#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int currlen( int n) {
	return 1 + (n-1)*4;
}

void printSpaces (int len) {
	int i;
	for (i=0; i < len; i++) printf(" ");
}

void printStarsClose(int len) {
	int i;
	for (i=0; i < len; i++) {
		printf("*");
	}
}

void printStars (int len) {
	int i;
	for (i=0; i < len-1; i++) printf("* ");
	printf("*");
}

void printTriangle (int n) {
	int i, q, maxlen;
	
	maxlen = currlen(n);
	for (i=0; i < n; i++) {
		printSpaces( (maxlen-currlen(i)) / 2 - 1);
		printStars(2*i + 1);
		printf("\n");
	}
}

void printSquare (int n) {
	int i;
	for (i=0; i < n; i++) {
		printStars(n);
		printf("\n");
	}
}

void printRhombus (int n) {
	int i, q;
	printStars(2*n + 1);
	printf("\n");
	for (i=1; i <= n; i++) {
		printStars(n - i + 1);
		printSpaces(4*i-1);
		printStars(n - i + 1);
		printf("\n");
	}
	for (i=n-1; i>=1; i--) {
		printStars(n - i + 1);
		printSpaces(4*i-1);
		printStars(n - i + 1);
		printf("\n");
	}
	printStars(2*n + 1);
	printf("\n");
}

int main(int argc, char** argv) {
	// get number from argv[1]
	int s,n=0,i;
	char A[10];
	sscanf(argv[1],"%s",A);
	s = strlen(A);
	for (i=0; i < s; i++) {
		n = n*10 + (A[i] - '0');
	}
	// result number is n
	
	//printTriangle(n);
	
	//printRhombus(n);
	
	printSquare(n);
	return 0;
}
