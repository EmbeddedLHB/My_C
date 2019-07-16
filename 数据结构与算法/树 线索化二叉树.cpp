#include <iostream>
using namespace std;

typedef enum { Link, Thread } PointTag;

typedef struct Trees {
	char data;
	Trees* lchild;
	Trees* rchild;
	PointTag l_tag;
	PointTag r_tag;
}*Tree;
Tree pre = (Tree)malloc(sizeof(Tree));

void init(Tree& t);
void in_thread(Tree t);
void add_node(Tree& t);
void inorder(Tree t);

int main()
{
	Tree t = NULL;
	init(t);
	add_node(t);
	inorder(t);
	return 0;
}

void init(Tree& t)
{
	char c;
	cin >> c;
	if (c == '0')
		t = NULL;
	else
	{
		t = (Tree)malloc(sizeof(Tree));
		t->data = c;
		t->l_tag = Link;
		t->r_tag = Link;
		init(t->lchild);
		init(t->rchild);
	}
}

void in_thread(Tree t)
{
	if (t)
	{
		in_thread(t->lchild);
		if (!t->lchild)
		{
			t->l_tag = Thread;
			t->lchild = pre;
		}
		if (!pre->rchild)
		{
			pre->r_tag = Thread;
			pre->rchild = t;
		}
		pre = t;
		in_thread(t->rchild);
	}
}

void add_node(Tree& t)
{
	Tree p = (Tree)malloc(sizeof(Tree));
	p->l_tag = Link;
	p->r_tag = Thread;
	p->lchild = t;
	p->rchild = p;

	pre = p;
	in_thread(t);
	pre->r_tag = Thread;
	pre->rchild = p;
	p->rchild = pre;
}

void inorder(Tree t)
{
	Tree p = t->lchild;
	while (p != t)
	{
		while (p->l_tag == Link)
			p = p->lchild;
		cout << p->data << " ";
		while (p->r_tag == Thread && p->rchild != t)
		{
			p = p->rchild;
			cout << p->data << " ";
		}
		p = p->rchild;
	}
}