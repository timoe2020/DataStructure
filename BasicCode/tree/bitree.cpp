#include <iostream>
#include <vector>
#include <string>
#define MAXSIZE 100
#define nullptr NULL 
using namespace std;
template <typename T>
class TNode {
public:
	T data;
	TNode<T>* lchild;
	TNode<T>* rchild;
	TNode()
	{
		this->data = 0;
		lchild = nullptr;
		rchild = nullptr;
	}
	TNode(T data)
	{
		this->data = data;
		lchild = nullptr;
		rchild = nullptr;
	}
};

//递归创建二叉树，当输入flag时创建空子树
template <typename T>
void CreateBiTree(TNode<T>* &root,T flag)
{
	T ch;
	cin >> ch;
	//递归出口为输入flag，此时递归结束，建立空树
	if (ch == flag)
	{
		root = nullptr;
	}
	else {
		root = new TNode<T>(ch);
		CreateBiTree(root->lchild,flag);
		CreateBiTree(root->rchild,flag);
	}	
}

//先序遍历
template <typename T>
void PreOrderTraverse(TNode<T> *&Tree)
{
	if (Tree)
	{
		cout<< Tree->data;
		PreOrderTraverse(Tree->lchild);
		PreOrderTraverse(Tree->rchild);
	}
	else {
		cout << " " ;
	}
}



//中序遍历
template <typename T>
void InOrderTraverse(TNode<T>*& Tree)
{
	if (Tree)
	{
		
		InOrderTraverse(Tree->lchild);
		cout << Tree->data;
		InOrderTraverse(Tree->rchild);
	}
	else {
		cout << " ";
	}
}

//后序遍历
template <typename T>
void LastOrderTraverse(TNode<T>*& Tree)
{
	if (Tree)
	{
		
		LastOrderTraverse(Tree->lchild);
		LastOrderTraverse(Tree->rchild);
		cout << Tree->data;
	}
	else {
		cout << " ";
	}
}

//复制二叉树
template <typename T>
void Copy(TNode<T>* tree, TNode<T>*& NewTree)
{
	if (tree == nullptr)
	{
		NewTree = nullptr;
		return;
	}
	else {
		NewTree = new TNode<T>();
		NewTree->data = tree->data;
		Copy(tree->lchild, NewTree->lchild);
		Copy(tree->rchild, NewTree->rchild);
	}
}

//计算二叉树的深度
template <typename T>
int depth(TNode<T>* tree)
{
	if (tree == nullptr)
		return 0;
	else {
		int m = depth(tree->lchild);
		int n = depth(tree->rchild);
		if (m > n)
			return m + 1;
		else
			return n + 1;
	}
}

//计算结点个数
template <typename T>
int NodeCount(TNode<T>* tree)
{
	if (tree == nullptr)
		return 0;
	else
		return NodeCount(tree->lchild) + NodeCount(tree->rchild) + 1;
}

int main()
{
	cout << "创建一颗二叉树,其中1-9字符代表树的数据,用0表示空树:" << endl;
	TNode<int>* Tree;
	CreateBiTree<int>(Tree,0);
	cout << "先序递归遍历" << endl;
	PreOrderTraverse<int>(Tree);
	cout << "中序递归遍历" << endl;
	InOrderTraverse<int>(Tree);
	cout << "后序递归遍历" << endl;
	LastOrderTraverse<int>(Tree);

	TNode<int>* NewTree;
	Copy<int>(Tree, NewTree);
	cout << "先序递归遍历" << endl;
	PreOrderTraverse<int>(Tree);

	cout << "depth:" << depth(Tree) << endl;

	cout << "count of node" << NodeCount(Tree) << endl;
	return 0;
}


