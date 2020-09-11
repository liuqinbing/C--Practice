/*������̬���麯��ʵ�֡���д������p7-4���ͼ��ݹ���ĸĽ����û��������Է���������ĺ���*/
#include<iostream>
using namespace std;

class Base1 {
public:
	void fun() {
		display();
	}
	virtual void display() {
		cout<<"Base1::display()"<<endl;
	}
};

class Base2 : public Base1 {
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
};

void fun1(Base1 *ptr){  //�������ָ���������ת��Ϊ�����ָ��
	ptr->display();
}

void fun2(Base1 base){  //������Ķ����������ת��Ϊ����Ķ���
	base.display();
}

void fun3(Base1 &base){ //������Ķ�����Գ�ʼ�����������
	base.display();
}

int main() {

	Base1 base1;
	Base2 base2;
	Base3 base3;

	//�麯��ֻ��ͨ����Ա������ָ������������ʣ����ܷ��������������
	cout<<"ָ�룺"<<endl;
	fun1(&base1);
	fun1(&base2); //�������ָ���������ת��Ϊ�����ָ��
	fun1(&base3);

	cout<<"���ã�"<<endl;
	fun3(base2); //������Ķ�����Գ�ʼ�����������
	fun3(base3);

	cout<<"��Ա������"<<endl;
	base2.fun();
	base3.fun();


	//�麯��ͨ��������ʣ�ֻ�ܷ��ӻ��������
	cout<<"����"<<endl;
	fun2(base2); //������Ķ���ת��Ϊ����Ķ��󣬵���ת����ֻ�ܷ��ӻ��������
	fun2(base3);

	return 0;

}