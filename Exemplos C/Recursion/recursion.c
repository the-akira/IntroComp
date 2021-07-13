#include <stdio.h>

// Exemplo de funções recursivas

void func(int n)
{
    if(n > 0)
    {
        printf("%d\n",n);
        func(n-1);
    }
}

void funct(int n)
{
    if(n > 0)
    {
        funct(n-1);
        printf("%d\n",n);
    }
}

int main(void)
{
    int x = 5;
    printf("Função 1:\n");
    func(x);
    printf("Função 2:\n");
    funct(x);
}