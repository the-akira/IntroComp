#include <stdio.h>

int stringlen(char s[]);

int main(void)
{
    char string[] = "Programming in C";
    printf("O tamanho da string é = %d\n", stringlen(string));
}

// Função que calcula o tamanho de uma string
int stringlen(char s[])
{
    int i;

    while(s[i] != '\0')
        ++i;
    return i;
}