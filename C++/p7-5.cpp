/*������Ĺ��캯������ִ��������Ĺ��캯��ʱ������ִ�л���Ĺ��캯��*/
#include<iostream>
using namespace std;

class Base1 {
public:
	Base1(){
		cout<<"Base1"<<endl;
	}

	Base1(int x){
		cout<<"Base1 "<<x<<endl;
	}
};

class Base2 {
public:
	Base2(){
		cout<<"Base2"<<endl;
	}

	Base2(int x){
		cout<<"Base2 "<<x<<endl;
	}
};

class Base3 : public Base1, public Base2 {
public:
	Base3(){
		cout<<"Base3"<<endl;
	}

	Base3(int x, int y):Base2(x),Base1(y){
		cout<<"Base3 "<<x<<endl;
	}

};

int main() {

	Base3 base;

	//���
	//Base1
	//Base2
	//Base3      �ɴ˿�֪������������Ĺ��캯��ʱ�����ȵ��û���Ĺ��캯��


	Base3 base3(7, 8);

	//���
	//Base1 8
	//Base2 7
	//Base3 7    �ɴ˿�֪�����û���Ĺ��캯��˳���ǰ��̳�ʱ������˳��

	return 0;
}