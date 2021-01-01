#pragma once
#include"DEFINE.h"

class sqQueue
{
private:
	int rear, front;          //ͷβָ�� 
	ElemType* elements;       //��������
	int maxsize;              //���е��������
	int current;              //��ǰ����
public:
	//���캯�� nΪ���е�����
	sqQueue(int n);
	//��������
	~sqQueue();
	//������n���
	Status enQueue(ElemType n);
	//���Ӳ������������ݵ�n
	Status deQueue(ElemType& n);
	//�����Ƿ�����
	Status isFull();
	//�����Ƿ�Ϊ��
	Status isEmpty();
	//������Ԫ��ȫ�����
	Status outPut();
};
