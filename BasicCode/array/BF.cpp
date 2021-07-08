#include <iostream>
#include <vector>
#include <string>
#define MAXSIZE 100
using namespace std;
bool kmp(string str1, string str2)
{
	int i = 0, j = 0;
	int flag = 0;
	while (i < str1.size() && j < str2.size())
	{
		
		if (str1[i] == str2[j])
		{
			i++;
			j++;
		}
		else {
			flag++;
			i = flag;
			j = 0;
		}
	}
	if (j >= str2.size())
	{
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	string str1 = "ababcabcacbab";
	string str2 = "abcac";
	cout<<kmp(str1, str2);
}
