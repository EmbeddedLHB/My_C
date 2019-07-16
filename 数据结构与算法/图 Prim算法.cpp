#include <iostream>
#define MAXSIZE 100
#define INF 65535
using namespace std;

typedef struct Graphs {
	int vex[MAXSIZE];
	int arc[MAXSIZE][MAXSIZE];
	int num_vex, num_edge;
}*Graph;

void init(Graph& g);
void prim(const Graph& g);

int main()
{
	Graph g = NULL;
	init(g);
	prim(g);
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

void prim(const Graph& g)
{
	int min = 0;
	int min_sub = 0;
	// low_cost == 0 indicates that it has been incorporated
	// into the minimum spanning tree
	// low_cost[i] means the minimum distance
	int low_cost[MAXSIZE] = { 0 };
	// vex[i] means the subscript of the minimum distance
	int vex[MAXSIZE] = { 0 };

	// Assign the first line of the matrix to the array
	for (int i = 1; i < g->num_vex; i++)
		low_cost[i] = g->arc[0][i];

	for (int i = 1; i < g->num_vex; i++)
	{
		min = INF;
		min_sub = 0;
		for (int j = 1; j < g->num_vex; j++)
			if (low_cost[j] != 0 && low_cost[j] < min)
			{
				min = low_cost[j];
				min_sub = j;
			}

		cout << "(" << vex[min_sub] << ", " << min_sub << ")";
		cout << " " << g->arc[vex[min_sub]][min_sub] << endl;

		low_cost[min_sub] = 0;
		for (int j = 1; j < g->num_vex; j++)
			if (low_cost[j] != 0 && g->arc[min_sub][j] < low_cost[j])
			{
				low_cost[j] = g->arc[min_sub][j];
				vex[j] = min_sub;
			}
	}
}
