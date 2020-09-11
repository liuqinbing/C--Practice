#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "Point.h"

/*共有继承
（1）基类的公有成员和保护成员，作为派生类的公有成员和保护成员；
（2）基类的私有成员，派生类的成员函数和派生类对象都无法访问，只能通过基类的函数访问；
*/

class Rectangle : public Point {
public:
	void initRectangle(float x, float y, float w, float h) {
		initPoint(x, y);   //调用父类的公有成员函数
		this->w = w;
		this->h = h;
	}
	float getH() const{ //常成员函数
		return h;
	}
	float getW() const{
		return w;
	}

private:
	float h,w;
};
#endif