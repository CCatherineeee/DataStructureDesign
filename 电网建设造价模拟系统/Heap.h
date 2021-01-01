#pragma once
#include"MST.h"

#define HEAPSIZE 1000                //�ѵĴ�С
typedef MSTEdge ElemType;        //����ѵ���������


class Heap
{
private:
	int HeapSize;                      //���е�Ԫ������
	ElemType* Array;                   //�ѵĶ�������
	int HeapMaxsize;                   //�ѵ��������  
	Status ShiftUp(int start);         //�ѵ��ϻ�����
	Status ShiftDown(int start);        //�ѵ��»�����

public:
	//���캯��
	Heap();
	//��������
	~Heap();
	//���Ƿ�Ϊ��
	Status IsEmpty();
	//Elem���
	Status PushHeap(ElemType Elem);
	//���ѣ����Ѷ�Ԫ�ط��ظ�Elem
	Status PopHeap(ElemType& Elem);
	//���ضѵĴ�С
	Status GetHeapSize();
};