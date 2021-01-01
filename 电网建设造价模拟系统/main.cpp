#include<iostream>
#include"DEFINE.h"
#include"ALGraph.h"
#include"MST.h"
#include<cstring>

using namespace std;


int main()
{

	cout << "**                       电费模拟造价系统                    **" << endl;
	cout << "===============================================================" << endl;
	cout << "**                    请选择要进行的操作                     **" << endl;
	cout << "**                       A --- 创建电网节点                  **" << endl;
	cout << "**                       B --- 添加电网的边                  **" << endl;
	cout << "**                       C --- 构造最小生成树                **" << endl;
	cout << "**                       D --- 增加电网节点                  **" << endl;
	cout << "**                       E --- 删除电网节点                  **" << endl;
	cout << "**                       F --- 删除电网节的边                **" << endl;
	cout << "**                       G --- 退出程序                      **" << endl;
	cout << "===============================================================" << endl;

	ALGraph G;

	while (1)
	{
		char op;
		while (1) {
			cout << "请选择要进行的操作:";
			char op_[10];
			cin >> op_;
			int n = strlen(op_);
			if (n > 1)
			{
				cout << "警告：操作输入错误\n" << endl;
				continue;
			}
			else
				op = op_[0];
			if (!(op >= 'A' && op <= 'G'))
			{
				cout << "警告：没有此项操作,请重输\n" << endl;
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
			cout << "系统关闭" << endl;
			break;
		}
		else
		{
			if (G.GetVexNum()==0)
			{
				cout << "警告：电网中没有节点，请先创建节点\n" << endl;
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
				cout << "请选择：1.Prime算法   2.Kruskal算法\n" << endl;
				cout << "你的选择是：";
				int command;
				cin >> command;
				if(cin.fail()||(command != 1 && command != 2))
				{
					cout << "警告：请输入 1 或 2 \n" << endl;
					cin.clear();
					cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
					continue;
				}
				int flag = 0;
				if (command == 1)
				{
					VertexType V;
					cout << "请输入构建起点：\n";
					cin >> V;
					if (G.LocateVex(V) == ERROR)
					{
						cout << "警告：没有该顶点" << endl;
						continue;
					}
					cout << "正在构建prim树" << endl;
					flag=CreateMST_Prim(T, G, V);
				}
				else if (command == 2)
				{
					cout << "正在构建Kruskal树" << endl;
					flag=CreateMST_Kruskal(T, G);
				}
				if (flag != ERROR)
				{
					cout << "构建完毕\n" << endl;
					cout << "下面显示最小生成树\n" << endl;
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