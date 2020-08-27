/*指针的安全性隐患：类型安全性*/
#include<iostream>
using namespace std;

int main() {

	int a = 2;

	//指针类型转换是将地址直接传递，将地址中的数据解释为不同类型，这就发生了错误
	float *p = reinterpret_cast<float *>(&a);

	cout<<*p<<endl;

	return 0;
}