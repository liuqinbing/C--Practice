/* µÝ¹éº¯Êý*/
#include<iostream>
using namespace std;

int getPower(int x, int y)
{
	if(y == 1)
		return x;
	else
		return (x * getPower(x, y-1));
}

void main()
{
	int x;
	int y;

	cin >> x >> y;
	cout << getPower(x, y) << endl;
}