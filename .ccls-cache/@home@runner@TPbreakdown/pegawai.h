#include <iostream>
#include <string>
using namespace std;

class pegawai
{
public:
    pegawai(int NIP = 0,string NAMA = "", double GAJI = 0, string JABATAN = 0, int BERAT = 0, int UMUR = 0)
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