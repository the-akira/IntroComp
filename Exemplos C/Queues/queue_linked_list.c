#include <stdio.h>
#include <stdlib.h>

// Programa que implementar a Estrutura de Dados Queue usando uma LL

// Estrutura que define um Node
struct Node
{
	int data;
	struct Node *next;
}*front=NULL,*rear=NULL;

// Função enqueue: insere um elemento no final da Queue
void enqueue(int x)
{
	struct Node *t;
	t = (struct Node*)malloc(sizeof(struct Node));

	if(t == NULL)
		printf("Queue is Full\n");
	else
	{
		t->data = x;
		t->next = NULL;
		if(front == NULL)
			front = rear = t;
		else
		{
			rear->next = t;
			rear = t;
		}
	}
}

// Função dequeue: remove um elemento do início da Queue
int dequeue()
{
	int x = -1;
	struct Node *t;

	if(front == NULL)
		printf("Queue is Empty\n");
	else
	{
		x = front->data;
		t = front;
		front = front->next;
		free(t);
	}
	return x;
}

// Função display: imprime todos os elementos da Queue
void display()
{
	struct Node *p = front;

	while(p)
	{
		printf("%d\n",p->data);
		p = p->next;
	}
}

int main()
{
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	printf("Removido da Queue: %d\n",dequeue());
	printf("Removido da Queue: %d\n",dequeue());
	enqueue(6);
	display();
}