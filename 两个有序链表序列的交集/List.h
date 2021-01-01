#pragma once
#define OK      1
#define TRUE    1
#define FALSE   0
#define ERROR   -1

typedef int Status;          //定义返回提示值类型
typedef int ElemTtype;       //定义节点数据类型

/********************** 链表的类储存 *******************************/
struct node
{
	ElemTtype data;          //节点的数据
	node* next;              //结点指针
};
class SqList
{
private:
	node* head;              // 头节点      
public:
	//构造函数，创建空表
	SqList();
	//析构函数，调用MadeListClear()
	~SqList();
	//创建一个有序链表
	Status CreateList();
	//输出一个有序链表
	Status Output();
	//释放除头节点以外的结点
	Status MadeListClear();
	//判断是否为有序链表
	Status IsOrdered();
	//获得链表头节点
	node* GetHead();

};
