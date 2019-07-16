#include <iostream>
using namespace std;

typedef struct LinkList {
	int data;
	LinkList* next;
}*Link;

void init(Link& list, int n);
void process(Link& list, int k, int m);

int main()
{
	int n = 0;
	int m = 0;
	int k = 0;
	Link list = NULL;

	cout << "n individuals start counting from people numbered k"
		<< " and people who report to m are listed" << endl;
	cout << "Please input the value of n, k, m: ";
	cin >> n >> k >> m;
	init(list, n);
	process(list, k, m);
	return 0;
}

void init(Link& list, int n)
{
	Link p = NULL;
	Link node = NULL;

	list = (Link)malloc(sizeof(LinkList));
	if (list == NULL)
		return;
	list->next = NULL;
	p = list;

	while (p->next)
		p = p->next;
	for (int i = 1; i <= n; i++)
	{
		node = (Link)malloc(sizeof(LinkList));
		if (node == NULL)
			return;
		node->data = i;
		node->next = NULL;
		p->next = node;
		p = node;
	}
	// circular queue
	p->next = list->next;
}

void process(Link& list, int k, int m)
{
	Link tmp = NULL;

	for (int i = 0; i < k - 1; i++)
		list = list->next;

	while (list->next != list)
	{
		for (int i = 0; i < m - 1; i++)
			list = list->next;
		tmp = list->next;
		cout << tmp->data << " ";
		list->next = tmp->next;
		free(tmp);
	}
	cout << "\nThe winner is " << list->data;
	free(list);
}