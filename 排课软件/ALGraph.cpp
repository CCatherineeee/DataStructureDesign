#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<sstream>
#include"DEFINE.h"
#include"ALGraph.h"
using namespace std;


ALGraph::ALGraph()
{
	//建立课程总表
	ClassList = new Class[MAXCLASSNUM];
	if (!ClassList)
	{
		cout << "创建失败" << endl;
		exit(-1);
	}
	for (int i = 0; i < MAXCLASSNUM; i++)
		ClassList[i].adj = NULL;
	//建立入度表
	InDegree = new int[MAXCLASSNUM];
	if (!InDegree)
	{
		cout << "创建失败" << endl;
		exit(-1);
	}
	for (int i = 0; i < MAXCLASSNUM; i++)
		InDegree[i] = 0;
	//建立访问表
	visited = new int[MAXCLASSNUM];
	if (!visited)
	{
		cout << "创建失败" << endl;
		exit(-1);
	}
	for (int i = 0; i < MAXCLASSNUM; i++)
		visited[i] = FALSE;
	//建立学期课程数量表
	NumberOfSemeters = new int[8];
	for (int i = 0; i < 8; i++)
		NumberOfSemeters[i] = -1;

}

ALGraph::~ALGraph()
{
	for (int i = 0; i < MAXCLASSNUM; i++)
	{
		if (ClassList[i].adj != NULL)
		{
			Edge* p = ClassList[i].adj;
			while (p)
			{
				Edge* q = p;
				p = p->link;
				delete q;
			}
		}
	}
	delete[] ClassList;
	delete[] InDegree;
	delete[] visited;
	delete[] NumberOfSemeters;
}

Status ALGraph::LocatePrioClass(ClassName Elem)
{
	for (int i = 0; i < MAXCLASSNUM; i++)
		if (ClassList[i].Code == Elem)
			return i;
	return ERROR;
}

Status ALGraph::FirstAdjvex(int pos)
{
	if (ClassList[pos].adj)
		return ClassList[pos].adj->dest;
	return ERROR;
}

Status ALGraph::NextAdjvex(int Vpos, int Wpos)
{
	Edge* p = ClassList[Vpos].adj;
	while (p->dest != Wpos && p != NULL)
		p = p->link;
	if (p == NULL)
		return ERROR;
	if (p->link == NULL)
		return ERROR;
	return p->link->dest;
}

Status ALGraph::InsertEdge(int pos1, int pos2)
{
	Edge* p = new(Edge);
	if (!p)
		return ERROR;
	InDegree[pos2]++;
	p->dest = pos2;
	p->link = NULL;
	if (!ClassList[pos1].adj)
	{
		ClassList[pos1].adj = p;
		return OK;
	}
	Edge* q = ClassList[pos1].adj;
	while (q->link != NULL)
		q = q->link;
	q->link = p;
	return OK;
}

Status ALGraph::InitALGraphInfo()
{

	ifstream ifile;
	ifile.open("课程说明.txt", ios::in);
	if (!ifile)
	{
		cout << "打开失败" << endl;
		return ERROR;
	}
	string str;
	//读取每学期课程数
	int classnum = 0;
	for (int i = 0; i < 8; i++)
	{
		ifile >> str;
		ifile >> NumberOfSemeters[i];
		classnum += NumberOfSemeters[i];
	}

	if (classnum != MAXCLASSNUM)
	{
		cout << "各学期排课数量总和与总课程数不相等" << endl;
		exit(-1);
	}
	while (getline(ifile, str))
	{
		if (str == "课程编号	课程名称		学时数		指定开课学期		先修课程")
			break;
	}
	//输入数据
	for (int i = 0; i < MAXCLASSNUM; i++)
	{
		getline(ifile, str);
		stringstream sstream(str);
		int count = 0;
		char ret;
		while (sstream)
		{
			count++;
			if (count == 1)
				sstream >> ClassList[i].Code;
			else if (count == 2)
				sstream >> ClassList[i].Name;
			else if (count == 3)
				sstream >> ClassList[i].Cost;
			else if (count == 4)
				sstream >> ClassList[i].Term;
			else
			{
				ClassName prio;
				sstream >> prio;
				if (sstream.fail())
				{
					sstream.clear();
					sstream.ignore(1024, '\n');
					break;
				}
				int pos = LocatePrioClass(prio);
				InsertEdge(pos, i);
			}
		}
	}
	ifile.close();
	return OK;
}