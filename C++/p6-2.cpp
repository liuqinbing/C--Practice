/*指针。“*”指针运算符，“&”取地址运算符。*/
#include<iostream>
using namespace std;

int main(){

	int i;
	int *ptr = &i;

	i = 10;

	cout<<"i="<<i<<endl;
	cout<<"*ptr="<<*ptr<<endl;

	return 0;
}