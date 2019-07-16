#include <iostream>
#define MAXSIZE 100
using namespace std;

typedef struct Trees {
	char data;
	Trees* lchild;
	Trees* rchild;
}*Tree;

void init(Tree& t);
void preorder(const Tree& t);
void inorder(const Tree& t);
void postorder(const Tree& t);
void level_order(const Tree& t);

int main()
{
	Tree t = NULL;
	cout << "Please input nodes according to preorder"
		<< "(represent an empty node with '#'): " << endl;
	init(t);
	preorder(t);
	return 0;
}

void init(Tree& t)
{
	char c;
	cin >> c;
	if (c == '#')
		t = NULL;
	else
	{
		t = (Tree)malloc(sizeof(Trees));
		if (t == NULL)
			return;
		t->data = c;
		init(t->lchild);
		init(t->rchild);
	}
}

void preorder(const Tree& t)
{
	if (t)
	{
		cout << t->data << " ";
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

void inorder(const Tree& t)
{
	if (t)
	{
		inorder(t->lchild);
		cout << t->data << " ";
		inorder(t->rchild);
	}
}

void postorder(const Tree& t)
{
	if (t)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		cout << t->data << " ";
	}
}

void level_order(const Tree& t)
{
	Tree tmp;
	Tree queue[MAXSIZE];
	int front = 0;
	int rear = 0;

	// Root node enqueue
	queue[rear++] = t;
	while (front < rear)
	{
		// Root node dequeue
		tmp = queue[front++];
		cout << tmp->data << " ";
		// The left child dequeue
		if (tmp->lchild)
			queue[rear++] = tmp->lchild;
		// The right child dequeue
		if (tmp->rchild)
			queue[rear++] = tmp->rchild;
	}
}