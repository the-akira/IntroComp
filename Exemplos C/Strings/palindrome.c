#include <stdio.h>
#include <string.h>

/*
Checando por palindrome
*/

int main()
{
	int i=0, j, is_palim = 1;
	char string[50];

	printf("Informe a palavra: ");
	if(scanf("%s",string)){};

	// Obtém o último índice da string
	j = strlen(string) - 1;

	while(i <= j)
	{
		if(string[i] != string[j])
		{
			is_palim = 0;
			break;
		}
		i++;
		j--;
	}
	if(is_palim)
		printf("%s é palindrome\n",string);
	else
		printf("%s não é palindrome\n",string);
}