#include <iostream>
#include <vector>
#define MAXSIZE 100
using namespace std;
template<class T>
class queue {
public:
	//存储空间的基地址
	T* base;
	//头指针
	int front;
	//尾指针
	int rear;


	//1.构造队列
	queue()
	{
		base = new T[MAXSIZE];
		rear = front = 0;
	}
	//2.求队列长度
	int QueueLength()
	{
		return (rear + MAXSIZE - front) % MAXSIZE;
	}

	//3.入队
	bool EnQueue(T e)
	{
		//队列满则返回false
		if ((rear + 1) % MAXSIZE == front)
			return false;
		//新元素插入队尾
		base[rear] = e;
		rear = (rear + 1) % MAXSIZE;
		return true;
	}
	//4.出队
	bool DeQueue()
	{
		//队列为空则不能出队
		if (rear == front)
			return false;
		//队头指针加一
		front = (front + 1) % MAXSIZE;
		return true;
	}

	//5.取队头元素
	T getHead()
	{
		if (front != rear)
			return base[front];
	}
};

int main()
{
	queue<int> qu;
	cout << "测试入队";
	for (int i = 0; i < 10; i++)
	{
		qu.EnQueue(i);
	}
	cout << endl<<"长度为：" << qu.QueueLength() << endl;
	cout << endl << "测试取队头元素" << endl;
	cout<<qu.getHead();

	cout << endl << "测试出队" << endl;
	qu.DeQueue();
	cout << "长度为：" << qu.QueueLength() << endl;
}


