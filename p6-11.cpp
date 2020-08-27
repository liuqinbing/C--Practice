/*动态内存分配。类对象和数组*/
#include<iostream>
using namespace std;

class Point {
public:
	Point():x(0),y(0){
		cout<<"Defaule called"<<endl;
	}
	Point(int x, int y):x(x),y(y){
		cout<<"Constructor called"<<endl;
	}
private:
	int x,y;
};

int main(){

	Point *a = new Point; //无参，调用默认构造函数
	delete a;

	Point *b = new Point(1,2);  //有参，调用有形参的构造函数
	delete b;

	Point *c = new Point[2];
	delete[] c;  //动态分配的数组的释放需要在delete后加[]

	return 0;
}