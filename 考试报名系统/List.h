#pragma once
#include<string>
#include<cstring>
#include"DEFINE.h"
using namespace std;
struct Stu
{
	int num;			//学号
	int age;			//年龄
	string name;		//姓名
	string type;		//报考类型
	string sex;			//性别
	Stu* next;
};
class List
{
private:
	int lenth;
	Stu* head;
public:
	//List的构造函数，在构造函数中创建一个带有头 head 的空表。
	List();
	//List的析构函数，在析构函数中释放所有节点，包括头节点。
	~List();
	//List的初始化函数，后插法建立链表，共输入lenth个数据
	Status InPut_List();
	//进行插入操作，插入后节点为第pos个节点
	Status Insert_List(int pos);
	//进行删除操作，删除考号为n的节点，并通过targetNode返回
	Status del_Position(int n, Stu*& targetNode);
	//进行查询操作，查找考号为n的节点，并通过targetNode返回
	Status seek_Position(int n, Stu*& targetNode);
	//进行修改操作，修改考号为n的节点
	Status ChangePos_WithNew(int n);
	//进行统计操作，统计性别人数
	void Statistic_List_sex();
	//进行统计操作，统计报考类别人数
	void Statistic_List_type();
	//输出所有数据
	void Output_List();
};