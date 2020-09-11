/*类的静态函数成员*/
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

	static void showCount(){  //静态函数，访问静态成员
		cout<<"count="<<count<<endl;
	}

    static void showX(Point a){      //静态函数，访问非静态成员
		cout<<"x="<<a.x<<endl;
	}

private:
	int x,y;
	static int count;   //静态成员

};

int Point::count = 0; //定义静态成员

int main(){

	Point a(4, 5);

	a.showCount();   

	Point::showX(a);

	Point b(a);

	Point::showCount();

	return 0;
}