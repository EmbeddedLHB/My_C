#include <iostream>
using namespace std;

int main()
{
	char c = '\0';  // A character to receive istream
	char stack[20] = { '\0' };
	int top = -1;

	cout << "Please input a math expression with parenthesis:" << endl;
	while ((c = getchar()) != '\n')
	{
		// When c is left parenthesis, enter stack
		if (c == '(' || c == '[' || c == '{')
			stack[++top] = c;
		// If stack is not empty, and the expression is right parenthesis,
		// compare it, if it matches, then eliminate
		else if (c == ')' || c == ']' || c == '}')
		{
			if (top >= 0 && (
				(c == ')' && stack[top] == '(') ||
				(c == ']' && stack[top] == '[') ||
				(c == '}' && stack[top] == '{')))
				top--;
			else
				break;
		}
	}

	if (top == -1)
		cout << "Match successfully" << endl;
	else
		cout << "Match failed" << endl;
	return 0;
}