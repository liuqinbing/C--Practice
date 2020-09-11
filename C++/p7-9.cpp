/*基类和派生类的转换：显示（强制）转换和隐式转换*/
#include<iostream>
using namespace std;

class Base1 {
public:
	void display() {
		cout<<"Base1::display()"<<endl;
	}
};

class Base2 : public Base1 {
public:
	void display() {
		cout<<"Base2::display()"<<endl;
	}
};

class Base3 : public Base2 {
public:
	void display() {
		cout<<"Base3::display()"<<endl;
	}
};

int main() {

	Base3 base3;
	base3.display();
	
	Base1 base1 = base3;  //从特殊转一般，可以使用隐式转换
	base1.display();      //转换后只能发挥基类的作用

	//Base1 base;
	//Base2 base2 = static_cast<Base2>(base);//报错，无法从基类对象显示转换为派生类对象

	//可以从基类指针或引用转换为派生类的指针或引用
	//转换后发挥的是派生类的作用
	//但这样转换可能有安全问题
	Base1 *p1 = new Base1();
	Base2 *p2 = static_cast<Base2 *>(p1); 
	p2->display();

	Base1 &r1 = base1;
	Base2 &r2 = static_cast<Base2 &>(r1); 
	r2.display();

	return 0;

}
