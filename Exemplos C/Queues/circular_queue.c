#include <stdio.h>
#include <stdlib.h>

// Programa que cria uma estrutura de dados Circular Queue

// Estrutura que define a Queue
struct Queue
{
	int size;
	int front;
	int rear;
	int *Q;
};

// função create: cria uma Queue
void create(struct Queue *q, int size)
{
	q->size = size;
	q->front = q->rear = 0;
	q->Q = (int *)malloc(q->size*sizeof(int));
}

// função enqueue: insere um elemento no final da Queue
void enqueue(struct Queue *q, int x)
{
	if((q->rear + 1)%q->size == q->front)
		printf("Queue is Full\n");
	else
	{
		q->rear = (q->rear + 1)%q->size;
		q->Q[q->rear] = x;
	}
}

// função dequeue: elimina um elemento do início da Queue
int dequeue(struct Queue *q)
{
	int x = -1;
	if(q->front == q->rear)
		printf("Queue is Empty\n");
	else
	{
		q->front = (q->front + 1)%q->size;
		x = q->Q[q->front];	
	}
	return x;
}

// função display: imprime todos os elementos da Queue
void display(struct Queue q)
{
	int i = q.front + 1;

	do
	{
		printf("%d\n",q.Q[i]);
		i = (i + 1)%q.size;
	}while(i != (q.rear + 1)%q.size);
}

int main()
{
	struct Queue q;
	create(&q,5);
	enqueue(&q,10);
	enqueue(&q,11);
	enqueue(&q,12);
	printf("Removido: %d\n",dequeue(&q));
	display(q);
}