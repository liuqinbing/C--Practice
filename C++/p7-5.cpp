/*派生类的构造函数。在执行派生类的构造函数时，会先执行基类的构造函数*/
#include<iostream>
using namespace std;

class Base1 {
public:
	Base1(){
		cout<<"Base1"<<endl;
	}

	Base1(int x){
		cout<<"Base1 "<<x<<endl;
	}
};

class Base2 {
public:
	Base2(){
		cout<<"Base2"<<endl;
	}

	Base2(int x){
		cout<<"Base2 "<<x<<endl;
	}
};

class Base3 : public Base1, public Base2 {
public:
	Base3(){
		cout<<"Base3"<<endl;
	}

	Base3(int x, int y):Base2(x),Base1(y){
		cout<<"Base3 "<<x<<endl;
	}

};

int main() {

	Base3 base;

	//输出
	//Base1
	//Base2
	//Base3      由此可知，调用派生类的构造函数时，会先调用基类的构造函数


	Base3 base3(7, 8);

	//输出
	//Base1 8
	//Base2 7
	//Base3 7    由此可知，调用基类的构造函数顺序，是按继承时的声明顺序

	return 0;
}