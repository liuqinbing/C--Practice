/*��ľ�̬���ݳ�Ա*/
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
	static int count;   //��̬��Ա

};

int Point::count = 0; //���徲̬��Ա

int main(){

	Point a(4, 5);

	a.showCount();

	Point b(a);

	b.showCount();

	return 0;
}