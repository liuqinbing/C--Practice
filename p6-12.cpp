/*vector,��̬���飬һ����ģ��*/
#include<iostream>
#include<vector>
using namespace std;

void printV(vector<int> arr){ //vector��������������󣬲���������׵�ַ�����Ժ���Ҫʹ�����ò��ܸ�������ֵvector<int> &arr

	arr[1] = 10;
	for(int i=0; i<arr.size(); i++) //size()��vector���еĳ�Ա���������������С
	{
		cout<<arr[i]<<endl;
	}
}

int main(){

	int n;
	cin>>n;

	vector<int> arr(n);  //��ֵȫ��Ϊ0������������ͣ������Ĭ�Ϲ��캯��

	for(int i=0; i<arr.size(); i++)
	{
		cin>>arr[i];
	}

	printV(arr);  

	return 0;
}