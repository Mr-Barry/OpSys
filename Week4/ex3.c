#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ever ;;

int main() {
        char line[500];

        for(ever) {
                scanf("%s", line);
                if (strncmp(line, "exit", 5) == 0) break;
                system(line);
        }
        return 0;
}
