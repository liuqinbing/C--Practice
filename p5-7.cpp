/*常对象和常成员函数*/
#include<iostream>
using namespace std;

class R {
public:
	R(int x, int y): x(x),y(y){}
	
	void print();
	void print() const;  //常成员函数，可以利用常函数来实现重载
private:
	int x, y;
};

void R::print() {
	cout<<x<<":"<<y<<endl;
}

void R::print() const {
	cout<<x<<":"<<y<<endl;
}

int main() {
	R a(1,2);
	const R b(10,20);    //常对象，常对象的数据成员不能改变

	a.print();

	b.print();   //调用常函数的对象不管是不是常对象，都被视为常对象，不能改变数据成员

	return 0;
}
