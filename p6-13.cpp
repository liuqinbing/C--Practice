/*C++使用字符数组来处理字符串，但还定义了string类来处理字符串*/
#include<iostream>
#include<string>
using namespace std;

int main() {

	char str[4] = {'a','b','c','\0'};  //字符串末尾为\0
	//char str[4] = "abc";   //等价
	//char str[] = "abc";   //等价

	string s = str;
	//string s(str);
	//string s = "abc";

	cout<<s<<endl;

	return 0;
}