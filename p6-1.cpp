/*����*/
#include<iostream>
using namespace std;

void rowSum(int a[][2], int nRow) {  //��ά�������ָ������λ����   ������Ϊ�������������ݵ��ǵ�ַ��
	for(int i=0; i<nRow; i++)
	{
		for(int j=1; j<2; j++)
		{
			a[i][0] += a[i][j];
		}
	}
}

int main() {

	int table[2][2] = {{1,1},{2,2}};

	for(int i=0; i<2; i++)
	{
		for(int j=0; j<2; j++)
		{
			cout<<table[i][j]<<"  ";
		}
		cout<<endl;
	}

	cout<<endl;

	rowSum(table, 2);
	for(i=0; i<2; i++)
	{
		for(int j=0; j<2; j++)
		{
			cout<<table[i][j]<<"  ";
		}
		cout<<endl;
	}
	return 0;
}