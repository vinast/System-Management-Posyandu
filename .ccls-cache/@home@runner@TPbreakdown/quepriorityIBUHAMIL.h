#include <iostream>
using namespace std;

struct Ibuha {
  int norekamib;
  string ibu_hamil;
  int usia_hamil;
  double brtib_hamil;
  int usiaib;
  int hpl_TGL;
  int hpl_BLN;
  int hpl_TH;
  Ibuha *sebelum;
  Ibuha *selanjutnya;
};

class PriorityQueue {
public:
  PriorityQueue() { awal = akhir = NULL; }
  void Enqueue(int norekamib, string ibu_hamil, int usia_hamil, 
                double brtib_hamil, int usiaib, int hpl_TGL, int hpl_BLN, 
                int hpl_TH);
  void Dequeue();
  void List();
  int Firstrekam();
  string FirstNama();
  int FirstUsiaHamil();
  double FirstBerat();
  int FirstUsiaIbu();
  int FirstTGL();
  int FirstBLN();
  int FirstTH();
  bool isEmpty();
  
private:
  Ibuha *awal;
  Ibuha *akhir;
};

void PriorityQueue::Enqueue(int norekamib, string ibu_hamil, int usia_hamil, double brtib_hamil, int usiaib, int hpl_TGL, int hpl_BLN, int hpl_TH)
{
  Ibuha *baru = new Ibuha;
  baru->norekamib = norekamib;
  baru->ibu_hamil = ibu_hamil;
  baru->usia_hamil = usia_hamil;
  baru->brtib_hamil = brtib_hamil;
  baru->usiaib  = usiaib;
  baru->hpl_TGL = hpl_TGL;
  baru->hpl_BLN = hpl_BLN;
  baru->hpl_TH = hpl_TH;
  

  if (awal == NULL || usia_hamil > awal->usia_hamil) {
    baru->selanjutnya = awal;
    awal = baru;
  } else {
    Ibuha *lama = new Ibuha;
    lama = awal;
    
    while (lama->selanjutnya != NULL && lama->selanjutnya->usia_hamil >= usia_hamil) {
      }
    baru->selanjutnya = lama->selanjutnya;
    lama->selanjutnya = baru;
    akhir = baru;
  }
}

void PriorityQueue::Dequeue() {
  if (awal == NULL) {
    cout << "data kosong" << endl;
  } else {
    Ibuha *hapus = awal;
    awal = awal->selanjutnya;
  }
}

void PriorityQueue::List() {
  int i=1;
  Ibuha *lihat = awal;
  while(lihat!=NULL){
    cout << "data ke-" << i << endl;
    cout<<"  norekamib = "<< lihat->norekamib<<endl;
    cout << "nama Ibuha = " << lihat->ibu_hamil << endl;
    cout << "usia_hamil = " << lihat->usia_hamil << endl;
    cout << "brtib_hamil = " << lihat->brtib_hamil << endl;
    cout << "usiaib  = " << lihat->usiaib; 
    
    lihat=lihat->selanjutnya;
  }
}

double PriorityQueue::FirstBerat(){
  return awal->brtib_hamil;
}
string PriorityQueue::FirstNama(){
  return awal->ibu_hamil;
}
int PriorityQueue::FirstUsiaHamil(){
  return awal->usia_hamil;
}
int PriorityQueue::FirstUsiaIbu(){
  return awal->usiaib;
}
int PriorityQueue::Firstrekam(){
  return awal->norekamib;
}
int PriorityQueue::FirstTGL(){
  return awal->hpl_TGL;
}
int PriorityQueue::FirstBLN(){
  return awal->hpl_BLN;
}
int PriorityQueue::FirstTH(){
  return awal->hpl_TH;
}

bool PriorityQueue::isEmpty(){
  if(awal==NULL){
    return true;
  }
  else{
    return false;
  }
}