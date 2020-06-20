#include <stdio.h>

// Invertendo uma string

int main()
{
	char lang[] = "python";
	char L[7];
	int i, j;
	for(i=0;lang[i]!='\0';i++){}
	i -= 1;
	for(j=0;i>=0;i--,j++)
	{
		L[j] = lang[i];
	}
	L[i] = '\0';
	printf("%s\n",L);
}