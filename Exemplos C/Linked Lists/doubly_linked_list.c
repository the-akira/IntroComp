#include <stdio.h>
#include <stdlib.h>

// Programa que cria uma Doubly Linked List

// Estrutura que define uma DLL
struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
}*first=NULL;

// Função create: cria uma DLL
// Recebe um array e o número de nodes
void create(int A[], int n)
{
	struct Node *t,*last;
	int i;
	first = (struct Node *)malloc(sizeof(struct Node));
	first->data=A[0];
	first->prev=first->next=NULL;
	last=first;

	for(i=1;i<n;i++)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=last->next;
		t->prev=last;
		last->next=t;
		last=t;
	}
}

// Função display: imprime os elementos da DLL
void display(struct Node *p)
{
	while(p)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}

// Função length: retorna o número de elementos da DLL
int length(struct Node *p)
{
	int len = 0;

	while(p)
	{
		len++;
		p = p->next;
	}
	return len;
}

// Função insert: insere um elemento em uma determinada posição da DLL
// Recebe um ponteiro, um índice e um elemento a ser inserido
void insert(struct Node *p, int index, int x)
{
	struct Node *t;
	int i;

	if(index < 0 || index > length(p))
		return;
	if(index == 0)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = x;
		t->prev = NULL;
		t->next = first;
		first->prev = t;
		first = t;
	}
	else
	{
		for(i=0;i<index-1;i++)
			p = p->next;
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = x;
		t->prev = p;
		t->next = p->next;
		if(p->next)
		{
			p->next->prev=t;
		}
		p->next = t;
	}
}

// Função delete: remove um elemento da DLL
// Recebe um ponteiro e o índice do elemento a ser removido
int delete(struct Node *p, int index)
{
	struct Node *q;
	int x = -1, i;

	if(index < 1 || index > length(p))
		return -1;

	if(index == 1)
	{
		first = first->next;
		if(first)
			first->prev = NULL;
		x = p->data;
		free(p);
	}
	else
	{
		for(i=0;i<index-1;i++)
			p = p->next;
		p->prev->next = p->next;
		if(p->next)
			p->next->prev = p->prev;
		x = p->data;
		free(p);
	}
	return x;
}

// Função reverse: inverte os elementos da DLL
void reverse(struct Node *p)
{
	struct Node *temp;

	while(p != NULL)
	{
		temp = p->next;
		p->next = p->prev;
		p->prev = temp;
		p = p->prev;
		if(p != NULL && p->next == NULL)
			first = p;
	}
}

int main()
{
	int arr[] = {10,20,30,40,50,60,70};
	create(arr,7);
	insert(first,2,25);
	insert(first,7,45);
	delete(first,1);
	delete(first,8);
	reverse(first);
	printf("Tamanho da lista é: %d\n",length(first));
	display(first);
}