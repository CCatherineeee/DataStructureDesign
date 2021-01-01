#include<iostream>
#include"List.h"
using namespace std;
SqList::SqList()
{
	head = new(node);
	if (head == NULL)
		exit(-1);
	head->next = NULL;
}

SqList::~SqList()
{
	MadeListClear();
	delete head;
}
//输入数据
Status SqList::CreateList()
{
	node* p = head;
	int data_;
	cin >> data_;
	if (cin.fail())
	{
		cout << "应输入整数，输入失败，操作结束\n" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
		return ERROR;
	}
	while (data_ != -1)
	{
		node* n = new(node);
		if (n == NULL)
			return ERROR;
		n->data = data_;
		p->next = n;
		p = p->next;
		cin >> data_;
		if (cin.fail())
		{
			cout << "应输入整数，输入失败，操作结束\n" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
			return ERROR;
		}
	}
	p->next = NULL;
	return OK;
}

Status SqList::Output()
{
	node* p = head->next;
	if (p == NULL)
	{
		cout << "NULL" << endl;
		return FALSE;
	}
	while (p != NULL)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
	return OK;
}
Status SqList::MadeListClear()
{
	node* p = head->next;
	while (p != NULL)
	{
		node* q = p;
		p = p->next;
		delete q;
	}
	head->next = NULL;
	return OK;
}
Status SqList::IsOrdered()
{
	node* q = head->next;
	if (q != NULL)
	{
		ElemTtype pre = q->data;
		while (q->next != NULL)
		{
			ElemTtype p = q->next->data;
			if (p < pre)
				return FALSE;
			q = q->next;
		}

	}
	return TRUE;
}
node* SqList::GetHead()
{
	return head;
}