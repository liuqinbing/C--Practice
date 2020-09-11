/*重载多态。普通函数和类的成员函数的重载。例：运算符重载*/
#include<iostream>
using namespace std;

class Complex {
public:
	Complex(double r=0, double i=0):r(r),i(i){}//添加=0后，相当于多了一个默认构造函数

	Complex operator+ (const Complex &c) const {//重载“+”运算符
		return Complex(r+c.r, i+c.i);
	}

	Complex operator- (const Complex &c) const {//重载“-”运算符
		return Complex(r-c.r, i-c.i);
	}

	void display() {
		cout<<r<<","<<i<<endl;
	}
private:
	double r, i;
};

int main() {

	Complex a(5, 6), c(2, 3), b;

	b = a + c;
	b.display();

	b = a - c;
	b.display();

	cout<<2+3<<endl;//运算符还能有原先的功能

	return 0;
}