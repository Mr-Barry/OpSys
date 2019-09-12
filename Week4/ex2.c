#include <sys/types.h> 
#include <unistd.h> 
#include <stdio.h>
//#include < unistd.h >

int main() {
	int n;
	
	for (n=0 ; n < 5; n++) {
		fork();
		sleep(5);
	}
	return 0;
}

/*
 * Each loop iteration number of forks doubles: each existing fork makes a child
 * f0
 * 
 * f0 -> f1
 * 
 * f0 -> (f1 -> f3), f2
 * 
 * fo -> (f1 -> (f3 -> f7), f6), (f2 -> f5), f4
 * 
 * ...
 */
