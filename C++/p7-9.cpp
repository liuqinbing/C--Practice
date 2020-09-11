/*������������ת������ʾ��ǿ�ƣ�ת������ʽת��*/
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

int main() {

	Base3 base3;
	base3.display();
	
	Base1 base1 = base3;  //������תһ�㣬����ʹ����ʽת��
	base1.display();      //ת����ֻ�ܷ��ӻ��������

	//Base1 base;
	//Base2 base2 = static_cast<Base2>(base);//�����޷��ӻ��������ʾת��Ϊ���������

	//���Դӻ���ָ�������ת��Ϊ�������ָ�������
	//ת���󷢻ӵ��������������
	//������ת�������а�ȫ����
	Base1 *p1 = new Base1();
	Base2 *p2 = static_cast<Base2 *>(p1); 
	p2->display();

	Base1 &r1 = base1;
	Base2 &r2 = static_cast<Base2 &>(r1); 
	r2.display();

	return 0;

}
