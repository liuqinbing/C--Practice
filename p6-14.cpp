/*ָ�������õ�����*/
#include<iostream>
using namespace std;

int main() {

	int a = 10;
	int b = 20;

	int *p = &a;
	//int *p;
	//p = &a;  //������1��ָ����������Բ���ʼ��

	int &r = a;
	//int &r;  //����������2������������ʼ��
	//r = a; 

	cout<<a<<endl;
	cout<<*p<<endl; //ָ���ȡaֵ
	cout<<r<<endl;  //���ö�ȡaֵ

	cout<<&a<<endl;
	cout<<p<<endl;  //ָ���ȡa�ĵ�ַ
	cout<<&r<<endl; //���ö�ȡa�ĵ�ַ

	p = &b;         //3��ָ����Ը���ָ��Ķ���
	cout<<*p<<endl; //ֵ����
	cout<<p<<endl;  //��ַ�ı��ˣ�˵��ָ��Ķ���ı���

	r = b;          //4�����ò����Ը���ָ��Ķ���
	cout<<r<<endl;  //ֵ����
	cout<<&r<<endl; //��ַû�䣬˵������ֻ�����˸�ֵ������ָ��Ķ���û�иı�

	return 0;
}