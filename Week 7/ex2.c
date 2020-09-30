#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i;
    scanf("%i",&N);
    int * arr = (int*) calloc(N,sizeof(int));

    for(i=0; i < N; i++) printf("%i ",arr[i] = i);
    free(arr);

    return 0;
}
