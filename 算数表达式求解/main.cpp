#include<iostream>
#include"Stack.h"
#include"Calculate.h"
using namespace std;


int main()
{
	//cout << "����һ�����⣬�뽫���д��з���λ����ֵ������������,����ӦΪ��Ƿ���" << endl;
	cout << "���������޷�����˷�ָ��Ϊ�����������" << endl;
	while (1)
	{
		cout << "������ʽ:" << endl;
		int res;
		int reg = Calculator(res);
		if (reg == OK)
			cout << "���ǣ�" << res << endl;
		else if (reg == _MATH_ERROR_)
			cout << "Ӧ������ȷ���������������" << endl;
		else if (reg == _ZERO_ERROR_)
			cout << "����/ȡ�� ����Ϊ0���˷�ָ������С��0" << endl;
		else
			cout << "�����밢��������" << endl;
		
		char op;
		cout << "�Ƿ������y,n��" << endl;
		cout << "��Ĳ�����" << endl;
		cin >> op;
		while (op != 'y' && op != 'Y'&&op!='n'&&op!='N')
		{
			cout << "������������ȷ�Ĳ�����" << endl;

			cin.clear();
			cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
			cin >> op;
		}
		if (op == 'n' || op == 'N')
			break;
		cin.clear();
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
	}
	return 0;
}