#include <stdio.h>
#include <stdlib.h>

// Programa que define uma estrutura de dados Stack

// Estrutura que define a Stack
struct Stack
{
    int size;
    int top;
    int *S;
};

// Função create: cria uma stack
void create(struct Stack *st)
{
    printf("Informe o tamanho: ");
    if(scanf("%d",&st->size)){};
    st->top = -1;
    st->S=(int *)malloc(st->size*sizeof(int));
}

// Função display: imprime os elementos da stack
void display(struct Stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
        printf("%d\n",st.S[i]);
}

// Função push: adiciona um elemento no topo da stack
void push(struct Stack *st, int x)
{
    if(st->top == st->size-1)
        printf("Stack Overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

// Função pop: remove um elemento do topo da stack
int pop(struct Stack *st)
{
    int x = -1;
    if(st->top == -1)
        printf("Stack Underflow\n");
    else
    {
        x = st->S[st->top--];
    }
    return x;
}

// Função peek: busca um elemento em um determinado índice
// Retorna ele se ele estiver presente
int peek(struct Stack st, int index)
{
    int x = -1;
    if(st.top-index+1 < 0)
        printf("Índice inválido\n");
    x = st.S[st.top-index+1];
    return x;
}

// Função is_empty: verifica se a stack está vazia
int is_empty(struct Stack st)
{
    if(st.top == -1)
        return 1;
    return 0;
}

// Função is_full: verifica se a stack está cheia
int is_full(struct Stack st)
{
    return st.top == st.size - 1;
}

// Função stack_top: retorna o elemento do topo da stack
int stack_top(struct Stack st)
{
    if(!is_empty(st))
        return st.S[st.top];
    return -1;
}

int main()
{
    struct Stack st;
    create(&st);
    push(&st,10);
    push(&st,11);
    push(&st,12);
    push(&st,13);
    push(&st,14);
    push(&st,15);
    printf("Removido da stack: %d\n",pop(&st));
    printf("Removido da stack: %d\n",pop(&st));
    push(&st,20);
    push(&st,21);
    printf("Elemento na posição 1: %d\n",peek(st,1));
    printf("Elemento na posição 2: %d\n",peek(st,2));
    printf("A stack está vazia? %d\n",is_empty(st));
    printf("A stack está cheia? %d\n",is_full(st));
    printf("Elemento do topo é: %d\n",stack_top(st));
    display(st);
}