/*ָ��İ�ȫ����������ַ��ȫ��*/
#include<iostream>
using namespace std;

void fun1()
{
	//1��ָ��δ����ֵ�ͱ�ʹ��
	int *p;
	int a = 1;
	cout<<a+(*p)<<endl;
}

void fun2()
{
    //2�������±�Խ��
	int s[5] = {1,2,3,4,5};
	int *p = s;
	cout<<*(p+5)<<endl;
}


int main() {

	//fun1();

	fun2();

	return 0;
}