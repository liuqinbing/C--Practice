/*指针的安全性隐患：地址安全性*/
#include<iostream>
using namespace std;

void fun1()
{
	//1、指针未被赋值就被使用
	int *p;
	int a = 1;
	cout<<a+(*p)<<endl;
}

void fun2()
{
    //2、数组下标越界
	int s[5] = {1,2,3,4,5};
	int *p = s;
	cout<<*(p+5)<<endl;
}


int main() {

	//fun1();

	fun2();

	return 0;
}