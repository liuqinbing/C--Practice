/*指针。用指针处理数组*/
#include<iostream>
using namespace std;

void f(int a[])  //把数组当做形参，等价于把指向数组的指针当做形参
{
	for(int i=0; i<10; i++)
	{
		cout<<*(a+i)<<endl;  //数组名a是数组的首地址
	}
}

int main() {

	int a[10]={1,2,3,4,5,6,7,8,9,0};
	
	f(a);
	return 0;
}