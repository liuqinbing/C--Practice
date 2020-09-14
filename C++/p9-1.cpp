/*模板类*/
/*好处：使一个数据结构或算法只需要写一次就能够适用于各种具体的数据类型*/
#include<iostream>
using namespace std;

struct Student {
	int id;
	float qpa; 
};

template<class T>
class Store {
public:
	Store(){}

	T getElem();
	void putElem(T x);
private:
	T elem;
};

template<class T>
T Store<T>::getElem() {
	return elem;
}

template<class T>
void Store<T>::putElem(T x) {
	elem = x;
}

int main() {

	Store<int> s1;
	s1.putElem(10);
	cout<<s1.getElem()<<endl;

	Store<double> s2;
	s2.putElem(10.23);
	cout<<s2.getElem()<<endl;

	Store<Student> s3;
	Student g = {1001,80.5};
	s3.putElem(g);
	cout<<s3.getElem().id<<endl;
	cout<<s3.getElem().qpa<<endl;

	return 0;
}