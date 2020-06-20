#include <stdio.h>

/*
Comparando Strings
*/

int main()
{
	char A[] = "cachorro";
	char B[] = "cachorro";
	int i, j;

	for(i=0,j=0;A[i]!='\0' && B[j]!='\0';i++,j++)
	{
		if(A[i] != B[j])
			break;
	}
	if(A[i] == B[j])
		printf("Ela são iguais\n");
	else if(A[i] < B[j])
		printf("A é menor\n");
	else 
		printf("B é maior\n");
}