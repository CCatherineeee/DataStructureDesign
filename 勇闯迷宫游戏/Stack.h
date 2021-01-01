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
	//构造函数，建立一个空栈
	LinkStack();
	//析构函数，释放所有节点
	~LinkStack();
	//将数据nodeData入栈
	int push(T nodeData);
	//将数据栈头节点的数据传给topData，并删除栈头节点
	int pop(T& topData);
	//判断是否栈空，空则返回1，反之返回0
	int isEmpty();
	//将栈清空
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
		cout << "进栈失败" << endl;
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
		cout << "这是一个空栈" << endl;
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
