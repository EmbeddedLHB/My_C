#include <iostream>
#define MAXSIZE 100
using namespace std;

// Return the next array of s2
void get_nextval(char* s2, int* nextval);
int KMP(char* s1, char* s2);

int main()
{
	char s1[20];
	char s2[20];
	cin >> s1 >> s2;
	cout << KMP(s1, s2) << endl;
	return 0;
}

// Return the next array of s2
void get_nextval(char* s2, int* nextval)
{
	int i = 0;
	int j = -1;
	int len = strlen(s2);

	nextval[0] = -1;
	while (i < len)
	{
		// t[i] represents a single character of the suffix
		// t[j] represents a single character of the prefix
		if (j == -1 || s2[i] == s2[j])
		{
			i++;
			j++;
			// If the current character is different from the prefix character,
			// the current j is the value of nextval at the i position
			if (s2[i] != s2[j])
				nextval[i] = j;
			// If the current character is different from the prefix character,
			// then the nextval value of the character is assigned to the value of
			// nextval at the i position
			else
				nextval[i] = nextval[j];
		}
		// If the characters are not the same, then the j value is backtracked
		else
			j = nextval[j];
	}
}

int KMP(char* s1, char* s2)
{
	int i = 0;
	int j = -1;
	int nextval[MAXSIZE] = { 0 };
	int s1_len = strlen(s1);
	int s2_len = strlen(s2);

	get_nextval(s2, nextval);
	while (i < s1_len && j < s2_len)
	{
		if (j == -1 || s1[i] == s2[j])
		{
			i++;
			j++;
		}
		else
			// If the characters are not the same, then the j value is backtracked
			j = nextval[j];
	}
	if (j >= s2_len)
		return i - s2_len;
	else
		return 0;
}