/*��̬�ڴ���䣨��̬�����Ѷ���*/
#include<iostream>
using namespace std;

int main(){

	int *a = new int(2); //��̬�ڴ�����ɹ�������ָ���·����ڴ��׵�ַ�����͵�ָ��

	int *b = new int;  //���Բ����ֵ
	*b = 3;

	cout<<*a<<endl;
	cout<<*b<<endl;

	delete a;  //�ǵý��ڴ��ͷţ���ֹ�ڴ�й¶
	delete b;

	return 0;
}