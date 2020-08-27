#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "Point.h"

/*�����̳�
��1������Ĺ��г�Ա�ͱ�����Ա����Ϊ������ı�����Ա��
��2�������˽�г�Ա��������ĳ�Ա����������������޷����ʣ�ֻ��ͨ������ĺ������ʣ�
*/

class Rectangle : protected Point {
public:
	void initRectangle(float x, float y, float w, float h) {
		initPoint(x, y);   //���ø���Ĺ��г�Ա����
		this->w = w;
		this->h = h;
	}
	void move(float offX, float offY){
		Point::move(offX, offY);
	}
	float getX() const{ 
		return Point::getX();
	}
	float getY() const{ 
		return Point::getY();
	}
	float getH() const{ //����Ա����
		return h;
	}
	float getW() const{
		return w;
	}

private:
	float h,w;
};
#endif