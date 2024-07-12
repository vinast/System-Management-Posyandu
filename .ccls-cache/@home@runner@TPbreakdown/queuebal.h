#include "xcept.h"
#include <iostream>
using namespace std;

template <class T> 
class Queuebal {

  // template <class U> friend ostream &operator<<(ostream &, const Queuebal<U> &);

public:
  Queuebal(int size = 0);
  Queuebal(const Queuebal<T> &v);
  ~Queuebal() { delete[] element; }
  T &operator[](int i) const;
  int Size() { return size; }
  Queuebal<T> &operator=(const Queuebal<T> &v);
  Queuebal<T> operator+() const;
  Queuebal<T> operator+(const Queuebal<T> &v) const;
  Queuebal<T> operator-() const;
  Queuebal<T> operator-(const Queuebal<T> &v) const;
  Queuebal<T> operator*(const Queuebal<T> &v) const;
  Queuebal<T> &operator+=(const T &x);
  void tampil();
  T First() const;
  int FirstNorekam();
  string FirstNama();
  string FirstIbu();
  double FirstTinggi();
  double FirstBerat();
  int FirstUmur(); 
  T Last() const;
  T firsindex() { return front; }
  T lastindex() { return rear; }
  Queuebal<T> &ReSize(int sz);
  Queuebal<T> &Enqueue(int Norekam,string namaBal, string ibBal,double tingBal, double bertBal, int umrBal);


  Queuebal<T> &Dequeue();
  // Queuebal<T> &index();
  // bool IsFull() const {return top == MaxTop;}
  int IsFull() const { return (((rear + 1) % size == front) ? 1 : 0); }
  // bool IsEmpty() const {return  == -1;}
  int IsEmpty() const { return front == rear; }
  T Top() const;

private:
  int size;
  int rear; // current top of stack
  int front;
  int MaxTop; // max value for top
  T *temp;
  T *element;
};

template <class T> Queuebal<T> &Queuebal<T>::ReSize(int sz) {
  int temps = size;
  temp = new T[size];
  for (int i = 1; i < size; i++) {
    temp[i].Norekam = element[i].Norekam;
    temp[i].namaBal = element[i].namaBal;
    temp[i].ibBal = element[i].ibBal;
    temp[i].tingBal = element[i].tingBal;
    temp[i].bertBal = element[i].bertBal;
    temp[i].umrBal = element[i].umrBal;
  }

  delete[] element;
  size = sz;
  element = new T[size];
  for (int i = 1; i < temps; i++) {
    element[i].Norekam = temp[i].Norekam ;
    element[i].namaBal = temp[i].namaBal;
    element[i].ibBal = temp[i].ibBal;
    element[i].tingBal = temp[i].tingBal;
    element[i].bertBal = temp[i].bertBal;
    element[i].umrBal = temp[i].umrBal;
  }
  return *this;
}
template <class T> T &Queuebal<T>::operator[](int i) const {
  if (i < 0 || i >= size)
    throw OutOfBounds();
  return element[i];
}

template <class T> Queuebal<T> &Queuebal<T>::operator=(const Queuebal<T> &v) {
  if (this != &v) {
    size = v.size;
    delete[] element;
    element = new T[size];
    for (int i = 0; i < size; i++)
      element[i] = v.element[i];
  }
  return *this;
}

template <class T> Queuebal<T> Queuebal<T>::operator+(const Queuebal<T> &v) const {
  if (size != v.size)
    throw SizeMismatch();
  Queuebal<T> w(size);
  for (int i = 0; i < size; i++)
    w.element[i] = element[i] + v.element[i];
  return w;
}

template <class T> Queuebal<T> Queuebal<T>::operator-(const Queuebal<T> &v) const {
  if (size != v.size)
    throw SizeMismatch();
  Queuebal<T> w(size);
  for (int i = 0; i < size; i++)
    w.element[i] = element[i] - v.element[i];
  return w;
}

template <class T> Queuebal<T> Queuebal<T>::operator-() const {
  Queuebal<T> w(size);
  for (int i = 0; i < size; i++)
    w.element[i] = -element[i];
  return w;
}

template <class T> Queuebal<T> Queuebal<T>::operator*(const Queuebal<T> &v) const {
  if (size != v.size)
    throw SizeMismatch();
  Queuebal<T> w(size);
  for (int i = 0; i < size; i++)
    w.element[i] = element[i] * v.element[i];
  return w;
}
template <class T> Queuebal<T> &Queuebal<T>::operator+=(const T &x) {
  for (int i = 0; i < size; i++)
    element[i] += x;
  return *this;
}

// template <class T> ostream &operator<<(ostream &out, const Queuebal<T> &x) {
//   for (int i = 0; i < x.size; i++)
//     out << x.element[i] << " ";
//   return out;
// }

template <class T>
Queuebal<T>::Queuebal(int MaxQueuebalSize) { // Create an empty queue whose capacity
                                    // is MaxQueuebalSize.
  size = MaxQueuebalSize + 1;
  element = new T[size];
  front = rear = 0;
}

