#pragma once
#include"ALGraph.h"

#define MSTMAXSIZE 10000             //��С��������������


//��С�������߽��Ľṹ�崢��
struct MSTEdge
{
	CostType cost;         //�ߵ�Ȩֵ
	int head;              //�ߵ���ʼ��
	int tail;              //�ߵĽ�����

};

//��С���������ഢ��
class MST
{
private:
	MSTEdge* MSTree;      //��С�������ı�����
	int MSTMAX;           //��С���������������
	int MSTSize;          //��С��������Ԫ�ظ���
public:
	//���캯��
	MST();
	//��������
	~MST();
	//����Item������С������
	Status InsertMST(MSTEdge& Item);
	//Prim�㷨������С������
	friend Status CreateMST_Prim(MST& T, ALGraph& G, VertexType V);
	//Kruskal �㷨������С������
	friend Status CreateMST_Kruskal(MST& T, ALGraph& G);
	//��ʾ��С������
	friend Status ShowTree(MST& T, ALGraph& G);
};
