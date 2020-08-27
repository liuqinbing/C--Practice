/*定义枚举类型weekday，包括Sunday到Saturday七个元素在程序中定义weekday类型的变量，对其赋值，定义整型变量，看看能否对其赋weekday类型的值。*/
#include<iostream>
using namespace std;

enum weekday
{
	Sunday,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
}; 
void main()
{
	int i;
	weekday d = Sunday;

	cout << "d = " << d << endl;
	i = d;
	cout << "i = " << i << endl;
	d = (weekday)6;
	cout << "d = " << d << endl;
	d = weekday(4);
	cout << "d = " << d << endl;
}