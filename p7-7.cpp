/*���ع���Ҫ���ʱ����صĳ�Ա��ʹ��������ֱ����::���ͻ����������޶���*/
#include<iostream>
using namespace std;

class Base1 {
public:
	int var;

	void fun(){
		cout<<"Member of Base1"<<endl;
	}

	void fun(int x){
		cout<<"Member of Base1 + x"<<endl;
	}
};

class Base2 {
public:
	int var;

	void fun(){
		cout<<"Member of Base2"<<endl;
	}
};

class Base3 : public Base2, public Base1 {
public:
	
	int var;   //�����ͬ�����ݳ�Ա������

	//������ĺ�������������ͬ���Ļ��ຯ����ע��ֻҪͬ���������һ���û��virtual���Σ����ܲ����б��Ƿ���ͬ�����ຯ�����ᱻ���ء�
	void fun(){
		cout<<"Member of Base3"<<endl;
	}
};

int main() {

	Base3 p;

	p.var = 3;
	p.Base1::var = 1;
	p.Base2::var = 2;

	cout<<p.var<<endl;  //�����ͬ�����ݳ�Ա������


	//p.fun(10);  �����޷����ʻ���Base1�����غ���,����������
	p.fun();
	p.Base1::fun();
	p.Base2::fun();

	return 0;
}