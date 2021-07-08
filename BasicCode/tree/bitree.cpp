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

//�ݹ鴴����������������flagʱ����������
template <typename T>
void CreateBiTree(TNode<T>* &root,T flag)
{
	T ch;
	cin >> ch;
	//�ݹ����Ϊ����flag����ʱ�ݹ��������������
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

//�������
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



//�������
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

//�������
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

//���ƶ�����
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

//��������������
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

//���������
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
	cout << "����һ�Ŷ�����,����1-9�ַ�������������,��0��ʾ����:" << endl;
	TNode<int>* Tree;
	CreateBiTree<int>(Tree,0);
	cout << "����ݹ����" << endl;
	PreOrderTraverse<int>(Tree);
	cout << "����ݹ����" << endl;
	InOrderTraverse<int>(Tree);
	cout << "����ݹ����" << endl;
	LastOrderTraverse<int>(Tree);

	TNode<int>* NewTree;
	Copy<int>(Tree, NewTree);
	cout << "����ݹ����" << endl;
	PreOrderTraverse<int>(Tree);

	cout << "depth:" << depth(Tree) << endl;

	cout << "count of node" << NodeCount(Tree) << endl;
	return 0;
}


