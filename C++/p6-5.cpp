/*ָ�롣��ָ�봦������*/
#include<iostream>
using namespace std;

void f(int a[])  //�����鵱���βΣ��ȼ��ڰ�ָ�������ָ�뵱���β�
{
	for(int i=0; i<10; i++)
	{
		cout<<*(a+i)<<endl;  //������a��������׵�ַ
	}
}

int main() {

	int a[10]={1,2,3,4,5,6,7,8,9,0};
	
	f(a);
	return 0;
}