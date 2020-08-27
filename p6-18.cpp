/*static_cast、reinterpret_cast、const_cast*/
#include<iostream>
using namespace std;

int main() {

	//static_cast是基于内容的数据类型转换
	int i = 2;
	float x = static_cast<float>(i);
	cout<<x<<endl;

	//reinterpret_cast是基于指针类型转换，具有危险性和不确定性，最好不要使用
	int j = 2;
	float *p = reinterpret_cast<float *>(j);
	//cout<<*p<<endl;

	//const_cast是可以将const属性去除，将常引用变成普通引用，将常指针变成普通指针，从而能修改值，但破坏了数据的保护
	const int k = 2;
	//int &r = k;   //报错，const int是无法转成int
	int &r = const_cast<int &>(k);
	r++;
	cout<<r<<endl;

	return 0;
}