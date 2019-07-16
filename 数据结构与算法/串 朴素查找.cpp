#include <iostream>
using namespace std;

int main()
{
	char s1[20];
	char s2[20];
	int m = 0;
	int n = 0;
	int max_len = 0;
	int len = 0;
	int start = 0;
	int end = 0;

	cin >> s1 >> s2;
	// Cracked through two cycles of brute force
	for (int i = 0; i < strlen(s1); i++)
		for (int j = 0; j < strlen(s2); j++)
		{
			len = 0;
			// The temporary subscipt
			m = i;
			n = j;
			// The subscript keep moving to the right continually
			// until the 2 characters are equal
			while (m < strlen(s1) && n < strlen(s2) && s1[m] == s2[n])
			{
				m++;
				n++;
				len++;
			}
			if (max_len < len)
			{
				max_len = len;
				start = i;
				// Minus the first character
				end = i + len - 1;
			}
		}
	cout << "The largest substring is:" << endl;
	for (int i = start; i <= end; i++)
		cout << s1[i];
	return 0;
}
