#pragma once
#include<string>
#include<cstring>
#include"DEFINE.h"
using namespace std;
struct Stu
{
	int num;			//ѧ��
	int age;			//����
	string name;		//����
	string type;		//��������
	string sex;			//�Ա�
	Stu* next;
};
class List
{
private:
	int lenth;
	Stu* head;
public:
	//List�Ĺ��캯�����ڹ��캯���д���һ������ͷ head �Ŀձ�
	List();
	//List�������������������������ͷ����нڵ㣬����ͷ�ڵ㡣
	~List();
	//List�ĳ�ʼ����������巨��������������lenth������
	Status InPut_List();
	//���в�������������ڵ�Ϊ��pos���ڵ�
	Status Insert_List(int pos);
	//����ɾ��������ɾ������Ϊn�Ľڵ㣬��ͨ��targetNode����
	Status del_Position(int n, Stu*& targetNode);
	//���в�ѯ���������ҿ���Ϊn�Ľڵ㣬��ͨ��targetNode����
	Status seek_Position(int n, Stu*& targetNode);
	//�����޸Ĳ������޸Ŀ���Ϊn�Ľڵ�
	Status ChangePos_WithNew(int n);
	//����ͳ�Ʋ�����ͳ���Ա�����
	void Statistic_List_sex();
	//����ͳ�Ʋ�����ͳ�Ʊ����������
	void Statistic_List_type();
	//�����������
	void Output_List();
};