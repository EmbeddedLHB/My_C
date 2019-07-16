#include <iostream>
#define MAXSIZE 20
#define MINDATA -1000
using namespace std;

typedef struct Nodes {
	char code[10];
	char data;
	int weight;
	Nodes* lchild;
	Nodes* rchild;
}*Node;

typedef struct Heap {
	int size;
	Node* node;
}*MinHeap;

void init_min_heap(MinHeap& h);
void adjust_order(MinHeap& h);
void add_node(MinHeap& h, Node& add);
void get_min(MinHeap& h, Node& min_node);
void create_Huffman(MinHeap& h);
void code(Node& node);
void order(const Node& node);

int main()
{
	MinHeap h;
	init_min_heap(h);
	adjust_order(h);
	create_Huffman(h);
	code(h->node[1]);
	order(h->node[1]);
	return 0;
}

void init_min_heap(MinHeap& h)
{
	char c;
	int weight;
	int n;

	h = (MinHeap)malloc(sizeof(Heap));
	if (h == NULL)
		return;
	h->node = (Node*)malloc(MAXSIZE * sizeof(Nodes));
	if (h->node == NULL)
		return;
	h->node[0] = (Node)malloc(sizeof(Nodes));
	if (h->node[0] == NULL)
		return;

	cout << "Please input the number of characters: ";
	cin >> n;
	if (n > MAXSIZE - 1)
	{
		cout << "Memory excedded limit";
		exit(0);
	}
	h->size = n;
	h->node[0]->weight = MINDATA;

	cout << "Please input characters and weight: " << endl;
	// Subscript starts from 1
	for (int i = 1; i <= n; i++)
	{
		h->node[i] = (Node)malloc(sizeof(Nodes));
		if (h->node[i] == NULL)
			return;
		cin >> c >> weight;
		for (int j = 0; j < 10; j++)
			h->node[i]->code[j] = '\0';
		h->node[i]->data = c;
		h->node[i]->weight = weight;
		h->node[i]->lchild = NULL;
		h->node[i]->rchild = NULL;
	}
}

void adjust_order(MinHeap& h)
{
	int parent = 0;
	int child = 0;
	Node root = NULL;
	for (int i = h->size / 2; i; i--)
	{
		root = h->node[i];
		for (parent = i; parent * 2 <= h->size; parent = child)
		{
			child = parent * 2;
			// The miner one
			if (child != h->size && h->node[child]->weight > h->node[child + 1]->weight)
				child++;
			// Find the appropriate
			if (root->weight <= h->node[child]->weight)
				break;
			else
				h->node[parent] = h->node[child];
		}
		h->node[parent] = root;
	}
}

void add_node(MinHeap& h, Node& add)
{
	int i;
	if (h->size + 1 > MAXSIZE)
	{
		cout << "MinHeap is full";
		exit(0);
	}
	// i points to the position of the last element in the heap after the insertion
	i = ++h->size;
	// If the parental weight is greater than the weight of the new node,
	// the parents become subtrees, and i points to both parents
	for (; h->node[i / 2]->weight > add->weight; i /= 2)
		h->node[i] = h->node[i / 2];
	h->node[i] = add;
}

void get_min(MinHeap& h, Node& min_node)
{
	int parent;
	int child;
	Node x;
	if (h->size == 0)
	{
		cout << "MinHeap is empty";
		exit(0);
	}
	min_node = h->node[1];
	// x is the last node, filtering nodes from the root node
	x = h->node[h->size--];
	for (parent = 1; parent * 2 <= h->size; parent = child)
	{
		child = parent * 2;
		// child points to the smaller of the left and right child nodes
		if (child != h->size && h->node[child] > h->node[child + 1])
			child++;
		if (x->weight <= h->node[child]->weight)
			break;
		else
			h->node[parent] = h->node[child];
	}
	h->node[parent] = x;
}

void create_Huffman(MinHeap& h)
{
	Node min_node1 = NULL;
	Node min_node2 = NULL;
	Node add = NULL;
	int num_node = h->size;

	for (int i = 0; i < num_node - 1; i++)
	{
		get_min(h, min_node1);
		get_min(h, min_node2);
		add = (Node)malloc(sizeof(Nodes));
		if (add == NULL)
			return;
		for (int j = 0; j < 10; j++)
			add->code[j] = '\0';
		add->data = '\0';
		add->weight = min_node1->weight + min_node2->weight;
		add->lchild = min_node1;
		add->rchild = min_node2;
		add_node(h, add);
	}
}

void code(Node& node)
{
	if (node)
	{
		if (node->lchild)
		{
			strcpy_s(node->lchild->code, strlen(node->code) + 1, node->code);
			node->lchild->code[strlen(node->code)] = '0';
		}
		if (node->rchild)
		{
			strcpy_s(node->rchild->code, strlen(node->code) + 1, node->code);
			node->rchild->code[strlen(node->code)] = '1';
		}
		code(node->lchild);
		code(node->rchild);
	}
}

void order(const Node& node)
{
	if (node)
	{
		if (!node->lchild && !node->rchild && node->data != '\0')
			cout << node->data << "'s code is: " << node->code << endl;
		order(node->lchild);
		order(node->rchild);
	}
}
