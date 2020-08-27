/*指针与引用的区别*/
#include<iostream>
using namespace std;

int main() {

	int a = 10;
	int b = 20;

	int *p = &a;
	//int *p;
	//p = &a;  //不报错，1、指针声明后可以不初始化

	int &r = a;
	//int &r;  //引用声明后，2、必须立即初始化
	//r = a; 

	cout<<a<<endl;
	cout<<*p<<endl; //指针读取a值
	cout<<r<<endl;  //引用读取a值

	cout<<&a<<endl;
	cout<<p<<endl;  //指针读取a的地址
	cout<<&r<<endl; //引用读取a的地址

	p = &b;         //3、指针可以更改指向的对象
	cout<<*p<<endl; //值变了
	cout<<p<<endl;  //地址改变了，说明指向的对象改变了

	r = b;          //4、引用不可以更改指向的对象
	cout<<r<<endl;  //值变了
	cout<<&r<<endl; //地址没变，说明上面只是做了赋值操作，指向的对象并没有改变

	return 0;
}