#include <iostream>
#define MAXSIZE 100
using namespace std;

int* earliest = NULL;
int* latest = NULL;
int* stack = NULL;
int top = -1;

typedef struct ENode {
	int sub;
	int weight;
	ENode* next;
}*EdgeNode;

typedef struct VNode {
	int in;
	int data;
	EdgeNode first_edge;
}*VexNode;

typedef struct Graphs {
	VexNode vex;
	int num_vex;
	int num_edge;
}*Graph;

void init(Graph& g);
void topo_sort(const Graph& g);
void critical_path(const Graph& g);

int main()
{
	Graph g;
	init(g);
	critical_path(g);
	return 0;
}

void init(Graph& g)
{
	EdgeNode e = NULL;
	int begin = 0;
	int end = 0;
	int weight = 0;

	g = (Graph)malloc(sizeof(Graphs));
	if (g == NULL)
		return;
	cout << "Please input the number of vertexes and edges: ";
	cin >> g->num_vex >> g->num_edge;
	cout << "Please input vertexes: ";

	g->vex = (VexNode)malloc(g->num_vex * sizeof(VNode));
	if (g->vex == NULL)
		return;
	earliest = (int*)malloc(g->num_vex * sizeof(int));
	if (earliest == NULL)
		return;
	latest = (int*)malloc(g->num_vex * sizeof(int));
	if (latest == NULL)
		return;
	stack = (int*)malloc(g->num_vex * sizeof(int));
	if (stack == NULL)
		return;

	for (int i = 0; i < g->num_vex; i++)
	{
		cin >> g->vex[i].data;
		g->vex[i].in = 0;
		g->vex[i].first_edge = NULL;
	}

	cout << "Please input edges and weight:" << endl;
	for (int i = 0; i < g->num_edge; i++)
	{
		cin >> begin >> end >> weight;
		g->vex[end].in++;
		e = (EdgeNode)malloc(sizeof(ENode));
		if (e == NULL)
			return;
		e->sub = end;
		e->weight = weight;
		e->next = g->vex[begin].first_edge;
		g->vex[begin].first_edge = e;
	}
}

void topo_sort(const Graph& g)
{
	EdgeNode e = NULL;
	int get_top = 0;
	int count = 0;
	int front = 0;
	int rear = 0;
	int k = 0;
	int* queue = (int*)malloc(g->num_vex * sizeof(int));

	if (queue == NULL)
		return;
	for (int i = 0; i < g->num_vex; i++)
		earliest[i] = 0;
	for (int i = 0; i < g->num_vex; i++)
		if (g->vex[i].in == 0)
			queue[rear++] = i;

	while (rear - front)
	{
		get_top = queue[front++];
		count++;
		stack[++top] = get_top;

		for (e = g->vex[get_top].first_edge; e; e = e->next)
		{
			k = e->sub;
			if (--g->vex[k].in == 0)
				queue[rear++] = k;
			if (earliest[get_top] + e->weight > earliest[k])
				earliest[k] = earliest[get_top] + e->weight;
		}
	}
	if (count < g->num_vex)
	{
		cout << "Existence ring";
		exit(0);
	}
}

void critical_path(const Graph& g)
{
	EdgeNode e = NULL;
	int k = 0;
	int get_top = 0;
	int early_num = 0;
	int late_num = 0;

	topo_sort(g);
	for (int i = 0; i < g->num_vex; i++)
		latest[i] = earliest[g->num_vex - 1];
	// Calculate the latest[]
	while (top)
	{
		get_top = stack[top--];
		for (e = g->vex[get_top].first_edge; e; e = e->next)
			if (latest[e->sub] - e->weight < latest[get_top])
				latest[get_top] = latest[e->sub] - e->weight;
	}

	for (int i = 0; i < g->num_vex; i++)
		for (e = g->vex[i].first_edge; e; e = e->next)
		{
			early_num = earliest[i];
			late_num = latest[e->sub] - e->weight;
			if (early_num == late_num)
				cout << g->vex[i].data << "->" << g->vex[e->sub].data
				<< " length: " << e->weight << endl;
		}
}