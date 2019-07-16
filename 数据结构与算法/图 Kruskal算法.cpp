#include <iostream>
#define MAXSIZE 100
#define INF 65535
using namespace std;

typedef struct Graphs {
	int vex[MAXSIZE];
	int arc[MAXSIZE][MAXSIZE];
	int num_vex, num_edge;
}*Graph;

typedef struct {
	int begin;
	int end;
	int weight;
}Edge;

void init(Graph& g);
void kruskal(const Graph& g, Edge* e);
int find(int* parent, int n);

int main()
{
	Graph g = NULL;
	Edge e[MAXSIZE] = { 0 };
	init(g);
	kruskal(g, e);
	return 0;
}

void init(Graph& g)
{
	int begin = 0;
	int end = 0;
	int weight = 0;

	g = (Graph)malloc(sizeof(Graphs));
	if (g == NULL)
		return;
	for (int i = 0; i < MAXSIZE; i++)
		g->vex[i] = 0;
	for (int i = 0; i < MAXSIZE; i++)
		for (int j = 0; j < MAXSIZE; j++)
			g->arc[i][j] = INF;

	cout << "Please input the number of vertexes and edges: ";
	cin >> g->num_vex >> g->num_edge;
	cout << "Please input vertexes: ";
	for (int i = 1; i <= g->num_vex; i++)
		cin >> g->vex[i];

	cout << "Please input edges and the weights:" << endl;
	for (int i = 0; i < g->num_edge; i++)
	{
		cin >> begin >> end >> weight;
		g->arc[begin][end] = weight;
		g->arc[end][begin] = weight;
	}
}

void kruskal(const Graph& g, Edge* e)
{
	int n = 0;
	int m = 0;
	int k = 0;  // The size of edge sets
	int parent[MAXSIZE] = { 0 };
	Edge tmp;

	// Build an array of edge sets and sort them
	for (int i = 0; i < g->num_vex - 1; i++)
		for (int j = i + 1; j < g->num_vex; j++)
			if (g->arc[i][j] < INF)
			{
				e[k].begin = i;
				e[k].end = j;
				e[k].weight = g->arc[i][j];
				k++;
			}
	for (int i = 0; i < k - 1; i++)
		for (int j = i + 1; j < k; j++)
			if (e[i].weight > e[j].weight)
			{
				tmp = e[i];
				e[i] = e[j];
				e[j] = tmp;
			}

	for (int i = 0; i < g->num_edge; i++)
	{
		n = find(parent, e[i].begin);
		m = find(parent, e[i].end);
		if (n != m)
		{
			parent[n] = m;
			cout << "(" << e[i].begin << ", " << e[i].end << ")";
			cout << " " << e[i].weight << endl;
		}
	}

}

int find(int* parent, int n)
{
	while (parent[n] > 0)
		n = parent[n];
	return n;
}