#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

template<class T>
class LinkedList {
public:
	LinkedList(void): front(NULL), rear(NULL), prevPtr(NULL), currPtr(NULL), size(0), position(0){}
	LinkedList(const LinkedList<T> &L) : front(NULL), rear(NULL), prevPtr(NULL), currPtr(NULL), size(0), position(0){copy(L);}// 复制构造函数
	~LinkedList(void){Clear();}   // 析构函数
	LinkedList<T>& operator =(const LinkedList<T> &L){ // 重载赋值运算符
		clear();
		copy(L);

		return *this;
	}

	int getSize(){return size;}                // 获取链表元素个数
	bool isEmpty(){return (size==0);}          // 判断链表是否为空

	void reset(int newPosition = 0);           // 初始化游标的位置
	void next();                               // 使游标移动到下一个节点
	bool endOfList(){return (currPtr==NULL);}  // 判断游标是否到了链尾
	int currentPosition(){return position;}    // 返回游标当前的位置

	void insertFront(const T &item);           // 在表头插入结点
	void insertRear(const T &item);            // 在表尾插入结点
	void insertBefore(const T &item);          // 在当前结点之前插入结点
	void insertAfter(const T &item);           // 在当前结点之后插入结点

	T deleteFront();                           // 删除头结点，return data
	T deleteCurrent();                         // 删除当前结点，return data

	T& data();                                 // 返回当前结点成员数据的引用

	void clear();                              // 清空链表：释放所有结点的内存空间

private:
	Node<T> *front, *rear;      // 表头和表尾指针
	int size;                   // 表中的元素个数

	// 游标参数
	int position;               // 当前元素在表中的位置序号。由函数 reset 使用
	Node<T> *prevPtr, *currPtr; // 记录当前遍历位置的指针和前一个指针，由插入和删除操作更新

	Node<T>* newNode(const T &data, Node<T> *ptrNext = NULL);// 生成新结点，数据域为data，指针域为ptrNext
	void freeNode(Node<T> *p);                               // 释放结点
	void copy(const LinkedList<T> &L);                       // 复制链表
}

// 生成新结点，数据域为 item，指针域为 ptrNext
Node<T>* LinkedList::newNode(const T &data, Node<T> *ptrNext = NULL){
	Node<T> *newNode;
	
	newNode = new Node<T>(data, ptrNext);
	
	if (newNode == NULL) {
		cout << "动态创建结点失败!" << endl;
		exit(1);
	}
	
	return newNode;
}

// 释放结点
void LinkedList::freeNode(Node<T> *p){
	delete p;
}

// 复制链表
void LinkedList::copy(const LinkedList<T> &L){
	if (L.size == 0)
		return;
	
	front = rear = newNode(L.front->data);
	
	//复制节点数据
	for (Node<T> *srcNode = L.front->nextNode(); srcNode != NULL; srcNode = srcNode->nextNode())
	{
		Node<T> *newNode = newNode(srcNode->data);
		rear->insertAfter(newNode);
		rear = newNode;
	}
	
	size = L.size;//复制大小
	reset(position = L.currentPosition());//复制当前位置
}

// 初始化游标的位置
void LinkedList::reset(int newPosition = 0){
	if (0 <= newPosition && newPosition <= size) {
		//初始化和游标有关的参数
		position = 0;
		prevPtr = NULL;
		currPtr = front;
		// 游标回到头结点，再逐步前移
		while (newPosition--)
			Next();
	}
	else {
		cout<<"超过链表范围!"<<endl;
		exit(1);
	}
}


// 使游标移动到下一个结点
void LinkedList::next(){
	position++;
	prevPtr = currPtr;
	
	if (currPtr != NULL)
		currPtr = currPtr->nextNode();
}

// 在表头插入结点
void LinkedList::insertFront(const T &data){
	front = newNode(data, front);//表头插入结点
	
	if (isEmpty())
		rear = front;
	
	size++;//表的大小加一
	reset(++position);//修改游标参数
}

// 在表尾插入结点
void LinkedList::insertRear(const T &data){
	Node<T> *newNode = newNode(data);
	
	if (isEmpty()) {
		front = rear = newNode;
	}
	else {
		rear->insertAfter(newNode);//表尾插入结点
		rear = newNode;//修改表尾指针
	}
	
	size++;//表的大小加一
	reset(position);//修改游标参数
}

// 在当前结点之前插入结点
void LinkedList::insertAfter(const T &data){
	if (currPtr != NULL) {
		Node<T> *newNode = newNode(data, currPtr->nextNode());//创建新结点
		currPtr->insertAfter(newNode);//当前节点后面，插入新结点
		
		//在尾结点位置的话，修改尾结点指针
		if (rear == currPtr)
			rear = newNode;
		
		size++;//表的大小加一
	}
	else{
		cout<<"当前位置不在链表的范围内!"<<endl;
		exit(1);
	}
}

// 在当前结点之前插入结点
void LinkedList::insertBefore(const T &data){  
	if (currPtr != NULL) {
		Node<T> *newNode = newNode(data, currPtr);
		
		if (prevPtr != NULL)
			prevPtr->InsertAfter(newNode);//当前结点的前结点后面，插入新结点
		else
			front = prevPtr = newNode;//当前位置为表头，将新结点设为表头
		
		size++;//表的大小加一
		reset(++position);//修改游标参数
	}
}

// 删除头结点
// return data
T LinkedList::deleteFront(){
	if (isEmpty()) {
		cout << "该链表为空链表，无法删除结点!" << endl;
		exit(1);
	}
	
	Node<T> *delNode = front;
	front = front->nextNode();//将表头的下一个结点作为表头
	
	//链表只有一个结点
	if (--size == 0)
		rear = NULL;
	
	reset(--position);//修改游标参数
	
	T data = delNode->data;
	freeNode(delNode);
	
	return data;
}

// 删除当前结点
T deleteCurrent(){
	if (currPtr != NULL) {
		//当前结点是表头
		if (front == currPtr)
			front = currPtr->nextNode();//修改表头指针为表头的下一个结点
		
		//当前结点是表尾
		if (rear == currPtr)
			rear = prevPtr;//修改表尾指针为表尾的前一个结点
		
		if (prevPtr != NULL)
			prevPtr->deleteAfter();//删除当前结点
		
		T data = currPtr->data;
		freeNode(currPtr);
		size--;
		reset(position);

		return data;
	}
	else{
		cout<<"当前位置不在链表的范围内!"<<endl;
		exit(1);
	}
}

// 返回对当前结点成员数据的引用
T& data(){
	if (currPtr == NULL) {
		cerr << "当前位置不在链表的范围内!" << endl;
		exit(1);
	}
	
	return currPtr->data;
}

// 清空链表：释放所有结点的内存空间。被析构函数和“operator =”调用
void clear(){
	while (!isEmpty())
		deleteFront();
}