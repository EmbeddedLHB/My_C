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
void dijkstra(const Graph& g);

int main()
{
	Graph g = NULL;
	init(g);
	dijkstra(g);
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

// It's modified from prim algorithm
void dijkstra(const Graph& g)
{
	int min_distance = 0;
	int min = 0;
	// distance == 0 indicates that it has been calculated
	// distance[i] means the minimum distance from v0 to vi
	int distance[MAXSIZE] = { 0 };
	// vex[i] means the subscript of the minimum distance
	int vex[MAXSIZE] = { 0 };

	// Assign the first line of the matrix to the array
	for (int i = 1; i < g->num_vex; i++)
		distance[i] = g->arc[0][i];

	for (int i = 1; i < g->num_vex; i++)
	{
		min_distance = INF;
		min = 0;
		for (int j = 1; j < g->num_vex; j++)
			if (distance[j] != 0 && distance[j] < min_distance)
			{
				min_distance = distance[j];
				min = j;
			}

		cout << "(" << vex[min] << ", " << min << ")";
		cout << " " << g->arc[vex[min]][min] << endl;

		distance[min] = 0;
		for (int j = 1; j < g->num_vex; j++)
			if (distance[j] != 0 && min_distance + g->arc[min][j] < distance[j])
			{
				distance[j] = min_distance + g->arc[min][j];
				vex[j] = min;
			}
	}
}