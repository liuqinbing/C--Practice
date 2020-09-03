/*强制多态。先变换类型，再进行操作*/
#include<iostream>
using namespace std;

int main() {

	int a = 1;
	float b = 2.1;

	float c = a + b;//先将a类型强制转化为float，再进行加法运算

	cout<<c<<endl;

	return 0;
}