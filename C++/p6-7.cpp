/* 指针。作为函数参数*/
#include<iostream>
#include<cmath>
using namespace std;

int getPower(int *a, int m)
{
	*a = pow(*a,m);
	return *a;
}


void main()
{
	int a;
	int m;

	cin >> a >> m;
	getPower(&a,m);
	cout << a << endl;
}