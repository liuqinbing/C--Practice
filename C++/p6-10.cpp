/*动态内存分配（动态创建堆对象）*/
#include<iostream>
using namespace std;

int main(){

	int *a = new int(2); //动态内存申请成功，返回指向新分配内存首地址的类型的指针

	int *b = new int;  //可以不设初值
	*b = 3;

	cout<<*a<<endl;
	cout<<*b<<endl;

	delete a;  //记得将内存释放，防止内存泄露
	delete b;

	return 0;
}