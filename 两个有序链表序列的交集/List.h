#pragma once
#define OK      1
#define TRUE    1
#define FALSE   0
#define ERROR   -1

typedef int Status;          //���巵����ʾֵ����
typedef int ElemTtype;       //����ڵ���������

/********************** ������ഢ�� *******************************/
struct node
{
	ElemTtype data;          //�ڵ������
	node* next;              //���ָ��
};
class SqList
{
private:
	node* head;              // ͷ�ڵ�      
public:
	//���캯���������ձ�
	SqList();
	//��������������MadeListClear()
	~SqList();
	//����һ����������
	Status CreateList();
	//���һ����������
	Status Output();
	//�ͷų�ͷ�ڵ�����Ľ��
	Status MadeListClear();
	//�ж��Ƿ�Ϊ��������
	Status IsOrdered();
	//�������ͷ�ڵ�
	node* GetHead();

};
