/*������ͳ���Ա����*/
#include<iostream>
using namespace std;

class R {
public:
	R(int x, int y): x(x),y(y){}
	
	void print();
	void print() const;  //����Ա�������������ó�������ʵ������
private:
	int x, y;
};

void R::print() {
	cout<<x<<":"<<y<<endl;
}

void R::print() const {
	cout<<x<<":"<<y<<endl;
}

int main() {
	R a(1,2);
	const R b(10,20);    //�����󣬳���������ݳ�Ա���ܸı�

	a.print();

	b.print();   //���ó������Ķ��󲻹��ǲ��ǳ����󣬶�����Ϊ�����󣬲��ܸı����ݳ�Ա

	return 0;
}
