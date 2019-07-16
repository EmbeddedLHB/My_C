#include <iostream>
using namespace std;

void merge_sort(int* a, const int& n);
// Merge a turn
void merge_pass(int* a, int* tmp_a, int n, int length);
// Merge two sequences or two numbers
void merge(int* a, int* tmp_a, int l, int r, int right_end);

int main()
{
	int a[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

	merge_sort(a, 10);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	return 0;
}

void merge_sort(int* a, const int& n)
{
	int length = 1;  // Initialize subsequence length
	int* tmp_a = (int*)malloc(n * sizeof(int));
	if (tmp_a == NULL)
		return;
	while (length < n)
	{
		merge_pass(a, tmp_a, n, length);
		length *= 2;
		merge_pass(tmp_a, a, n, length);
		length *= 2;
	}
	free(tmp_a);
}

// Merge a turn
void merge_pass(int* a, int* tmp_a, int n, int length)
{
	int i = 0;
	for (i = 0; i <= n - 2 * length; i += 2 * length)
		merge(a, tmp_a, i, i + length, i + 2 * length - 1);
	// Merge the last two sequences
	if (i + length < n)
		merge(a, tmp_a, i, i + length, n - 1);
	else
		for (int j = i; j < n; j++)
			tmp_a[j] = a[j];
}

// Merge two sequences or two numbers
//(Finally, there is no need to pass the data back to the original array)
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
}