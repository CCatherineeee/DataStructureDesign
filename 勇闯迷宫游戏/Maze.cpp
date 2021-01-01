#include"Maze.h"
#include"Stack.h"
#include"DEFINE.h"
#include<iostream>
#include<iomanip>
using namespace std;



//寻路方向
const int MazeOffset[4][2] = { 1,0,0,1,0,-1,-1,0 };

//判断是否访问过辅助数组
int VisitFlag[MazeSize][MazeSize] = {TRUE, FALSE };

char Maze[MazeSize][MazeSize] =
{
		'#','#','#','#','#','#','#',
		'0','0','0','#','0','0','#',
		'#','#','0','#','#','#','#',
		'#','#','0','#','0','0','#',
		'#','0','0','0','#','#','#',
		'#','#','#','0','0','0','0',
		'#','#','#','#','#','#','#'
};

void MazePrint(char maze[][MazeSize])
{
	cout << setw(4) << ' ';
	//打印横坐标
	for (int i = 0; i < MazeSize; i++)
	{
		cout << setw(4) << i;
	}
	cout << endl << setw(3) << ' ';
	for (int i = 0; i < MazeSize; i++)
	{
		//打印纵坐标
		cout << i << setw(4);
		for (int j = 0; j < MazeSize; j++)
			cout << maze[i][j] << setw(4);
		cout << endl;
	}
}



int SeekPath(char Maze[][MazeSize], int x, int y, LinkStack<node>& T)
{

	int NextX = x, NextY = y;
	if (x == EndX && y == EndY)
		return OK;
	for (int i = 0; i < 4; i++)
	{
		NextX = x + MazeOffset[i][0];
		NextY = y + MazeOffset[i][1];
		if (NextX < 0 || NextY < 0 || NextX > MazeSize - 1 || NextY > MazeSize - 1)
			continue;
		if (Maze[NextX][NextY] == '0' && VisitFlag[NextX][NextY] == FALSE)
		{
			VisitFlag[NextX][NextY] = TRUE;
			int flag = SeekPath(Maze, NextX, NextY, T);
			if (flag)
			{
				node n;
				n.x = NextX;
				n.y = NextY;
				T.push(n);
				return OK;
			}
		}
	}
	return PATHFAILED;
}