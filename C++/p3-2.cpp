/*ʹ��ģ�庯��ʵ��Swap( x�� y )����������Ϊ����x��y��ֵ��*/
#include<iostream>
using namespace std;

template<class T>
void swapxy(T &x, T &y)
{
	T z;
	z = x;
	x = y;
	y = z;
}

void main()
{
	int j = 1, k = 2;
	double v = 3.0, w = 4.0;
	cout << "j = " <<j << " k = " << k << endl;
	cout << "v = " <<v << " w = " << w << endl;
	swapxy(j, k); //int
	swapxy(v, w); //double
	cout << "After swap:" << endl;
	cout << "j = " <<j << " k = " << k << endl;
	cout << "v = " <<v << " w = " << w << endl;
}