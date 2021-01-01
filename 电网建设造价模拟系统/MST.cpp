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
//Prim �㷨����������
Status CreateMST_Prim(MST& T, ALGraph& G, VertexType V)
{
	int nvex = G.GetVexNum();
	int nedge = G.GetEdgeNum();
	//���ɶ������鲢��ʼ��
	int* Vmst = new int[nvex];
	for (int i = 0; i < nvex; i++)
		Vmst[i] = FALSE;
	//������С��
	Heap H;
	//�����ʼ���λ��
	int Vpos = G.LocateVex(V);
	int W = G.FirstAdjvex(Vpos);
	if (W == ERROR)
	{
		cout << "������ͨͼ���޷�������С������" << endl;
		return ERROR;
	}
	Vmst[Vpos] = TRUE;
	int count = 1;
	while (count < nvex && (count - 1) != nedge)
	{
		//���������е��ڽӱ����
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
		//�ҳ���С��
		while (!H.IsEmpty() && count < nvex)
		{
			MSTEdge ed;
			H.PopHeap(ed);
			//�ߵ���һ���㲻������
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
		cout << "������ͨͼ���޷�������С������\n" << endl;
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
	//�ѽڵ��ٵ�����ڵ���
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
	//�������鼯����ʼ��
	int* UnionSet = new int[nvex];
	for (int i = 0; i < nvex; i++)
		UnionSet[i] = -1;
	//���б߽���
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
		cout << "������ͨͼ���޷�������С������\n" << endl;
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
	cout << "\n�����Ϊ��" << cost << endl;
	return OK;
}