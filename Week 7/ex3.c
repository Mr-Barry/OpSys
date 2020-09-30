#include <stdlib.h>
#include <stdio.h>


int main(){
	srand(time(NULL));

	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	int* a1 = (int*) calloc(n1,sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		//Set each value in a1 to 100
		a1[i]=100;

		//Print each element out (to make sure things look right)
		printf("%d ",a1[i] );
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	//Dynamically change the array to size n2
	a1 = (int*) realloc(a1, sizeof(int) * n2);

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

	if (n1 < n2) for(i=0; i <n2; i++) a1[i] = 0;


	for(i=0; i<n2;i++){
		//Print each element out (to make sure things look right)
		printf("%d ", a1[i]);
	}
	printf("\n");

	//Done with array now, done with program :D

	return 0;
}
