#include<iostream>
#include<string>
#include<cstring>
#include"BinTree.h"
#include"DEFINE.h"


using namespace std;

void printTree(BinTreeNode* t);

int main()
{
	cout << "**                        家谱管理系统                       **" << endl;
	cout << "===============================================================" << endl;
	cout << "**                    请选择要进行的操作                     **" << endl;
	cout << "**                       A --- 完善家庭                      **" << endl;
	cout << "**                       B --- 添加家庭成员                  **" << endl;
	cout << "**                       C --- 解散局部家庭                  **" << endl;
	cout << "**                       D --- 更改家庭成员姓名              **" << endl;
	cout << "**                       E --- 括号形式打印家谱              **" << endl;
	cout << "**                       F --- 退出程序                      **" << endl;
	cout << "===============================================================" << endl;

	BinTree T;
	while (1)
	{
		char op;
		while (1) 
		{
			cout << "请选择要进行的操作:";
			char op_[10];
			cin >> op_;
			int n = strlen(op_);
			if (n > 1)
			{
				cout << "操作输入错误" << endl;
				continue;
			}
			else
				op = op_[0];
			if (!(op >= 'A' && op <= 'F'))
			{
				cout << "没有此项操作,请重输" << endl;
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
				cout << "系统关闭" << endl;
				break;
			}
			cout << "\n";
		}
		else if(op=='F')
		{
			cout << "系统关闭" << endl;
			break;
		}
		else
		{
			BinTreeNode* p = T.GetRoot();
			if (!p)
			{
				cout << "家谱中没有人，请先完善家庭成员\n" << endl;
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
				cout << "现在的家谱是：\n" << endl;
				printTree(p);
				cout << "\n\n";
			}

		}
	}

	return 0;
}
