#include<iostream>
#include"Stack.h"
using namespace std;


//计算幂
int getPow(int p, int e)
{
	int res = 1;
	for (int i = 0; i < e; i++)
		res = res * p;
	return res;
}
//栈内优先级表
int inStack_priority(char tmp_iS)
{
	int getPriority = -1;
	if (tmp_iS == '(')
		getPriority = 0;
	else if (tmp_iS == '*' || tmp_iS == '/' || tmp_iS == '%')
		getPriority = 4;
	else if (tmp_iS == '+' || tmp_iS == '-')
		getPriority = 2;
	else if (tmp_iS == '^')
		getPriority = 6;
	else if (tmp_iS == ')')
		getPriority = 7;
	return getPriority;
}
//栈外优先级表
int inComing_priority(char tmp_iC)
{
	int getPriority = -1;
	if (tmp_iC == '(')
		getPriority = 7;
	else if (tmp_iC == '^')
		getPriority = 5;
	else if (tmp_iC == '*' || tmp_iC == '/' || tmp_iC == '%')
		getPriority = 3;
	else if (tmp_iC == '+' || tmp_iC == '-')
		getPriority = 1;
	else if (tmp_iC == ')')
		getPriority = 0;
	return getPriority;
}
//计算操作
int DoCalculate(char tmp, LinkStack<int>& num_Stack)
{
	int res;
	int op_a, op_b;
	num_Stack.pop(op_a);
	if (num_Stack.isEmpty())
		return _MATH_ERROR_;
	num_Stack.pop(op_b);
	if (tmp == '+')
		res = op_b + op_a;
	else if (tmp == '-')
		res = op_b - op_a;
	else if (tmp == '*')
		res = op_a * op_b;
	else if (tmp == '/')
	{
		if (op_a == 0)
		{
			return _ZERO_ERROR_;
		}
		res = op_b / op_a;
	}
	else if (tmp == '%')
	{
		if (op_a == 0)
		{
			return _ZERO_ERROR_;
		}
		res = op_b % op_a;
	}
	else if (tmp == '^')
	{
		if (op_a < 0)
		{
			return _ZERO_ERROR_;
		}
		res = getPow(op_b, op_a);
	}
	num_Stack.push(res);
	return OK;
}
//控制操作
int Calculator(int& res)
{
	LinkStack<int> num_Stack;
	LinkStack<char> tmp_Stack;
	int n;
	cin >> n;
	while (cin.fail())
	{
		num_Stack.MadeEmpty();
		tmp_Stack.MadeEmpty();
		cin.clear();
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
		return _DIGIT_ERROR_;
	}
	num_Stack.push(n);
	char ch;
	while (1)
	{
		ch = cin.peek();
		if (ch == '=')
		{
			getchar();
			break;
		}
		//输入的是数字
		//判断无符号数字
		if (ch >= '0' && ch <= '9')
		{
			//处理多位数
			cin >> ch;
			if (cin.peek() >= '0' && cin.peek() <= '9')
			{
				cin.putback(ch);
				cin >> n;
			}
			else
				n = ch - '0';
			num_Stack.push(n);
		}
		//输入的是运算符
		else
		{
			char c;
			cin >> c;
			if (c != '(' && c != ')' && c != '+' && c != '-' && c != '*' && c != '/' && c != '^' && c != '%')
			{
				num_Stack.MadeEmpty();
				tmp_Stack.MadeEmpty();
				cin.clear();
				cin.ignore(std::numeric_limits< streamsize >::max(), '\n');

				return _MATH_ERROR_;

			}
			//判断下一位是否为带符号数字
			if (cin.peek() == '-' || cin.peek() == '+' && c != ')')
			{
				cin >> n;
				if (cin.fail())
				{
					num_Stack.MadeEmpty();
					tmp_Stack.MadeEmpty();
					cin.clear();
					cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
					return _DIGIT_ERROR_;
				}
				tmp_Stack.push(c);
				num_Stack.push(n);
				continue;
			}

			//处理运算符
			if (!tmp_Stack.isEmpty())
			{
				char tmp_iS;
				tmp_Stack.getTop(tmp_iS);
				//得到优先级
				int p_iS = inStack_priority(tmp_iS);
				int p_iC = inComing_priority(c);
				if (p_iC > p_iS)
					tmp_Stack.push(c);
				else if (p_iC == p_iS)
				{
					char t;
					tmp_Stack.pop(t);
				}
				else
				{
					cin.putback(c);
					char tmp;
					tmp_Stack.pop(tmp);
					int flag = DoCalculate(tmp, num_Stack);
					if (flag != OK)
					{
						cin.clear();
						cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
						return flag;
					}
				}
			}
			else
				tmp_Stack.push(ch);
		}
	}
	//处理剩余运算符
	while (!tmp_Stack.isEmpty() && !num_Stack.isEmpty())
	{
		char tmp;
		tmp_Stack.pop(tmp);
		int flag = DoCalculate(tmp, num_Stack);
		if (flag != OK)
			return flag;
	}
	num_Stack.pop(res);
	return OK;
}
