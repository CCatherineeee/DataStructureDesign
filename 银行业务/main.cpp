#include<iostream>
#include"Queue.h"
#include"DEFINE.h"
using namespace std;

void ManageService(sqQueue& A,sqQueue& B)
{
	int count = -1;
	while (!A.isEmpty() && !B.isEmpty())
	{
		count = (count + 1) % 3;       //ʹ��countΪ�˷�ֹA����ֻʣһ������� count=1/2ʱ���A
		int n;
	
		if (count == 2)
		{
			B.deQueue(n);
			cout << n << ' ';
		}
		else
		{
			A.deQueue(n);
			cout << n << ' ';
		}
	}
	if (!A.isEmpty())
		A.outPut();
	if(!B.isEmpty())
		B.outPut();
}

Status ControlService(int n)
{
	sqQueue WindowA(n), WindowB(n);
	for (int i = 0; i < n; i++)
	{
		int peo;
		cin >> peo;
		if (cin.fail())
			return ERROR;
		if (peo % 2 == 0)
			WindowB.enQueue(peo);
		else
			WindowA.enQueue(peo);
	}
	cout << "�����������" << endl;
	ManageService(WindowA, WindowB);
	return OK;
}
int main()
{
	cout << "*************************************************************************************" << endl;
	cout << "����˵��:\n" << endl;
	cout << "����Ϊһ�������������е�һ����N��N<=1000��Ϊ�˿��������������Nλ�˿͵ı�š�\n\n���Ϊ�����Ĺ˿���Ҫ��A���ڰ���ҵ��Ϊż���Ĺ˿���ȥB���ڡ�\n\n���ּ��Կո�ָ���\n" << endl;
	cout << "*************************************************************************************" << endl;
	while (1)
	{
		int flag = 0;
		cout << "��������˿�����" << endl;
		int n;
		cin >> n;
		while (cin.fail())
		{
			cout << "���棺��������������\n" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
			cout << "����������˿�����" << endl;
			cin >> n;
		}
		if (n <= 0)
		{
			cout << "���棺��������Ϊ������" << endl;
			flag = 1;
		}
		if (flag == 0) 
		{
			cout << "������˿͵��������" << endl;
			while(ControlService(n) == ERROR)
			{
				cout << "���棺���������֣�\n" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
				cout << "����������˿Ͷ���" << endl;
			}
			cout << "\n\n";
		}
		char op;
		cout << "�Ƿ������y,n��" << endl;
		cout << "��Ĳ�����" << endl;
		cin >> op;
		while (op != 'y' && op != 'Y'&& op != 'n' && op != 'N')
		{
			cout << "������������ȷ�Ĳ�����" << endl;
			
			cin >> op;
		}
		if (op == 'n' || op == 'N')
			break;
		cin.clear();
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
	}
	return 0;

}