/*友元函数。友元函数非该类的成员函数，可以通过对象名访问私有和保护成员*/
#include<iostream>
#include<cmath>
using namespace std;

class Point {
public:
	Point(int x=0, int y=0):x(x),y(y){
	}
	~Point(){
	}
	int getX(){
		return x;
	}
	int getY(){
		return y;
	}

	/*
	friend double dist(Point &a, Point &b){   //友元函数
		double x = a.x - b.x;
		double y = a.y - b.y;
		return sqrt(x*x+y*y);
	}
	*/
	friend double dist(Point &a, Point &b);   //友元函数

private:
	int x,y;
};

double dist(Point &a, Point &b){    //在类外定义，不需要类名
	double x = a.x - b.x;
	double y = a.y - b.y;
	return sqrt(x*x+y*y);
}

int main(){

	Point a(1, 1), b(4, 5);

	cout<<"距离为："<<dist(a, b)<<endl;

	return 0;
}