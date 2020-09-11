/*友元类。B类为A类的友元类，那么B类的所有成员函数都是A类的友元函数，都可以访问A类的私有或保护成员*/
#include<iostream>
using namespace std;

class A {
public:
	A(int x):x(x){}
	void set(int i){
		x = i;
	}
	int get(){
		return x;
	}
	friend class B;  //B类为A类的友元类
private:
	int x;
};

class B {
public:
	B(A a):a(a){}
	void set(int i);
	int get();
private:
	A a;
};

void B::set(int i){
	a.x = i;
}

int B::get(){
	return a.x;
}

int main(){

	A a(1);
	B b(a);

	b.set(2);

	cout<<b.get()<<endl;
	cout<<a.get()<<endl;
	return 0;
}