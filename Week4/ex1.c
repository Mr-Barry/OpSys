#include <sys/types.h> 
#include <unistd.h> 
#include <stdio.h>

int main() {
	pid_t pid;
	int n = 5000;
	if (pid == fork() == 0) {
		printf("Hello from child [PID - %d]\n",getpid() - 5000);
	} 
	else printf("Hello from parent [PID - %d]\n",getpid() - 5000);
	return 0;
}
