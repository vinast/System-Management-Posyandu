#ifndef stackArray1D_
#define stackArray1D_
#include <iostream>
using namespace std;

struct nota {
  int tgl;
  int bulan;
  int tahun;
  int total;
};

template <class T> class stackArray1D {
  template <class A>
  friend ostream &operator<<(ostream &out, const stackArray1D<A> &x);

public:
  stackArray1D(int size = 0);
  stackArray1D(const stackArray1D<T> &v);
  ~stackArray1D() { delete[] element; }
  T &operator[](int i) const;
  int Size() { return size; }

  stackArray1D<T> &operator=(const stackArray1D<T> &v);
  stackArray1D<T> operator+() const;
  stackArray1D<T> operator+(const stackArray1D<T> &v) const;
  stackArray1D<T> operator-() const;
  stackArray1D<T> operator-(const stackArray1D<T> &v) const;
  stackArray1D<T> operator*() const;
  stackArray1D<T> operator*(const stackArray1D<T> &v) const;
  stackArray1D<T> &operator+=(const T &x);
  stackArray1D<T> &ReSize(int sz);

private:
  int size;
  T *element;
  T *temp;
};

template <class T> stackArray1D<T>::stackArray1D(int sz) {
  size = sz;
  element = new T[sz];
}

template <class T> stackArray1D<T>::stackArray1D(const stackArray1D<T> &v) {
  size = v.size;
  element = new T[size];
  for (int i = 0; i < size; i++) {
    element[i] = v.element[i];
  }
}

template <class T> T &stackArray1D<T>::operator[](int i) const {
  return element[i];
}

template <class T>
stackArray1D<T> &stackArray1D<T>::operator=(const stackArray1D<T> &v) {
  if (this != &v) {
    size = v.size;
    delete[] element;
    element = new T[size];
    for (int i = 0; i < size; i++) {
      element[i] = v.element[i];
    }
  }
  return *this;
}

template <class T>
stackArray1D<T> stackArray1D<T>::operator+(const stackArray1D<T> &v) const {
  stackArray1D<T> w(size);
  for (int i = 0; i < size; i++) {
    w.element[i] = element[i] + v.element[i];
  }
  return w;
}

template <class T>
stackArray1D<T> stackArray1D<T>::operator-(const stackArray1D<T> &v) const {
  stackArray1D<T> w(size);
  for (int i = 0; i < size; i++) {
    w.element[i] = element[i] - v.element[i];
  }
  return w;
}

template <class T> stackArray1D<T> stackArray1D<T>::operator-() const {
  stackArray1D<T> w(size);
  for (int i = 0; i < size; i++) {
    w.element[i] = -element[i];
  }
  return w;
}

template <class T>
stackArray1D<T> stackArray1D<T>::operator*(const stackArray1D<T> &v) const {
  stackArray1D<T> w(size);
  for (int i = 0; i < size; i++) {
    w.element[i] = element[i] * v.element[i];
  }
  return w;
}

template <class T> stackArray1D<T> &stackArray1D<T>::operator+=(const T &x) {
  for (int i = 0; i < size; i++) {
    element[i] += x;
  }
  return *this;
}

template <class T> stackArray1D<T> &stackArray1D<T>::ReSize(int sz) {
  temp = new T[size];
  for (int i = 0; i < size; i++) {
    temp[i] = element[i];
  }

  delete[] element;
  size = sz;
  element = new T[size];
  for (int i = 0; i < size; i++) {
    element[i] = temp[i];
  }
  return *this;
}

template <class T> ostream &operator<<(ostream &out, const stackArray1D<T> &x) {
  for (int i = 0; i < x.size; i++) {
    out << x.element[i] << " ";
  }
  return out;
}

stackArray1D<nota> arraydinamis(1);

class stack {
public:
  bool isfull();
  void pushArray(int tanggal, int bulan, int tahun, int total);
  void tampil();
  bool isempty() ;
  void popStack();
  int ambilatasTgl();
  int ambilatasTotal();
  int ambilatasBulan();
  int ambilatastahun();

  int hitungTotal(int total);

private:
  int jumlah = 0;
  int besararray = 1;
  int atas = 0;
};

bool stack::isfull() {
  if (atas >= besararray) {
    return true;
  } else {
    return false;
  }
}

void stack::pushArray(int tanggal, int bulan, int tahun, int total) {
  if (isfull())
  // true
  {
    besararray++;
    arraydinamis.ReSize(besararray);
    arraydinamis[atas].tgl = tanggal;
    arraydinamis[atas].bulan = bulan;
    arraydinamis[atas].tahun = tahun;
    arraydinamis[atas].total = total;
    atas++; /* code */
  } else {

    arraydinamis[atas].tgl = tanggal;
    arraydinamis[atas].bulan = bulan;
    arraydinamis[atas].tahun = tahun;
    arraydinamis[atas].total = total;
    atas++;
  }
}

// ini outputnya
void stack::tampil() {
  cout << "isi stack \n";
  for (int i = besararray - 1; i >= 0; i--) {
    // cout << besararray;
    cout << "Tanggal/Bulan/Tahun : " << arraydinamis[i].tgl << "/"
         << arraydinamis[i].bulan << "/" << arraydinamis[i].tahun
         << endl; /* code */
    cout << "Total               : " << arraydinamis[i].total << endl;
  }
}

bool stack::isempty() {
  if (atas -1 == 0) {
    return true;
  } else {
    return false;
  }
}

void stack::popStack() {
  if (isempty()) {
    cout << "data kosong";
  } else {
    atas--;
    besararray--;
    arraydinamis.ReSize(atas);
  }
}

int stack::ambilatasTgl() { return arraydinamis[atas - 1].tgl; }
int stack::ambilatasBulan() { return arraydinamis[atas - 1].bulan; }
int stack::ambilatastahun() { return arraydinamis[atas - 1].tahun; }
int stack::ambilatasTotal() { return arraydinamis[atas - 1].total; }

// For / While di main
int stack::hitungTotal(int total) {
  jumlah = jumlah + total;
  return jumlah;

  // int stack::hitungTotal() {
  // jumlah = jumlah + arraydinamis[atas].total;
  // return jumlah;

  // int jumlah = 0;
  // for (int i = 0; i < besararray; i++) {
  //   jumlah = jumlah + arraydinamis[i].total;
  //   return jumlah;
  // }
}

#endif