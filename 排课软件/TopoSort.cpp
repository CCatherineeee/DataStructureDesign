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
int Avai[4] = { 0,2,5,7 };   //ÿ�ڴ�εĿ�ʼʱ��

//���ص�һ�ڿ��еĴ��
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
//�ҵ��������еĴ��
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
		//�����γ̱�
		int** Schedule;
		Schedule = new int* [10];
		for (int i = 0; i < 10; i++)
			Schedule[i] = new int[5];
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 5; j++)
				Schedule[i][j] = -1;
		//��ʼ����
		int flag = OK;
		flag = TopoSort(G, G.NumberOfSemeters[i], i + 1, Schedule);
		if (flag == ERROR)
			exit(-1);
	}
	cout << "�������" << endl;
	return OK;
}
Status TopoSort(ALGraph& G, int n, int t, int** Schedule)
{
	//nΪ��ѧ���ſ����� tΪѧ����
	sqQueue Q(MAXCLASSNUM);
	//���ڼ��ѳɹ��ſεĸ���
	int cnt = 0;
	//ÿѧ�ڱ��������޶�һ��Ӣ���
	//���ȿ���Ӣ���
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
		//Ӣ��εı��
		if (i >= 29 && i <= 36)
			continue;
		//����ѧ����Ҫ�޶��Ŀγ̼������
		if (G.InDegree[i] == 0 && (G.ClassList[i].Term <= t) && G.visited[i] == FALSE)
		{
			G.visited[i] = t;
			Q.enQueue(i);
			cnt++;
		}
	}
	ofstream ofile;
	ofile.open("������γ̱�.txt", ios::app);
	if (!ofile)
	{
		cout << "��ʧ��" << endl;
		return ERROR;
	}
	ofile << "��" << t << "ѧ�ڿγ̱�" << endl;
	ofile << "��ѧ����ѧ�Ŀγ���:";
	for (int i = 0; i < n; i++)
	{
		int m;
		Q.deQueue(m);
		//�������γ̵���ȼ�һ
		int w = G.FirstAdjvex(m);
		while (w != ERROR)
		{
			if (G.visited[w] == FALSE)
				G.InDegree[w]--;
			w = G.NextAdjvex(m, w);
		}
		//��ʾ�γ�����
		ofile << G.ClassList[m].Name << G.ClassList[m].Code << '\t';
		//��ȡѧʱ
		int ClassCost = G.ClassList[m].Cost;
		//��Ǹÿ�һ����Ҫ�ϼ���
		int ClassTime = -1, StartWeekDay = 0;
		//����һ��һ�ڿο�ʼ����
		int StartClass = 0, WeekDay = 0;
		//��ʼ����
		while (ClassCost > 0)
		{
			//ÿ�������������3�ڿ�
			int cst = ClassCost > 3 ? 3 : ClassCost;
			ClassCost -= cst;
			ClassTime++;
			//һ�ܶ���Ͽ���Ҫ�����Ͽ�
			if (ClassTime > 0)
				StartWeekDay = (StartWeekDay + 2) % 5;
			//�ҵ���һ�ڿ��еĴ��
			int flag = GetFirstBClass(Schedule, StartClass, WeekDay, StartWeekDay);
			if (flag == ERROR)
			{
				cout << "ѧ�ڿγ��������ò�����" << endl;
				return ERROR;
			}
			//�����һ�ڿ��ŵĴ�β�����Ҫ�� ��Ѱ�Һ������ſεĴ��
			while (!((cst + StartClass - 1) <= 1 || ((cst + StartClass - 1) <= 5 && (cst + StartClass - 1) >= 4) || (cst + StartClass - 1) == 6 || (cst + StartClass - 1) == 9))
			{
				flag = GetNextBClass(Schedule, StartClass, WeekDay, StartClass, WeekDay);
				if (flag == ERROR)
				{
					cout << "ѧ�ڿγ��������ò�����" << endl;
					ofile.clear();
					return ERROR;
				}
			}
			StartWeekDay = WeekDay;
			//���γ̼���γ̱�
			for (int i = StartClass; i < cst + StartClass; i++)
				Schedule[i][WeekDay] = m;
		}
	}
	ofile << endl << endl;
	//��ӡ�γ̱�
	for (int i = 0; i < 5; i++)
		ofile << setw(9) << setiosflags(ios::left) << "��" << i + 1 << "\t\t";
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
				ofile << setw(8) << setiosflags(ios::left) << "-----(�޿�)-----" << "\t";

		}
		ofile << endl;
	}
	ofile << endl << endl << endl;
	ofile.close();
	return OK;
}