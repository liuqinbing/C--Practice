/*C++ʹ���ַ������������ַ���������������string���������ַ���*/
#include<iostream>
#include<string>
using namespace std;

int main() {

	char str[4] = {'a','b','c','\0'};  //�ַ���ĩβΪ\0
	//char str[4] = "abc";   //�ȼ�
	//char str[] = "abc";   //�ȼ�

	string s = str;
	//string s(str);
	//string s = "abc";

	cout<<s<<endl;

	return 0;
}