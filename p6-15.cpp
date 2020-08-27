/*什么时候用指针，不用引用*/
#include<iostream>
using namespace std;

int max(int a, int b)
{
	if(a >= b)
		return a;
	else
		return b;
}


int main() {

	//1、声明后不需要立即初始化赋值,或者中途需要修改所指对象

    //2、赋值空值（null）

	//3、函数指针
	int(*p)(int, int);
	p = max;
	int c = (*p)(10,20);
	cout<<c<<endl;

	//4、new动态创建对象或数组
	int *p2 = new int(2);
	int &r1 = *(new int(2)); //虽然也能用引用，但是太繁琐了
	cout<<r1<<endl;
	delete &r1;

	//5、以数组形式传递大批量数据时用指针接收
	int s[5] = {1,3,5,7,9};
	int *p1 = s;
	int &r = *s; //虽然也能用引用，但是太繁琐了
	cout<<*(&r+2)<<endl;

	return 0;
}