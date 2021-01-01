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
	//������
	if (sz == maxsize)
	{
		cout << "Heap is full" << endl;
		return ERROR;
	}
	//��Ԫ�ز������
	Array[sz] = data;
	//�ϻ�����
	ShiftUp(sz);
	sz++;
	return OK;
}
Status Heap::PopHeap(ElemType& n)
{
	//��Ϊ��
	if (!sz)
	{
		cout << "Heap is empty" << endl;
		return ERROR;
	}
	//��ȡ���Ѷ�Ԫ��
	n = Array[0];
	//���һ�����ݲ���
	Array[0] = Array[sz - 1];
	sz--;
	//�»�����
	ShiftDown(0);
	return OK;
}

Status Heap::ShiftDown(int start)
{
	ElemType temp = Array[start];
	//����ӽڵ�λ��
	int i = start, j = 2 * i + 1;
	//�Ƿ�������
	while (j <= (sz - 1))
	{
		//ѡȡ�ӽڵ������н�С��
		if (j<(sz - 1) && Array[j] > Array[j + 1])
			j++;
		//�������
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
	//�ϻ���ʼ��
	int j = start;
	//��÷�֧��λ��
	int i = (j - 1) / 2;
	ElemType temp = Array[j];
	while (j > 0)
	{
		//�����ϻ�
		if (Array[i] <= temp)
			break;
		else
		{
			Array[j] = Array[i];
			j = i;
			i = (j - 1) / 2;
		}
	}
	//��Ԫ����ض�
	Array[j] = temp;
	return OK;
}
Status Heap::GetHeapSize()
{
	return sz;
}