#include <stdio.h>
#include <stdlib.h>

int main(){
	int  size, i1, i2, tmp;
	int *A;
	printf("Enter size of array: \n");
	scanf("%d", &size);
	A = (int*)malloc(sizeof(int) * size);
	for (i1=0; i1 < size; i1++) scanf("%d",&A[i1]);
	
	for (i1=0; i1 < size-1; i1++) {
		for (i2=i1+1; i2 < size; i2++) {
			if (A[i1] > A[i2]) {
				tmp = A[i1];
				A[i1] = A[i2];
				A[i2] = tmp;
			}
		}
	}
	printf("\nSorted array:\n");
	for (i1=0; i1 < size; i1++) printf("%d ",A[i1]);
	printf("\n");
	return 0;
}
