/*指针。指向常量的指针和指针类型的常量。*/
#include<iostream>
using namespace std;

int main(){

	int i = 1;
	const int *ptr = &i; //指向常量的指针,不能改变所指对象的值,但可以更换所指对象

	//*ptr = 2;  //错误

	cout<<"*ptr="<<*ptr<<endl;

	int b = 2;

	ptr = &b;
	
	cout<<"*ptr="<<*ptr<<endl;


	int c = 3;

	int* const p2 = &c;  //指针类型的常量，不能改变所指对象的值,也不可以更换所指对象

	//int d = 4;

	//p2 = &d;  //错误

	cout<<"*p2="<<*p2<<endl;

	return 0;
}