/*抽象类。带有纯虚函数的类是抽象类。一个类族派生类的共同接口。
无法定义抽象类对象，只能定义非抽象派生类的对象。
但是能定义抽象的指针和引用，然后指向派生类的对象，实现多态*/
#include<iostream>
using namespace std;

class Base1 {
public:
	virtual void display()=0; //纯虚函数，声明格式后面加“=0”，基类没有定义实现部分，由派生类给出
	virtual void func()=0;
};

class Base2 : public Base1 {   //只实现了一个纯虚函数，所以该类还是抽象类
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
	void func() {
		cout<<"Base3::func()"<<endl;
	}
};

class Base4 : public Base2 {
public:
	void func() {
		cout<<"Base4::func()"<<endl;
	}
};

int main() {

	//Base1 base1;
	//Base2 base2;  报错，抽象类不能定义对象

	Base3 base3;

	Base1 &base1 = base3;
	base1.display();
	base1.func();

	Base4 base4;

	Base1 *base = &base4;
	base->display();
	base->func();

	return 0;
}