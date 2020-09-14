#ifndef NODE_H
#define NODE_H

//ģ����Ķ���
template<class T>
class Node {
public:
	Node(const T &data, Node<T> *next=0);

	void insertAfter(Node<T> *p);  //�ڵ�ǰ�ڵ�����һ���ڵ�
	Node<T> *deleteAfter();        //ɾ����ǰ�ڵ��Ľڵ�
	Node<T> *nextNode();           //��ȡ��̽ڵ�

	T data;          //������
private:
	Node<T> *next;   //��̽ڵ�ĵ�ַ
};

template<class T>
Node<T>::Node(const T& data, Node<T> *next):data(data), next(next){}

template<class T>
Node<T>* Node<T>::nextNode(){
	return next;
}

//�ڵ�ǰ�ڵ�����һ���ڵ�
template<class T>
void Node<T>::insertAfter(Node<T> *p){
	p->next = next;  //�Ƚ���ǰ�ڵ�ĺ����ڵ� ��Ϊ p�ڵ�ĺ����ڵ�
	next = p;        //��p�ڵ� ��Ϊ ��ǰ�ڵ�ĺ����ڵ�
}

//ɾ����ǰ�ڵ�ĺ�̽ڵ�
template<class T>
Node<T>* Node<T>::deleteAfter(){
	Node<T> *tempPtr = next;  //��ȡ��̽ڵ�ĵ�ַ

	if(next == 0){
		return 0;
	}

	next = tempPtr->next;    //����ǰ�ڵ�ĺ����ڵ�ĺ����ڵ㸳����ǰ�ڵ�ĺ����ڵ�
	return tempPtr;  //����ɾ���ڵ�ĵ�ַ
}

#endif