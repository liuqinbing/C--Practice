/*��̬�ڴ���䡣����������*/
#include<iostream>
using namespace std;

class Point {
public:
	Point():x(0),y(0){
		cout<<"Defaule called"<<endl;
	}
	Point(int x, int y):x(x),y(y){
		cout<<"Constructor called"<<endl;
	}
private:
	int x,y;
};

int main(){

	Point *a = new Point; //�޲Σ�����Ĭ�Ϲ��캯��
	delete a;

	Point *b = new Point(1,2);  //�вΣ��������βεĹ��캯��
	delete b;

	Point *c = new Point[2];
	delete[] c;  //��̬�����������ͷ���Ҫ��delete���[]

	return 0;
}