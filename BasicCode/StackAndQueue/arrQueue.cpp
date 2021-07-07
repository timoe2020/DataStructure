#include <iostream>
#include <vector>
#define MAXSIZE 100
using namespace std;
template<class T>
class queue {
public:
	//�洢�ռ�Ļ���ַ
	T* base;
	//ͷָ��
	int front;
	//βָ��
	int rear;


	//1.�������
	queue()
	{
		base = new T[MAXSIZE];
		rear = front = 0;
	}
	//2.����г���
	int QueueLength()
	{
		return (rear + MAXSIZE - front) % MAXSIZE;
	}

	//3.���
	bool EnQueue(T e)
	{
		//�������򷵻�false
		if ((rear + 1) % MAXSIZE == front)
			return false;
		//��Ԫ�ز����β
		base[rear] = e;
		rear = (rear + 1) % MAXSIZE;
		return true;
	}
	//4.����
	bool DeQueue()
	{
		//����Ϊ�����ܳ���
		if (rear == front)
			return false;
		//��ͷָ���һ
		front = (front + 1) % MAXSIZE;
		return true;
	}

	//5.ȡ��ͷԪ��
	T getHead()
	{
		if (front != rear)
			return base[front];
	}
};

int main()
{
	queue<int> qu;
	cout << "�������";
	for (int i = 0; i < 10; i++)
	{
		qu.EnQueue(i);
	}
	cout << endl<<"����Ϊ��" << qu.QueueLength() << endl;
	cout << endl << "����ȡ��ͷԪ��" << endl;
	cout<<qu.getHead();

	cout << endl << "���Գ���" << endl;
	qu.DeQueue();
	cout << "����Ϊ��" << qu.QueueLength() << endl;
}


