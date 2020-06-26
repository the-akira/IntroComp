#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

// Programa que define uma estrutura Tree

struct Node *root = NULL;

// função create_tree: cria uma árvore binária
void create_tree()
{
	struct Node *p, *t;
	int x;
	struct Queue q;
	create(&q,100);

	printf("Entre o valor do root: ");
	if(scanf("%d", &x)){};
	root = (struct Node *)malloc(sizeof(struct Node));
	root->data = x;
	root->lchild = root->rchild = NULL;
	enqueue(&q,root);

	while(!is_empty(q))
	{
		p = dequeue(&q);
		printf("Entre o left child de %d: ",p->data);
		if(scanf("%d", &x)){};
		if(x != -1)
		{
			t = (struct Node *)malloc(sizeof(struct Node));
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->lchild = t;
			enqueue(&q,t);
		}
		printf("Entre o right child de %d: ",p->data);
		if(scanf("%d", &x)){};
		if(x != -1)
		{
			t = (struct Node *)malloc(sizeof(struct Node));
			t->data = x;
			t->lchild = t->rchild = NULL;
			p->rchild = t;
			enqueue(&q,t);
		}
	}
}

// função pre_order: imprime os dados em preorder
void pre_order(struct Node *p)
{
	if(p)
	{
		printf("%d\n",p->data);
		pre_order(p->lchild);
		pre_order(p->rchild);
	}
}

// função in_order: imprime os dados em inorder
void in_order(struct Node *p)
{
	if(p)
	{
		in_order(p->lchild);
		printf("%d\n",p->data);
		in_order(p->rchild);
	}
}

// função post_order: imprime os dados em postorder
void post_order(struct Node *p)
{
	if(p)
	{
		post_order(p->lchild);
		post_order(p->rchild);
		printf("%d\n",p->data);
	}
}

// função iterative_pre_order: imprime os dados em postorder iterativamente
void iterative_pre_order(struct Node *p)
{
	struct Stack stk;
	create_stack(&stk,100);

	while(p || !is_empty_stack(stk))
	{
		if(p)
		{
			printf("%d\n",p->data);
			push(&stk,p);
			p = p->lchild;
		}
		else
		{
			p = pop(&stk);
			p = p->rchild;
		}
	}
}

// função iterative_in_order: imprime os dados em inorder iterativamente
void iterative_in_order(struct Node *p)
{
	struct Stack stk;
	create_stack(&stk,100);

	while(p || !is_empty_stack(stk))
	{
		if(p)
		{
			push(&stk,p);
			p = p->lchild;
		}
		else
		{
			p = pop(&stk);
			printf("%d\n",p->data);
			p = p->rchild;
		}
	}
}

// função level_order: imprime os dados da tree em levelorder
void level_order(struct Node *root)
{
	struct Queue q;
	create(&q,100);

	printf("%d\n",root->data);
	enqueue(&q,root);

	while(!is_empty(q))
	{
		root = dequeue(&q);
		if(root->lchild)
		{
			printf("%d\n",root->lchild->data);
			enqueue(&q,root->lchild);
		}
		if(root->rchild)
		{
			printf("%d\n",root->rchild->data);
			enqueue(&q,root->rchild);			
		}
	}
}

// função count: retorna o número de nodes da Tree
int count(struct Node *root)
{
	if(root)
		return count(root->lchild) + count(root->rchild) + 1;
	return 0;
}

// função height: retorna a altura da Tree
int height(struct Node *root)
{
	int x = 0, y = 0;
	if(root == 0)
		return 0;
	x = height(root->lchild);
	y = height(root->rchild);
	if(x > y)
		return x + 1;
	else
		return y + 1;
}

// função sum: retorna a soma dos elementos da Tree
int sum(struct Node *root)
{
	int x, y;
	if(root != NULL)
	{
		x = sum(root->lchild);
		y = sum(root->rchild);
		return x + y + root->data;
	}
	return 0;
}

// função count_leaft: retorna o número de folhas da Tree
int count_leaf(struct Node *root)
{
	int x, y;
	if(root != NULL)
	{
		x = count_leaf(root->lchild);
		y = count_leaf(root->rchild);
		if(root->lchild == NULL && root->rchild == NULL)
			return x + y + 1;
		else
			return x + y;
	}
	return 0;
}

// função degree_two: retorna o número de nodes de grau 2
int degree_two(struct Node *root)
{
	int x, y;
	if(root != NULL)
	{
		x = degree_two(root->lchild);
		y = degree_two(root->rchild);
		if(root->lchild != NULL && root->rchild != NULL)
			return x + y + 1;
		else
			return x + y;
	}
	return 0;
}

// função degree_one: retorna o número de nodes de grau 1
int degree_one(struct Node *root)
{
	int x, y;
	if(root != NULL)
	{
		x = degree_one(root->lchild);
		y = degree_one(root->rchild);
		if(root->lchild != NULL ^ root->rchild != NULL)
			return x + y + 1;
		else
			return x + y;
	}
	return 0;
}

int main()
{
	create_tree();
	pre_order(root);
	printf("\n");
	iterative_pre_order(root);
	printf("\n");
	post_order(root);
	printf("\n");
	in_order(root);
	printf("\n");
	iterative_in_order(root);
	printf("\n");
	level_order(root);
	printf("Número de Nodes = %d\n",count(root));
	printf("Altura da Tree = %d\n",height(root));
	printf("Soma dos valores da Tree = %d\n",sum(root));
	printf("Número de folhas da Tree = %d\n",count_leaf(root));
	printf("Número de nodes da Tree de Grau 2 = %d\n",degree_two(root));
	printf("Número de nodes da Tree de Grau 1 = %d\n",degree_one(root));
}