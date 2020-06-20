#include <stdio.h>
#include <stdlib.h>

// Programa que utiliza a estrutura stack para parenthesis matching

// Estrutura que define um node da Linked List
struct Node
{
	char data;
	struct Node *next;
}*top=NULL;

// Função push: adiciona um elemento no topo da stack
void push(char x)
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
char pop()
{
	struct Node *t;
	char x = -1;
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

// Função is_balanced: retorna se os parenteses estão balanceados
// Recebe uma expressão como argumento
int is_balanced(char *exp)
{
	int i;

	for(i=0;exp[i]!='\0';i++)
	{
		if(exp[i] == '(')
			push(exp[i]);
		else if(exp[i] == ')')
		{
			if(top == NULL)
				return 0;
			pop();
		}
	}
	if(top == NULL)
		return 1;
	else
		return 0;
}

int main()
{
	char *exp = "((a+b)*(c-d))"; 
	char *xp = "((a+b)*(c-d)"; 
	printf("Parenteses fecham corretamente? %d\n",is_balanced(exp));
	printf("Parenteses fecham corretamente? %d\n",is_balanced(xp));
}