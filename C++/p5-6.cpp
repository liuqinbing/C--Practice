/*��Ԫ�ࡣB��ΪA�����Ԫ�࣬��ôB������г�Ա��������A�����Ԫ�����������Է���A���˽�л򱣻���Ա*/
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
	friend class B;  //B��ΪA�����Ԫ��
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