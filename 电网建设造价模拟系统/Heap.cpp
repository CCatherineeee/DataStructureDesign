#include"Heap.h"
#include<iostream>
using namespace std;

Heap::Heap()
{
	HeapMaxsize = HEAPSIZE;
	HeapSize = 0;
	Array = new ElemType[HeapMaxsize + 1];
}

Heap::~Heap()
{
	delete[] Array;
}

Status Heap::PushHeap(ElemType Elem)
{
	if (HeapSize == HeapMaxsize)
	{
		cout << "Heap is full" << endl;
		return ERROR;
	}
	Array[HeapSize] = Elem;
	ShiftUp(HeapSize);
	HeapSize++;
	return OK;
}

Status Heap::PopHeap(ElemType& Elem)
{
	if (!HeapSize)
	{
		cout << "Heap is empty" << endl;
		return ERROR;
	}
	Elem = Array[0];
	Array[0] = Array[HeapSize - 1];
	HeapSize--;
	ShiftDown(0);
	return OK;
}

Status Heap::ShiftDown(int start)
{
	ElemType temp = Array[start];
	int i = start, j = 2 * i + 1;
	while (j <= (HeapSize - 1))
	{
		if (j<(HeapSize - 1) && Array[j].cost > Array[j + 1].cost)
			j++;
		if (temp.cost <= Array[j].cost)
			break;
		else
		{
			Array[i].cost = Array[j].cost;
			i = j;
			j = 2 * i + 1;
		}
	}
	Array[i] = temp;
	return OK;
}

Status Heap::ShiftUp(int start)
{
	int j = start;
	int i = (j - 1) / 2;
	ElemType temp = Array[j];
	while (j > 0)
	{
		if (Array[i].cost <= temp.cost)
			break;
		else
		{
			Array[j] = Array[i];
			j = i;
			i = (j - 1) / 2;
		}
	}
	Array[j] = temp;
	return OK;
}

Status Heap::GetHeapSize()
{
	return HeapSize;
}

Status Heap::IsEmpty()
{
	if (HeapSize != 0)
		return FALSE;
	return TRUE;
}
