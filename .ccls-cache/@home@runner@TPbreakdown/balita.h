#include <iostream>
#include <string>
using namespace std;

class balita
{
public:
    balita(int NOREKAM = 0,string NAMA = "", string IBU = "", int TINGGI = 0, int BERAT = 0, int UMUR = 0)
    {
        norekam = NOREKAM;
        namaBalita = NAMA;
        ibu = IBU;
        tinggi = TINGGI;
        berat = BERAT;
        umur = UMUR;
    }
    int norekam;
    double tinggi;
    double berat; 
    double umur;
    string namaBalita; 
    string ibu;
};