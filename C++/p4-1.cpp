/*�ṹ��*/
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

struct A{
	int no;
	//string name;   string����ĳЩ�������ﲻ��ֱ���ó�ֵ����ֵ,Ҫ��Ȼ�ᱨ��
	char sex;
	int age;
};

int main()
{
	//A a={2001,"liming",'F',18};
	A a={2001,'F',18};
	cout<<a.no<<endl;
	//cout<<a.name<<endl;
	cout<<a.sex<<endl;
	cout<<a.age<<endl;

	return 0;
}
