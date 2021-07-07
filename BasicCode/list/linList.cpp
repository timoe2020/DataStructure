#define nullptr NULL
#include <iostream>
#include <vector>
#define MAXSIZE 100
using namespace std;

template<class T>
class  Node {
public:
	T data;
	Node* next;
	Node(){}
	Node(T data)
	{
		this->data = data;
		this->next = nullptr;
	}
};

template<class T>
class  LinList{
public:
	//ͷ�ڵ�
	Node<T> *head;

	//1.��ʼ��
	LinList()
	{
		head = new Node<T>;
		head->next = nullptr;
	}

	//2.ȡֵ
	T GetElem(int index)
	{
		Node<int>* p =head;
		int flag = 0;
		while (p != nullptr && flag < index)
		{
			p = p->next;
			flag++;
		}
		if (p == nullptr || flag > index)
		{
			return false;
		}
		return p->next->data;
	}

	//3.����
	bool LocateElen(T element)
	{
		Node<int>* p = head;
		while (p != nullptr && p->data != element)
		{
			p = p->next;
		}
		if (p == nullptr)
			return false;
		return true;
		
	}

	//4.����
	bool ListInsert(int index, T element)
	{
		Node<T>* p=head;
		int i = 0;
		while (p!=nullptr && i < index )
		{
			p = p->next;
			i++;
		}
		if (p == nullptr || i > index )
			return false;
		Node<T>* newNode = new Node<int>(element);
		newNode->next = p->next;
		p->next = newNode;
		return true;
		
	}
	//5.ɾ��
	bool ListDelete(int i)
	{
		if (i < 0)
			return false;
		
		int flag = 0;
		Node<T>* p = head;
		Node<T>* q = p;
		if (p == nullptr)
			return false;
		while (p->next != nullptr&&flag<i-1)
		{
			p = p->next;
			flag++;
		}
		if (p->next == nullptr || flag > i)
			return false;
		q = p->next;
		p->next = p->next->next;
		delete(q);
		return true;
		
	}

	//6.����
	void show()
	{
		Node<T>* p = head;
		while (p->next != nullptr)
		{
			p = p->next;
			cout << p->data;
			
		}
	}

};

int main()
{
	LinList<int> list;

	cout << "���Բ���" << endl;
	for (int i = 0; i < 10; i++)
	{
		list.ListInsert(i, i);
	}
	list.show();

	cout << endl << "����ɾ��" << endl;
	list.ListDelete(0);
	list.show();

	cout <<endl<< "����ȡֵ" << endl;
	cout << list.GetElem(0);

	cout << endl << "���Բ���" << endl;
	cout << list.LocateElen(33);

	return 0;
}
