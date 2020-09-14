#ifndef NODE_H
#define NODE_H

//模板类的定义
template<class T>
class Node {
public:
	Node(const T &data, Node<T> *next=0);

	void insertAfter(Node<T> *p);  //在当前节点后插入一个节点
	Node<T> *deleteAfter();        //删除当前节点后的节点
	Node<T> *nextNode();           //获取后继节点

	T data;          //数据域
private:
	Node<T> *next;   //后继节点的地址
};

template<class T>
Node<T>::Node(const T& data, Node<T> *next):data(data), next(next){}

template<class T>
Node<T>* Node<T>::nextNode(){
	return next;
}

//在当前节点后插入一个节点
template<class T>
void Node<T>::insertAfter(Node<T> *p){
	p->next = next;  //先将当前节点的后续节点 作为 p节点的后续节点
	next = p;        //将p节点 作为 当前节点的后续节点
}

//删除当前节点的后继节点
template<class T>
Node<T>* Node<T>::deleteAfter(){
	Node<T> *tempPtr = next;  //获取后继节点的地址

	if(next == 0){
		return 0;
	}

	next = tempPtr->next;    //将当前节点的后续节点的后续节点赋给当前节点的后续节点
	return tempPtr;  //返回删除节点的地址
}

#endif