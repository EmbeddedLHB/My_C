#include <iostream>
using namespace std;

void binary_search(int* a, const int& n);

int main()
{
	int a[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	binary_search(a, 10);
	return 0;
}

void binary_search(int* a, const int& n)
{
	int find = 0;
	int min = 0;  
	int max = n - 1;
	int mid = 0; 
	cout << "Please input the value you want to reserch: ";
	cin >> find;
	while (min + 1 != max)
	{
		mid = min + (max - min) / 2;
		if (find < a[mid])
			max = mid;
		if (find > a[mid])
			min = mid;
		if (find == a[mid])
		{
			cout << "The number you find is in " << mid + 1 << endl;
			return;
		}
	}
	cout << "The number you find is not in the sequence" << endl;
}
