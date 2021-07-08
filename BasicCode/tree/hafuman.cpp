#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <list>
#include <queue>
#include <stack>
using namespace std;
typedef struct Node{
	//����Ȩֵ
	int weight;
	//����
	int leftChild;
	//�Һ���
	int rightChild;
	//˫�׽��
	int parent;
}Node;

//ͳ�ƴ�����ַ�����ÿ����ĸ�����˶��ٴ�
map<char,int> CountChar(string str)
{
	map<char, int> res;
	for (int i = 0; i < str.size(); i++)
	{
		if (res.count(str[i]) == 0)
		{
			res.insert(pair<char, int>(str[i], 1));
		}
		else {
			res[str[i]]++;
		}	
	}	
	return res;
}

//���ַ�ͳ�Ƶ�mapת��Ϊ����
vector<int> MapToVector(map<char, int> countMap)
{
	vector<int> res;
	map<char, int>::iterator iter;
	iter = countMap.begin();
	while (iter != countMap.end()) {
		res.push_back(iter->second);
		iter++;
	}
	return res;
}

void printTree(vector<Node*> tree)
{
	cout << endl;
	//����Ϊ�±�+1
	for (int i = 0; i < tree.size(); i++)
	{
		cout << i + 1 << " ";
		cout << tree[i]->weight<<" ";
		if (tree[i]->parent != -1)
			cout << tree[i]->parent + 1 << " ";
		else
			cout << 0 << " ";

		if (tree[i]->leftChild != -1|| tree[i]->rightChild != -1)
		{
			cout << tree[i]->leftChild + 1 << " ";
			cout << tree[i]->rightChild + 1 << " ";
		}			
		else
		{
			cout << 0 << " ";
			cout << 0 << " ";
		}
			
		cout << endl;
	}
}



//������������
vector<Node*> CreatTree(string str)
{
	map<char, int> count = CountChar(str);
	vector<int> arr = MapToVector(count);
	//�������鹲�� 2*n+1��λ�÷ֱ������Ľ��
	vector<Node*> tree(2 * arr.size() - 1);

	//��ʼ����������������Ȩֵ�Ĵ��ȥ��ûȨֵ�Ĵ�Ϊ0
	for (int i = 0; i < arr.size(); i++)
	{
		Node* temp = (Node*)malloc(sizeof(Node));
		temp->weight = arr[i];
		temp->leftChild = -1;
		temp->rightChild = -1;
		temp->parent = -1;
		tree[i]=temp;
	}
	for (int i = arr.size(); i < tree.size(); i++)
	{
		Node* temp = (Node*)malloc(sizeof(Node));
		temp->weight = -1;
		temp->leftChild = -1;
		temp->rightChild = -1;
		temp->parent = -1;
		tree[i] = temp;
	}
	/*printTree(tree);*/

	
	int n = arr.size();

	while (n < tree.size())
	{
		int min1 = INT_MAX;
		int min2 = INT_MAX;
		int s1 = 0, s2 = 0;
		//�ҵ�������С�Ľ��min1���±�s1
		for (int i = 0; i < n; i++)
		{
			//�����ǰ�����±����СֵС����˫�׽��Ϊ-1Ҳ����˵û�����������Ǿ�����Сֵ�����������Ȩֵ
			if (min1 > tree[i]->weight && tree[i]->parent == -1) {
				min1 = tree[i]->weight;
				s1 = i;
			}
		}
		//�ҵ����еڶ�С�Ľ��min2���±�s2
		for (int i = 0; i < n; i++)
		{
			//�����ǰ�����±����СֵС����˫�׽��Ϊ-1Ҳ����˵û�����������Ǿ�����Сֵ�����������Ȩֵ
			if (min2 > tree[i]->weight && tree[i]->parent == -1 && i != s1) {
				min2 = tree[i]->weight;
				s2 = i;
			}
		}
		//�ҵ���С���������֮�󣬺ϲ����
		//��n������ȨֵΪ������С���ĺ�,�������ֱ�Ϊ���Һ���
		tree[n]->weight = tree[s1]->weight + tree[s2]->weight;
		tree[n]->leftChild = s1;
		tree[n]->rightChild = s2;
		

		//������С����˫�׽��Ϊ��n�����
		tree[s1]->parent = n;
		tree[s2]->parent = n;

		//��һ���洢��������
		n++;
		/*printTree(tree);*/
	}
	
	return tree;
}


//��ӡ�ַ�����ÿ���ַ����м���
void printCountchar(string str)
{
	map<char, int> res = CountChar(str);
	map<char, int>::iterator itor;
	itor = res.begin();
	while (itor != res.end())
	{
		cout << itor->first << ":" << itor->second << " ";
		itor++;
	}
}

