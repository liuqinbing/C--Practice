/*ָ��İ�ȫ�����������Ͱ�ȫ��*/
#include<iostream>
using namespace std;

int main() {

	int a = 2;

	//ָ������ת���ǽ���ֱַ�Ӵ��ݣ�����ַ�е����ݽ���Ϊ��ͬ���ͣ���ͷ����˴���
	float *p = reinterpret_cast<float *>(&a);

	cout<<*p<<endl;

	return 0;
}