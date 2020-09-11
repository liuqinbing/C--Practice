/* 引用传递、函数重载*/
#include<iostream>
#include<cmath>
using namespace std;

int getPower(int &a, int m)  //引用传递，传递值不能为空，指针传递可以为空
{
	a = pow(a,m);
	return a;
}

double getPower(double &b, int m)  //函数重载
{
	b = pow(b,m);
	return b;
}


void main()
{
	int a;
	double b;
	int m;

	cin >> a >> m;
	getPower(a,m);
	cout << a << endl;

	cin >> b >> m;
	getPower(b,m);
	cout << b << endl;
}