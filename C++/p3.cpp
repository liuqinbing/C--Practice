/* ���ô��ݡ���������*/
#include<iostream>
#include<cmath>
using namespace std;

int getPower(int &a, int m)  //���ô��ݣ�����ֵ����Ϊ�գ�ָ�봫�ݿ���Ϊ��
{
	a = pow(a,m);
	return a;
}

double getPower(double &b, int m)  //��������
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