#include<iostream>
#include<string>
#include<cstring>
#include"List.h"

using namespace std;


const int Maxsize = 100;

//创建一个带有头节点的空表
List::List()
{
	head = new (Stu);
	if (head == NULL)
	{
		cout << "建立失败" << endl;
		return;
	}
	lenth = 0;
	head->next = NULL;
}

//初始化链表
Status List::InPut_List()
{
	cout << "首先建立考试报名系统" << endl;
	cout << "请输入考生人数：";
	cin >> lenth;
	while (lenth <= 0)
	{
		cout << "请输入一个正整数" << endl;
		cout << "请输入考生人数：";
		cin >> lenth;
	}
	cout << "请依次输入考生的考号，姓名，性别，年龄以及报名类型：" << endl;
	Stu* p = head;
	//head->next = node;

	for (int i = 0; i < lenth; i++)
	{
		Stu* node = new (Stu);
		if (node == NULL)
		{
			cout << "建立失败" << endl;
			return ERROR;
		}
		cin >> node->num >> node->name >> node->sex >> node->age >> node->type;
		while (node->sex != "女" && node->sex != "男")
		{
			cout << "性别必须为男/女,请重新输入性别" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			cin >> node->sex;

		}
		p->next = node;
		p = node;
	}
	p->next = NULL;
	return OK;
}
//插入操作
Status List::Insert_List(int pos)
{
	if (pos<1 || pos>lenth + 1)
	{
		if (lenth != 0)
			cout << "修改位置不合法,应为1至" << lenth << endl;
		else
			cout << "修改位置不合法,应为1" << endl;
		return ERROR;
	}
	cout << "请依次输入考生的考号，姓名，性别，年龄以及报名类型：" << endl;
	Stu* node = new (Stu);
	if (node == NULL)
	{
		cout << "插入失败" << endl;
		return ERROR;
	}
	cin >> node->num >> node->name >> node->sex >> node->age >> node->type;
	while (node->sex != "女" && node->sex != "男")
	{
		cout << "性别必须为男/女,请重新输入性别" << endl;
		cin >> node->sex;
	}
	Stu* current = head;
	//找到插入位置 current指向插入位置的前一个节点
	for (int i = 1; i < pos; i++)
		current = current->next;
	node->next = current->next;
	current->next = node;
	lenth++;
	return OK;
}
//删除指定学号的考生的节点
Status List::del_Position(int n, Stu*& targetNode)
{
	Stu* node;
	if (!seek_Position(n, node))
	{
		cout << "没有该考生" << endl;
		return FALSE;
	}
	Stu* current = head;
	for (int i = 0; i < lenth; i++)
	{
		if (current->next == node)
			break;
		current = current->next;
	}
	current->next = node->next;
	targetNode = node;
	lenth--;
	return OK;
}
//进行查询操作，查找考号为n的节点，并通过targetNode返回
Status List::seek_Position(int n, Stu*& targetNode)
{

	Stu* current = head->next;
	if (!current)
		return FALSE;
	while (current)
	{
		if (current->num == n)
			break;
		current = current->next;
	}
	if (current)
	{
		targetNode = current;
		return OK;
	}
	return FALSE;
}
//修改指定节点数据
Status List::ChangePos_WithNew(int n)
{
	Stu* node;
	if (!seek_Position(n, node))
	{
		cout << "没有该考生" << endl;
		return FALSE;
	}
	cout << "请依次输入考生的考号，姓名，性别，年龄以及报名类型：" << endl;

	cin >> node->num >> node->name >> node->sex >> node->age >> node->type;
	while (node->sex != "女" && node->sex != "男")
	{
		cout << "性别必须为男/女,请重新输入性别" << endl;
		cin >> node->sex;
	}
	return OK;
}
//释放所有节点
List::~List()
{
	Stu* p = head->next;
	while (p != NULL)
	{
		Stu* q = p;
		p = p->next;
		delete q;
	}
	delete head;
}
//输出操作
void List::Output_List()
{
	cout << endl;
	Stu* node = head->next;
	if (!node)
	{
		cout << "系统中没有考生" << endl;
		return;
	}
	cout << "考号           姓名           性别           年龄           报考类别" << endl;
	while (node != NULL)
	{
		cout << node->num << "              " << node->name << "           " << node->sex << "             " << node->age << "             " << node->type << endl;
		node = node->next;
	}
}
//统计性别
void List::Statistic_List_sex()
{

	Stu* p = head->next;
	int count_Sex = 0;
	cout << endl;
	cout << "下面开始统计性别" << endl;
	cout << "性别为女的考生有：" << endl;
	cout << "考号           姓名           性别           年龄           报考类别" << endl;
	while (p != NULL)
	{
		if (p->sex == "女")
		{
			cout << p->num << "              " << p->name << "              " << p->sex << "              " << p->age << "              " << p->type << endl;
			count_Sex++;
		}
		p = p->next;
	}
	cout << "共有" << count_Sex << "位" << endl;
	cout << endl;
	p = head->next;
	count_Sex = 0;
	cout << "性别为男的考生有：" << endl;
	cout << "考号           姓名           性别           年龄           报考类别" << endl;
	while (p != NULL)
	{
		if (p->sex == "男")
		{
			cout << p->num << "              " << p->name << "              " << p->sex << "              " << p->age << "              " << p->type << endl;
			count_Sex++;
		}
		p = p->next;
	}
	cout << "共有" << count_Sex << "位" << endl;

}
//统计报考类型
void List::Statistic_List_type()
{
	cout << endl;
	cout << "下面开始统计报考类别" << endl;

	//统计类别，先统计类别的个数
	static string allType[Maxsize];
	Stu* p = head->next;
	int count_Type = 0;             //用于记录类型个数 从0计数 始终指向当前位置
	while (p != NULL)
	{
		int tag = 1;
		for (int i = 0; i < count_Type; i++)
			if (p->type == allType[i])
				tag = 0;
		if (tag)
		{

			allType[count_Type] = p->type;
			count_Type++;
		}
		p = p->next;
	}
	cout << "共有" << count_Type << "种报考类别" << endl;

	//统计每种报考类别下的人数
	for (int i = 0; i < count_Type; i++)
	{
		cout << "报考类别为 " << allType[i] << " 的考生有:" << endl;
		cout << "考号           姓名           性别           年龄           报考类别" << endl;
		int total = 0;
		p = head->next;
		while (p != NULL)
		{
			if (p->type == allType[i])
			{
				cout << p->num << "              " << p->name << "              " << p->sex << "              " << p->age << "              " << p->type << endl;
				total++;
			}
			p = p->next;
		}
		cout << "共有" << total << "位" << endl;
		cout << endl;
	}
}