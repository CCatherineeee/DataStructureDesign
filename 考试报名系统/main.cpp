#include<iostream>
#include<string>
#include<iomanip>
#include"List.h"
using namespace std;

int main()
{
	List L;
	L.InPut_List();
	L.Output_List ();
	cout << "��ѡ����Ҫ���еĲ�����1.���� 2.ɾ�� 3.���� 4.�޸� 5.ͳ�� 0.ȡ������" << endl;
	while (1)
	{
		char op;
		cout << "��ѡ��Ĳ����ǣ�";
		cin >> op;
		cout << endl;
		while (!(op >= '0' && op <= '5'))
		{
			cout << "û���������" << endl;
			cout << "��ѡ��Ĳ����ǣ�";
			cin >> op;
		}
		if (op == '0')
		{
			cout << "ϵͳ�ر�" << endl;
			break;
		}
		if (op == '1')
		{
			cout << "��������Ҫ����Ŀ�����λ�ã�";
			int pos;
			cin >> pos;
			L.Insert_List(pos);
			L.Output_List();
		}
		else if (op == '2')
		{
			cout << "��������Ҫɾ���Ŀ����Ŀ��ţ�";
			int n;
			cin >> n;
			Stu* nodeTarget;
			int tag=L.del_Position(n,nodeTarget);
			if (tag) 
			{
				cout << "��ɾ���Ŀ�����ϢΪ��";
				cout << nodeTarget->num << "              " << nodeTarget->name << "           " << nodeTarget->sex << "             " << nodeTarget->age << "           " << nodeTarget->type << endl;
			}
			L.Output_List();
		}
		else if (op == '3')
		{
			cout << "��������Ҫ���ҵĿ����Ŀ��ţ�";
			int num;
			cin >> num;
			Stu* nodeTarget;
			int tag = L.seek_Position(num, nodeTarget);
			if (tag)
			{
				cout << "����           ����           �Ա�           ����           �������" << endl;
				cout << nodeTarget->num << "              " << nodeTarget->name << "           " << nodeTarget->sex << "             " << nodeTarget->age << "           " << nodeTarget->type << endl;
			}
			else
			{
				cout << "û�иÿ�������Ϣ" << endl;
			}
			L.Output_List();
		}
		else if (op == '4')
		{
			cout << "��������Ҫ�޸ĵĿ����Ŀ��ţ�";
			int pos;
			cin >> pos;
			L.ChangePos_WithNew(pos);
			L.Output_List();
		}
		else if (op == '5')
		{
			cout << "��ѡ��1.ͳ���Ա� 2.ͳ�Ʊ������" << endl;
			cout << "����ѡ���ǣ�";
			int op_;
			cin >> op_;
			if(op_==1)
				L.Statistic_List_sex();
			if(op_==2)
				L.Statistic_List_type();
		}
	}
	return 0;
}