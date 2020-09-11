/*隐藏规则。要访问被隐藏的成员，使用作用域分辨符“::”和基类类名类限定。*/
#include<iostream>
using namespace std;

class Base1 {
public:
	int var;

	void fun(){
		cout<<"Member of Base1"<<endl;
	}

	void fun(int x){
		cout<<"Member of Base1 + x"<<endl;
	}
};

class Base2 {
public:
	int var;

	void fun(){
		cout<<"Member of Base2"<<endl;
	}
};

class Base3 : public Base2, public Base1 {
public:
	
	int var;   //基类的同名数据成员被隐藏

	//派生类的函数屏蔽了与其同名的基类函数，注意只要同名函数并且基类没有virtual修饰，不管参数列表是否相同，基类函数都会被隐藏。
	void fun(){
		cout<<"Member of Base3"<<endl;
	}
};

int main() {

	Base3 p;

	p.var = 3;
	p.Base1::var = 1;
	p.Base2::var = 2;

	cout<<p.var<<endl;  //基类的同名数据成员被隐藏


	//p.fun(10);  报错，无法访问基类Base1的重载函数,它被隐藏了
	p.fun();
	p.Base1::fun();
	p.Base2::fun();

	return 0;
}