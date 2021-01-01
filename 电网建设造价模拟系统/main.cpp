#include<iostream>
#include"DEFINE.h"
#include"ALGraph.h"
#include"MST.h"
#include<cstring>

using namespace std;


int main()
{

	cout << "**                       ���ģ�����ϵͳ                    **" << endl;
	cout << "===============================================================" << endl;
	cout << "**                    ��ѡ��Ҫ���еĲ���                     **" << endl;
	cout << "**                       A --- ���������ڵ�                  **" << endl;
	cout << "**                       B --- ��ӵ����ı�                  **" << endl;
	cout << "**                       C --- ������С������                **" << endl;
	cout << "**                       D --- ���ӵ����ڵ�                  **" << endl;
	cout << "**                       E --- ɾ�������ڵ�                  **" << endl;
	cout << "**                       F --- ɾ�������ڵı�                **" << endl;
	cout << "**                       G --- �˳�����                      **" << endl;
	cout << "===============================================================" << endl;

	ALGraph G;

	while (1)
	{
		char op;
		while (1) {
			cout << "��ѡ��Ҫ���еĲ���:";
			char op_[10];
			cin >> op_;
			int n = strlen(op_);
			if (n > 1)
			{
				cout << "���棺�����������\n" << endl;
				continue;
			}
			else
				op = op_[0];
			if (!(op >= 'A' && op <= 'G'))
			{
				cout << "���棺û�д������,������\n" << endl;
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
			G.CreateDG_VEX();
			cout << endl;
		}
		else if (op == 'G')
		{
			cout << "ϵͳ�ر�" << endl;
			break;
		}
		else
		{
			if (G.GetVexNum()==0)
			{
				cout << "���棺������û�нڵ㣬���ȴ����ڵ�\n" << endl;
				continue;
			}
			if (op == 'B')
			{
				G.CreateDG_EDGE();
				cout << "\n";
			}
			else if (op == 'C')
			{
				MST T;
				cout << "��ѡ��1.Prime�㷨   2.Kruskal�㷨\n" << endl;
				cout << "���ѡ���ǣ�";
				int command;
				cin >> command;
				if(cin.fail()||(command != 1 && command != 2))
				{
					cout << "���棺������ 1 �� 2 \n" << endl;
					cin.clear();
					cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
					continue;
				}
				int flag = 0;
				if (command == 1)
				{
					VertexType V;
					cout << "�����빹����㣺\n";
					cin >> V;
					if (G.LocateVex(V) == ERROR)
					{
						cout << "���棺û�иö���" << endl;
						continue;
					}
					cout << "���ڹ���prim��" << endl;
					flag=CreateMST_Prim(T, G, V);
				}
				else if (command == 2)
				{
					cout << "���ڹ���Kruskal��" << endl;
					flag=CreateMST_Kruskal(T, G);
				}
				if (flag != ERROR)
				{
					cout << "�������\n" << endl;
					cout << "������ʾ��С������\n" << endl;
					ShowTree(T, G);
					cout << "\n";
				}

			}
			
			else if (op == 'D')
			{
				G.AddDG_Vex();
				cout << "\n";
			}
			else if (op == 'E')
			{
				G.DelDG_Vex();

				cout << "\n";
			}
			else if (op == 'F')
			{
				G.DelDG_Edge();

				cout << "\n";
			}
			
		}
	}

	return 0;
}