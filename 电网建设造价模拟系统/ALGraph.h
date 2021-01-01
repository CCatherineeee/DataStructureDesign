#pragma once
#include"DEFINE.h"

#define MAXVERTEX 20                 //ͼ����󶥵���

typedef char VertexType;     //���嶥�����������
typedef int CostType;        //����ߵ�Ȩֵ����

//�ߵĽṹ�崢��
struct Edge
{
	int dest;                //�ڽӶ���
	Edge* link;              //��ָ��
	CostType cost;           //Ȩֵ
};

//����Ľṹ�崢��
struct Vertex
{
	Edge* adj;               //�ߵ�ͷ�ڵ�
	VertexType data;         //������
};

//��Ȩ����ͼ���ഢ��
class ALGraph
{
private:
	Vertex* VertexList;       //�����
	int arc_num;              //����
	int vertex_num;           //�ڵ���
	//ͷ�巨�����
	Status InsertEdge(int pos1, int pos2, CostType cost_);
	//ɾ����
	Status DeleteEdge(int pos1, int pos2);

public:
	//���캯��
	ALGraph();
	//��������
	~ALGraph();
	//��λelem��λ��
	Status LocateVex(VertexType elem);
	//Ѱ�ҵ�һ���ڽӽڵ�
	Status FirstAdjvex(int pos);
	//Ѱ����һ����ӽڵ�
	Status NextAdjvex(int Vpos, int Wpos);
	//����ͼ�Ľڵ�
	Status CreateDG_VEX();
	//����ͼ�ı�,ͨ�����ò���ߺ���ʵ��
	Status CreateDG_EDGE();
	//����ͼ�Ľ��
	Status AddDG_Vex();
	//ɾ��ͼ�Ľ����ƺ���
	Status DelDG_Vex();
	//ɾ��ͼ�ı߿��ƺ���
	Status DelDG_Edge();
	//���ͼ�ı���
	Status GetVexNum();
	//���ͼ�Ķ�����
	Status GetEdgeNum();
	//������ڵ�Ȩֵ
	Status GetWeight(int pos1, int pos2);
	//���λ��Ϊpos�Ķ��������
	Status GetData(int pos, VertexType& DATA);

};
