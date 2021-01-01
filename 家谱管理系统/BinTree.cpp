#include"BinTree.h"
#include"DEFINE.h"
#include<string>
#include<cstring>
#include<iostream>
using namespace std;

//���ŷ���ӡ����
void printTree(BinTreeNode* t)
{
	if (t == NULL)
		return;
	cout << t->name;
	if (t->firstChild || t->rSibling)
	{
		if (t->firstChild)
		{
			cout << '(';
			printTree(t->firstChild);
		}
		if (t->rSibling)
		{
			cout << ',';
			printTree(t->rSibling);
		}
		cout << ')';
	}
}
//��ʼ������
BinTree::BinTree()
{
	cout << "���Ƚ���һ�����ף�" << endl;
	cout << "���������ȵ�����:";
	root = new(BinTreeNode);
	if (!root)
	{
		cout << "����ʧ��" << endl;
		exit(1);
	}
	cin >> root->name;
	root->firstChild = NULL;
	root->rSibling = NULL;
	cin.clear();
	cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
}
BinTree::~BinTree()
{
	BTreeSetNull(root);
}
//�ҵ���Ϊtemp�������ڵĽڵ�
BinTreeNode* BinTree::LocateName(BinTreeNode* t, ElemType temp)
{
	if (!t)
		return t;
	if (t->name == temp)
		return t;
	BinTreeNode* p;
	p = LocateName(t->firstChild, temp);
	if (p)
		return p;
	p = LocateName(t->rSibling, temp);
	return p;
}
//���ָ���ڵ�ĵ�һ����Ů
Statue BinTree::PrintChild(BinTreeNode* t, ElemType temp)
{
	cout << temp << "�ĵ�һ��������:  ";
	t = t->firstChild;
	if (!t)
	{
		cout << "�����û������" << endl;
		return FALSE;
	}
	while (t)
	{
		cout << t->name << "    ";
		t = t->rSibling;
	}
	return OK;
}

