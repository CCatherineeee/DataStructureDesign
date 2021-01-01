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
	//构造函数
	Heap(int n);
	//析构函数
	~Heap();
	//将data入堆
	Status PushHeap(ElemType data);
	//取出堆顶元素返回给n
	Status PopHeap(ElemType& n);
	//返回堆的当前大小
	Status GetHeapSize();
};