/*������̬��ģ���Ӧ��:����ģ�塢��ģ��*/
#include<iostream>
using namespace std;

//����ģ��
//template<typename T1, typename T2>  ������ȫͬ��
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