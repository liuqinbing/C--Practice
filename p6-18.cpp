/*static_cast��reinterpret_cast��const_cast*/
#include<iostream>
using namespace std;

int main() {

	//static_cast�ǻ������ݵ���������ת��
	int i = 2;
	float x = static_cast<float>(i);
	cout<<x<<endl;

	//reinterpret_cast�ǻ���ָ������ת��������Σ���ԺͲ�ȷ���ԣ���ò�Ҫʹ��
	int j = 2;
	float *p = reinterpret_cast<float *>(j);
	//cout<<*p<<endl;

	//const_cast�ǿ��Խ�const����ȥ�����������ñ����ͨ���ã�����ָ������ָͨ�룬�Ӷ����޸�ֵ�����ƻ������ݵı���
	const int k = 2;
	//int &r = k;   //����const int���޷�ת��int
	int &r = const_cast<int &>(k);
	r++;
	cout<<r<<endl;

	return 0;
}