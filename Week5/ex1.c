#include <stdio.h>
#include <pthread.h>
#include <sys/types.h> 
#include <unistd.h> 

void * print_text() {
	printf("Hello from this thread\n");
	return NULL;
}

int main() {
	pthread_t thread_id;
	int n  = 4;
	for (int i=0; i < n; i++) {
		printf("Creating thread number %d\n",i);
		//pthread_create( &thread_id, NULL, print_text(getpid()), NULL);
		pthread_create( &thread_id, NULL, print_text, NULL);
		pthread_join(thread_id, NULL);
	}

    return 0;
}
