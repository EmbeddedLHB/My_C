#include <iostream>
#define MAXSIZE 100
using namespace std;

typedef struct Trees {
	char data;
	Trees* lchild;
	Trees* rchild;
}*Tree;

void init(Tree& t);
void inorder(Tree& t);

int main()
{
	Tree t = NULL;
	cout << "Please input nodes according to preorder"
		<< "(represent an empty node with '#'): " << endl;
	init(t);
	inorder(t);
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

void inorder(Tree& t)
{
	Tree stack[MAXSIZE];
	int top = -1;

	while (t || top >= 0)
	{
		// Find the left child tree
		while (t->lchild)
		{
			stack[++top] = t;
			t = t->lchild;
		}
		cout << t->data << " ";
		t = t->rchild;

		while (!t && top >= 0)
		{
			t = stack[top--];
			cout << t->data << " ";
			t = t->rchild;
		}
	}
}