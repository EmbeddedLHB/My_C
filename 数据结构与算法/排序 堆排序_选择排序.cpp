#include <iostream>
using namespace std;

void selection_sort(int* a, const int& n);

int main()
{
	int a[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

	swap_sort(a, 10);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	return 0;
}

void selection_sort(int* a, const int& n)
{
	int max = 0;  // The subscript of maxvalue
	int tmp = 0;

	for (int i = 0; i < n - 1; i++)
	{
		max = i;
		for (int j = i + 1; j < n; j++)
			if (a[max] < a[j])
				max = j;
		tmp = a[i];
		a[i] = a[max];
		a[max] = tmp;
	}
}
