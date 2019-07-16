#include <iostream>
#define MAXSIZE 100
#define LEFT 0
#define RIGHT 1
using namespace std;

typedef struct Trees {
	char data;
	Trees* lchild;
	Trees* rchild;
}*Tree;

void init(Tree& t);
void order(const Tree& t);
void preorder(const Tree& t);

int main()
{
	Tree t = NULL;
	init(t);
	order(t);
	preorder(t);
	return 0;
}

void init(Tree& t)
{
	int direction = LEFT;
	int top = -1;
	char c = '\0';
	Tree add = NULL;
	Tree stack[MAXSIZE] = { NULL };

	while ((c = getchar()) != '\n')
	{
		if (c == '(')
		{
			stack[++top] = add;
			direction = LEFT;
		}
		else if (c == ')')
			top--;
		else if (c == ',')
			direction = RIGHT;
		else
		{
			add = (Tree)malloc(sizeof(Trees));
			if (add == NULL)
				return;
			add->data = c;
			add->lchild = NULL;
			add->rchild = NULL;
			if (t == NULL)
				t = add;
			else
				if (direction == LEFT)
					stack[top]->lchild = add;
				else if (direction == RIGHT)
					stack[top]->rchild = add;
		}
	}
}

void order(const Tree& t)
{
	if (t->lchild)
	{
		cout << t->data << "'s left child is: " << t->lchild->data << endl;
		order(t->lchild);
	}
	if (t->rchild)
	{
		cout << t->data << "'s right child is: " << t->rchild->data << endl;
		order(t->rchild);
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