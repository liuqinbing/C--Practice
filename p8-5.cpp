/*�����ࡣ���д��麯�������ǳ����ࡣһ������������Ĺ�ͬ�ӿڡ�
�޷�������������ֻ�ܶ���ǳ���������Ķ���
�����ܶ�������ָ������ã�Ȼ��ָ��������Ķ���ʵ�ֶ�̬*/
#include<iostream>
using namespace std;

class Base1 {
public:
	virtual void display()=0; //���麯����������ʽ����ӡ�=0��������û�ж���ʵ�ֲ��֣������������
	virtual void func()=0;
};

class Base2 : public Base1 {   //ֻʵ����һ�����麯�������Ը��໹�ǳ�����
public:
	void display() {
		cout<<"Base2::display()"<<endl;
	}
};

class Base3 : public Base2 {
public:
	void display() {
		cout<<"Base3::display()"<<endl;
	}
	void func() {
		cout<<"Base3::func()"<<endl;
	}
};

class Base4 : public Base2 {
public:
	void func() {
		cout<<"Base4::func()"<<endl;
	}
};

int main() {

	//Base1 base1;
	//Base2 base2;  ���������಻�ܶ������

	Base3 base3;

	Base1 &base1 = base3;
	base1.display();
	base1.func();

	Base4 base4;

	Base1 *base = &base4;
	base->display();
	base->func();

	return 0;
}