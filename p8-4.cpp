/*参数多态。模板的应用:函数模板、类模板*/
#include<iostream>
using namespace std;

//函数模板
//template<typename T1, typename T2>  作用完全同下
template<class T1, class T2>
T1 func(T1 a, T2 b) {
	T1 c = (T1)(a + b);
	return c;
}

int main() {

	int a = 10;
	float b = 10.1;

	cout<<func(a, b)<<endl;
	cout<<func(b, a)<<endl;

	return 0;
}