template <class T>
T Queuebal<T>::First() const { // Return first element of queue.  Throw
                            // OutOfBounds exception if the queue is empty.
  if (IsEmpty())
    throw OutOfBounds();
  return element[(front + 1) % size];
}

template <class T>
int Queuebal<T>::FirstNorekam() { // Return first element of queue.  Throw
                               // OutOfBounds exception if the queue is empty.
  if (IsEmpty())
    throw OutOfBounds();
  return element[(front + 1) % size].Norekam;
}

template <class T>
string Queuebal<T>::FirstNama() { // Return first element of queue.  Throw
                               // OutOfBounds exception if the queue is empty.
  if (IsEmpty())
    throw OutOfBounds();
  return element[(front + 1) % size].namaBal;
}

template <class T>
string Queuebal<T>::FirstIbu() { // Return first element of queue.  Throw
                               // OutOfBounds exception if the queue is empty.
  if (IsEmpty())
    throw OutOfBounds();
  return element[(front + 1) % size].ibBal;
}

template <class T>
double Queuebal<T>::FirstTinggi() { // Return first element of queue.  Throw
                                 // OutOfBounds exception if the queue is empty.
  if (IsEmpty())
    throw OutOfBounds();
  return element[(front + 1) % size].tingBal;
}

template <class T>
double Queuebal<T>::FirstBerat() { // Return first element of queue.  Throw
                             // OutOfBounds exception if the queue is empty.
  if (IsEmpty())
    throw OutOfBounds();
  return element[(front + 1) % size].bertBal;
}
template <class T>
int Queuebal<T>::FirstUmur() { // Return first element of queue.  Throw
                               // OutOfBounds exception if the queue is empty.
  if (IsEmpty())
    throw OutOfBounds();
  return element[(front + 1) % size].umrBal;
}

template <class T>
T Queuebal<T>::Last() const { // Return last element of queue.  Throw
                           // OutOfBounds exception if the queue is empty.
  if (IsEmpty())
    throw OutOfBounds();
  return element[rear];
}

template <class T> 
Queuebal<T> &Queuebal<T>::Enqueue(int Norekam, string namaBal, string ibBal, double tingBal, double bertBal, int umrBal)
{ // Add x to the rear of the queue.  Throw
                               // NoMem exception if the queue is full.
  if (IsFull()) {
    // throw NoMem();
    ReSize(size + 1);
    rear = (rear + 1) % size;
    element[rear].Norekam = Norekam;
    element[rear].namaBal = namaBal;
    element[rear].ibBal = ibBal;
    element[rear].tingBal = tingBal;
    element[rear].bertBal = bertBal;
    element[rear].umrBal = umrBal;
    return *this;
  } else {
    rear = (rear + 1) % size;
    element[rear].Norekam = Norekam;
    element[rear].namaBal = namaBal;
    element[rear].ibBal = ibBal;
    element[rear].tingBal = tingBal;
    element[rear].bertBal = bertBal;
    element[rear].umrBal = umrBal;
    return *this;
  }
}

template <class T>
Queuebal<T> &Queuebal<T>::Dequeue() { // Delete first element and put in x.  Throw
                                // OutOfBounds exception if the queue is empty.
  if (IsEmpty())
    throw OutOfBounds();
  front = (front + 1) % size;
  return *this;
}

template <class T> void Queuebal<T>::tampil() {
  system("clear");
  // cout << "fungsi tampil"<< endl;
  for (int i = front + 1; i < size ; i++) {
    cout << "Data Ke - " << i << endl;
    
    // cout << "Nama Balita  = " << element[i].namaBal << endl;
    // // cout << "nama = " << element[i].nama << endl;
    // cout << "Ibu Balita = " << element[i].ibBal << endl;
    // cout << "Tinggi Balita = " << element[i].tingBal << endl;

    // temp[i].Norekam = element[i].Norekam;
    // temp[i].namaBal = element[i].namaBal;
    // temp[i].ibBal = element[i].ibBal;
    // temp[i].tingBal = element[i].tingBal;
    // temp[i].bertBal = element[i].bertBal;
    // temp[i].umrBal = element[i].umrBal;

    cout<<"----------------------------------------------" << endl;
    cout<<"No Rekam Medis        : "<< element[i].Norekam ;
    cout<<endl; 
    cout<<"Nama Balita           : "<< element[i].namaBal;
    cout<<endl;
    cout<<"Nama Ibu              : "<< element[i].ibBal;
    cout<<endl;
    cout<<"Tinggi                : "<< element[i].tingBal;
    cout<<endl;
    cout<<"Berat                 : "<< element[i].bertBal;
    cout<<endl;
    cout<<"Umur                  : "<< element[i].umrBal;
    cout<<endl;
    cout << "----------------------------------------------" << endl;
  
  }
}

// T Queuebal::index() { // Delete first element and put in x.  Throw
//                             // OutOfBounds exception if the queue is empty.
//   if (IsEmpty())
//     throw OutOfBounds();
//   front = (front + 1) % size;
//   x = element[front];
//   return *this;
// }
