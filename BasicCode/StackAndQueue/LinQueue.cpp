#include <iostream>
#include <vector>
#define MAXSIZE 100
#define nullptr NULL 
using namespace std;
template<class T>
class QNode {
public:
	T data;
	QNode* next;
	QNode()
	{

	}
	QNode(T e)
	{
		this->data = e;
		this->next = nullptr;
	}
};

template<class T>
class Queue {
public:
	//队头指针
	QNode<T>* front;
	//队尾指针
	QNode<T>* rear;
	//1.初始化
	Queue()
	{
		front = rear = new QNode<T>();
		front->next = nullptr;
	}
	//2.入队
	bool EnQueue(T e)
	{
		QNode<T> *p = new QNode<T>(e);
		rear->next = p;
		rear = p;
		return true;
	}

	int QueueLength()
	{
		int length = 0;
		QNode<T>* temp = front;
		
		while (temp->next != nullptr)
		{	
			temp = temp->next;
			cout << temp->data << endl;
			length++;
		}
		return length;
	}

	//3.出队
	bool DeQueue()
	{
		if (front == rear)
			return false;
		QNode<T>* p = front;
		//修改头指针
		front = p->next;
		//出队到最后一个元素，尾指针指向头节点
		if (rear == p)
			rear = front;
		delete(p);
		return true;
	}
	//4.取队头元素
	T GetHead()
	{
		if(rear!=front)
			return front->next->data;
	}
	
};

int main()
{
	Queue<int> qu;
	cout << "测试入队";
	for (int i = 0; i < 10; i++)
	{
		qu.EnQueue(i);
	}
	cout << endl << "长度为：" << qu.QueueLength() << endl;
	cout << endl << "测试取队头元素" << endl;
	cout << qu.GetHead();

	cout << endl << "测试出队" << endl;
	qu.DeQueue();
	cout << "长度为：" << qu.QueueLength() << endl;
}
