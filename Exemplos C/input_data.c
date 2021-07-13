#include <stdio.h>

int soma(int x, int y);

// programa que lê dois inteiros 
// e retorna sua respectiva soma
int main(void)
{
    int x, y;
    printf("Digite um valor para x: ");
    if(scanf("%d", &x)){};
    printf("Digite um valor para y: ");
    if(scanf("%d", &y)){};
    printf("A soma de x e y é = %d\n", soma(x, y));
}

int soma(int x, int y)
{
    int z;
    z = x + y;
    return z;
}