//�������������
void printCode(map<char, string> codeMap)
{
	map<char, string>::iterator itor;
	itor = codeMap.begin();
	while (itor != codeMap.end()) {
		cout << itor->first << ":" << itor->second << " ";
		itor++;
	}
	cout << endl;
}

//����������
//����һ�ù�������
//����ÿ���ַ����ֵĴ�����map
//���ع����������
map<char,string> HuffCoding(vector<Node*> tree, map<char, int> count)
{
	//���ڴ��ַ��Ͷ�Ӧ�ı���
	map<char, string> res;
	//���ڴ洢����
	vector<string> codeString;

	for (int i = 0; i < count.size(); i++)
	{
		//��ÿ��������ѹջ�ͳ�ջ����
		stack<char> temp;
		//������Ǹ��ڵ㣬���жϵ�ǰ��������ӻ����Һ���
		Node* cur = tree[i];
		int index = i;
		while(cur->parent != -1)
		{
			//��������Ӿ�ѹ��0
			if (tree[cur->parent]->leftChild == index)
			{
				temp.push('0');		
			}
			//������Һ��Ӿ�ѹ��1
			if (tree[cur->parent]->rightChild == index) {
				temp.push('1');
			}
			//�����򸸽ڵ�������ֱ���ѵ����ڵ�
			index = cur->parent;
			cur = tree[cur->parent];
			
		}
		//����Ǹ��ڵ�Ϳ���һ�����
		//�����ǰ��ջ
		/*cout << temp.size() << "  ";*/
		vector<char> code;
		int tempSize = temp.size();
		for (int j = 0; j < tempSize; j++)
		{
			//cout << temp.top();
			code.push_back(temp.top());
			temp.pop();
		}
		string codeStr;
		codeStr.assign(code.begin(), code.end());
		codeString.push_back(codeStr);	
	}
	
	map<char, int>::iterator itor=count.begin();
	int resIndex = 0;
	for ( count.begin(); resIndex < count.size(); resIndex++, itor++)
	{
		res.insert(pair<char, string>(itor->first, codeString[resIndex]));
	}
	//printCode(res);
	return res;
}

//���ַ������й���������
//����������ַ����������������
//return ����õ��ַ���
string StringToHuffBode(string str1,map<char,string> HuffCodeList)
{
	//�洢���صĹ���������
	string res;
	for (int i = 0; i < str1.size(); i++)
	{
		map<char, string>::iterator itor=HuffCodeList.begin();
		while (itor!=HuffCodeList.end())
		{
			if (itor->first == str1[i]) {
				res = res + itor->second;
				break;
			}
			itor++;
		}
	}
	return res;
}

//�������
//ͨ������ҵ��Ľ����±���ַ��������ҵ���Ӧ���ַ�
string transHuffCode(string code, vector<Node*> tree, map<char, int> count)
{
	int i = 0;
	vector<char> resVector;
	while (i < code.size())
	{
		char tempChar = code[i];
		
		//tree�������һ���϶��Ƿ��Ÿ��ڵ�
		int nodeIndex=tree.size()-1;
		Node* tempNode = tree[nodeIndex];
		//�������ҵ�Ҷ�ӽڵ�
		
		while (i < code.size()&&tempNode->leftChild != -1)
		{
			if (code[i] == '0')
			{
				nodeIndex = tempNode->leftChild;
				tempNode = tree[nodeIndex];
			}
			else {
				nodeIndex = tempNode->rightChild;
				tempNode = tree[nodeIndex];
			}
			i++;
		}

		//�ҵ�Ҷ�ӽ��֮�󣬰����ֵ��Ӧ���ַ����res�У����Ľ����±�ΪnodeIndex
		map<char, int>::iterator itor = count.begin();
		if (nodeIndex == 0)
		{
			resVector.push_back(itor->second);
			continue;
		}
		int flag = 0;
		while (flag < nodeIndex&&itor!=count.end())
		{
			itor++;
			flag++;
		}
		//itor--;
		//resVector.push_back(itor->second);
		i++;
	}

	string res;
	res.assign(resVector.begin(), resVector.end());
	//cout << res;
	return code;

}


//int main()
//{
//	string str1;
//	cin >> str1;
//	while (str1 != "0")
//	{
//		printCountchar(str1);
//		vector<Node*> tree = CreatTree(str1);
//		printTree(tree);
//
//		map<char, int> count = CountChar(str1);
//		map<char, string> code = HuffCoding(tree, count);
//		printCode(code);
//
//		string strToCode = StringToHuffBode(str1, code);
//		cout << strToCode << endl;
//		cout << transHuffCode(str1, tree, count)<<endl;
//		cin >> str1;
//	}
//}
