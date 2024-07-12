template <class T> class LinkedQueue;

template <class T>
class Nodel {
	friend LinkedQueue<T>;
private:
	T data;
	Nodel<T> *link;
};