#include <iostream>
#define MAXSIZE 100
using namespace std;

int visited[MAXSIZE] = { 0 };
int visited1[MAXSIZE] = { 0 };

typedef struct MyGraph {
	int vex[MAXSIZE];
	int arc[MAXSIZE][MAXSIZE];
	int num_vex, num_edge;
}*Graph;

void init(Graph& g);
void df_traverse(const Graph& g);
void df(const Graph& g, const int n);
void bf_traverse(const Graph& g);

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

	g = (Graph)malloc(sizeof(MyGraph));
	if (g == NULL)
		return;
	for (int i = 0; i < MAXSIZE; i++)
		for (int j = 0; j < MAXSIZE; j++)
			g->arc[i][j] = 0;

	cout << "Please input the number of vertexes and edges: ";
	cin >> g->num_vex >> g->num_edge;
	cout << "Please input vertexes: ";
	for (int i = 1; i <= g->num_vex; i++)
		cin >> g->vex[i];

	cout << "Please input edges and the weights:" << endl;
	// If vertex begin at 0 then the array is arc[begin][end] and arc[end][begin]
	for (int i = 0; i < g->num_edge; i++)
	{
		cin >> begin >> end;
		if (begin && end)
		{
			g->arc[begin - 1][end - 1] = 1;
			// If this is a directed graph, comment the next line
			g->arc[end - 1][begin - 1] = 1;
		}
	}
}

void df_traverse(const Graph& g)
{
	cout << "The depth-first traversal sequence of the graph is:" << endl;
	for (int i = 0; i < g->num_vex; i++)
		if (!visited[i])
			df(g, i);
}

void df(const Graph& g, const int n)
{
	cout << g->vex[n] << " ";
	visited[n] = 1;

	for (int i = 0; i < g->num_vex; i++)
		if (!visited[i] && g->arc[n][i])
			df(g, i);
}

void bf_traverse(const Graph& g)
{
	int queue[MAXSIZE];
	int front = 0;
	int rear = 0;

	cout << "The breadth-first traversal sequence of the graph is:" << endl;
	for (int i = 0; i < g->num_vex; i++)
		if (!visited1[i])
		{
			visited1[i] = 1;
			cout << g->vex[i] << " ";
			queue[rear++] = i;

			while (front < rear)
			{
				i = queue[front++];
				for (int j = 0; j < g->num_vex; j++)
					if (!visited1[j] && g->arc[i][j])
					{
						visited1[j] = 1;
						cout << g->vex[j] << " ";
						queue[rear++] = j;
					}
			}
		}
}