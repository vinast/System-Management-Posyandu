#include "Node.h"
#include "xcept.h"
template<class T>
class LinkedQueue{
public:
	LinkedQueue(){
		front = rear = 0;
	}
	~LinkedQueue();
	int IsEmpty() const{
		return ((front) ? 0 : 1);
	}
	int IsFull() const;
	T First() const;
	T Last() const;
	LinkedQueue<T>& Add(const T& x);
	LinkedQueue<T>& Delete(T& x);
private:
	Nodel<T> *front;
	Nodel<T> *rear;
};

template<class T>
LinkedQueue<T>::~LinkedQueue(){
	Nodel<T> *next;
	while (front){
		next = front->link;
		delete front;
		front = next;
	}
}

template<class T>
int LinkedQueue<T>::IsFull() const{
	Nodel<T> *p;
	try{
		p = new Nodel<T>;
		delete p;
		return 0;
	}
	catch (NoMem){
		return 1;
	}
}

template<class T>
T LinkedQueue<T>::First() const{
	if (IsEmpty()) throw OutOfBounds();
	return front->data;
}

template<class T>
T LinkedQueue<T>::Last() const{
	if (IsEmpty()) throw OutOfBounds();
	return rear->data;
}

template<class T>
LinkedQueue<T>& LinkedQueue<T>::Add(const T& x){
	Nodel<T> *p = new Nodel<T>;
	p->data = x;
	p->link = 0;
	if (front) rear->link = p;
	else front = p;
	rear = p;
	return *this;
}

template<class T>
LinkedQueue<T>& LinkedQueue<T>::Delete(T& x){
	if (IsEmpty()) throw OutOfBounds();
	x = front->data;
	Nodel<T> *p = front;
	front = front->link;
	delete p;
	return *this;
}