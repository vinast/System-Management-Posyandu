#include <iostream>
using namespace std;

class Transaksi
{
public:
    Transaksi(string ID = "", string NAMA = "", int STOK = 0, int HARGA = 0, int JUMLAH = 0, int TOTAL = 0)
    {
        id = ID;
        nama = NAMA;
        stok = STOK;
        harga = HARGA;
        jumlah = JUMLAH;
        total = TOTAL;
    }

    int stok;
    int harga;
    int jumlah; 
    int total;
    string nama;
    string id;
};