/*�����ݳ�Ա����̬�����ݳ�Ա*/
#include<iostream>
using namespace std;

class A {
public:
	A(int i): a(i) {}    //�����ݳ�Աֻ��ͨ����ʼ���б�����ó�ֵ
	void print();
private:
	const int a;         //�����ݳ�Ա
	static const int b;  //��̬�����ݳ�Ա
	//static const int b = 10;
};	

const int A::b = 10;     //��̬�����ݳ�Ա��Ӧ�������ʼ���������������ͺ�ö����������

void A::print()
{
	cout<<a<<"  "<<b<<endl;
}


int main(){

	A a1(10),a2(20);

	a1.print();
	a2.print();
	return 0;
}
