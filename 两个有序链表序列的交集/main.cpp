#include<iostream>
#include"List.h"
using namespace std;

Status Intersection_La_with_Lb(SqList& La, SqList& Lb, SqList& Lc);

int main()
{
	while (1)
	{

		cout << "\n�����������ǽ�������������� -1 Ϊ������־\n" << endl;
		SqList La, Lb, Lc;
		cout << "�������һ������:\n" << endl;
		int flag=La.CreateList();
		if (flag == ERROR)
			goto next;
		if (!La.IsOrdered())
		{
			cout << "����ʧ�ܣ�ӦΪ�ǽ���������������\n" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
			goto next;
		}
		cout << "������ڶ�������:\n" << endl;
		flag=Lb.CreateList();
		if (flag == ERROR)
			goto next;
		if (!Lb.IsOrdered())
		{
			cout << "����ʧ�ܣ�ӦΪ�ǽ���������������\n" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
			goto next;
		}
		Intersection_La_with_Lb(La, Lb, Lc);
		cout << "�����ǣ�\n" << endl;
		Lc.Output();
		cout << endl;

		next:cout << "�Ƿ���� 1.�� 2.��\n" << endl;
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