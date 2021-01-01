#pragma once
#include"DEFINE.h"

class sqQueue
{
private:
	int rear, front;          //头尾指针 
	ElemType* elements;       //队列数组
	int maxsize;              //队列的最大容量
	int current;              //当前容量
public:
	//构造函数 n为队列的容量
	sqQueue(int n);
	//析构函数
	~sqQueue();
	//将数据n入队
	Status enQueue(ElemType n);
	//出队操作，返回数据到n
	Status deQueue(ElemType& n);
	//队列是否已满
	Status isFull();
	//队列是否为空
	Status isEmpty();
	//将队列元素全部输出
	Status outPut();
};
