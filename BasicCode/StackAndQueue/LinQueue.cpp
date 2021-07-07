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
	//��ͷָ��
	QNode<T>* front;
	//��βָ��
	QNode<T>* rear;
	//1.��ʼ��
	Queue()
	{
		front = rear = new QNode<T>();
		front->next = nullptr;
	}
	//2.���
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

	//3.����
	bool DeQueue()
	{
		if (front == rear)
			return false;
		QNode<T>* p = front;
		//�޸�ͷָ��
		front = p->next;
		//���ӵ����һ��Ԫ�أ�βָ��ָ��ͷ�ڵ�
		if (rear == p)
			rear = front;
		delete(p);
		return true;
	}
	//4.ȡ��ͷԪ��
	T GetHead()
	{
		if(rear!=front)
			return front->next->data;
	}
	
};

int main()
{
	Queue<int> qu;
	cout << "�������";
	for (int i = 0; i < 10; i++)
	{
		qu.EnQueue(i);
	}
	cout << endl << "����Ϊ��" << qu.QueueLength() << endl;
	cout << endl << "����ȡ��ͷԪ��" << endl;
	cout << qu.GetHead();

	cout << endl << "���Գ���" << endl;
	qu.DeQueue();
	cout << "����Ϊ��" << qu.QueueLength() << endl;
}
