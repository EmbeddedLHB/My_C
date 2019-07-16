#include<iostream>
using namespace std;

void bubble_sort(int* a, const int& n);
// Uniform interface
void quick_sort(int* a, const int& n);
// Core recursion function
void q_sort(int* a, int left, int right);
int median3(int* a, int left, int right);
void swap(int& a, int& b);

int main()
{
	int a[10] = { 90, 80, 70, 60, 50, 40, 30, 20, 10, 0 };
	quick_sort(a, 10);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	return 0;
}

// Time complexity best case: n, worst case: n^2
void bubble_sort(int* a, const int& n)
{
	int flag = 0;
	int tmp = 0;
	for (int p = n - 1; p; p--)
	{
		flag = 0;
		for (int i = 0; i < p; i++)
			if (a[i] > a[i + 1])
			{
				tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
				flag = 1;  // Identification has exchanged
			}
		if (flag == 0)
			break;
	}
}

// Time complexity average case: nlogn, worst case: n^2
void quick_sort(int* a, const int& n)
{
	q_sort(a, 0, n - 1);
}

// Core recursion function
void q_sort(int* a, int left, int right)
{
	int pivot = 0;
	int cutoff = 3;
	int low = 0;
	int high = 0;

	// If the sequence elements are suffciently large, use quick sort
	if (cutoff <= right - left)
	{
		pivot = median3(a, left, right);
		low = left;
		high = right - 1;
		while (1)
		{
			// Move the sequence smaller than the reference to the left
			// and the big to the right
			while (a[++low] < pivot);
			while (a[--high] > pivot);
			if (low < high)
				swap(a[low], a[high]);
			else
				break;
		}
		// Change the pivot to the correct position
		swap(a[low], a[right - 1]);
		q_sort(a, left, low - 1);
		q_sort(a, low + 1, right);
	}
	// If there's too few elements, use simple sort
	else
		bubble_sort(a + left, right - left + 1);
}

int median3(int* a, int left, int right)
{
	int center = left + (right - left) / 2;  // Use this form to prevent overflow
	if (a[left] > a[center])
		swap(a[left], a[center]);
	if (a[left] > a[right])
		swap(a[left], a[right]);
	if (a[center] > a[right])
		swap(a[center], a[right]);
	// In this time, a[left] <= a[center] <= a[right]
	// Hide the pivot on the position of right-1
	swap(a[center], a[right - 1]);
	return a[right - 1];
}

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}