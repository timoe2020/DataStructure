#include <iostream>
#include <vector>
#define MAXSIZE 100
#define nullptr NULL 
using namespace std;
template<class T>
class Node {
public:
	T data;
	Node<T>* next;
	Node()
	{

	}
	Node(T data)
	{
		this->data = data;
	}
};


template<class T>
class LinStack {
public:
	Node<T>* head;
	LinStack()
	{
		head = new Node<T>();
		head->next = nullptr;

	}

	//入栈
	bool Push(T e)
	{
		Node<T>* p = new Node<T>(e);
		p->next = head;
		this->head = p;
		return true;
	}

	//出栈
	bool Pop()
	{
		if (this->head->next == nullptr)
			return false;
		Node<T>* e = this->head;
		this->head = this->head->next;
		delete(e);
		return true;
	}

	//取栈顶元素
	T GetTop()
	{
		if (this->head->next)
		{
			return this->head->data;
		}
		return -1;
	}
};

int main()
{
	LinStack<int> stack;
	cout << endl << "test push" << endl;
	for (int i = 0; i < 10; i++)
	{
		stack.Push(i);
	}
	cout << endl << "test get top" << endl;
	cout << stack.GetTop();
	cout << endl << "test pop" << endl;
	stack.Pop();
	cout << stack.GetTop();
}
