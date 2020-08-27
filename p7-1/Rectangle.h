#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "Point.h"

/*���м̳�
��1������Ĺ��г�Ա�ͱ�����Ա����Ϊ������Ĺ��г�Ա�ͱ�����Ա��
��2�������˽�г�Ա��������ĳ�Ա����������������޷����ʣ�ֻ��ͨ������ĺ������ʣ�
*/

class Rectangle : public Point {
public:
	void initRectangle(float x, float y, float w, float h) {
		initPoint(x, y);   //���ø���Ĺ��г�Ա����
		this->w = w;
		this->h = h;
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