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
	cout << "请选择您要进行的操作：1.插入 2.删除 3.查找 4.修改 5.统计 0.取消操作" << endl;
	while (1)
	{
		char op;
		cout << "您选择的操作是：";
		cin >> op;
		cout << endl;
		while (!(op >= '0' && op <= '5'))
		{
			cout << "没有这个操作" << endl;
			cout << "您选择的操作是：";
			cin >> op;
		}
		if (op == '0')
		{
			cout << "系统关闭" << endl;
			break;
		}
		if (op == '1')
		{
			cout << "请输入您要插入的考生的位置：";
			int pos;
			cin >> pos;
			L.Insert_List(pos);
			L.Output_List();
		}
		else if (op == '2')
		{
			cout << "请输入您要删除的考生的考号：";
			int n;
			cin >> n;
			Stu* nodeTarget;
			int tag=L.del_Position(n,nodeTarget);
			if (tag) 
			{
				cout << "您删除的考生信息为：";
				cout << nodeTarget->num << "              " << nodeTarget->name << "           " << nodeTarget->sex << "             " << nodeTarget->age << "           " << nodeTarget->type << endl;
			}
			L.Output_List();
		}
		else if (op == '3')
		{
			cout << "请输入您要查找的考生的考号：";
			int num;
			cin >> num;
			Stu* nodeTarget;
			int tag = L.seek_Position(num, nodeTarget);
			if (tag)
			{
				cout << "考号           姓名           性别           年龄           报考类别" << endl;
				cout << nodeTarget->num << "              " << nodeTarget->name << "           " << nodeTarget->sex << "             " << nodeTarget->age << "           " << nodeTarget->type << endl;
			}
			else
			{
				cout << "没有该考生的信息" << endl;
			}
			L.Output_List();
		}
		else if (op == '4')
		{
			cout << "请输入您要修改的考生的考号：";
			int pos;
			cin >> pos;
			L.ChangePos_WithNew(pos);
			L.Output_List();
		}
		else if (op == '5')
		{
			cout << "请选择：1.统计性别 2.统计报考类别" << endl;
			cout << "您的选择是：";
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