/*��Ԫ��������Ԫ�����Ǹ���ĳ�Ա����������ͨ������������˽�кͱ�����Ա*/
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
	friend double dist(Point &a, Point &b){   //��Ԫ����
		double x = a.x - b.x;
		double y = a.y - b.y;
		return sqrt(x*x+y*y);
	}
	*/
	friend double dist(Point &a, Point &b);   //��Ԫ����

private:
	int x,y;
};

double dist(Point &a, Point &b){    //�����ⶨ�壬����Ҫ����
	double x = a.x - b.x;
	double y = a.y - b.y;
	return sqrt(x*x+y*y);
}

int main(){

	Point a(1, 1), b(4, 5);

	cout<<"����Ϊ��"<<dist(a, b)<<endl;

	return 0;
}