/*����ࡣ���������������ʹ��virtual�ؼ���*/
#include<iostream>
using namespace std;

class Base0 {
public:
	int var0;

	void fun0(){
		cout<<"Member of Base0"<<endl;
	}
};

class Base1 : virtual public Base0 {
public:
	int var1;
};

class Base2 : virtual public Base0 {
public:
	int var2;
};

class Own : public Base1, public Base2 {
public:
	int var3;

	void fun3(){
		cout<<"Member of Own"<<endl;
	}
};

int main(){

	Own p;

	//����ͬ������Ϊ����࣬�Ӳ�ͬ·���̳е����ݳ�Աֻ��һ��������������Աֻ��һ��ӳ��

	p.var0 = 0; //����ֱ�ӷ������������ݳ�Ա   û����Base1::var0��Base2::var0  ֻ��һ������
	p.fun0();   //����ֱ�ӷ��������ĺ�����Ա   û����Base1::fun0��Base2::fun0  ֻ��һ��ӳ��

	return 0;
}