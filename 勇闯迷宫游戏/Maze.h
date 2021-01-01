#pragma once

/*char Maze[MazeSize][MazeSize] =
{
		'#','#',
		'#','#'
};*/

struct node
{
	int x;
	int y;
};

const int MazeSize = 7;

const int StartX = 1, StartY = 0, EndX = MazeSize - 2, EndY = MazeSize - 1;
