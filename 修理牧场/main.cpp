#include<iostream>
#include"Heap.h"
#include"DEFINE.h"
using namespace std;

Status Manage()
{
	cout << "������Ҫ��ľͷ���ɶε�����:";
	Heap H(MAXSIZE);
	int count;
	cin >> count;
	ElemType cost = 0;
	if (cin.fail() )
	{
		cout << "\nӦ����������������ʧ�ܣ���������\n" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
		return ERROR;
	}
	ElemType m, n;
	if (count != 0)
	{
		cout << "������ÿ�εĳ��ȣ�";
		for (int i = 0; i < count; i++)
		{
			int elem;
			cin >> elem;
			if (cin.fail() || (elem <= 0))
			{
				cout << "\nӦ����������������ʧ�ܣ���������\n" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
				return ERROR;
			}
			H.PushHeap(elem);
		}
		while (H.GetHeapSize() > 1)
		{
			H.PopHeap(m);
			H.PopHeap(n);
			H.PushHeap(m + n);
			cost = cost + m + n;
		}
	}
	cout << "\n��С����Ϊ��" << cost << endl;
	cout << endl;
	return OK;
}


int main()
{
	while (1)
	{
		Manage();
		cout << "�Ƿ���� 1.�� 2.��\n" << endl;
		cout << "���ѡ���ǣ�";
		int op;
		cin >> op;
		while (cin.fail() || (op != 1 && op != 2))
		{
			cin.clear();
			cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
			cout << "������ 1 �� 2\n" << endl;
			cout << "����������\n" << endl;
			cout << "���ѡ���ǣ�";
			cin >> op;
		}
		if (op == 2)
		{
			cout << "�������\n" << endl;
			break;
		}
	}
	return 0;
}
