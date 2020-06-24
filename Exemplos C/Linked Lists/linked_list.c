#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Criando uma Linked List em C

/* Struct que define um Node da LL */
struct Node 
{
	int data;
	struct Node *next;
}*first=NULL;

/* Função createLL: Cria uma Linked List */
// Recebe um array e o número de nodes como argumento
void createLL(int A[], int n)
{
	int i;
	struct Node *t, *last;
	first = (struct Node *)malloc(sizeof(struct Node));
	first->data=A[0];
	first->next=NULL;
	last=first;

	for(i=1;i<n;i++)
	{
		t=(struct Node *)malloc(sizeof(struct Node));
		t->data=A[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}

/* Função display: Função que apresenta a LL */
void display(struct Node *p)
{
	while(p != NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}

/* Função display_recusrive: Função recursiva que apresenta os dados da LL*/
void display_recursive(struct Node *p)
{
	if(p != NULL)
	{
		printf("%d\n",p->data);
		display_recursive(p->next);
	}
}

/* Função count: conta o número de nodes na LL */
int count(struct Node *p)
{
	int total=0;
	while(p)
	{
		total++;
		p=p->next;
	}
	return total;
}

/* Função count_recursive: conta recursivamente o número de nodes na LL */
int count_recursive(struct Node *p)
{
	if(p != NULL)
		return count_recursive(p->next) + 1;
	else
		return 0;
}

/* Função sum: retorna a soma dos elementos da LL */
int sum(struct Node *p)
{
	int s=0;
	while(p != NULL)
	{
		s += p->data;
		p=p->next;
	}
	return s;
}

/* Função sum_recursive: retorna recursivamente a soma dos elementos da LL */
int sum_recursive(struct Node *p)
{
	if(p == NULL)
		return 0;
	else
		return sum_recursive(p->next) + p->data;
}

/* Função max: Retorna o maior elemento da LL */
int max(struct Node *p)
{
	int max = INT_MIN;

	while(p != NULL)
	{
		if(p->data > max)
			max=p->data;
		p=p->next;
	}
	return max;
}

/* Função max_recursive: Retorna recursivamente o maior elemento da LL */
int max_recursive(struct Node *p)
{
	int x = 0;
	if(p == 0)
		return INT_MIN;
	x = max_recursive(p->next);
	if(x > p->data)
		return x;
	else
		return p->data;
}

/* Função min: Retorna o menor elemento da LL */
int min(struct Node *p)
{
	int m = INT_MAX;

	while(p != NULL)
	{
		if(p->data < m)
			m=p->data;
		p=p->next;
	}
	return m;
}

/* Função min_recursive: Retorna recursivamente o menor elemento da LL */
int min_recursive(struct Node *p)
{
	int x = 0;
	if(p == 0)
		return INT_MAX;
	x = min_recursive(p->next);
	if(x < p->data)
		return x;
	else
		return p->data;
}

/* Função linear_search: busca um elemento de determinada chave na LL*/
struct Node* linear_search(struct Node *p, int key)
{
	while(p != NULL)
	{
		if(key == p->data)
			return p;
		p=p->next;
	}
	return NULL;
}

/* Função linear_search_rec: busca recursivamente um elemento de determinada chave na LL */
struct Node* linear_search_rec(struct Node *p, int key)
{
	if(p == NULL)
		return NULL;
	if(key == p->data)
		return p;
	return linear_search_rec(p->next,key);
}

/* Função insert: insere um elemento em uma determinada posição da LL */
void insert(struct Node *p, int index, int x)
{
	struct Node *t;
	if(index < 0 || index > count(p))
		return;
	t = (struct Node *)malloc(sizeof(struct Node));
	t->data = x;

	if(index == 0)
	{
		t->next = first;
		first = t;
	}
	else
	{
		for(int i=0;i<index-1;i++)
			p=p->next;
		t->next = p->next;
		p->next = t;
	}
}

/* Função delete: deleta um elemento em um determinado índice */
int delete(struct Node *p, int index)
{
	struct Node *q=NULL;
	int x = -1, i;

	if(index < 1 || index > count(p))
		return -1;
	if(index == 1)
	{
		q = first;
		x = first->data;
		first = first->next;
		free(q); 
		return x;
	}
	else 
	{
		for(i=0;i<index-1;i++)
		{
			q=p; 
			p=p->next;
		}
		q->next = p->next;
		x = p->data;
		free(p);
		return x;
	}
}

/* Função is_sorted: checa se uma LL está ordenada */
int is_sorted(struct Node *p)
{
	int x = INT_MIN;

	while(p != NULL)
	{
		if(p->data < x)
			return 0;
		x = p->data;
		p = p->next;
	}
	return 1;
}

/* Função remove_duplicates: remove elementos duplicados de uma LL ordenada */
void remove_duplicates_sortedLL(struct Node *p)
{
	struct Node *q = p->next;

	while(q != NULL)
	{
		if(p->data != q->data)
		{
			p=q;
			q=q->next;
		}
		else 
		{
			p->next=q->next;
			free(q);
			q=p->next;
		}
	}
}

/* Função remove_duplicates: remove elementos duplicados de uma LL */
void remove_duplicates(struct Node *p)
{
	struct Node *pt1, *pt2, *dup;
	pt1 = first;

	while(pt1 != NULL && pt1->next != NULL)
	{
		pt2 = pt1;

		while(pt2->next != NULL)
		{
			if(pt1->data == pt2->next->data)
			{
				dup = pt2->next;
				pt2->next = pt2->next->next;
				free(dup);
			}
			else
				pt2 = pt2->next;
		}
		pt1 = pt1->next;
	}
}

/* Função reverse_array: inverte os elementos de uma LL usando um array*/
void reverse_array(struct Node *p)
{
	int *A, i=0;
	struct Node *q=p;
	A=(int *)malloc(sizeof(int)*count(p));

	while(q != NULL)
	{
		A[i] = q->data;
		q = q->next;
		i++;
	}
	q = p;
	i--;

	while(q != NULL)
	{
		q->data = A[i];
		q = q->next;
		i--;
	}
}

/* Função reverse: inverte os elementos de uma LL */
void reverse(struct Node *p)
{
	struct Node *q=NULL, *r=NULL;

	while(p != NULL)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r; 
	} 
	first = q;
}

/* Função reverse_recursive: inverte recursivamente os elementos de uma LL */
void reverse_recursive(struct Node *q, struct Node *p)
{
	if(p)
	{
		reverse_recursive(p,p->next);
		p->next = q;
	}
	else
		first = q;
}

int main()
{
	struct Node *temp1;
	struct Node *temp2;
	int arr[]={1,0,1,2,3,4,5,13,13,14,14,1,2,3};
	createLL(arr,14);
	insert(first,0,15);
	insert(first,4,6);
	display(first);
	printf("Elemento deletado: %d\n",delete(first,1));
	printf("Elemento deletado: %d\n",delete(first,9));
	printf("\n");
	remove_duplicates(first);
	// remove_duplicates_sortedLL(first);
	display(first);
	printf("\n");
	reverse_recursive(NULL,first);
	display_recursive(first);
	printf("Tamanho da LL é: %d\n",count(first));
	printf("Tamanho da LL é: %d\n",count_recursive(first));
	printf("Soma dos elementos da LL é: %d\n",sum(first));
	printf("Soma dos elementos da LL é: %d\n",sum_recursive(first));
	printf("O maior elemento é: %d\n",max(first));
	printf("O maior elemento é: %d\n",max_recursive(first));
	printf("O menor elemento é: %d\n",min(first));
	printf("O menor elemento é: %d\n",min_recursive(first));
	temp1 = linear_search(first,13);
	temp2 = linear_search_rec(first,14);
	if(temp1)
		printf("Key foi encontrada %d\n",temp1->data);
	else
		printf("Key não foi encontrada\n");
	if(temp2)
		printf("Key foi encontrada %d\n",temp2->data);
	else
		printf("Key não foi encontrada\n");
	printf("Lista está ordenada? %d\n",is_sorted(first));
}