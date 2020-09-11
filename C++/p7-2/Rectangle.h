#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "Point.h"

/*私有继承
（1）基类的公有成员和保护成员，作为派生类的私有成员；
（2）基类的私有成员，派生类的成员函数和派生类对象都无法访问，只能通过基类的函数访问；
*/

class Rectangle : private Point {
public:
	void initRectangle(float x, float y, float w, float h) {
		initPoint(x, y);   //调用父类的公有成员函数
		this->w = w;
		this->h = h;
	}
	void move(float offX, float offY){   //隐藏。将父类的同名函数隐藏
	    Point::move(offX, offY);
	}
	float getX(){
		return Point::getX();
	}
	float getY(){
		return Point::getY();
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