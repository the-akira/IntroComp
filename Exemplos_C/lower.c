#include <stdio.h>
#include <ctype.h>

// lower: converte o input para lower case
int main(void)
{
	int c;

	while((c = getchar()) != EOF)
		putchar(tolower(c));
	return 0;
}