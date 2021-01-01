#pragma once
#include"DEFINE.h"
#include<string>
#include<cstring>
using namespace std;

typedef string ClassName;    //定义课程名称的名字类型
typedef string ClassCode;    //定义课程编号的名字类型

//边的结构体储存
struct Edge
{
	int dest;                //邻接顶点
	Edge* link;              //边指针

};

//顶点的结构体储存
struct Class
{
	Edge* adj;               //边的头节点
	ClassName Name;          //课程名称
	ClassCode Code;          //课程编号
	int Term;                //开课学期
	int Cost;                //学时
};
//带权有向图的类储存
class ALGraph
{
private:
	Class* ClassList;        //顶点表
	int* InDegree;           //入度表
	int* visited;            //排课辅助数组
	int* NumberOfSemeters;   //每学期课程数
	//定位先修课程的位置
	Status LocatePrioClass(ClassName elem);
	//插入边
	Status InsertEdge(int pos1, int pos2);

public:
	//构造函数
	ALGraph();
	//析构函数
	~ALGraph();
	//初始化函数
	Status InitALGraphInfo();
	//寻找第一个邻接节点
	Status FirstAdjvex(int pos);
	//寻找下一个领接节点
	Status NextAdjvex(int Vpos, int Wpos);

	//排序课表
	friend Status TopoSort(ALGraph& G, int n, int t, int** Schedule);
	//排课控制函数
	friend Status ManageTopo(ALGraph& G);
};
