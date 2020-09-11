/*指针。this指针*/
#include<iostream>
using namespace std;

class A{
public:
	A(int x):x(x){}
	int getX()
	{
		//return this->x;   
		return (*this).x;   //记得加括号
	}

	bool comp(A b)
	{
		return this->x < b.x; //this指向调用该函数的目的对象
	}

private:
	int x;
};

int main() {

	A a(10);
	A b(9);
	
	cout<<a.getX()<<endl;

	cout<<a.comp(b)<<endl;

	return 0;
}
