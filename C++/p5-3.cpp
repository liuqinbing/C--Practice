/*类的静态数据成员*/
#include<iostream>
using namespace std;

class Point {
public:
	Point(int x=0, int y=0):x(x),y(y){
		count++;
	}
	Point(Point &p){
		x = p.x;
		y = p.y;
		count++;
	}
	~Point(){
		count--;
	}
	int getX(){
		return x;
	}
	int getY(){
		return y;
	}

	void showCount(){
		cout<<"count="<<count<<endl;
	}

private:
	int x,y;
	static int count;   //静态成员

};

int Point::count = 0; //定义静态成员

int main(){

	Point a(4, 5);

	a.showCount();

	Point b(a);

	b.showCount();

	return 0;
}