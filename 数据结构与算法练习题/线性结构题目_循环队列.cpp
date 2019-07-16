#include <iostream>
using namespace std;

int main()
{
	char queue1[4] = { '\0' };
	char queue2[6] = { '\0' };
	int front1 = 0;
	int rear1 = 0;
	int front2 = 0;
	int rear2 = 0;

	for (int i = 0; i < 4; i++)
	{
		cout << "输入第" << i + 1 << "个男人名: ";
		cin >> queue1[i];
		rear1 = (rear1 + 1) % 4;
	}
	cout << "输出男人队列: ";
	for (int i = 0; i < 4; i++)
		cout << queue1[i] << " ";
	cout << "\n\n";

	for (int i = 0; i < 6; i++)
	{
		cout << "输入第" << i + 1 << "个女人名: ";
		cin >> queue2[i];
		rear2 = (rear2 + 1) % 6;
	}
	cout << "输出女人队列: ";
	for (int i = 0; i < 6; i++)
		cout << queue2[i] << " ";
	cout << "\n\n";

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << "配对者: " << queue1[front1] << "--" << queue2[front2] << endl;
			front1 = (front1 + 1) % 4;
			front2 = (front2 + 1) % 6;
		}
		cout << "未配对的第一个出来的是: " << queue2[front2] << endl;
	}
	return 0;
}