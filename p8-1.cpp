/*���ض�̬����ͨ��������ĳ�Ա���������ء��������������*/
#include<iostream>
using namespace std;

class Complex {
public:
	Complex(double r=0, double i=0):r(r),i(i){}//���=0���൱�ڶ���һ��Ĭ�Ϲ��캯��

	Complex operator+ (const Complex &c) const {//���ء�+�������
		return Complex(r+c.r, i+c.i);
	}

	Complex operator- (const Complex &c) const {//���ء�-�������
		return Complex(r-c.r, i-c.i);
	}

	void display() {
		cout<<r<<","<<i<<endl;
	}
private:
	double r, i;
};

int main() {

	Complex a(5, 6), c(2, 3), b;

	b = a + c;
	b.display();

	b = a - c;
	b.display();

	cout<<2+3<<endl;//�����������ԭ�ȵĹ���

	return 0;
}