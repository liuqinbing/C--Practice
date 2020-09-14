#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

template<class T>
class LinkedList {
public:
	LinkedList(void): front(NULL), rear(NULL), prevPtr(NULL), currPtr(NULL), size(0), position(0){}
	LinkedList(const LinkedList<T> &L) : front(NULL), rear(NULL), prevPtr(NULL), currPtr(NULL), size(0), position(0){copy(L);}// ���ƹ��캯��
	~LinkedList(void){Clear();}   // ��������
	LinkedList<T>& operator =(const LinkedList<T> &L){ // ���ظ�ֵ�����
		clear();
		copy(L);

		return *this;
	}

	int getSize(){return size;}                // ��ȡ����Ԫ�ظ���
	bool isEmpty(){return (size==0);}          // �ж������Ƿ�Ϊ��

	void reset(int newPosition = 0);           // ��ʼ���α��λ��
	void next();                               // ʹ�α��ƶ�����һ���ڵ�
	bool endOfList(){return (currPtr==NULL);}  // �ж��α��Ƿ�����β
	int currentPosition(){return position;}    // �����α굱ǰ��λ��

	void insertFront(const T &item);           // �ڱ�ͷ������
	void insertRear(const T &item);            // �ڱ�β������
	void insertBefore(const T &item);          // �ڵ�ǰ���֮ǰ������
	void insertAfter(const T &item);           // �ڵ�ǰ���֮�������

	T deleteFront();                           // ɾ��ͷ��㣬return data
	T deleteCurrent();                         // ɾ����ǰ��㣬return data

	T& data();                                 // ���ص�ǰ����Ա���ݵ�����

	void clear();                              // ��������ͷ����н����ڴ�ռ�

private:
	Node<T> *front, *rear;      // ��ͷ�ͱ�βָ��
	int size;                   // ���е�Ԫ�ظ���

	// �α����
	int position;               // ��ǰԪ���ڱ��е�λ����š��ɺ��� reset ʹ��
	Node<T> *prevPtr, *currPtr; // ��¼��ǰ����λ�õ�ָ���ǰһ��ָ�룬�ɲ����ɾ����������

	Node<T>* newNode(const T &data, Node<T> *ptrNext = NULL);// �����½�㣬������Ϊdata��ָ����ΪptrNext
	void freeNode(Node<T> *p);                               // �ͷŽ��
	void copy(const LinkedList<T> &L);                       // ��������
}

// �����½�㣬������Ϊ item��ָ����Ϊ ptrNext
Node<T>* LinkedList::newNode(const T &data, Node<T> *ptrNext = NULL){
	Node<T> *newNode;
	
	newNode = new Node<T>(data, ptrNext);
	
	if (newNode == NULL) {
		cout << "��̬�������ʧ��!" << endl;
		exit(1);
	}
	
	return newNode;
}

// �ͷŽ��
void LinkedList::freeNode(Node<T> *p){
	delete p;
}

// ��������
void LinkedList::copy(const LinkedList<T> &L){
	if (L.size == 0)
		return;
	
	front = rear = newNode(L.front->data);
	
	//���ƽڵ�����
	for (Node<T> *srcNode = L.front->nextNode(); srcNode != NULL; srcNode = srcNode->nextNode())
	{
		Node<T> *newNode = newNode(srcNode->data);
		rear->insertAfter(newNode);
		rear = newNode;
	}
	
	size = L.size;//���ƴ�С
	reset(position = L.currentPosition());//���Ƶ�ǰλ��
}

// ��ʼ���α��λ��
void LinkedList::reset(int newPosition = 0){
	if (0 <= newPosition && newPosition <= size) {
		//��ʼ�����α��йصĲ���
		position = 0;
		prevPtr = NULL;
		currPtr = front;
		// �α�ص�ͷ��㣬����ǰ��
		while (newPosition--)
			Next();
	}
	else {
		cout<<"��������Χ!"<<endl;
		exit(1);
	}
}


// ʹ�α��ƶ�����һ�����
void LinkedList::next(){
	position++;
	prevPtr = currPtr;
	
	if (currPtr != NULL)
		currPtr = currPtr->nextNode();
}

// �ڱ�ͷ������
void LinkedList::insertFront(const T &data){
	front = newNode(data, front);//��ͷ������
	
	if (isEmpty())
		rear = front;
	
	size++;//��Ĵ�С��һ
	reset(++position);//�޸��α����
}

// �ڱ�β������
void LinkedList::insertRear(const T &data){
	Node<T> *newNode = newNode(data);
	
	if (isEmpty()) {
		front = rear = newNode;
	}
	else {
		rear->insertAfter(newNode);//��β������
		rear = newNode;//�޸ı�βָ��
	}
	
	size++;//��Ĵ�С��һ
	reset(position);//�޸��α����
}

// �ڵ�ǰ���֮ǰ������
void LinkedList::insertAfter(const T &data){
	if (currPtr != NULL) {
		Node<T> *newNode = newNode(data, currPtr->nextNode());//�����½��
		currPtr->insertAfter(newNode);//��ǰ�ڵ���棬�����½��
		
		//��β���λ�õĻ����޸�β���ָ��
		if (rear == currPtr)
			rear = newNode;
		
		size++;//��Ĵ�С��һ
	}
	else{
		cout<<"��ǰλ�ò�������ķ�Χ��!"<<endl;
		exit(1);
	}
}

// �ڵ�ǰ���֮ǰ������
void LinkedList::insertBefore(const T &data){  
	if (currPtr != NULL) {
		Node<T> *newNode = newNode(data, currPtr);
		
		if (prevPtr != NULL)
			prevPtr->InsertAfter(newNode);//��ǰ����ǰ�����棬�����½��
		else
			front = prevPtr = newNode;//��ǰλ��Ϊ��ͷ�����½����Ϊ��ͷ
		
		size++;//��Ĵ�С��һ
		reset(++position);//�޸��α����
	}
}

// ɾ��ͷ���
// return data
T LinkedList::deleteFront(){
	if (isEmpty()) {
		cout << "������Ϊ�������޷�ɾ�����!" << endl;
		exit(1);
	}
	
	Node<T> *delNode = front;
	front = front->nextNode();//����ͷ����һ�������Ϊ��ͷ
	
	//����ֻ��һ�����
	if (--size == 0)
		rear = NULL;
	
	reset(--position);//�޸��α����
	
	T data = delNode->data;
	freeNode(delNode);
	
	return data;
}

// ɾ����ǰ���
T deleteCurrent(){
	if (currPtr != NULL) {
		//��ǰ����Ǳ�ͷ
		if (front == currPtr)
			front = currPtr->nextNode();//�޸ı�ͷָ��Ϊ��ͷ����һ�����
		
		//��ǰ����Ǳ�β
		if (rear == currPtr)
			rear = prevPtr;//�޸ı�βָ��Ϊ��β��ǰһ�����
		
		if (prevPtr != NULL)
			prevPtr->deleteAfter();//ɾ����ǰ���
		
		T data = currPtr->data;
		freeNode(currPtr);
		size--;
		reset(position);

		return data;
	}
	else{
		cout<<"��ǰλ�ò�������ķ�Χ��!"<<endl;
		exit(1);
	}
}

// ���ضԵ�ǰ����Ա���ݵ�����
T& data(){
	if (currPtr == NULL) {
		cerr << "��ǰλ�ò�������ķ�Χ��!" << endl;
		exit(1);
	}
	
	return currPtr->data;
}

// ��������ͷ����н����ڴ�ռ䡣�����������͡�operator =������
void clear(){
	while (!isEmpty())
		deleteFront();
}