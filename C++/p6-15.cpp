/*ʲôʱ����ָ�룬��������*/
#include<iostream>
using namespace std;

int max(int a, int b)
{
	if(a >= b)
		return a;
	else
		return b;
}


int main() {

	//1����������Ҫ������ʼ����ֵ,������;��Ҫ�޸���ָ����

    //2����ֵ��ֵ��null��

	//3������ָ��
	int(*p)(int, int);
	p = max;
	int c = (*p)(10,20);
	cout<<c<<endl;

	//4��new��̬�������������
	int *p2 = new int(2);
	int &r1 = *(new int(2)); //��ȻҲ�������ã�����̫������
	cout<<r1<<endl;
	delete &r1;

	//5����������ʽ���ݴ���������ʱ��ָ�����
	int s[5] = {1,3,5,7,9};
	int *p1 = s;
	int &r = *s; //��ȻҲ�������ã�����̫������
	cout<<*(&r+2)<<endl;

	return 0;
}