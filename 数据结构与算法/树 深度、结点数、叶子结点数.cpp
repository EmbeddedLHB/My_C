#include <iostream>
using namespace std;

typedef struct Trees {
	char data;
	Trees* lchild;
	Trees* rchild;
}*Tree;

void init(Tree& t);
int calc_depth(Tree& t);
int calc_num_node(Tree& t);
int calc_num_leaf(Tree& t);

int main()
{
	Tree t = NULL;
	cout << "Please input nodes according to preorder"
		<< "(represent an empty node with '#'): " << endl;
	init(t);
	cout << "The depth of the binary tree is: " << calc_depth(t) << endl;
	cout << "The total number of nodes of the binary tree is: " << calc_num_node(t) << endl;
	cout << "The number of the leaf nodes of the binary tree is: " << calc_num_leaf(t) << endl;
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

int calc_depth(Tree& t)
{
	int l, r;
	if (t == NULL)
		return 0;
	if (!t->lchild && !t->rchild)
		return 1;
	else
	{
		l = calc_depth(t->lchild);
		r = calc_depth(t->rchild);
		if (r < l)
			r = l;
		return r + 1;
	}
}

int calc_num_node(Tree& t)
{
	int l, r;
	if (t == NULL)
		return 0;
	if (!t->lchild && !t->rchild)
		return 1;
	else
	{
		l = calc_num_node(t->lchild);
		r = calc_num_node(t->rchild);
		return l + r + 1;
	}
}

int calc_num_leaf(Tree& t)
{
	int l, r;
	if (t == NULL)
		return 0;
	if (!t->lchild && !t->rchild)
		return 1;
	else
	{
		l = calc_num_leaf(t->lchild);
		r = calc_num_leaf(t->rchild);
		return l + r;
	}
}