#pragma once
#include<string>
#include<cstring>
using namespace std;

typedef int Statue;
typedef string ElemType;

struct BinTreeNode
{
	//左节点为第一个子女节点 右节点为兄弟节点
	BinTreeNode* firstChild, * rSibling;
	//姓名
	ElemType name;
};
class BinTree
{
private:
	BinTreeNode* root;

public:
	//构造函数，初始化家谱，建立祖先的姓名
	BinTree();
	//析构函数，通过调用BTreeSetNull实现内存释放
	~BinTree();
	//建立一个家庭
	Statue CreateFamily();
	//通过名字temp定位到结点，并将节点返回
	BinTreeNode* LocateName(BinTreeNode* t, ElemType temp);
	//返回根节点
	BinTreeNode* GetRoot();
	//定位到节点t的前驱节点，并将节点通过parent返回，返回值指示他的前驱是父亲还是兄弟
	Statue LocateParent(BinTreeNode* t, ElemType temp, BinTreeNode*& parent);
	//创建一个子女节点
	Statue CreateChild(int n, BinTreeNode* t);
	//把节点t的第一代子孙打印出来
	Statue PrintChild(BinTreeNode* t, ElemType temp);
	//在家谱中新加入一个子女
	Statue AddChild();
	//解散一个家庭
	Statue ReleaseFamily();
	//改变一个节点的名字
	Statue ChangeName();
	//删除节点t的所有子女
	void DelChild(BinTreeNode* t);
	//释放以t为根节点的树的所有内存
	void BTreeSetNull(BinTreeNode* r);
	friend void printTree(BinTreeNode* r);
};