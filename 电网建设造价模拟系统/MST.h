#pragma once
#include"ALGraph.h"

#define MSTMAXSIZE 10000             //最小生成树的最大边数


//最小生成树边结点的结构体储存
struct MSTEdge
{
	CostType cost;         //边的权值
	int head;              //边的起始点
	int tail;              //边的结束点

};

//最小生成树的类储存
class MST
{
private:
	MSTEdge* MSTree;      //最小生成树的边数组
	int MSTMAX;           //最小生成树的最大容量
	int MSTSize;          //最小生成树的元素个数
public:
	//构造函数
	MST();
	//析构函数
	~MST();
	//将边Item插入最小生成树
	Status InsertMST(MSTEdge& Item);
	//Prim算法创建最小生成树
	friend Status CreateMST_Prim(MST& T, ALGraph& G, VertexType V);
	//Kruskal 算法构建最小生成树
	friend Status CreateMST_Kruskal(MST& T, ALGraph& G);
	//显示最小生成树
	friend Status ShowTree(MST& T, ALGraph& G);
};
