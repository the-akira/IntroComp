#include <stdio.h>
#include <math.h>

// Estrutura que define um ponto
struct point {
    int x;
    int y;
};

// Estrutura que define um retângulo
struct rect {
    struct point pt1;
    struct point pt2;
};

/* Função addpoints(): adiciona dois pontos */
struct point addpoint(struct point p1, struct point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

/* Função makepoint(): cria um ponto através dos componentes x e y */
struct point makepoint(int x, int y)
{
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

int main(void)
{
    double distance, sqrt(double);
    struct point pt = { 320, 200 };
    
    struct point pt1 = { 10, 10 };
    struct point pt2 = { 20, 20 };
    struct rect screen = { pt1, pt2 };

    printf("(%d,%d)\n", pt.x, pt.y);
    distance = sqrt((double)pt.x * pt.x + (double)pt.y * pt.y);
    printf("A distância da origem é = %f\n",distance);

    printf("Coordenadas x do retângulo: (%d,%d)\n",screen.pt1.x,screen.pt2.x);
    printf("Coordenadas y do retângulo: (%d,%d)\n",screen.pt1.y,screen.pt2.y);

    struct point soma = addpoint(pt1,pt2);
    printf("Soma dos pontos é (%d,%d)\n", soma.x, soma.y);

    struct rect quadrado;
    struct point centro;
    struct point makepoint(int, int);

    quadrado.pt1 = makepoint(0,0);
    quadrado.pt2 = makepoint(10,10);
    centro = makepoint((quadrado.pt1.x + quadrado.pt2.x)/2, (quadrado.pt1.x + quadrado.pt2.y)/2);
    printf("O centro é = (%d,%d)\n",centro.x, centro.y);
}