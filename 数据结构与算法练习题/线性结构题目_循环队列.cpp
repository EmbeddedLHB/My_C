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
		cout << "�����" << i + 1 << "��������: ";
		cin >> queue1[i];
		rear1 = (rear1 + 1) % 4;
	}
	cout << "������˶���: ";
	for (int i = 0; i < 4; i++)
		cout << queue1[i] << " ";
	cout << "\n\n";

	for (int i = 0; i < 6; i++)
	{
		cout << "�����" << i + 1 << "��Ů����: ";
		cin >> queue2[i];
		rear2 = (rear2 + 1) % 6;
	}
	cout << "���Ů�˶���: ";
	for (int i = 0; i < 6; i++)
		cout << queue2[i] << " ";
	cout << "\n\n";

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << "�����: " << queue1[front1] << "--" << queue2[front2] << endl;
			front1 = (front1 + 1) % 4;
			front2 = (front2 + 1) % 6;
		}
		cout << "δ��Եĵ�һ����������: " << queue2[front2] << endl;
	}
	return 0;
}