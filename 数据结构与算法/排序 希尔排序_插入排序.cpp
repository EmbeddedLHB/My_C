#include <iostream>
using namespace std;

void insertion_sort(int* a, const int& n);
void shell_sort(int* a, const int& n);

int main()
{
	int a[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

	shell_sort(a, 10);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	return 0;
}

// Time complexity best case: n, worst case: n^2
void insertion_sort(int* a, const int& n)
{
	int tmp = 0;
	int i = 0;
	// The first card is already in the hand
	for (int p = 1; p < n; p++)
	{
		tmp = a[p];  // Get next card
		for (i = p; i && a[i - 1] > tmp; i--)
			a[i] = a[i - 1];  // Remove the vacancy
		a[i] = tmp;  // New card position
	}
}

void shell_sort(int* a, const int& n)
{
	int i = 0;
	int tmp = 0;
	int si = 1;  // Shell increment
	// Shell incremental sequence
	int sedgewick[] = { 929, 505, 209, 109, 41, 19, 5, 1, 0 };
	// The initial increment sedgewick[si] can't exceed the length of th esequence to be sorted
	while (sedgewick[si] >= n)
		si++;
	for (int d = sedgewick[si]; d; d = sedgewick[++si])
		// A insertion sort
		for (int p = d; p < n; p++)
		{
			tmp = a[p];
			for (i = p; i >= d && a[i - d] > tmp; i -= d)
				a[i] = a[i - d];
			a[i] = tmp;
		}
}