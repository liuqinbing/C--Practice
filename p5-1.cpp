/*�����ռ�������*/
#include<iostream>
using namespace std;
int i;  //��ȫ�������ռ��е�ȫ�ֱ���
namespace Ns{
	int j;   //��Ns�����ռ��е�ȫ�ֱ���
}
int main(){

	i = 5;
	Ns::j=6;
	{
		using namespace Ns;  //ʹ��ǰ���п���ʹ��Ns�����ռ�ı�ʶ��
		int i;  //�ֲ�����
 		i = 7;
		cout<<"i="<<i<<endl;
		cout<<"j="<<j<<endl;
	}
	cout<<"i="<<i<<endl;
	3
	return 0;
}