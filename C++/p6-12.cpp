/*vector,动态数组，一个类模板*/
#include<iostream>
#include<vector>
using namespace std;

void printV(vector<int> arr){ //vector对象名是数组对象，不是数组的首地址，所以函数要使用引用才能更改数组值vector<int> &arr

	arr[1] = 10;
	for(int i=0; i<arr.size(); i++) //size()是vector具有的成员变量，返回数组大小
	{
		cout<<arr[i]<<endl;
	}
}

int main(){

	int n;
	cin>>n;

	vector<int> arr(n);  //初值全设为0，如果是类类型，则调用默认构造函数

	for(int i=0; i<arr.size(); i++)
	{
		cin>>arr[i];
	}

	printV(arr);  

	return 0;
}