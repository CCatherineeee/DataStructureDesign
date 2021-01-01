#include"DEFINE.h"
#include"Queue.h"
#include<iostream>
using namespace std;
sqQueue::sqQueue(int n)
{
	maxsize = n + 1;
	rear = front = 0;
	elements = new ElemType[n + 1];
}
sqQueue::~sqQueue()
{
	delete elements;
}
Status sqQueue::enQueue(ElemType n)
{

	if ((rear + 1) % maxsize == front)
	{
		cout << "Window is full" << endl;
		return OVERFLOW_;
	}
	rear = (rear + 1) % maxsize;
	elements[rear] = n;
	return OK;
}
Status sqQueue::deQueue(ElemType& n)
{
	if (front == rear)
	{
		cout << "Window is empty" << endl;
		return INFEASIBLE;
	}
	front = (front + 1) % maxsize;
	n = elements[front];
	return OK;
}
Status sqQueue::isFull()
{
	if ((rear + 1) % maxsize == front)
		return TRUE;
	else
		return FALSE;
}
Status sqQueue::isEmpty()
{
	if (front == rear)
		return TRUE;
	else
		return FALSE;
}
Status sqQueue::outPut()
{
	while (front != rear)
	{
		front = (front + 1) % maxsize;
		cout << elements[front] << ' ';
	}
	return OK;
}
