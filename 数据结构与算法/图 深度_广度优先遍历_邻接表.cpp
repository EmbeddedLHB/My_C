#include <iostream>
#define MAXSIZE 100
#define FALSE 0
#define TRUE 1
using namespace std;

int visited[MAXSIZE] = { FALSE };

typedef struct ENode {
	int sub;
	ENode* next;
}*EdgeNode;

typedef struct VNode {
	int data;
	EdgeNode first_edge;
}*VexNode;

typedef struct Graphs {
	VexNode vex;
	int num_vex;
	int num_edge;
}*Graph;

struct Queue {
	int base[MAXSIZE];
	int front;
	int rear;
};

void init(Graph& g);
void df_traverse(const Graph& g);
void df(const Graph& g, const int& i);

void bf_traverse(const Graph& g);
void enqueue(Queue& q, const int& n);
void dequeue(Queue& q, int& top);

int main()
{
	Graph g;
	init(g);
	df_traverse(g);
	return 0;
}

void init(Graph& g)
{
	int begin = 0;
	int end = 0;
	EdgeNode e = NULL;

	g = (Graph)malloc(sizeof(Graphs));
	if (g == NULL)
		return;
	g->vex = (VexNode)malloc(MAXSIZE * sizeof(VNode));
	if (g->vex == NULL)
		return;

	cout << "Please input the number of vertexes and edges: ";
	cin >> g->num_vex >> g->num_edge;
	cout << "Please input vertexes: ";
	for (int i = 0; i < g->num_vex; i++)
	{
		cin >> g->vex[i].data;
		g->vex[i].first_edge = NULL;
	}

	cout << "Please input edges and the weights:" << endl;
	for (int i = 0; i < g->num_edge; i++)
	{
		cin >> begin >> end;
		e = (EdgeNode)malloc(sizeof(ENode));
		if (e == NULL)
			return;
		e->sub = end;
		e->next = g->vex[begin].first_edge;
		g->vex[begin].first_edge = e;

		e = (EdgeNode)malloc(sizeof(ENode));
		if (e == NULL)
			return;
		e->sub = begin;
		e->next = g->vex[end].first_edge;
		g->vex[end].first_edge = e;
	}
}

void df_traverse(const Graph& g)
{
	for (int i = 0; i < g->num_vex; i++)
		if (visited[i] == FALSE)
			df(g, i);
}

void df(const Graph& g, const int& n)
{
	EdgeNode e = g->vex[n].first_edge;
	visited[n] = TRUE;
	cout << g->vex[n].data << " ";
	while (e)
	{
		if (visited[e->sub] == FALSE)
			df(g, e->sub);
		e = e->next;
	}
}

void bf_traverse(const Graph& g)
{
	int top = 0;
	EdgeNode e = NULL;
	Queue q = { 0 };

	cout << "The breadth-first traversal sequence of the graph is:" << endl;
	for (int i = 0; i < g->num_vex; i++)
		if (!visited[i])
		{
			visited[i] = 1;
			cout << g->vex[i].data << " ";
			enqueue(q, i);

			while (1)
			{
				dequeue(q, top);
				e = g->vex[top].first_edge;
				while (e)
				{
					if (!visited[e->sub])
					{
						visited[e->sub] = 1;
						cout << g->vex[e->sub].data << " ";
						enqueue(q, e->sub);
					}
					e = e->next;
				}
			}
		}
}

void enqueue(Queue& q, const int& n)
{
	if ((q.rear + 1) % MAXSIZE == q.front)
		return;
	q.base[q.rear] = n;
	q.rear = (q.rear + 1) % MAXSIZE;
}

void dequeue(Queue& q, int& top)
{
	if (q.front == q.rear)
		exit(0);
	int temp = q.base[q.front];
	q.front = (q.front + 1) % MAXSIZE;
	top = temp;
}