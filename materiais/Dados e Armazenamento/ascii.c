#include <stdio.h>

int main()
{
	int i;
	for(i = 33; i < 127; i++)
	{
		printf("O valor ASCII de %c = %d = %x\n", i, i, i);
	}
}