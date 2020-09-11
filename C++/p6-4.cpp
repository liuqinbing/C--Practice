/*指针。void类型的指针*/
#include<iostream>
using namespace std;

int main(){

	void* pv; //void类型的指针，可以存储任何类型的对象地址
	int i = 5;

	pv = &i;   //void类型的指针指向整型变量

	int* pint = static_cast<int*>(pv);   //void类型的指针赋值给int类型指针

	cout<<"*pint="<<*pint<<endl;

	return 0;
}