/*命名空间作用域*/
#include<iostream>
using namespace std;
int i;  //在全局命名空间中的全局变量
namespace Ns{
	int j;   //在Ns命名空间中的全局变量
}
int main(){

	i = 5;
	Ns::j=6;
	{
		using namespace Ns;  //使当前块中可以使用Ns命名空间的标识符
		int i;  //局部变量
 		i = 7;
		cout<<"i="<<i<<endl;
		cout<<"j="<<j<<endl;
	}
	cout<<"i="<<i<<endl;
	3
	return 0;
}