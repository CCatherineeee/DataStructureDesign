#include<iostream>
#include"Heap.h"
#include"DEFINE.h"
using namespace std;

Status Manage()
{
	cout << "请输入要将木头砍成段的数量:";
	Heap H(MAXSIZE);
	int count;
	cin >> count;
	ElemType cost = 0;
	if (cin.fail() )
	{
		cout << "\n应输入正整数，输入失败，操作结束\n" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
		return ERROR;
	}
	ElemType m, n;
	if (count != 0)
	{
		cout << "请输入每段的长度：";
		for (int i = 0; i < count; i++)
		{
			int elem;
			cin >> elem;
			if (cin.fail() || (elem <= 0))
			{
				cout << "\n应输入正整数，输入失败，操作结束\n" << endl;
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
	cout << "\n最小花费为：" << cost << endl;
	cout << endl;
	return OK;
}


int main()
{
	while (1)
	{
		Manage();
		cout << "是否继续 1.是 2.否\n" << endl;
		cout << "你的选择是：";
		int op;
		cin >> op;
		while (cin.fail() || (op != 1 && op != 2))
		{
			cin.clear();
			cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
			cout << "请输入 1 或 2\n" << endl;
			cout << "请重新输入\n" << endl;
			cout << "你的选择是：";
			cin >> op;
		}
		if (op == 2)
		{
			cout << "程序结束\n" << endl;
			break;
		}
	}
	return 0;
}
