#include <iostream>
using namespace std;

typedef struct LinkList {
	char data;
	LinkList* next;
}*Link;

void push(Link& stack, const char& c);
void get_top(Link& stack, char& top);
void pop(Link& stack);

int main()
{
	char c = '\0';
	char top = '\0';
	Link stack = (Link)malloc(sizeof(LinkList));
	if (stack == NULL)
		return 0;
	stack->next = NULL;

	cout << "Please input a math expression with parenthesis:" << endl;
	while ((c = getchar()) != '\n')
	{
		// When c is left parenthesis, enter stack
		if (c == '(' || c == '[' || c == '{')
			push(stack, c);
		// If stack is not empty, and the expression is right parenthesis,
		// compare it, if it matches, then eliminate
		else if (c == ')' || c == ']' || c == '}')
		{
			get_top(stack, top);
			if ((c == ')' && top == '(') ||
				(c == ']' && top == '[') ||
				(c == '}' && top == '{'))
				pop(stack);
			else
				break;
		}
	}

	if (stack->next == NULL)
		cout << "Match successfully" << endl;
	else
		cout << "Match failed" << endl;
	return 0;
}

void push(Link& stack, const char& c)
{
	Link add = (Link)malloc(sizeof(LinkList));
	if (add == NULL)
		return;
	add->data = c;
	add->next = stack->next;
	stack->next = add;
}

void get_top(Link& stack, char& top)
{
	Link temp;
	if (stack->next == NULL)
	{
		cout << "Match failed" << endl;
		exit(0);
	}
	top = stack->next->data;
}

void pop(Link& stack)
{
	Link temp = stack->next;
	stack->next = temp->next;
	free(temp);
}