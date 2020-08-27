/*�������������������������ִ�е�˳���빹�캯��ִ�е�˳���෴*/
#include<iostream>
using namespace std;

class Base1 {
public:
	Base1(){
		cout<<"Constructing Base1"<<endl;
	}

	~Base1(){
		cout<<"Destructing Base1"<<endl;
	}
};

class Base2 {
public:
	Base2(){
		cout<<"Constructing Base2"<<endl;
	}

	~Base2(){
		cout<<"Destructing Base2"<<endl;
	}
};

class Base3 : public Base2, public Base1 {
public:
	Base3(){
		cout<<"Constructing Base3"<<endl;
	}

	~Base3(){
		cout<<"Destructing Base3"<<endl;
	}
};

int main() {

	Base3 base;

	//���
	//Constructing Base1
	//Constructing Base2
	//Constructing Base3
	//Destructing Base3
	//Destructing Base2
	//Destructing Base1       �ɴ˿�֪����������ִ�е�˳���빹�캯��ִ�е�˳���෴

	return 0;
}