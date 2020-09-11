/*类型兼容规则*/
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

void fun1(Base1 *ptr){  //派生类的指针可以隐含转换为基类的指针
	ptr->display();
}

void fun2(Base1 base){  //派生类的对象可以隐含转换为基类的对象
	base.display();
}

void fun3(Base1 &base){ //派生类的对象可以初始化基类的引用
	base.display();
}

int main() {

	Base1 base1;
	Base2 base2;
	Base3 base3;

	fun1(&base1);
	fun1(&base2); //派生类的指针可以隐含转换为基类的指针，但是转化后只能发挥基类的作用
	fun1(&base3);

	fun2(base2); //派生类的对象转化为基类的对象，但是转化后只能发挥基类的作用
	fun2(base3);

	fun3(base2); //派生类的对象可以初始化基类的引用，但是只能发挥基类的作用
	fun3(base3);

	return 0;

}
