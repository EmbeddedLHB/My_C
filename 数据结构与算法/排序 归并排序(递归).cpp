#include <iostream>
using namespace std;

// Time complexity: n^2
void merge_sort(int* a, const int& n);
void m_sort(int* a, int* tmp_a, int l, int right_end);
// Merge two numbers or two sequences
void merge(int* a, int* tmp_a, int l, int r, int right_end);

int main()
{
	int a[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

	merge_sort(a, 10);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	return 0;
}

// Time complexity: n^2
void merge_sort(int* a, const int& n)
{
	int* tmp_a = (int*)malloc(n * sizeof(int));
	if (tmp_a == NULL)
		return;
	m_sort(a, tmp_a, 0, n - 1);
	free(tmp_a);
}

void m_sort(int* a, int* tmp_a, int l, int right_end)
{
	int center = 0;
	if (l < right_end)
	{
		center = (l + right_end) / 2;
		m_sort(a, tmp_a, l, center);
		m_sort(a, tmp_a, center + 1, right_end);
		merge(a, tmp_a, l, center + 1, right_end);
	}
}

// Merge two sequences or two numbers
void merge(int* a, int* tmp_a, int l, int r, int right_end)
{
	// The left end position, assuming the left and right columns are next to each other
	int left_end = r - 1;
	int tmp = l;  // Store the initial position of the result array
	int num_elements = right_end - l + 1;

	// Get the smaller head element from two sequences
	while (l <= left_end && r <= right_end)
		if (a[l] <= a[r])
			tmp_a[tmp++] = a[l++];
		else
			tmp_a[tmp++] = a[r++];

	// Copy the remaining elements into an array
	while (l <= left_end)
		tmp_a[tmp++] = a[l++];
	while (r <= right_end)
		tmp_a[tmp++] = a[r++];
	for (int i = 0; i < num_elements; i++, right_end--)
		a[right_end] = tmp_a[right_end];
}