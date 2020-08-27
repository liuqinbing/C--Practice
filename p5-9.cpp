/*常引用*/
#include<iostream>
#include<cmath>
using namespace std;

class Point {
public:
	Point(int x=0, int y=0):x(x),y(y){}
	int getX(){
		return x;
	}
	int getY(){
		return y;
	}

	friend float dist(const Point &p1, const Point &p2){   //常引用被引用的对象不能被更新
		float x = p1.x - p2.x;
		float y = p1.y - p2.y;
		return sqrt(x*x+y*y);
	}

private:
	int x,y;
};

int main(){

	Point a(4, 5),b(1, 1);

	cout<<dist(a, b)<<endl;
	return 0;
}