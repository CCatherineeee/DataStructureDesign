#include"BinTree.h"
#include"DEFINE.h"
#include<string>
#include<cstring>
#include<iostream>
using namespace std;

//括号法打印家谱
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
//初始化家谱
BinTree::BinTree()
{
	cout << "首先建立一个家谱！" << endl;
	cout << "请输入祖先的姓名:";
	root = new(BinTreeNode);
	if (!root)
	{
		cout << "建立失败" << endl;
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
//找到名为temp的人所在的节点
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
//输出指定节点的第一代子女
Statue BinTree::PrintChild(BinTreeNode* t, ElemType temp)
{
	cout << temp << "的第一代子孙是:  ";
	t = t->firstChild;
	if (!t)
	{
		cout << "这个人没有子孙" << endl;
		return FALSE;
	}
	while (t)
	{
		cout << t->name << "    ";
		t = t->rSibling;
	}
	return OK;
}

//建立t的n个子女节点
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
			cout << "建立失败" << endl;
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
	//建立该子女的兄弟节点
	for (int i = count; i < n; i++)
	{
		t->rSibling = new(BinTreeNode);
		if (!t)
		{
			cout << "建立失败" << endl;
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
//创建一个新家庭
Statue BinTree::CreateFamily()
{
	if (!root)
	{
		cout << "家谱为空，是否建立一个新家谱" << endl;
		cout << "Y 是 N 否" << endl;
		char op;
		char op_[10];
		cin >> op_;
		int n = strlen(op_);
		if (n > 1)
		{
			cout << "操作输入错误,请重新输入" << endl;
			cin >> op_;
			n = strlen(op_);
		}
		else
			op = op_[0];
		while (op != 'N' && op != 'Y')
		{
			cout << "没有这个选项，请重新输入" << endl;
			cin >> op;
		}
		if (op == 'N')
		{
			cout << "即将关闭系统" << endl;
			return CLOSE;
		}
		root = new(BinTreeNode);
		if (!root)
		{
			cout << "建立失败" << endl;
			exit(1);
		}
		cout << "请输入祖先的姓名: ";
		ElemType temp;
		cin >> temp;
		root->name = temp;
		root->firstChild = NULL;
		root->rSibling = NULL;
		return OK;
	}
	cout << "请输入要建立家庭的人的姓名: ";
	ElemType temp;
	cin >> temp;

	//找到建立家族的人所在的节点
	BinTreeNode* t = LocateName(root, temp);
	if (!t)
	{
		cout << "家谱中没有这个人" << endl;
		return FALSE;
	}

	cin.clear();
	cin.ignore(std::numeric_limits< streamsize >::max(), '\n');

	cout << "请输入" << temp << "的儿女个数: ";
	int n;
	cin >> n;
	while (cin.fail())
	{
		cout << "请输入数字" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
		cout << "请输入" << temp << "的儿女个数: ";
		cin >> n;
	}

	while (n <= 0)
	{
		cout << "请输入一个正整数" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits< streamsize >::max(), '\n');
		cout << "请输入" << temp << "的儿女个数: ";
		cin >> n;
	}

	cout << "请依次输入" << temp << "的儿女姓名: ";

	//建立子女节点
	CreateChild(n, t);
	PrintChild(t, temp);
	cout << endl;
	return OK;
}
//在已有的家庭中加入子女
Statue BinTree::AddChild()
{
	cout << "请输入要添加儿子（或女儿）的人的姓名: ";
	ElemType temp;
	cin >> temp;
	BinTreeNode* t = LocateName(root, temp);
	if (!t)
	{
		cout << "家谱中没有这个人" << endl;
		return FALSE;
	}
	cout << "请输入" << temp << "要添加的儿子（或女儿）的个数: ";
	int n;
	cin >> n;
	while (n <= 0)
	{
		cout << "应输入一个正整数" << endl;
		cout << "请输入" << temp << "要添加的儿子（或女儿）的个数: ";
		cin >> n;
	}
	cout << "请输入" << temp << "要添加的儿子（或女儿）的姓名: ";
	CreateChild(n, t);
	PrintChild(t, temp);
	cout << endl;
	return OK;

}
//寻找前继
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
//删除t的所有子孙
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
//解散一个家庭
Statue BinTree::ReleaseFamily()
{
	cout << "请输入要解散的家庭的人的姓名: ";
	ElemType temp;
	cin >> temp;
	BinTreeNode* t = LocateName(root, temp);
	if (!t)
	{
		cout << "家谱中没有这个人" << endl;
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
		cout << "更新后的家谱为:" << endl;
		printTree(root);
		cout << endl;
		PrintChild(t_Parent, t_Parent->name);
	}
	return OK;
}
//更改姓名
Statue BinTree::ChangeName()
{
	cout << "要更改姓名的人目前的姓名:";
	ElemType temp;
	cin >> temp;
	BinTreeNode* t = LocateName(root, temp);
	if (!t)
	{
		cout << "家谱中没有这个人" << endl;
		return FALSE;
	}
	cout << "请输入更改后的姓名: ";
	ElemType temp_;
	cin >> temp_;
	t->name = temp_;
	cout << temp << "已更名为" << temp_;
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

