/*对象的生存期：静态生存期、动态生存期*/
#include<iostream>
using namespace std;
int i = 1;   //全局变量，静态生存期

void other(){

	//局部变量，静态生存期
	static int a = 2;
	static int b;

	//局部变量，动态生存期
	int c = 10;

	a += 2;
	i += 32;
	c += 5;

	cout<<"other"<<endl;
	cout<<"i="<<i<<" a="<<a<<" b="<<b<<" c="<<c<<endl;

	b = a;
}

int main() {

	//局部变量，静态生存期
	static int a;

	//局部变量，动态生存期
	int b = -10;
	int c = 0;

	cout<<"main"<<endl;
	cout<<"i="<<i<<" a="<<a<<" b="<<b<<" c="<<c<<endl;

	c += 8;

	other();

	cout<<"main"<<endl;
	cout<<"i="<<i<<" a="<<a<<" b="<<b<<" c="<<c<<endl;

	i += 10;
	other();

	return 0;
}