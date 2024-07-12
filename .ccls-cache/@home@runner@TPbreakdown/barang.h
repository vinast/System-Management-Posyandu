#include <iostream>
#include <string>
using namespace std;

class barang
{
public:
    barang(string ID = "", string NAMA = "", int STOK = 0, int HARGA = 0)
    {
        id = ID;
        nama = NAMA;
        stok = STOK;
        harga = HARGA;
    }

    int stok;
    int harga;
    string nama;
    string id;
};