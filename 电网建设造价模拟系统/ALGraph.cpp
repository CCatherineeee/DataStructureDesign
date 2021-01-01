#include"ALGraph.h"
#include<iostream>
using namespace std;

ALGraph::ALGraph()
{
	arc_num = 0;
	vertex_num = 0;
	VertexList = NULL;
}

ALGraph::~ALGraph()
{
	for (int i = 0; i < vertex_num; i++)
	{
		if (VertexList[i].adj != NULL)
		{
			Edge* p = VertexList[i].adj;
			while (p)
			{
				Edge* q = p;
				p = p->link;
				delete q;
			}
		}
		//delete VertexList[i].adj;

	}
	delete[] VertexList;
}

Status ALGraph::LocateVex(VertexType elem)
{
	for (int i = 0; i < vertex_num; i++)
		if (VertexList[i].data == elem)
			return i;
	return ERROR;
}

Status ALGraph::FirstAdjvex(int pos)
{
	if (VertexList[pos].adj)
		return VertexList[pos].adj->dest;
	return ERROR;

}

Status ALGraph::NextAdjvex(int Vpos, int Wpos)
{
	Edge* p = VertexList[Vpos].adj;
	while (p->dest != Wpos && p != NULL)
		p = p->link;
	if (p == NULL)
		return ERROR;
	if (p->link == NULL)
		return ERROR;
	return p->link->dest;
}

Status ALGraph::CreateDG_VEX()
{
	cout << "请输入节点数量：";
	//输入节点数
	cin >> vertex_num;
	if (cin.fail() || vertex_num <= 0)
	{
		cout << "警告：请输入一个大于0的正整数" << endl;
		cout << "操作结束" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
		return ERROR;
	}
	//开辟节点表
	VertexList = new Vertex[vertex_num];
	if (!VertexList)
		return ERROR;
	cout << "请依次输入结点的名字" << endl;
	for (int i = 0; i < vertex_num; i++)
	{
		cin >> VertexList[i].data;
		VertexList[i].adj = NULL;
	}
	return OK;
}

Status ALGraph::CreateDG_EDGE()
{
	cout << "请以 ? ? ?结束输入" << endl;
	//进行插入
	while (1)
	{
		cout << "请输入两个结点名与权值:";
		VertexType v1, v2;
		CostType cost_;
		cin >> v1 >> v2;
		if (v1 == '?')
		{
			cin.clear();
			cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
			return OK;
		}
		cin >> cost_;
		if (cin.fail())
		{
			cout << "警告：权值应为一个大于0的正整数" << endl;
			cout << "操作结束" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
			return ERROR;
		}
		if (v1 == v2)
		{
			cout << "警告：一条边的两个顶点不能相同" << endl;
			cout << "操作结束" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
			return ERROR;
		}
		int pos1 = LocateVex(v1);
		int pos2 = LocateVex(v2);
		if (pos1 == ERROR || pos2 == ERROR)
		{
			cout << "警告：无法创建该边" << endl;
			cout << "操作结束" << endl;
			return ERROR;
		}
		arc_num++;
		InsertEdge(pos1, pos2, cost_);
	}
	return OK;
}

Status ALGraph::AddDG_Vex()
{
	cout << "请输入增加的节点数量：";
	//输入节点数
	int Vexadd;
	cin >> Vexadd;
	if (cin.fail() || Vexadd <= 0)
	{
		cout << "警告：请输入一个大于0的正整数" << endl;
		cout << "操作结束" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
		return ERROR;
	}
	//创建新节点表
	Vertex* VexList = new Vertex[Vexadd + vertex_num];
	if (!VexList)
		return ERROR;
	//旧表赋值给新表
	for (int i = 0; i < vertex_num; i++)
	{
		VexList[i].data = VertexList[i].data;
		VexList[i].adj = VertexList[i].adj;
	}
	cout << "请依次输入结点的名字" << endl;
	for (int i = vertex_num; i < Vexadd + vertex_num; i++)
	{
		cin >> VexList[i].data;
		VexList[i].adj = NULL;
	}
	VertexList = VexList;
	vertex_num = Vexadd + vertex_num;

	return OK;
}

Status ALGraph::DelDG_Vex()
{
	cout << "请输入要删除的节点数量：";
	//输入节点数
	int DelNum;
	cin >> DelNum;
	if (cin.fail() || DelNum <= 0)
	{
		cout << "警告：请输入一个大于0的正整数" << endl;
		cout << "操作结束" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
		return ERROR;
	}
	cout << "请输入要删除的节点名：";
	for (int i = 0; i < DelNum; i++)
	{
		VertexType del;
		cin >> del;
		int pos = LocateVex(del);
		if (pos == ERROR)
		{
			cout << "无法找到被删除节点" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
			return ERROR;
		}
		for (int i = 0; i < vertex_num; i++)
		{
			if (i != pos)
				DeleteEdge(i, pos);
		}
		VertexList[pos] = VertexList[vertex_num - 1];
		vertex_num--;
	}
	return OK;
}

Status ALGraph::DelDG_Edge()
{
	cout << "请输入要删除的边数量：";
	int DelNum;
	cin >> DelNum;
	if (cin.fail() || DelNum <= 0)
	{
		cout << "警告：请输入一个大于0的正整数" << endl;
		cout << "操作结束" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
		return ERROR;
	}
	cout << "请输入要删除的节点的两个端点：";
	for (int i = 0; i < DelNum; i++)
	{
		VertexType del1, del2;
		cin >> del1 >> del2;
		int pos1 = LocateVex(del1);
		int pos2 = LocateVex(del2);
		int flag = DeleteEdge(pos1, pos2);
		if (flag == ERROR)
		{
			cout << "没有该边" << endl;
			return ERROR;
		}
		DeleteEdge(pos2, pos1);
	}
	arc_num -= DelNum;
	return OK;
}

Status ALGraph::InsertEdge(int pos1, int pos2, CostType cost_)
{
	Edge* p = new(Edge);
	if (!p)
		return ERROR;
	p->dest = pos2;
	p->cost = cost_;
	p->link = VertexList[pos1].adj;
	VertexList[pos1].adj = p;
	//无向图 做两次插入
	Edge* q = new(Edge);
	if (!q)
		return ERROR;
	q->dest = pos1;
	q->cost = cost_;
	q->link = VertexList[pos2].adj;
	VertexList[pos2].adj = q;
	return OK;
}

Status ALGraph::DeleteEdge(int pos1, int pos2)
{
	Edge* prio = VertexList[pos1].adj;
	if (!prio)
		return ERROR;
	Edge* p = VertexList[pos1].adj->link;
	if (prio->dest == pos2)
	{
		VertexList[pos1].adj = p;
		delete prio;
		return OK;
	}
	while (p != NULL && p->dest != pos2)
	{
		prio = p;
		p = p->link;
	}
	if (p != NULL)
	{
		prio->link = p->link;
		delete p;
	}
	else
		return ERROR;
	return OK;
}

Status ALGraph::GetVexNum()
{
	return vertex_num;
}

Status ALGraph::GetEdgeNum()
{
	return arc_num;
}

Status ALGraph::GetWeight(int pos1, int pos2)
{
	Edge* p = VertexList[pos1].adj;
	while (p->dest != pos2)
		p = p->link;
	return p->cost;

}

Status ALGraph::GetData(int pos, VertexType& DATA)
{
	if (pos < 0 || pos >= vertex_num)
		return ERROR;
	DATA = VertexList[pos].data;
	return OK;
}
