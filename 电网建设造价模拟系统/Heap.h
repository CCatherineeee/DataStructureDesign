#pragma once
#include"MST.h"

#define HEAPSIZE 1000                //堆的大小
typedef MSTEdge ElemType;        //定义堆的数据类型


class Heap
{
private:
	int HeapSize;                      //堆中的元素数量
	ElemType* Array;                   //堆的队列数组
	int HeapMaxsize;                   //堆的最大容量  
	Status ShiftUp(int start);         //堆的上滑调整
	Status ShiftDown(int start);        //堆的下滑调整

public:
	//构造函数
	Heap();
	//析构函数
	~Heap();
	//堆是否为空
	Status IsEmpty();
	//Elem入堆
	Status PushHeap(ElemType Elem);
	//出堆，将堆顶元素返回给Elem
	Status PopHeap(ElemType& Elem);
	//返回堆的大小
	Status GetHeapSize();
};