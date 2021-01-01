#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<sstream>
#include<iomanip>
#include"DEFINE.h"
#include"ALGraph.h"
#include"Queue.h"
using namespace std;
int Avai[4] = { 0,2,5,7 };   //每节大课的开始时间

//返回第一节空闲的大课
Status GetFirstBClass(int** Schedule, int& StartClass, int& WeekDay, int StartWeekDay)
{
	for (int j = StartWeekDay; j < 5; j++)
		for (int i = 0; i < 4; i++)
		{
			if (Schedule[Avai[i]][j] == -1)
			{
				StartClass = Avai[i];
				WeekDay = j;
				return OK;
			}
		}
	return ERROR;
}
//找到后续空闲的大课
Status GetNextBClass(int** Schedule, int& StartClass, int& WeekDay, int PrioClass, int PrioWeek)
{
	int PrioClassPos = 0;
	for (int i = 0; i < 4; i++)
		if (Avai[i] == PrioClass)
		{
			PrioClassPos = i;
			break;
		}
	for (int i = PrioClassPos + 1; i < 4; i++)
	{
		if (Schedule[Avai[i]][PrioWeek] == -1)
		{
			StartClass = Avai[i];
			WeekDay = PrioWeek;
			return OK;
		}
	}
	for (int j = PrioWeek + 1; j < 10; j++)
		for (int i = 0; i < 4; i++)
			if (Schedule[Avai[i]][j] == -1)
			{
				StartClass = Avai[i];
				WeekDay = j;
				return OK;
			}
	return ERROR;
}

Status ManageTopo(ALGraph& G)
{
	for (int i = 0; i < 8; i++)
	{
		//创建课程表
		int** Schedule;
		Schedule = new int* [10];
		for (int i = 0; i < 10; i++)
			Schedule[i] = new int[5];
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 5; j++)
				Schedule[i][j] = -1;
		//开始排序
		int flag = OK;
		flag = TopoSort(G, G.NumberOfSemeters[i], i + 1, Schedule);
		if (flag == ERROR)
			exit(-1);
	}
	cout << "排序完成" << endl;
	return OK;
}
Status TopoSort(ALGraph& G, int n, int t, int** Schedule)
{
	//n为本学期排课数量 t为学期数
	sqQueue Q(MAXCLASSNUM);
	//用于计已成功排课的个数
	int cnt = 0;
	//每学期必须允许修读一门英语课
	//优先考虑英语课
	for (int i = 29; i < 37; i++)
	{
		if (G.InDegree[i] == 0 && (G.ClassList[i].Term <= t) && G.visited[i] == FALSE)
		{
			G.visited[i] = t;
			Q.enQueue(i);
			cnt++;
			break;
		}
	}
	for (int i = 0; i < MAXCLASSNUM && cnt < n; i++)
	{
		//英语课的标记
		if (i >= 29 && i <= 36)
			continue;
		//将本学期需要修读的课程加入队列
		if (G.InDegree[i] == 0 && (G.ClassList[i].Term <= t) && G.visited[i] == FALSE)
		{
			G.visited[i] = t;
			Q.enQueue(i);
			cnt++;
		}
	}
	ofstream ofile;
	ofile.open("已排序课程表.txt", ios::app);
	if (!ofile)
	{
		cout << "打开失败" << endl;
		return ERROR;
	}
	ofile << "第" << t << "学期课程表" << endl;
	ofile << "本学期所学的课程是:";
	for (int i = 0; i < n; i++)
	{
		int m;
		Q.deQueue(m);
		//将后续课程的入度减一
		int w = G.FirstAdjvex(m);
		while (w != ERROR)
		{
			if (G.visited[w] == FALSE)
				G.InDegree[w]--;
			w = G.NextAdjvex(m, w);
		}
		//显示课程名称
		ofile << G.ClassList[m].Name << G.ClassList[m].Code << '\t';
		//获取学时
		int ClassCost = G.ClassList[m].Cost;
		//标记该课一周需要上几次
		int ClassTime = -1, StartWeekDay = 0;
		//从周一第一节课开始排序
		int StartClass = 0, WeekDay = 0;
		//开始排序
		while (ClassCost > 0)
		{
			//每次最多允许连上3节课
			int cst = ClassCost > 3 ? 3 : ClassCost;
			ClassCost -= cst;
			ClassTime++;
			//一周多次上课需要隔天上课
			if (ClassTime > 0)
				StartWeekDay = (StartWeekDay + 2) % 5;
			//找到第一节空闲的大课
			int flag = GetFirstBClass(Schedule, StartClass, WeekDay, StartWeekDay);
			if (flag == ERROR)
			{
				cout << "学期课程数量设置不合理" << endl;
				return ERROR;
			}
			//如果第一节可排的大课不满足要求 则寻找后续可排课的大课
			while (!((cst + StartClass - 1) <= 1 || ((cst + StartClass - 1) <= 5 && (cst + StartClass - 1) >= 4) || (cst + StartClass - 1) == 6 || (cst + StartClass - 1) == 9))
			{
				flag = GetNextBClass(Schedule, StartClass, WeekDay, StartClass, WeekDay);
				if (flag == ERROR)
				{
					cout << "学期课程数量设置不合理" << endl;
					ofile.clear();
					return ERROR;
				}
			}
			StartWeekDay = WeekDay;
			//将课程加入课程表
			for (int i = StartClass; i < cst + StartClass; i++)
				Schedule[i][WeekDay] = m;
		}
	}
	ofile << endl << endl;
	//打印课程表
	for (int i = 0; i < 5; i++)
		ofile << setw(9) << setiosflags(ios::left) << "周" << i + 1 << "\t\t";
	ofile << endl << endl;
	ofile << "------------------------------------------------------------------------------------------------------------" << endl << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (Schedule[i][j] != -1)
			{
				ofile << setw(8) << setiosflags(ios::left) << G.ClassList[Schedule[i][j]].Name << G.ClassList[Schedule[i][j]].Code << "\t";

			}
			else
				ofile << setw(8) << setiosflags(ios::left) << "-----(无课)-----" << "\t";

		}
		ofile << endl;
	}
	ofile << endl << endl << endl;
	ofile.close();
	return OK;
}