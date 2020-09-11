/*���ͼ��ݹ���*/
#include<iostream>
using namespace std;

class Base1 {
public:
	void display() {
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

	fun1(&base1);
	fun1(&base2); //�������ָ���������ת��Ϊ�����ָ�룬����ת����ֻ�ܷ��ӻ��������
	fun1(&base3);

	fun2(base2); //������Ķ���ת��Ϊ����Ķ��󣬵���ת����ֻ�ܷ��ӻ��������
	fun2(base3);

	fun3(base2); //������Ķ�����Գ�ʼ����������ã�����ֻ�ܷ��ӻ��������
	fun3(base3);

	return 0;

}
