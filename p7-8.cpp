/*虚基类。在类的派生过程中使用virtual关键词*/
#include<iostream>
using namespace std;

class Base0 {
public:
	int var0;

	void fun0(){
		cout<<"Member of Base0"<<endl;
	}
};

class Base1 : virtual public Base0 {
public:
	int var1;
};

class Base2 : virtual public Base0 {
public:
	int var2;
};

class Own : public Base1, public Base2 {
public:
	int var3;

	void fun3(){
		cout<<"Member of Own"<<endl;
	}
};

int main(){

	Own p;

	//将共同基类设为虚基类，从不同路径继承的数据成员只有一个副本，函数成员只有一个映射

	p.var0 = 0; //可以直接访问虚基类的数据成员   没有了Base1::var0和Base2::var0  只有一个副本
	p.fun0();   //可以直接访问虚基类的函数成员   没有了Base1::fun0和Base2::fun0  只有一个映射

	return 0;
}