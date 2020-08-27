#include<iostream>
#include<cmath>
#include "Rectangle.h"
using namespace std;

int main(){

	Rectangle rect;
	rect.initRectangle(2,3,20,10);
	rect.move(3,2);

	cout<<rect.getX()<<" "
		<<rect.getY()<<" "
		<<rect.getW()<<" "
		<<rect.getH()<<endl;

	return 0;
}