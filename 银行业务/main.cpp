#include<iostream>
#include"Queue.h"
#include"DEFINE.h"
using namespace std;

void ManageService(sqQueue& A,sqQueue& B)
{
	int count = -1;
	while (!A.isEmpty() && !B.isEmpty())
	{
		count = (count + 1) % 3;       //使用count为了防止A队列只剩一个的情况 count=1/2时输出A
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
	cout << "处理的序列是" << endl;
	ManageService(WindowA, WindowB);
	return OK;
}
int main()
{
	cout << "*************************************************************************************" << endl;
	cout << "输入说明:\n" << endl;
	cout << "输入为一行正整数，其中第一数字N（N<=1000）为顾客总数，后面跟着N位顾客的编号。\n\n编号为奇数的顾客需要到A窗口办理业务，为偶数的顾客则去B窗口。\n\n数字间以空格分隔。\n" << endl;
	cout << "*************************************************************************************" << endl;
	while (1)
	{
		int flag = 0;
		cout << "请先输入顾客人数" << endl;
		int n;
		cin >> n;
		while (cin.fail())
		{
			cout << "警告：请输入正整数！\n" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
			cout << "请重新输入顾客人数" << endl;
			cin >> n;
		}
		if (n <= 0)
		{
			cout << "警告：人数必须为正整数" << endl;
			flag = 1;
		}
		if (flag == 0) 
		{
			cout << "请输入顾客到达的序列" << endl;
			while(ControlService(n) == ERROR)
			{
				cout << "警告：请输入数字！\n" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
				cout << "请重新输入顾客队列" << endl;
			}
			cout << "\n\n";
		}
		char op;
		cout << "是否继续（y,n）" << endl;
		cout << "你的操作是" << endl;
		cin >> op;
		while (op != 'y' && op != 'Y'&& op != 'n' && op != 'N')
		{
			cout << "请重新输入正确的操作码" << endl;
			
			cin >> op;
		}
		if (op == 'n' || op == 'N')
			break;
		cin.clear();
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
	}
	return 0;

}