//����t��n����Ů�ڵ�
Statue BinTree::CreateChild(int n, BinTreeNode* t)
{
	if (!t)
		return ERROR;
	string temp;
	int count = 0;
	if (!t->firstChild)
	{
		t->firstChild = new(BinTreeNode);
		if (!t->firstChild)
		{
			cout << "����ʧ��" << endl;
			return ERROR;
		}
		t = t->firstChild;
		cin >> temp;
		t->name = temp;
		t->firstChild = NULL;
		count = 1;
	}
	else
	{
		t = t->firstChild;
		while (t->rSibling != NULL)
			t = t->rSibling;
	}
	//��������Ů���ֵܽڵ�
	for (int i = count; i < n; i++)
	{
		t->rSibling = new(BinTreeNode);
		if (!t)
		{
			cout << "����ʧ��" << endl;
			return ERROR;
		}
		cin >> temp;
		t->rSibling->name = temp;
		t->rSibling->firstChild = NULL;
		t = t->rSibling;
	}
	t->rSibling = NULL;
	return OK;
}
//����һ���¼�ͥ
Statue BinTree::CreateFamily()
{
	if (!root)
	{
		cout << "����Ϊ�գ��Ƿ���һ���¼���" << endl;
		cout << "Y �� N ��" << endl;
		char op;
		char op_[10];
		cin >> op_;
		int n = strlen(op_);
		if (n > 1)
		{
			cout << "�����������,����������" << endl;
			cin >> op_;
			n = strlen(op_);
		}
		else
			op = op_[0];
		while (op != 'N' && op != 'Y')
		{
			cout << "û�����ѡ�����������" << endl;
			cin >> op;
		}
		if (op == 'N')
		{
			cout << "�����ر�ϵͳ" << endl;
			return CLOSE;
		}
		root = new(BinTreeNode);
		if (!root)
		{
			cout << "����ʧ��" << endl;
			exit(1);
		}
		cout << "���������ȵ�����: ";
		ElemType temp;
		cin >> temp;
		root->name = temp;
		root->firstChild = NULL;
		root->rSibling = NULL;
		return OK;
	}
	cout << "������Ҫ������ͥ���˵�����: ";
	ElemType temp;
	cin >> temp;

	//�ҵ���������������ڵĽڵ�
	BinTreeNode* t = LocateName(root, temp);
	if (!t)
	{
		cout << "������û�������" << endl;
		return FALSE;
	}

	cin.clear();
	cin.ignore(std::numeric_limits< streamsize >::max(), '\n');

	cout << "������" << temp << "�Ķ�Ů����: ";
	int n;
	cin >> n;
	while (cin.fail())
	{
		cout << "����������" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
		cout << "������" << temp << "�Ķ�Ů����: ";
		cin >> n;
	}

	while (n <= 0)
	{
		cout << "������һ��������" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
		cout << "������" << temp << "�Ķ�Ů����: ";
		cin >> n;
	}

	cout << "����������" << temp << "�Ķ�Ů����: ";

	//������Ů�ڵ�
	CreateChild(n, t);
	PrintChild(t, temp);
	cout << endl;
	return OK;
}
//�����еļ�ͥ�м�����Ů
Statue BinTree::AddChild()
{
	cout << "������Ҫ��Ӷ��ӣ���Ů�������˵�����: ";
	ElemType temp;
	cin >> temp;
	BinTreeNode* t = LocateName(root, temp);
	if (!t)
	{
		cout << "������û�������" << endl;
		return FALSE;
	}
	cout << "������" << temp << "Ҫ��ӵĶ��ӣ���Ů�����ĸ���: ";
	int n;
	cin >> n;
	while (n <= 0)
	{
		cout << "Ӧ����һ��������" << endl;
		cout << "������" << temp << "Ҫ��ӵĶ��ӣ���Ů�����ĸ���: ";
		cin >> n;
	}
	cout << "������" << temp << "Ҫ��ӵĶ��ӣ���Ů����������: ";
	CreateChild(n, t);
	PrintChild(t, temp);
	cout << endl;
	return OK;

}
//Ѱ��ǰ��
Statue BinTree::LocateParent(BinTreeNode* t, ElemType temp, BinTreeNode*& parent)
{
	if (!t)
		return FALSE;
	if (t->firstChild && t->firstChild->name == temp)
	{
		parent = t;
		return FIRSTCHILD;
	}
	if (t->rSibling && t->rSibling->name == temp)
	{
		parent = t;
		return RSIBLING;
	}
	int p;
	p = LocateParent(t->firstChild, temp, parent);
	if (p)
		return p;
	p = LocateParent(t->rSibling, temp, parent);
	return p;
}
//ɾ��t����������
void BinTree::DelChild(BinTreeNode* t)
{
	if (!t)
		return;
	DelChild(t->firstChild);
	BinTreeNode* p = t->firstChild;
	t->firstChild = NULL;
	delete p;
	DelChild(t->rSibling);
}
//��ɢһ����ͥ
Statue BinTree::ReleaseFamily()
{
	cout << "������Ҫ��ɢ�ļ�ͥ���˵�����: ";
	ElemType temp;
	cin >> temp;
	BinTreeNode* t = LocateName(root, temp);
	if (!t)
	{
		cout << "������û�������" << endl;
		return FALSE;
	}
	if (t == root)
	{
		delete t;
		root = NULL;
	}
	else
	{
		BinTreeNode* t_Parent;
		int p = LocateParent(root, temp, t_Parent);
		if (p == FIRSTCHILD)
		{
			DelChild(t->firstChild);
			t_Parent->firstChild = t->rSibling;
			delete t;
		}
		else if (p == RSIBLING)
		{
			DelChild(t->firstChild);
			t_Parent->rSibling = t->rSibling;
			delete t;
		}
		else
			return ERROR;
		cout << "���º�ļ���Ϊ:" << endl;
		printTree(root);
		cout << endl;
		PrintChild(t_Parent, t_Parent->name);
	}
	return OK;
}
//��������
Statue BinTree::ChangeName()
{
	cout << "Ҫ������������Ŀǰ������:";
	ElemType temp;
	cin >> temp;
	BinTreeNode* t = LocateName(root, temp);
	if (!t)
	{
		cout << "������û�������" << endl;
		return FALSE;
	}
	cout << "��������ĺ������: ";
	ElemType temp_;
	cin >> temp_;
	t->name = temp_;
	cout << temp << "�Ѹ���Ϊ" << temp_;
	return OK;
}
BinTreeNode* BinTree::GetRoot()
{
	return root;
}

void BinTree::BTreeSetNull(BinTreeNode* r)
{
	if (r == NULL)
		return;
	BTreeSetNull(r->firstChild);
	BTreeSetNull(r->rSibling);
	delete r;
}

