/*常数据成员、静态常数据成员*/
#include<iostream>
using namespace std;

class A {
public:
	A(int i): a(i) {}    //常数据成员只能通过初始化列表来获得初值
	void print();
private:
	const int a;         //常数据成员
	static const int b;  //静态常数据成员
	//static const int b = 10;
};	

const int A::b = 10;     //静态常数据成员都应在类外初始化，但是整数类型和枚举类型例外

void A::print()
{
	cout<<a<<"  "<<b<<endl;
}


int main(){

	A a1(10),a2(20);

	a1.print();
	a2.print();
	return 0;
}
