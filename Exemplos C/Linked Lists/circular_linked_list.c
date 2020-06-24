#include <stdio.h>
#include <stdlib.h>

// Programa que cria uma Circular Linked List

// Estrutura que define uma CLL
struct Node
{
	int data;
	struct Node *next;
}*Head;

// Função create: Cria uma CCL, recebe um array e número de nodes
void create(int A[], int n)
{
	int i;
	struct Node *t, *last;
	Head = (struct Node*)malloc(sizeof(struct Node));
	Head->data=A[0];
	Head->next=Head;
	last=Head;

	for(i=1;i<n;i++)
	{
		t=(struct Node*)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=last->next;
		last->next=t;
		last=t;
	}
}

// Função display: imprime os elementos da CLL
void display(struct Node *h)
{
	do
	{
		printf("%d\n",h->data);
		h = h->next;	
	}while(h != Head);
}

// Função display_recursive: imprime recursivamente os elementos da CLL
void display_recursive(struct Node *h)
{
	static int flag=0;
	if(h != Head || flag == 0)
	{
		flag = 1;
		printf("%d\n",h->data);
		display_recursive(h->next);
	}
	flag=0;
}

// Função length: retorna o tamanho de uma CLL
int length(struct Node *p)
{
	int len=0;
	do
	{
		len++;
		p = p->next;
	}while(p != Head);
	return len;
}

// Função insert: insere um elemento na CLL
// Recebe como argumento um ponteiro, um índice e um elemento a ser inserido
void insert(struct Node *p, int index, int x)
{
	struct Node *t;
	int i;

	if(index < 0 || index > length(p))
		return;

	if(index == 0)
	{
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = x;
		if(Head == NULL)
		{
			Head=t;
			Head->next=Head;
		}
		else
		{
			while(p->next != Head)
			{
				p = p->next;
			}
			p->next = t;
			t->next = Head;
			Head = t;
		}
	}
	else
	{
		for(i=0;i<index-1;i++)
			p=p->next;
		t = (struct Node*)malloc(sizeof(struct Node));
		t->data = x;
		t->next = p->next;
		p->next = t;
	}
}

// Função delete: remove um elemento em uma determinada posição da CLL
int delete(struct Node *p, int index)
{
	struct Node *q;
	int i,x;

	if(index < 0 || index > length(Head))
		return -1;
	if(index == 1)
	{
		while(p->next != Head)
		{
			p = p->next;
		}
		x = Head->data;
		if(Head == p)
		{
			free(Head);
			Head = NULL;
		}
		else
		{
			p->next = Head->next;
			free(Head);
			Head = p->next;
		}
	}
	else
	{
		for(i=0;i<index-2;i++)
			p = p->next;
		q = p->next;
		p->next = q->next;
		x = q->data;
		free(q);
	}
	return x;
}

int main()
{
	int arr[] = {2,3,4,7,9};
	create(arr,5);
	insert(Head,0,1);
	insert(Head,5,13);
	printf("Elemento removido: %d\n",delete(Head,1));
	display(Head);
	printf("\n");
	display_recursive(Head);
	printf("Número de elementos da CLL é: %d\n",length(Head));
}