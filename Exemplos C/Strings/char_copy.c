#include <stdio.h>

// Programa que copia uma cadeia de caracteres

int main()
{
    int c;

    printf("Expression: %d\n", (c = getchar()) != EOF);
    printf("EOF: %d", EOF);

    while((c = getchar()) != EOF){
        putchar(c);
    }
}