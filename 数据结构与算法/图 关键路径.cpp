#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

int *early_time, *late_time;
int *stack2, top2 = 0;
typedef struct EdgeNode {							//边表结点
	int subscript;
	int weight;
	struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode {							//顶点表结点
	int in;
	int data;
	EdgeNode *first_edge;
}VertexNode;

typedef struct {									//由顶点表为主体组成的图
	VertexNode vex[maxsize];
	int Vertex_num, Edge_num;
}Gragh;

Gragh *Create(void);
void Topo(Gragh *g);
void CriticalPath(Gragh *g);

int main()
{
	Gragh *g = Create();
	CriticalPath(g);
	return 0;
}

Gragh *Create(void)
{
	int i, j, k, v;
	Gragh *g = (Gragh *)malloc(sizeof(Gragh));
	EdgeNode *e;

	printf("Please input the number of Vertexes and Edges:");
	scanf_s("%d%d", &g->Vertex_num, &g->Edge_num);
	printf("Please input Vertexes:");
	for (i = 1; i <= g->Vertex_num; i++)				//输入顶点信息，建立	
	{
		scanf_s("%d", &g->vex[i].data);
		g->vex[i].in = 0;
		g->vex[i].first_edge = NULL;
	}

	printf("Please input Edges and Weights:\n");
	for (k = 1; k <= g->Edge_num; k++)
	{
		scanf_s("%d%d%d", &i, &j, &v);
		g->vex[j].in++;
		e = (EdgeNode *)malloc(sizeof(EdgeNode));
		e->subscript = j;							//边表下标赋值
		e->weight = v;								//路径长度赋值
		e->next = g->vex[i].first_edge;				//将e指针指向当前顶点指向的结点
		g->vex[i].first_edge = e;					//头插法
	}
	return g;
}

void Topo(Gragh *g)
{
	EdgeNode *e;
	int i, k, temp;
	int *stack = (int *)malloc(g->Vertex_num * sizeof(int)), top = 0;
	for (i = 1; i <= g->Vertex_num; i++)					//将入度为0的顶点入栈
		if (!g->vex[i].in)
			stack[++top] = i;

	early_time = (int *)malloc((g->Vertex_num + 1) * sizeof(int));//事件最早发生时间
	early_time[i] = { 0 };
	stack2 = (int *)malloc(g->Vertex_num * sizeof(int));

	while (top)
	{
		temp = stack[top--];								//出栈
		stack2[++top2] = temp;								//压入拓扑序列的栈
		for (e = g->vex[temp].first_edge; e; e = e->next)	//遍历此顶点
		{
			k = e->subscript;
			if (!(--g->vex[k].in))							//将邻接点的入度减1
				stack[++top] = k;							//如果为零，就入栈
			if ((early_time[temp] + e->weight) > early_time[k])
				early_time[k] = early_time[temp] + e->weight;
		}
	}
}

void CriticalPath(Gragh *g)
{
	EdgeNode *e;
	int i, k, temp;
	int early_num, late_num;								//发生时间的变量
	Topo(g);												//求拓扑序列
	late_time = (int *)malloc((g->Vertex_num + 1) * sizeof(int));
	for (i = 1; i <= g->Vertex_num; i++)					//初始化late_time
		late_time[i] = early_time[g->Vertex_num];
	while (top2)
	{
		temp = stack2[top2--];								//拓扑序列进栈
		for (e = g->vex[temp].first_edge; e; e = e->next)
		{
			k = e->subscript;
			if (late_time[k] - e->weight < late_time[temp])
				late_time[temp] = late_time[k] - e->weight;
		}
	}
	for (i = 1; i <= g->Vertex_num; i++)
		for (e = g->vex[i].first_edge; e; e = e->next)
		{
			k = e->subscript;
			early_num = early_time[i];
			late_num = late_time[k] - e->weight;
			if (early_num == late_num)
				printf("%d->%d length:%d\n", g->vex[i].data, g->vex[k].data, e->weight);
		}
}