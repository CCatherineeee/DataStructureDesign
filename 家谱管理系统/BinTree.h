#pragma once
#include<string>
#include<cstring>
using namespace std;

typedef int Statue;
typedef string ElemType;

struct BinTreeNode
{
	//��ڵ�Ϊ��һ����Ů�ڵ� �ҽڵ�Ϊ�ֵܽڵ�
	BinTreeNode* firstChild, * rSibling;
	//����
	ElemType name;
};
class BinTree
{
private:
	BinTreeNode* root;

public:
	//���캯������ʼ�����ף��������ȵ�����
	BinTree();
	//����������ͨ������BTreeSetNullʵ���ڴ��ͷ�
	~BinTree();
	//����һ����ͥ
	Statue CreateFamily();
	//ͨ������temp��λ����㣬�����ڵ㷵��
	BinTreeNode* LocateName(BinTreeNode* t, ElemType temp);
	//���ظ��ڵ�
	BinTreeNode* GetRoot();
	//��λ���ڵ�t��ǰ���ڵ㣬�����ڵ�ͨ��parent���أ�����ֵָʾ����ǰ���Ǹ��׻����ֵ�
	Statue LocateParent(BinTreeNode* t, ElemType temp, BinTreeNode*& parent);
	//����һ����Ů�ڵ�
	Statue CreateChild(int n, BinTreeNode* t);
	//�ѽڵ�t�ĵ�һ�������ӡ����
	Statue PrintChild(BinTreeNode* t, ElemType temp);
	//�ڼ������¼���һ����Ů
	Statue AddChild();
	//��ɢһ����ͥ
	Statue ReleaseFamily();
	//�ı�һ���ڵ������
	Statue ChangeName();
	//ɾ���ڵ�t��������Ů
	void DelChild(BinTreeNode* t);
	//�ͷ���tΪ���ڵ�����������ڴ�
	void BTreeSetNull(BinTreeNode* r);
	friend void printTree(BinTreeNode* r);
};