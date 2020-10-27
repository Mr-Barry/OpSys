 #include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    //char b[6];
    setvbuf(stdout, 0, _IOLBF, 6);
	const char * text = "Hello";
	for (int i=0; i < 5; i++) {
		printf("%c", text[i]);
		if (i < 4) sleep(1);
	}
    return 0;
} 
