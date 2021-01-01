#include<iostream>
#include"Stack.h"
#include"Maze.h"
#include"DEFINE.h"
using namespace std;


void MazePrint(char maze[][MazeSize]);
int SeekPath(char Maze[][MazeSize], int x, int y, LinkStack<node>& T);

extern char Maze[MazeSize][MazeSize];


int main()
{
	if (StartX >= MazeSize - 1)
	{
		cout << "�Թ���С" << endl;
		exit(-1);
	}
	else if (Maze[StartX][StartY] != '0' || Maze[EndX][EndY] != '0')
	{
		cout << "û�н�����" << endl;
		exit(-1);
	}
	cout << "�Թ���ͼ" << endl;
	MazePrint(Maze);
	LinkStack<node> T;
	int flag=SeekPath(Maze, 1, 0, T);
	if (flag == PATHFAILED)
		cout << "�޷��߳��Թ�" << endl;
	else 
	{
		cout << "�Թ�·��" << endl;
		cout << "\n(" << StartX << "," << StartY << ")";
		Maze[StartX][StartY] = 'x';
		while (!T.isEmpty())
		{
			node n;
			T.pop(n);
			cout << "-->(" << n.x << "," << n.y << ")";
			Maze[n.x][n.y] = 'x';
		}
		cout << endl << endl;
		cout << "���켣���Թ���ͼ(�� x ��ע)" << endl;
		MazePrint(Maze);
	}
	return 0;
}
