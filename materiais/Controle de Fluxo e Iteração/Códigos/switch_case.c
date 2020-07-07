#include <stdio.h>

// Programa que define uma simples calculadora

int main() 
{
    char operador;
    double n1, n2;

    printf("Entre um operador (+, -, *, /): ");
    scanf("%c",&operador);
    printf("Entre dois operandos:\n");
    scanf("%lf %lf",&n1, &n2);

    switch(operador)
    {
        case '+':
            printf("%.1lf + %.1lf = %.1lf\n",n1, n2, n1+n2);
            break;

        case '-':
            printf("%.1lf - %.1lf = %.1lf\n",n1, n2, n1-n2);
            break;

        case '*':
            printf("%.1lf * %.1lf = %.1lf\n",n1, n2, n1*n2);
            break;

        case '/':
            printf("%.1lf / %.1lf = %.1lf\n",n1, n2, n1/n2);
            break;

        default:
            printf("Erro! Operador digitado é incorreto!");
    }
}