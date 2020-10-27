 #include <stdio.h>
 #include <sys/mman.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <unistd.h>
 #include <sys/types.h>
 #include <string.h>

int main(){
	char * text = "This is a nice day";
	int textlen = strlen(text) + 1;
	
	FILE *f = fopen("ex1.txt", "w");
	ftruncate(fileno(f), textlen - 1);
	fclose(f);
	
	int file = open("ex1.txt", O_RDWR);
	char * filestr = (char*) mmap(0, textlen + 1, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);
	for (int i=0; i < textlen; i++) {
		filestr[i] = text[i];
	}
	munmap(filestr, textlen);
    return 0;
}
