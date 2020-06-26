#include <stdio.h>
#include <stdlib.h>

// Programa que define uma Binary Search Tree

// Estrutura que define um Node
struct Node
{
	struct Node *lchild;
	int data;
	struct Node *rchild;
}*root=NULL;

// função insert: insere um elemento na BST
void insert(int key)
{
	struct Node *t = root;
	struct Node *r=NULL, *p;

	if(root == NULL)
	{
		p = (struct Node *)malloc(sizeof(struct Node));
		p->data = key;
		p->lchild = p->rchild = NULL;
		root = p;
		return;
	}
	while(t != NULL)
	{
		r = t;
		if(key < t->data)
			t = t->lchild;
		else if(key > t->data)
			t = t->rchild;
		else
			return;
	}
	p = (struct Node *)malloc(sizeof(struct Node));
	p->data = key;
	p->lchild = p->rchild = NULL;
	if(key < r->data)
		r->lchild = p;
	else
		r->rchild = p;
}

// função in_order: imprime os elementos da BST inorder
void in_order(struct Node *p)
{
	if(p)
	{
		in_order(p->lchild);
		printf("%d\n",p->data);
		in_order(p->rchild);
	}
}

// função search: busca por um determina elemento na BST
struct Node* search(int key)
{
	struct Node *t = root;

	while(t != NULL)
	{
		if(key == t->data)
			return t;
		else if(key < t->data)
			t = t->lchild;
		else
			t = t->rchild;
	}
	return NULL;
}

// função recursive_insert: insere recursivamente um determinado elemento na BST
struct Node* recursive_insert(struct Node *p, int key)
{
	struct Node *t = NULL;
	if(p == NULL)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = key;
		t->lchild = t->rchild = NULL;
		return t;
	}
	if(key < p->data)
		p->lchild = recursive_insert(p->lchild,key);
	else if(key > p->data)
		p->rchild = recursive_insert(p->rchild,key);
	return p;
} 

// função height: retorna a altura da Binary Search Tree
int height(struct Node *p)
{
	int x, y;
	if(p == NULL)
		return 0;
	x = height(p->lchild);
	y = height(p->rchild);
	return x > y ? x + 1 : y + 1;
}

// função in_pre: retorna o predecessor inorder
struct Node* in_pre(struct Node *p)
{
	while(p && p->rchild != NULL)
		p = p->rchild;
	return p;
} 

// função in_succ: retorna o sucessor inorder
struct Node* in_succ(struct Node *p)
{
	while(p && p->lchild != NULL)
		p = p->lchild;
	return p;
} 

// função delete: remove um determinado elemento da BST
struct Node* delete(struct Node *p, int key)
{
	struct Node *q;
	if(p == NULL)
		return NULL;
	if(p->lchild == NULL && p->rchild == NULL)
	{
		if(p == root)
			root = NULL;
		free(p);
		return NULL;
	}
	if(key < p->data)
		p->lchild = delete(p->lchild,key);
	else if(key > p->data)
		p->rchild = delete(p->rchild,key);
	else
	{
		if(height(p->lchild) > height(p->rchild))
		{
			q = in_pre(p->lchild);
			p->data = q->data;
			p->lchild = delete(p->lchild,q->data);
		}
		else
		{
			q = in_succ(p->rchild);
			p->data = q->data;
			p->rchild = delete(p->rchild,q->data);
		}
	}
	return p;
}

int main()
{
	struct Node *temp;
	insert(10);
	insert(5);
	insert(20);
	insert(7);
	insert(35);
	delete(root,20);
	in_order(root);
	temp = search(20);
	if(temp != NULL)
		printf("Elemento %d foi encontrado\n",temp->data);
	else
		printf("Elemento não foi encontrado\n");
}