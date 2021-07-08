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
	//结点的权值
	int weight;
	//左孩子
	int leftChild;
	//右孩子
	int rightChild;
	//双亲结点
	int parent;
}Node;

//统计传入的字符串中每个字母出现了多少次
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

//把字符统计的map转化为数组
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
	//坐标为下标+1
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



//构建哈夫曼树
vector<Node*> CreatTree(string str)
{
	map<char, int> count = CountChar(str);
	vector<int> arr = MapToVector(count);
	//整个数组共有 2*n+1个位置分别存放树的结点
	vector<Node*> tree(2 * arr.size() - 1);

	//初始化哈夫曼树，把有权值的存进去，没权值的存为0
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
		//找到树中最小的结点min1的下标s1
		for (int i = 0; i < n; i++)
		{
			//如果当前树的下标比最小值小而且双亲结点为-1也就是说没被遍历过，那就让最小值等于这个结点的权值
			if (min1 > tree[i]->weight && tree[i]->parent == -1) {
				min1 = tree[i]->weight;
				s1 = i;
			}
		}
		//找到树中第二小的结点min2的下标s2
		for (int i = 0; i < n; i++)
		{
			//如果当前树的下标比最小值小而且双亲结点为-1也就是说没被遍历过，那就让最小值等于这个结点的权值
			if (min2 > tree[i]->weight && tree[i]->parent == -1 && i != s1) {
				min2 = tree[i]->weight;
				s2 = i;
			}
		}
		//找到最小的两个结点之后，合并结点
		//第n个结点的权值为两个最小结点的和,两个结点分别为左右孩子
		tree[n]->weight = tree[s1]->weight + tree[s2]->weight;
		tree[n]->leftChild = s1;
		tree[n]->rightChild = s2;
		

		//两个最小结点的双亲结点为第n个结点
		tree[s1]->parent = n;
		tree[s2]->parent = n;

		//下一个存储坐标自增
		n++;
		/*printTree(tree);*/
	}
	
	return tree;
}


//打印字符串中每个字符各有几个
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

//输出哈夫曼编码
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

//哈夫曼编码
//传入一棵哈夫曼树
//传入每个字符出现的次数的map
//返回哈夫曼编码表
map<char,string> HuffCoding(vector<Node*> tree, map<char, int> count)
{
	//用于存字符和对应的编码
	map<char, string> res;
	//用于存储编码
	vector<string> codeString;

	for (int i = 0; i < count.size(); i++)
	{
		//对每个结点进行压栈和出栈处理
		stack<char> temp;
		//如果不是根节点，就判断当前结点是左孩子还是右孩子
		Node* cur = tree[i];
		int index = i;
		while(cur->parent != -1)
		{
			//如果是左孩子就压入0
			if (tree[cur->parent]->leftChild == index)
			{
				temp.push('0');		
			}
			//如果是右孩子就压入1
			if (tree[cur->parent]->rightChild == index) {
				temp.push('1');
			}
			//继续向父节点搜索，直到搜到根节点
			index = cur->parent;
			cur = tree[cur->parent];
			
		}
		//如果是根节点就看下一个结点
		//输出当前的栈
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

//将字符串进行哈夫曼编码
//传入参数：字符串，哈夫曼编码表
//return 编码好的字符串
string StringToHuffBode(string str1,map<char,string> HuffCodeList)
{
	//存储返回的哈夫曼编码
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

//逆向解码
//通过最后找到的结点的下标查字符次数表，找到对应的字符
string transHuffCode(string code, vector<Node*> tree, map<char, int> count)
{
	int i = 0;
	vector<char> resVector;
	while (i < code.size())
	{
		char tempChar = code[i];
		
		//tree里面最后一个肯定是放着根节点
		int nodeIndex=tree.size()-1;
		Node* tempNode = tree[nodeIndex];
		//遍历，找到叶子节点
		
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

		//找到叶子结点之后，把这个值对应的字符存进res中，最后的结点的下标为nodeIndex
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
