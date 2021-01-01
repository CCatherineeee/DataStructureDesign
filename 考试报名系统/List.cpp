#include<iostream>
#include<string>
#include<cstring>
#include"List.h"

using namespace std;


const int Maxsize = 100;

//����һ������ͷ�ڵ�Ŀձ�
List::List()
{
	head = new (Stu);
	if (head == NULL)
	{
		cout << "����ʧ��" << endl;
		return;
	}
	lenth = 0;
	head->next = NULL;
}

//��ʼ������
Status List::InPut_List()
{
	cout << "���Ƚ������Ա���ϵͳ" << endl;
	cout << "�����뿼��������";
	cin >> lenth;
	while (lenth <= 0)
	{
		cout << "������һ��������" << endl;
		cout << "�����뿼��������";
		cin >> lenth;
	}
	cout << "���������뿼���Ŀ��ţ��������Ա������Լ��������ͣ�" << endl;
	Stu* p = head;
	//head->next = node;

	for (int i = 0; i < lenth; i++)
	{
		Stu* node = new (Stu);
		if (node == NULL)
		{
			cout << "����ʧ��" << endl;
			return ERROR;
		}
		cin >> node->num >> node->name >> node->sex >> node->age >> node->type;
		while (node->sex != "Ů" && node->sex != "��")
		{
			cout << "�Ա����Ϊ��/Ů,�����������Ա�" << endl;
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
//�������
Status List::Insert_List(int pos)
{
	if (pos<1 || pos>lenth + 1)
	{
		if (lenth != 0)
			cout << "�޸�λ�ò��Ϸ�,ӦΪ1��" << lenth << endl;
		else
			cout << "�޸�λ�ò��Ϸ�,ӦΪ1" << endl;
		return ERROR;
	}
	cout << "���������뿼���Ŀ��ţ��������Ա������Լ��������ͣ�" << endl;
	Stu* node = new (Stu);
	if (node == NULL)
	{
		cout << "����ʧ��" << endl;
		return ERROR;
	}
	cin >> node->num >> node->name >> node->sex >> node->age >> node->type;
	while (node->sex != "Ů" && node->sex != "��")
	{
		cout << "�Ա����Ϊ��/Ů,�����������Ա�" << endl;
		cin >> node->sex;
	}
	Stu* current = head;
	//�ҵ�����λ�� currentָ�����λ�õ�ǰһ���ڵ�
	for (int i = 1; i < pos; i++)
		current = current->next;
	node->next = current->next;
	current->next = node;
	lenth++;
	return OK;
}
//ɾ��ָ��ѧ�ŵĿ����Ľڵ�
Status List::del_Position(int n, Stu*& targetNode)
{
	Stu* node;
	if (!seek_Position(n, node))
	{
		cout << "û�иÿ���" << endl;
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
//���в�ѯ���������ҿ���Ϊn�Ľڵ㣬��ͨ��targetNode����
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
//�޸�ָ���ڵ�����
Status List::ChangePos_WithNew(int n)
{
	Stu* node;
	if (!seek_Position(n, node))
	{
		cout << "û�иÿ���" << endl;
		return FALSE;
	}
	cout << "���������뿼���Ŀ��ţ��������Ա������Լ��������ͣ�" << endl;

	cin >> node->num >> node->name >> node->sex >> node->age >> node->type;
	while (node->sex != "Ů" && node->sex != "��")
	{
		cout << "�Ա����Ϊ��/Ů,�����������Ա�" << endl;
		cin >> node->sex;
	}
	return OK;
}
//�ͷ����нڵ�
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
//�������
void List::Output_List()
{
	cout << endl;
	Stu* node = head->next;
	if (!node)
	{
		cout << "ϵͳ��û�п���" << endl;
		return;
	}
	cout << "����           ����           �Ա�           ����           �������" << endl;
	while (node != NULL)
	{
		cout << node->num << "              " << node->name << "           " << node->sex << "             " << node->age << "             " << node->type << endl;
		node = node->next;
	}
}
//ͳ���Ա�
void List::Statistic_List_sex()
{

	Stu* p = head->next;
	int count_Sex = 0;
	cout << endl;
	cout << "���濪ʼͳ���Ա�" << endl;
	cout << "�Ա�ΪŮ�Ŀ����У�" << endl;
	cout << "����           ����           �Ա�           ����           �������" << endl;
	while (p != NULL)
	{
		if (p->sex == "Ů")
		{
			cout << p->num << "              " << p->name << "              " << p->sex << "              " << p->age << "              " << p->type << endl;
			count_Sex++;
		}
		p = p->next;
	}
	cout << "����" << count_Sex << "λ" << endl;
	cout << endl;
	p = head->next;
	count_Sex = 0;
	cout << "�Ա�Ϊ�еĿ����У�" << endl;
	cout << "����           ����           �Ա�           ����           �������" << endl;
	while (p != NULL)
	{
		if (p->sex == "��")
		{
			cout << p->num << "              " << p->name << "              " << p->sex << "              " << p->age << "              " << p->type << endl;
			count_Sex++;
		}
		p = p->next;
	}
	cout << "����" << count_Sex << "λ" << endl;

}
//ͳ�Ʊ�������
void List::Statistic_List_type()
{
	cout << endl;
	cout << "���濪ʼͳ�Ʊ������" << endl;

	//ͳ�������ͳ�����ĸ���
	static string allType[Maxsize];
	Stu* p = head->next;
	int count_Type = 0;             //���ڼ�¼���͸��� ��0���� ʼ��ָ��ǰλ��
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
	cout << "����" << count_Type << "�ֱ������" << endl;

	//ͳ��ÿ�ֱ�������µ�����
	for (int i = 0; i < count_Type; i++)
	{
		cout << "�������Ϊ " << allType[i] << " �Ŀ�����:" << endl;
		cout << "����           ����           �Ա�           ����           �������" << endl;
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
		cout << "����" << total << "λ" << endl;
		cout << endl;
	}
}