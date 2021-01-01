#include"MST.h"
#include"Heap.h"
#include<iostream>
using namespace std;

MST::MST()
{
	MSTMAX = MSTMAXSIZE;
	MSTSize = 0;
	MSTree = new MSTEdge[MSTMAX + 1];
}

MST::~MST()
{
	delete[] MSTree;
}

Status MST::InsertMST(MSTEdge& Item)
{
	MSTree[MSTSize] = Item;
	MSTSize++;
	return OK;
}
//Prim 算法构建生成树
Status CreateMST_Prim(MST& T, ALGraph& G, VertexType V)
{
	int nvex = G.GetVexNum();
	int nedge = G.GetEdgeNum();
	//生成顶点数组并初始化
	int* Vmst = new int[nvex];
	for (int i = 0; i < nvex; i++)
		Vmst[i] = FALSE;
	//建立最小堆
	Heap H;
	//获得起始点的位置
	int Vpos = G.LocateVex(V);
	int W = G.FirstAdjvex(Vpos);
	if (W == ERROR)
	{
		cout << "不是连通图，无法构建最小生成树" << endl;
		return ERROR;
	}
	Vmst[Vpos] = TRUE;
	int count = 1;
	while (count < nvex && (count - 1) != nedge)
	{
		//将不在树中的邻接边入堆
		int Wpos = G.FirstAdjvex(Vpos);
		while (Wpos != -1)
		{
			if (Vmst[Wpos] == FALSE)
			{
				MSTEdge ed;
				ed.head = Vpos;
				ed.tail = Wpos;
				ed.cost = G.GetWeight(Vpos, Wpos);
				H.PushHeap(ed);
			}
			Wpos = G.NextAdjvex(Vpos, Wpos);
		}
		//找出最小边
		while (!H.IsEmpty() && count < nvex)
		{
			MSTEdge ed;
			H.PopHeap(ed);
			//边的另一顶点不在树内
			if (!Vmst[ed.tail])
			{
				T.InsertMST(ed);
				Vpos = ed.tail;
				Vmst[ed.tail] = TRUE;
				count++;
				break;
			}
		}
	}
	if (count != nvex)
	{
		cout << "不是连通图，无法构建最小生成树\n" << endl;
		return ERROR;
	}
	return OK;
}
Status Find(int* UnionSet, int pos)
{
	while (UnionSet[pos] >= 0)
	{
		pos = UnionSet[pos];
	}
	return pos;
}
Status Union(int* UnionSet, int pos1, int pos2)
{
	//把节点少的链入节点多的
	if (pos1 < pos2)
	{
		UnionSet[pos1] = pos2;
		pos2 = pos1 + pos2;
	}
	return OK;
}

Status CreateMST_Kruskal(MST& T, ALGraph& G)
{
	int nvex = G.GetVexNum();
	int nedge = G.GetEdgeNum();
	//创建并查集并初始化
	int* UnionSet = new int[nvex];
	for (int i = 0; i < nvex; i++)
		UnionSet[i] = -1;
	//所有边进堆
	Heap H;
	for (int i = 0; i < nvex; i++)
	{
		int Vpos = i;
		int Wpos = G.FirstAdjvex(Vpos);
		while (Wpos != -1)
		{
			if (Wpos > Vpos)
			{
				MSTEdge ed;
				ed.head = Vpos;
				ed.tail = Wpos;
				ed.cost = G.GetWeight(Vpos, Wpos);
				H.PushHeap(ed);
			}
			Wpos = G.NextAdjvex(Vpos, Wpos);
		}
	}
	int count = 1;
	while (!H.IsEmpty() && count < nvex && (count - 1) != nedge)
	{
		MSTEdge ed;
		H.PopHeap(ed);
		int pos1 = Find(UnionSet, ed.head);
		int pos2 = Find(UnionSet, ed.tail);
		while (pos1 == pos2 && !H.IsEmpty())
		{
			H.PopHeap(ed);
			int pos1 = Find(UnionSet, ed.head);
			int pos2 = Find(UnionSet, ed.tail);
		}
		Union(UnionSet, pos1, pos2);
		T.InsertMST(ed);
		count++;
	}
	if (count != nvex)
	{
		cout << "不是连通图，无法构建最小生成树\n" << endl;
		return ERROR;
	}
	return OK;
}
Status ShowTree(MST& T, ALGraph& G)
{
	int cost = 0;
	for (int i = 0; i < T.MSTSize; i++)
	{
		VertexType v1, v2;
		G.GetData(T.MSTree[i].head, v1);
		G.GetData(T.MSTree[i].tail, v2);
		cout << v1 << "-<" << T.MSTree[i].cost << ">-" << v2 << "        ";
		cost += T.MSTree[i].cost;
	}
	cout << "\n总造价为：" << cost << endl;
	return OK;
}