#include"Heap.h"
#include"DEFINE.h"
#include<iostream>
using namespace std;

Heap::Heap(int n)
{
	maxsize = n;
	sz = 0;
	Array = new int[n + 1];
}
Heap::~Heap()
{
	delete[] Array;
}

Status Heap::PushHeap(ElemType data)
{
	//堆已满
	if (sz == maxsize)
	{
		cout << "Heap is full" << endl;
		return ERROR;
	}
	//将元素插在最后
	Array[sz] = data;
	//上滑调整
	ShiftUp(sz);
	sz++;
	return OK;
}
Status Heap::PopHeap(ElemType& n)
{
	//堆为空
	if (!sz)
	{
		cout << "Heap is empty" << endl;
		return ERROR;
	}
	//将取出堆顶元素
	n = Array[0];
	//最后一个数据补上
	Array[0] = Array[sz - 1];
	sz--;
	//下滑调整
	ShiftDown(0);
	return OK;
}

Status Heap::ShiftDown(int start)
{
	ElemType temp = Array[start];
	//获得子节点位置
	int i = start, j = 2 * i + 1;
	//是否调整完毕
	while (j <= (sz - 1))
	{
		//选取子节点数据中较小的
		if (j<(sz - 1) && Array[j] > Array[j + 1])
			j++;
		//无需调整
		if (temp <= Array[j])
			break;
		else
		{
			Array[i] = Array[j];
			i = j;
			j = 2 * i + 1;
		}
	}
	Array[i] = temp;
	return OK;
}

Status Heap::ShiftUp(int start)
{
	//上滑起始点
	int j = start;
	//获得分支点位置
	int i = (j - 1) / 2;
	ElemType temp = Array[j];
	while (j > 0)
	{
		//无需上滑
		if (Array[i] <= temp)
			break;
		else
		{
			Array[j] = Array[i];
			j = i;
			i = (j - 1) / 2;
		}
	}
	//将元素填补回堆
	Array[j] = temp;
	return OK;
}
Status Heap::GetHeapSize()
{
	return sz;
}