#include <iostream>
using namespace std;

int main()
{
	int start = 0;
	int len = 0;
	int i = 0;
	int num[20][20] = { 0 };
	char s1[20] = { '\0' };
	char s2[20] = { '\0' };

	cin >> s1 >> s2;
	for (i = 0; i < strlen(s1); i++)
		for (int j = 0; j < strlen(s2); j++)
			if (s1[i] == s2[j])
			{
				num[i][j] = i && j ? num[i - 1][j - 1] + 1 : 1;
				if (len < num[i][j])
				{
					len = num[i][j];
					start = i - len + 1;
				}
			}
	for (i = start; i < start + len; i++)
		cout << s1[i];
	return 0;
}