/*����ö������weekday������Sunday��Saturday�߸�Ԫ���ڳ����ж���weekday���͵ı��������丳ֵ���������ͱ����������ܷ���丳weekday���͵�ֵ��*/
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