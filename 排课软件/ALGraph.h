#pragma once
#include"DEFINE.h"
#include<string>
#include<cstring>
using namespace std;

typedef string ClassName;    //����γ����Ƶ���������
typedef string ClassCode;    //����γ̱�ŵ���������

//�ߵĽṹ�崢��
struct Edge
{
	int dest;                //�ڽӶ���
	Edge* link;              //��ָ��

};

//����Ľṹ�崢��
struct Class
{
	Edge* adj;               //�ߵ�ͷ�ڵ�
	ClassName Name;          //�γ�����
	ClassCode Code;          //�γ̱��
	int Term;                //����ѧ��
	int Cost;                //ѧʱ
};
//��Ȩ����ͼ���ഢ��
class ALGraph
{
private:
	Class* ClassList;        //�����
	int* InDegree;           //��ȱ�
	int* visited;            //�ſθ�������
	int* NumberOfSemeters;   //ÿѧ�ڿγ���
	//��λ���޿γ̵�λ��
	Status LocatePrioClass(ClassName elem);
	//�����
	Status InsertEdge(int pos1, int pos2);

public:
	//���캯��
	ALGraph();
	//��������
	~ALGraph();
	//��ʼ������
	Status InitALGraphInfo();
	//Ѱ�ҵ�һ���ڽӽڵ�
	Status FirstAdjvex(int pos);
	//Ѱ����һ����ӽڵ�
	Status NextAdjvex(int Vpos, int Wpos);

	//����α�
	friend Status TopoSort(ALGraph& G, int n, int t, int** Schedule);
	//�ſο��ƺ���
	friend Status ManageTopo(ALGraph& G);
};
