/*ָ�롣ָ������ָ���ָ�����͵ĳ�����*/
#include<iostream>
using namespace std;

int main(){

	int i = 1;
	const int *ptr = &i; //ָ������ָ��,���ܸı���ָ�����ֵ,�����Ը�����ָ����

	//*ptr = 2;  //����

	cout<<"*ptr="<<*ptr<<endl;

	int b = 2;

	ptr = &b;
	
	cout<<"*ptr="<<*ptr<<endl;


	int c = 3;

	int* const p2 = &c;  //ָ�����͵ĳ��������ܸı���ָ�����ֵ,Ҳ�����Ը�����ָ����

	//int d = 4;

	//p2 = &d;  //����

	cout<<"*p2="<<*p2<<endl;

	return 0;
}