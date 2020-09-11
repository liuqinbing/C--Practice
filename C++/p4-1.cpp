/*结构体*/
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

struct A{
	int no;
	//string name;   string型在某些编译器里不能直接用初值表赋初值,要不然会报错
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
