#include <iostream>
#include <vector>
#define MAXSIZE 100
using namespace std;
template<class E>
class arrList {
public:
	//记录线性表的长度
	int length;
	//线性表存储的数组
	int* list;

	//1初始化：构造一个空的线性表
	arrList()
	{
		length = 0;
		list = new E[MAXSIZE];
	}

	//2取值,根据指定的序号i，获取线性表中第i个元素的值
	E GetElem(int i)
	{	
		if (i<0 || i>length)
			return 0;
		E e = list[i];
		return e;
	}

	//3查找，找到和e相等的元素,返回下标
	int  LocateElem(E e)
	{
		for (int i = 0; i < length; i++)
		{
			if (list[i] == e)
				return i;
		}
		return -1;
	}

	//4插入，在第i个位置插入元素e
	bool ListInsert(int index,E e)
	{
		//位置不合法，返回错误
		if (index<0 || index>length + 1)
			return false;
		//存储空间已满，返回错误
		if (length >= MAXSIZE)
			return false;
		for(int i = length-1; i >= index; i--)
		{
			list[i + 1] = list[i];
		}
		list[index] = e;
		length++;
		return true;
	}

	//5删除:删除第index个位置的元素
	bool ListDelete(int index)
	{
		if (index<0 || index>length - 1)
			return false;
		for (int i = index; i < length; i++)
		{
			list[i] = list[i + 1];
		}
		length--;
		return true;
	}

	//遍历：输出线性表中的每一个元素
	bool show()
	{
		if (length == 0)
			return false;
		for (int i = 0; i < length; i++)
		{
			cout << list[i] << " ";
		}
		return true;
	}

};
int main()
{
	arrList<int> list;
	cout << "测试插入" << endl;
	for(int i=0;i<10;i++)
		list.ListInsert(i,i);
	list.show();
	
	cout <<endl<< "测试删除" << endl;
	list.ListDelete(3);
	list.show();
	
	cout <<endl<< "测试查找" << endl;
	cout<<list.GetElem(2);

	cout << endl << "测试定位" << endl;
	cout << list.LocateElem(6);
	return 0;
}
