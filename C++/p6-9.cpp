/*ָ�롣thisָ��*/
#include<iostream>
using namespace std;

class A{
public:
	A(int x):x(x){}
	int getX()
	{
		//return this->x;   
		return (*this).x;   //�ǵü�����
	}

	bool comp(A b)
	{
		return this->x < b.x; //thisָ����øú�����Ŀ�Ķ���
	}

private:
	int x;
};

int main() {

	A a(10);
	A b(9);
	
	cout<<a.getX()<<endl;

	cout<<a.comp(b)<<endl;

	return 0;
}
