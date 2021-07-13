#include <stdio.h>

// Exemplos de caracteres e strings em C

int main()
{
    // Criando um único caracter
    char c = 'A';

    // Criando um array de caracteres
    char *X[5] = {"B","C","D","E","F"};

    // Criando uma string
    char name[]={'G','A','B','R','I','E','L','\0'};

    printf("%c \n",c);

    for(int i=0;i<5;i++)
        printf("%s \n",X[i]);

    printf("%s",name);
}