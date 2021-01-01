#include<iostream>
#include<string>
#include<cstring>
#include"BinTree.h"
#include"DEFINE.h"


using namespace std;

void printTree(BinTreeNode* t);

int main()
{
	cout << "**                        ���׹���ϵͳ                       **" << endl;
	cout << "===============================================================" << endl;
	cout << "**                    ��ѡ��Ҫ���еĲ���                     **" << endl;
	cout << "**                       A --- ���Ƽ�ͥ                      **" << endl;
	cout << "**                       B --- ��Ӽ�ͥ��Ա                  **" << endl;
	cout << "**                       C --- ��ɢ�ֲ���ͥ                  **" << endl;
	cout << "**                       D --- ���ļ�ͥ��Ա����              **" << endl;
	cout << "**                       E --- ������ʽ��ӡ����              **" << endl;
	cout << "**                       F --- �˳�����                      **" << endl;
	cout << "===============================================================" << endl;

	BinTree T;
	while (1)
	{
		char op;
		while (1) 
		{
			cout << "��ѡ��Ҫ���еĲ���:";
			char op_[10];
			cin >> op_;
			int n = strlen(op_);
			if (n > 1)
			{
				cout << "�����������" << endl;
				continue;
			}
			else
				op = op_[0];
			if (!(op >= 'A' && op <= 'F'))
			{
				cout << "û�д������,������" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
			}
			else
				break;
		}
		cin.clear();
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
		if (op == 'A')
		{
			int t=T.CreateFamily();
			if (t == CLOSE)
			{
				cout << "ϵͳ�ر�" << endl;
				break;
			}
			cout << "\n";
		}
		else if(op=='F')
		{
			cout << "ϵͳ�ر�" << endl;
			break;
		}
		else
		{
			BinTreeNode* p = T.GetRoot();
			if (!p)
			{
				cout << "������û���ˣ��������Ƽ�ͥ��Ա\n" << endl;
				continue;
			}
			if (op == 'B')
			{

				T.AddChild();
				cout << "\n";
			}
			else if (op == 'C')
			{
				T.ReleaseFamily();
				cout << "\n\n";
			}
			else if (op == 'D')
			{
				T.ChangeName();
				cout << "\n";
			}
			else if (op == 'E')
			{
				cout << "���ڵļ����ǣ�\n" << endl;
				printTree(p);
				cout << "\n\n";
			}

		}
	}

	return 0;
}
