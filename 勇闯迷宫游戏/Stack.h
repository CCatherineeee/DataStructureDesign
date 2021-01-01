#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include"DEFINE.h"
using namespace std;

template <typename T>
struct StackNode
{
	T data;
	StackNode* link;
};

template <typename T>
class  LinkStack
{
public:
	//���캯��������һ����ջ
	LinkStack();
	//�����������ͷ����нڵ�
	~LinkStack();
	//������nodeData��ջ
	int push(T nodeData);
	//������ջͷ�ڵ�����ݴ���topData����ɾ��ջͷ�ڵ�
	int pop(T& topData);
	//�ж��Ƿ�ջ�գ����򷵻�1����֮����0
	int isEmpty();
	//��ջ���
	int MadeEmpty();
private:
	StackNode<T>* top;
};

template <typename T>
LinkStack<T>::LinkStack()
{
	top = NULL;
}

template <typename T>
LinkStack<T>::~LinkStack()
{
	MadeEmpty();
	delete top;
}

template <typename T>
int LinkStack<T>::MadeEmpty()
{
	if (!top)
		return OK;
	StackNode<T>* p = top->link;
	while (p != NULL)
	{
		StackNode<T>* q = p;
		p = p->link;
		delete q;
	}
	top = NULL;
	return OK;
}
template <typename T>
int LinkStack<T>::push(T nodeData)
{
	StackNode<T>* node = new(StackNode<T>);
	if (node == NULL)
	{
		cout << "��ջʧ��" << endl;
		return ERROR;
	}
	node->data = nodeData;
	node->link = top;
	top = node;
	return OK;
}

template <typename T>
int LinkStack<T>::pop(T& topData)
{
	if (top == NULL)
	{
		cout << "����һ����ջ" << endl;
		return ERROR;
	}
	StackNode<T>* p = top;
	topData = top->data;
	top = top->link;
	delete p;
	return OK;
}

template <typename T>
int LinkStack<T>::isEmpty()
{
	if (top == NULL)
		return TRUE;
	return FALSE;
}
