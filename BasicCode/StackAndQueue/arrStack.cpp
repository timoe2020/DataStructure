#include <iostream>
#include <vector>
#define MAXSIZE 100
using namespace std;

template<class T>
class  arrStack {
public:
	T* top;			//栈顶指针
	T* base;		//栈底指针
	int stacksize;	//栈可用的最大容量

	//1.初始化
	arrStack()
	{
		this->base = new T[MAXSIZE];
		this->top = this->base;
		this->stacksize = MAXSIZE;
	}


	//2.入栈：插入新的元素成为栈顶元素
	bool Push(T e)
	{
		if (this->top - this->base == this->stacksize)
			return false;
		*this->top = e;
		this->top++;
	
		return true;
	}

	//3.出栈
	bool Pop()
	{
		if (this->base != this->top)
		{
			this->top--;
			return true;
		}
		return false;
	}

	//4.取栈顶元素
	T GetTop()
	{
		if (this->base != this->top)
		{
			return *(this->top - 1);
		}
		return -1;
	}
};

int main()
{
	arrStack<int> stack;
	cout << endl << "test push" << endl;
	for (int i = 0; i < 10; i++)
	{
		stack.Push(i);
	}
	cout << endl << "test get top" << endl;
	cout<<stack.GetTop();
	cout << endl << "test pop" << endl;
	stack.Pop();
	cout << stack.GetTop();



	return 0;
}
