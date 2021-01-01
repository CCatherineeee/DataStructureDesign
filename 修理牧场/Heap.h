#pragma once
#include"DEFINE.h"

class Heap
{
private:
	ElemType* Array;
	int maxsize;
	int sz;
	Status ShiftUp(int start);
	Status ShiftDown(int start);
public:
	//���캯��
	Heap(int n);
	//��������
	~Heap();
	//��data���
	Status PushHeap(ElemType data);
	//ȡ���Ѷ�Ԫ�ط��ظ�n
	Status PopHeap(ElemType& n);
	//���ضѵĵ�ǰ��С
	Status GetHeapSize();
};