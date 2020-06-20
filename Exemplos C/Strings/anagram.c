#include <stdio.h>

// Programa que checa se duas strings são anagramas

// Função test_anagram: testa se duas strings são anagramas
int test_anagram(char a[], char b[])
{
	int first[26] = {0}, second[26] = {0}, c=0;

	// Calcula frequencia de caracteres da string 1
	while(a[c] != '\0')
	{
		first[a[c]-'a']++;
		c++;
	}

	c = 0;

	// Calcula frequencia de caracteres da string 2
	while(b[c] != '\0')
	{
		second[b[c]-'a']++;
		c++;
	}

	// Comparando a frequência dos caracteres
	for(c=0;c<26;c++)
		if(first[c] != second[c])
			return 0;
	return 1;
}

int main()
{
	char A[100], B[100];

	printf("Informe duas strings: \n");
	if(scanf("%s",A)){};
	if(scanf("%s",B)){};

	if(test_anagram(A,B))
		printf("As strings são anagramas\n");
	else
		printf("As strings não são anagramas\n");
}