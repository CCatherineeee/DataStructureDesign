#pragma once
#include"DEFINE.h"

#define MAXVERTEX 20                 //图的最大顶点数

typedef char VertexType;     //定义顶点的名字类型
typedef int CostType;        //定义边的权值类型

//边的结构体储存
struct Edge
{
	int dest;                //邻接顶点
	Edge* link;              //边指针
	CostType cost;           //权值
};

//顶点的结构体储存
struct Vertex
{
	Edge* adj;               //边的头节点
	VertexType data;         //顶点名
};

//带权无向图的类储存
class ALGraph
{
private:
	Vertex* VertexList;       //顶点表
	int arc_num;              //边数
	int vertex_num;           //节点数
	//头插法插入边
	Status InsertEdge(int pos1, int pos2, CostType cost_);
	//删除边
	Status DeleteEdge(int pos1, int pos2);

public:
	//构造函数
	ALGraph();
	//析构函数
	~ALGraph();
	//定位elem的位置
	Status LocateVex(VertexType elem);
	//寻找第一个邻接节点
	Status FirstAdjvex(int pos);
	//寻找下一个领接节点
	Status NextAdjvex(int Vpos, int Wpos);
	//构造图的节点
	Status CreateDG_VEX();
	//构造图的边,通过调用插入边函数实现
	Status CreateDG_EDGE();
	//增加图的结点
	Status AddDG_Vex();
	//删除图的结点控制函数
	Status DelDG_Vex();
	//删除图的边控制函数
	Status DelDG_Edge();
	//获得图的边数
	Status GetVexNum();
	//获得图的顶点数
	Status GetEdgeNum();
	//获得两节点权值
	Status GetWeight(int pos1, int pos2);
	//获得位置为pos的顶点的名字
	Status GetData(int pos, VertexType& DATA);

};
