#include <iostream>
using namespace std;

class complex{
	public:
		float Realpart;	//实数部分
		float Imagepart; //虚数部分 

	void creat(float x,float y)
	{
		this->Realpart=x;
		this->Imagepart=y;
	}
	
	float GetReal()
	{
		return this->Realpart;
	}
	
	float GetImag()
	{
		return this->Imagepart;
	}
	
	complex Add(complex C2)
	{
		complex sum;
		sum.Realpart=this->Realpart+C2.Realpart;
		sum.Imagepart=this->Imagepart+C2.Imagepart;
	return sum;
	}	
};


int main()
{
	complex c1,c2;
	c1.creat(1.3,1.5);
	c2.creat(2.5,6.7);
	cout<<c1.GetReal()<<endl;
	cout<<c2.GetReal()<<endl;
	complex c3=c1.Add(c2);
	cout<<c3.GetReal();
	return 0;
}

