#pragma once
#include"DEFINE.h"

typedef int ElemType;        //���������������

class sqQueue
{
private:
	int rear, front;          //ͷβָ�� 
	ElemType* elements;       //��������
	int maxsize;              //���е��������

public:
	//���캯�� nΪ���е�����
	sqQueue(int n);
	//��������
	~sqQueue();
	//������n���
	Status enQueue(ElemType n);
	//���Ӳ������������ݵ�n
	Status deQueue(ElemType& n);

};