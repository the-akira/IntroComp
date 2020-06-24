#include <stdio.h>

// programa que conta a quantidade de caracteres digitados
int main()
{
	long nc;
	nc = 0;
	while(getchar() != EOF){	
		++nc;	
	}
	printf("%ld\n", nc);
}