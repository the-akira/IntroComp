#include <stdio.h>
#include <stdlib.h>

// Programa que cria uma Stack usando uma Linked List

// Estrutura que define um node da Linked List
struct Node
{
    int data;
    struct Node *next;
}*top=NULL;

// Função push: adiciona um elemento no topo da stack
void push(int x)
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));

    if(t == NULL)
        printf("Stack is full\n");
    else 
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

// Função pop: remove um elemento do topo da stack
int pop()
{
    struct Node *t;
    int x = -1;
    if(top == NULL)
        printf("Stack is empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

// Funçao display: imprime todos os elementos da stack
void display()
{
    struct Node *p;
    p = top;

    while(p != NULL)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(47);
    printf("Removido da stack: %d\n",pop());
    display();
}