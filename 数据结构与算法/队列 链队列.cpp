#include <iostream>
using namespace std;

typedef struct Nodes {
	int data;
	Nodes* next;
}*Node;

typedef struct Queues {
	Node front;
	Node rear;
}*Queue;

void init(Queue& q);
void enqueue(Queue& q);
void dequeue(Queue& q);

int main()
{
	Queue q = NULL;
	init(q);
	for (int i = 0; i < 3; i++)
		enqueue(q);
	for (int i = 0; i < 3; i++)
		dequeue(q);
	return 0;
}

void init(Queue& q)
{
	q = (Queue)malloc(sizeof(Queues));
	if (q == NULL)
		return;
	q->front = (Node)malloc(sizeof(Nodes));
	if (q->front == NULL)
		return;

	q->front->next = NULL;
	q->rear = q->front;
}

void enqueue(Queue& q)
{
	int data = 0;
	Node add = (Node)malloc(sizeof(Nodes));
	if (add == NULL)
		return;

	cout << "Please input data: ";
	cin >> data;
	add->data = data;
	add->next = NULL;
	q->rear->next = add;
	q->rear = add;
}

void dequeue(Queue& q)
{
	Node pr = NULL;
	if (q->front == q->rear)
	{
		cout << "Queue is full" << endl;
		return;
	}
	pr = q->front->next;
	q->front->next = pr->next;
	if (pr == q->rear)
		q->front = q->rear;
	cout << "The departure element is: " << pr->data;
	free(pr);
}