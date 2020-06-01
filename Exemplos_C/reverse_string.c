#include <string.h>
#include <stdio.h>

void reverse(char s[]);

// Testando a função reverse()
int main(void)
{
	char string[] = "Programa";
	reverse(string);
	printf("A string invertida é: %s\n", string);
}

// Função que inverte uma string in place
void reverse(char s[])
{
	int c, i, j;

	for(i = 0, j = strlen(s)-1; i < j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}