#include<iostream>
#include"Stack.h"
#include"Calculate.h"
using namespace std;


int main()
{
	//cout << "除第一个数外，请将所有带有符号位的数值用括号括起来,括号应为半角符号" << endl;
	cout << "本计算器无法计算乘方指数为负数的情况。" << endl;
	while (1)
	{
		cout << "输入表达式:" << endl;
		int res;
		int reg = Calculator(res);
		if (reg == OK)
			cout << "答案是：" << res << endl;
		else if (reg == _MATH_ERROR_)
			cout << "应输入正确算术运算符和数字" << endl;
		else if (reg == _ZERO_ERROR_)
			cout << "除数/取余 不可为0，乘方指数不可小于0" << endl;
		else
			cout << "请输入阿拉伯数字" << endl;
		
		char op;
		cout << "是否继续（y,n）" << endl;
		cout << "你的操作是" << endl;
		cin >> op;
		while (op != 'y' && op != 'Y'&&op!='n'&&op!='N')
		{
			cout << "请重新输入正确的操作码" << endl;

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