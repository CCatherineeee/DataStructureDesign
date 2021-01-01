#include<iostream>
#include"List.h"
using namespace std;

Status Intersection_La_with_Lb(SqList& La, SqList& Lb, SqList& Lc);

int main()
{
	while (1)
	{

		cout << "\n请输入两个非降序的有序链表，以 -1 为结束标志\n" << endl;
		SqList La, Lb, Lc;
		cout << "请输入第一个链表:\n" << endl;
		int flag=La.CreateList();
		if (flag == ERROR)
			goto next;
		if (!La.IsOrdered())
		{
			cout << "输入失败，应为非降序链表，操作结束\n" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
			goto next;
		}
		cout << "请输入第二个链表:\n" << endl;
		flag=Lb.CreateList();
		if (flag == ERROR)
			goto next;
		if (!Lb.IsOrdered())
		{
			cout << "输入失败，应为非降序链表，操作结束\n" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
			goto next;
		}
		Intersection_La_with_Lb(La, Lb, Lc);
		cout << "交集是：\n" << endl;
		Lc.Output();
		cout << endl;

		next:cout << "是否继续 1.是 2.否\n" << endl;
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