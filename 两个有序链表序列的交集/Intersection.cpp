#include<iostream>
#include"List.h"

//取A,B交集，并将结果保存在C链
Status Intersection_La_with_Lb(SqList& La, SqList& Lb, SqList& Lc)
{
	node* pa = La.GetHead();
	node* pb = Lb.GetHead();
	node* pc = Lc.GetHead();
	pa = pa->next;
	pb = pb->next;

	while (pa != NULL && pb != NULL)
	{
		if (pa->data == pb->data)
		{
			node* q = new(node);
			if (q == NULL)
				return ERROR;
			q->data = pa->data;
			pa = pa->next;
			pb = pb->next;
			q->next = NULL;
			pc->next = q;
			pc = q;
		}
		else if (pa->data < pb->data)
			pa = pa->next;
		else
			pb = pb->next;
	}
	pc->next = NULL;
	return OK;
}