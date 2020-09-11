/*指针。指针型函数*/
#include<iostream>
using namespace std;

void printData(float data)
{
	cout<<data<<endl;
}

void printFloat(float data)
{
	cout<<data<<endl;
}

int main() {

	void (*functionPointer)(float);

	functionPointer = printData;
	functionPointer(13.1);

	functionPointer = printFloat;
	functionPointer(12.5);

	return 0;
}