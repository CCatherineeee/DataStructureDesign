#include<iostream>
#include"DEFINE.h"
#include"Queue.h"
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
		cout << "Queue is full" << endl;
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
		cout << "Queue is empty" << endl;
		return INFEASIBLE;
	}
	front = (front + 1) % maxsize;
	n = elements[front];
	return OK;
}
