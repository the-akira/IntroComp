#include <stdio.h>

int main(void)
{
    int x = 1, y = 2, z[10];
    int *ip; // ip é um ponteiro para int
    int **id; // id é um ponteiro para um ponteiro int
    printf("Endereço de x = %p \n", &x); // imprime o endereço de x
    printf("Endereço de ip = %p \n", &ip); // imprime o endereço de ip
    printf("Endereço de id = %p \n", &id); // imprime o endereço de id

    ip = &x; // ip atualmente é um ponteiro para x
    id = &ip; // id atualmente é um ponteiro para ip
    printf("Valor de ip = %d \n", *ip); // imprime o valor de ip
    printf("Valor de id = %d \n", **id); // imprime o valor de id

    y = *ip; // y é atualmente 1
    printf("Valor de y = %d \n", y);

    *ip = 0; // x é atualmente 0
    printf("Novo valor de ip = %d \n", *ip); // imprime o valor de ip

    ip = &z[0]; // ip atualmente é um ponteiro para z[0]
    printf("Novo valor de ip = %d \n", *ip); // imprime o valor de ip
}