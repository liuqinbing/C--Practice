/*ָ�롣void���͵�ָ��*/
#include<iostream>
using namespace std;

int main(){

	void* pv; //void���͵�ָ�룬���Դ洢�κ����͵Ķ����ַ
	int i = 5;

	pv = &i;   //void���͵�ָ��ָ�����ͱ���

	int* pint = static_cast<int*>(pv);   //void���͵�ָ�븳ֵ��int����ָ��

	cout<<"*pint="<<*pint<<endl;

	return 0;
}