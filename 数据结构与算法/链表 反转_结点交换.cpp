#include <iostream>
using namespace std;

typedef struct Links {
	int data;
	Links* next;
}*Link;

void init_link(Link& link);
void add_data(Link& link, const int data);
void traverse_link(Link& link);
void reverse_link(Link& link);
void find_pre(const Link& link, const Link& node, Link& pre);
void exchange_node(Link& link, Link& node1, Link& node2);

int main()
{
	Link link = NULL;
	init_link(link);
	for (int i = 0; i < 5; i++)
		add_data(link, i);
	traverse_link(link);

	reverse_link(link);
	exchange_node(link, link->next, link->next->next);
	traverse_link(link);
	return 0;
}

void init_link(Link& link)
{
	link = (Link)malloc(sizeof(Links));
	if (link == NULL)
		return;
	link->next = NULL;
}

void add_data(Link& link, const int data)
{
	Link p = link;
	Link add = (Link)malloc(sizeof(Links));

	if (add == NULL)
		return;
	while (p->next)
		p = p->next;
	add->data = data;
	add->next = NULL;
	p->next = add;
}

void traverse_link(Link& link)
{
	Link p = link->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << "\n";
}

void reverse_link(Link& link)
{
	if (link->next == NULL)
		return;
	Link p = link->next;
	Link head = link->next;
	Link next_node = NULL;

	while (p != NULL && p->next != NULL)
	{
		// If the sequence is link -> 5 -> 4 -> 3 -> 2 -> 1 -> NULL
		// Then p = 5, head = 5, next_node = 4
		next_node = p->next;
		// p = 5->3
		p->next = next_node->next;
		// next_node = 4->5
		next_node->next = head;
		// head = 4->5
		head = next_node;
		// After one transformation, the original linklist becomes
		// link  -> 5 -> 3 -> 2 -> 1,
		// and 4 -> 5 -> 3 -> 2 -> 1
	}
	link->next = head;
}

void find_pre(const Link& link, const Link& node, Link& pre)
{
	Link p = link;
	while (p->next != node)
		p = p->next;
	pre = p;
}

void exchange_node(Link& link, Link& node1, Link& node2)
{
	Link pre_node1 = NULL;
	Link post_node1 = NULL;
	Link pre_node2 = NULL;
	Link post_node2 = NULL;
	// If node1 or node2 is the head node, or node1 equals node2
	if (node1 == link || node2 == link || node1 == node2)
		return;

	find_pre(link, node1, pre_node1);
	find_pre(link, node2, pre_node2);
	post_node1 = node1->next;
	post_node2 = node2->next;

	// If node1 is next to node2
	if (post_node1 == node2)
	{
		pre_node1->next = node2;
		node2->next = node1;
		node1->next = post_node2;
		return;
	}
	if (post_node2 == node1)
	{
		pre_node2->next = node1;
		node1->next = node2;
		node2->next = post_node1;
		return;
	}

	// Another situation
	pre_node1->next = node2;
	node2->next = post_node1;
	pre_node2->next = node1;
	node1->next = post_node2;
}