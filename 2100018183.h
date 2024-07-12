#include "ArrayDinamisBalita.h"
#include "KTP.h"
#include "Transaksi.h"
#include "balita.h"
#include "doublell.h"
#include "linklist.h"
#include "Btree.h"

#include <fstream>
#include <iostream>
#include <sstream>

struct AIbuHamil {
  int Anorekamib_hamil;
  string Anamaib_hamil;
  int Ausiakehamilan;
  int Ausiaib_hamil;
  int Aberatib_hamil;
  // int hplib_hamil;
  int Ahplib_TGL;
  int Ahplib_BLN;
  int Ahplib_TH;

} Aibhml[100];



struct palingumum
{
  int kode;
  string tglLaksana;
  string jenis, pelaku,tempat, topik;
}; palingumum nyoba[100];



struct pohonygy
{
  string namanya;
  string nomornya;
} pohon;




struct buHamilcek {
  int norekambumil;
  string namabumil;
  int usiahamil;
  int usiabumil;
  int beratbumil;
  // int hplib_hamil;
  int hplibTGL;
  int hplibBLN;
  int hplibTH;

} bumilcek;





struct AIbuHamilantri {
  int Anorekamib_hamilantri;
  string Anamaib_hamilantri;
  int Ausiakehamilanantri;
  int Ausiaib_hamilantri;
  int Aberatib_hamilantri;
  // int hplib_hamil;
  int Ahplib_TGLantri;
  int Ahplib_BLNantri;
  int Ahplib_THantri;

} Aibhmlantri[100];

struct KTPBidann {
  string NIPn;
  string namaBidann;
  string nikBidann;
  string provBidann;
  string tmptLahirBidann;
  string tglLahirBidann;
  string noHpn;
  string jlnBidann;
  string rtBidann;
  string rwBidann;
  string kecBidann;
  string kabBidann;
  string desaBidann;
  double gajiBidann;
} dataBidann[1000];

struct Balitacek {
  int Norekam;
  double tinggibal;
  double beratbal;
  double umurbal;
  string namaBalitabal;
  string ibubal;
} balcek;

struct historyPemasukkan {
  int htgl;
  int hbln;
  int hthn;
  int htotal;
} hisIn;

// #include "Login.h"
using namespace std;

class User {
public:
  List<Transaksi> x;
  DinamisBalita<balita> G;
  DoubleLinkedList Z[1000];

  int toInt(string x) {
    int y;

    stringstream ss;
    ss << x;
    ss >> y;

    return y;
  }

  double toDouble(string p) {
    double l;

    stringstream ss;
    ss << p;
    ss >> l;

    return l;
  }

  void tokenizeIBHML(string sIB, string delIB = " ", int idxIB = 0) {
    string tmpIB;
    int iIB = 1;
    int start, end = -1 * delIB.size();

    // int Anorekamib_hamil;
    // string Anamaib_hamil;
    // double Ausiakehamilan;
    // double Ausiaib_hamil;
    // double Aberatib_hamil;
    // // double hplib_hamil;
    // double Ahplib_TGL;
    // double Ahplib_BLN;
    // double Ahplib_TH;

    do {
      start = end + delIB.size();
      end = sIB.find(delIB, start);
      tmpIB = sIB.substr(start, end - start);

      if (iIB == 1) 
      {
        Aibhml[idxIB].Anorekamib_hamil = toInt(tmpIB);
      } 
      else if (iIB == 2) 
      {
        Aibhml[idxIB].Anamaib_hamil = tmpIB;
      } 
      else if (iIB == 3) 
      {
        Aibhml[idxIB].Ausiakehamilan = toInt(tmpIB);
      } 
      else if (iIB == 4) 
      {
        Aibhml[idxIB].Aberatib_hamil = toInt(tmpIB);
      } 
      else if (iIB == 5) 
      {
        Aibhml[idxIB].Ausiaib_hamil = toInt(tmpIB);
      } 
      else if (iIB == 6) 
      {
        Aibhml[idxIB].Ahplib_TGL = toInt(tmpIB);
      } 
      else if (iIB == 7) 
      {
        Aibhml[idxIB].Ahplib_BLN = toInt(tmpIB);
      } 
      else 
      {
        Aibhml[idxIB].Ahplib_TH = toInt(tmpIB);
      }
      iIB++;

    } while (end != -1);
  }




  void tokenizeIBHMLantri(string sIBantri, string delIBantri = " ", int idxIBantri = 0) {
    string tmpIBantri;
    int iIBantri = 1;
    int start, end = -1 * delIBantri.size();

    do {
      start = end + delIBantri.size();
      end = sIBantri.find(delIBantri, start);
      tmpIBantri = sIBantri.substr(start, end - start);

      if (iIBantri == 1) 
      {
        Aibhmlantri[idxIBantri].Anorekamib_hamilantri = toInt(tmpIBantri);
      } 
      else if (iIBantri == 2) 
      {
        Aibhmlantri[idxIBantri].Anamaib_hamilantri = tmpIBantri;
      } 
      else if (iIBantri == 3)
      {
        Aibhmlantri[idxIBantri].Ausiakehamilanantri = toInt(tmpIBantri);
      } 
      else if (iIBantri == 4) 
      {
        Aibhmlantri[idxIBantri].Aberatib_hamilantri = toInt(tmpIBantri);
      } 
      else if (iIBantri == 5) 
      {
        Aibhmlantri[idxIBantri].Ausiaib_hamilantri = toInt(tmpIBantri);
      } 
      else if (iIBantri == 6) 
      {
        Aibhmlantri[idxIBantri].Ahplib_TGLantri = toInt(tmpIBantri);
      } 
      else if (iIBantri == 7) 
      {
        Aibhmlantri[idxIBantri].Ahplib_BLNantri = toInt(tmpIBantri);
      } 
      else
      {
        Aibhmlantri[idxIBantri].Ahplib_THantri = toInt(tmpIBantri);
      }
      iIBantri++;

    } while (end != -1);
  }





  void tokenizeBd(string sd, string deld = " ", int idxd = 0) {
    string tmpd;
    int i = 1;

    int startd, endd = -1 * deld.size();
    do {
      startd = endd + deld.size();
      endd = sd.find(deld, startd);
      tmpd = sd.substr(startd, endd - startd);

      if (i == 1) 
      {
        dataBidann[idxd].NIPn = tmpd;
      } else if (i == 2) 
      {
        dataBidann[idxd].nikBidann = tmpd;
      } else if (i == 3) 
      {
        dataBidann[idxd].namaBidann = tmpd;
      } else if (i == 4) 
      {
        dataBidann[idxd].provBidann = tmpd;
      } 
      else if (i == 5) 
      {
        dataBidann[idxd].tglLahirBidann = tmpd;
      } else if (i == 6) 
      {
        dataBidann[idxd].tmptLahirBidann = tmpd;
      } else if (i == 7) 
      {
        dataBidann[idxd].noHpn = tmpd;
      } 
      else if (i == 8) 
      {
        dataBidann[idxd].jlnBidann = tmpd;
      } 
      else if (i == 9) 
      {  
        dataBidann[idxd].rtBidann = tmpd;
      }
      else if (i == 10) 
      {
        dataBidann[idxd].rwBidann = tmpd;
      } 
      else if (i == 11) 
      {
        dataBidann[idxd].desaBidann = tmpd;
      } 
      else if (i == 12) 
      {
        dataBidann[idxd].kecBidann = tmpd;
      } 
      else if (i == 13)
      {
        dataBidann[idxd].kabBidann = tmpd;
      }
      else 
      {
        dataBidann[idxd].gajiBidann = toDouble(tmpd);
      }
      i++;

    } while (endd != -1);
  }




  void tokenizez(string sz, string delz = " ") {
    string tmpz;
    int i = 1;

    int startz, end = -1 * delz.size();
    do {
      startz = end + delz.size();
      end = sz.find(delz, startz);
      tmpz = sz.substr(startz, end - startz);

      if (i == 1) 
      {
        dataKTP.nik = tmpz;
      } 
      else if (i == 2) 
      {
        dataKTP.nama = tmpz;
      } 
      else if (i == 3) 
      {
        dataKTP.prov = tmpz;
      }
      else if (i == 4) 
      {
        dataKTP.tmptlahir = tmpz;
      } 
      else if (i == 5) 
      {
        dataKTP.tgllahir = tmpz;
      } 
      else if (i == 6) 
      {
        dataKTP.dusun = tmpz;
      } 
      else if (i == 7) 
      {
        dataKTP.rt = tmpz;
      } 
      else if (i == 8) 
      {
        dataKTP.rw = tmpz;
      } 
      else if (i == 9) 
      {
        dataKTP.desa = tmpz;
      } 
      else if (i == 10)
      {
        dataKTP.kecamatan = tmpz;
      } 
      else if (i == 11) 
      {
        dataKTP.kab = tmpz;
      } 
      else if (i == 12) 
      {
        dataKTP.agama = tmpz;
      } 
      else if (i == 13) 
      {
        dataKTP.skawin = tmpz;
      } 
      else if (i == 14) 
      {
        dataKTP.pekerjaan = tmpz;
      } 
      else if (i == 15) 
      {
        dataKTP.knegara = tmpz;
      } 
      else if (i == 16) 
      {
        dataKTP.berhing = tmpz;
      } 
      else if (i == 17) 
      {
        dataKTP.jklmn = tmpz;
      } 
      else {
        dataKTP.goldar = tmpz;
      }
      i++;

    } while (end != -1);
  }




  void tokenizebalcek(string sy, string dely = " ") {
    string tmpy;
    int i = 1;
    int starty, end = -1 * dely.size();
    do {
      starty = end + dely.size();
      end = sy.find(dely, starty);
      tmpy = sy.substr(starty, end - starty);

      if (i == 1) {
        balcek.Norekam = toInt(tmpy);
      } else if (i == 2) {
        balcek.namaBalitabal = tmpy;
      } else if (i == 3) {
        balcek.ibubal = tmpy;
      } else if (i == 4) {
        balcek.tinggibal = toDouble(tmpy);
      } else if (i == 5) {
        balcek.beratbal = toDouble(tmpy);
      } else {
        balcek.umurbal = toInt(tmpy);
      }
      i++;

    } while (end != -1);
  }



void tokenizebumilcek(string sImilcek, string delImilcek = " ") {
    string tmpImilcek;
    int iImilcek = 1;
    int start, end = -1 * delImilcek.size();

    do {
      start = end + delImilcek.size();
      end = sImilcek.find(delImilcek, start);
      tmpImilcek = sImilcek.substr(start, end - start);

      if (iImilcek == 1) {
        bumilcek.norekambumil = toInt(tmpImilcek);
      } 
      else if (iImilcek == 2) {
        bumilcek.namabumil = tmpImilcek;
      } 
      else if (iImilcek == 3) {
        bumilcek.usiahamil = toInt(tmpImilcek);
      } 
      else if (iImilcek == 4) {
        bumilcek.beratbumil = toInt(tmpImilcek);
      } 
      else if (iImilcek == 5) {
        bumilcek.usiabumil = toInt(tmpImilcek);
      } 
      else if (iImilcek == 6) {
        bumilcek.hplibTGL = toInt(tmpImilcek);
      } 
      else if (iImilcek == 7) {
        bumilcek.hplibBLN = toInt(tmpImilcek);
      } 
      else {
        bumilcek.hplibTH = toInt(tmpImilcek);
      }
      iImilcek++;

    } while (end != -1);
  }




  void tokenizee(string se, string dele = " ", int idxe = 0) {

    string tmpe;
    int i = 1;

    int starte, ende = -1 * dele.size();
    do {
      starte = ende + dele.size();
      ende = se.find(dele, starte);
      tmpe = se.substr(starte, ende - starte);

      if (i == 1) {
        brggu[idx].id = tmpe;
      } 
      else if (i == 2)
      {
        brggu[idx].nama = tmpe;
      }
      else if (i == 3) 
      {
        brggu[idx].stok = toInt(tmpe);
      }
      else if (i == 4) 
      {
        brggu[idx].harga = toInt(tmpe);
      } 
      else if (i == 5) 
      {
        brggu[idx].jumlah = toInt(tmpe);
      }
      else {
        brggu[idx].total = toInt(tmpe);
      }
      i++;

    } while (ende != -1);
  }




  void tokenize(string s, string del = " ", int idx = 0) {
    string tmp;
    int i = 1;

    int start, end = -1 * del.size();
    do {
      start = end + del.size();
      end = s.find(del, start);
      tmp = s.substr(start, end - start);

      if (i == 1)
      {
        brgg[idx].id = tmp;
      }
      else if (i == 2)
      {
        brgg[idx].nama = tmp;
      }
      else if (i == 3) 
      {
        brgg[idx].stok = toInt(tmp);
      }
      else 
      {
        brgg[idx].harga = toInt(tmp);
      }
      i++;

    } while (end != -1);
  }




  void tokenizeObt(string s, string del = " ", int idx = 0) {
    string tmp;
    int i = 1;

    int start, end = -1 * del.size();
    do {
      start = end + del.size();
      end = s.find(del, start);
      tmp = s.substr(start, end - start);

      if (i == 1) {
        obt[idx].id = tmp;
      } else if (i == 2) 
      {
        obt[idx].nama = tmp;
      }
      else if (i == 3) 
      {
        obt[idx].stok = toInt(tmp);
      }
      else 
      {
        obt[idx].harga = toInt(tmp);
      }
      i++;

    } while (end != -1);
  }






  void ambildatabeli() {
    idx = 0;
    string t;
    ambil.open("daftarBelanja.txt");
    while (!ambil.eof()) 
    {
      ambil >> t;
      tokenizee(t, ";", idx);
      idx++;
    }
    ambil.close();
  }





  void ambildatabrg() {
    idx = 0;
    string t;
    ambil.open("data.txt");
    while (!ambil.eof()) 
    {
      ambil >> t;
      tokenize(t, ";", idx);
      idx++;
    }
    ambil.close();
  }





  void ambildataobt() {
    idx = 0;
    string t;
    ambil.open("dataobat.txt");
    while (!ambil.eof()) 
    {
      ambil >> t;
      tokenizeObt(t, ";", idx);
      idx++;
    }
    ambil.close();
  }







  void tokenizeBlt(string s, string del = " ", int idx = 0) {
    string tmp;
    int i = 1;
    int start, end = -1 * del.size();
    do {
      start = end + del.size();
      end = s.find(del, start);
      tmp = s.substr(start, end - start);

      if (i == 1) {
        blt[idx].norekam = toInt(tmp);
      } else if (i == 2) {
        blt[idx].namaBalita = tmp;
      } else if (i == 3) {
        blt[idx].ibu = tmp;
      } else if (i == 4) {
        blt[idx].tinggi = toInt(tmp);
      } else if (i == 5) {
        blt[idx].berat = toDouble(tmp);
      } else {
        blt[idx].umur = toInt(tmp);
      }
      i++;

    } while (end != -1);
  }

  // antrian balita
  void tokenizeQueBlt(string s, string del = " ", int qidx = 0) {
    string qtmp;
    int qi = 1;
    int start, end = -1 * del.size();
    do {
      start = end + del.size();
      end = s.find(del, start);
      qtmp = s.substr(start, end - start);

      if (qi == 1)
      {
        queblt[qidx].norekam = toInt(qtmp);
      } 
      else if (qi == 2)
      {
        queblt[qidx].namaBalita = qtmp;
      } 
      else if (qi == 3) 
      {
        queblt[qidx].ibu = qtmp;
      }
      else if (qi == 4) 
      {
        queblt[qidx].tinggi = toInt(qtmp);
      } 
      else if (qi == 5) 
      {
        queblt[qidx].berat = toDouble(qtmp);
      } 
      else {
        queblt[qidx].umur = toInt(qtmp);
      }
      qi++;

    } while (end != -1);
  }

  void ambildataDinamisBlt() {
    // DinamisBalita<balita> X;
    int idxx = 0;
    batas = 0;
    string t;
    ambil.open("dataBalita.txt");
    while (!ambil.eof()) 
    {
      ambil >> t;
      tokenizeBlt(t, ";", idxx);
      idxx++;
      // X.ReSize(idx);
    }
    ambil.close();
    batas = idxx;
    // X.ReSize(idxx);
    G.ReSize(idxx);
    for (int i = 0; i < idxx - 1; i++) 
    {
      balita tambah(blt[i].norekam, blt[i].namaBalita, blt[i].ibu,
                    blt[i].tinggi, blt[i].berat, blt[i].umur);
      G[i] = tambah;
      tinggii[i] = blt[i].tinggi;
      beratt[i] = blt[i].berat;
    }
    hasil1 = n_jum(tinggii, idxx - 1);
    hasil2 = n_jum(beratt, idxx - 1);
    rata1 = rata(hasil1, idxx - 1);
    rata2 = rata(hasil2, idxx - 1);
  }

  void ambilLinklist() {
    int idxx = 0;
    // batas = 0;
    string t;
    ambil.open("dataBalita.txt");
    while (!ambil.eof()) 
    {
      ambil >> t;
      tokenizeBlt(t, ";", idxx);
      idxx++;
      // X.ReSize(idx);
    }
    ambil.close();
    // ambildataDinamisBlt();
    Z->inisialisasi();
    for (int i = 0; i < idxx - 1; i++) 
    {

      Z->inputData(blt[i].norekam, blt[i].namaBalita, blt[i].ibu, blt[i].tinggi,
                   blt[i].berat, blt[i].umur);
      tinggii[i] = blt[i].tinggi;
      beratt[i] = blt[i].berat;
    }
    // n_jum(blt->berat, idxx);
    hasil1 = n_jum(tinggii, idxx - 1);
    hasil2 = n_jum(beratt, idxx - 1);
    rata1 = rata(hasil1, idxx - 1);
    rata2 = rata(hasil2, idxx - 1);
  }

  // tambahan lagiii

  double n_jum(double angka[], int n) 
{

    if (n < 0) {
      return 0;
    } else 
    {
      return angka[n] + n_jum(angka, n - 1);
    }
  }

  double rata(double w, int e) 
{
    double r = 0;
    r = w / e;
    return r;
  }

  void lihatdataBlt() 
{
    // cout<< Y <<endl;
    // ambildataDinamisBlt();
    ambilLinklist();
    Z->tampilData();
    cout << "Rata-Rata Berat Badan  : " << rata2;
    cout << endl;
    cout << "Rata-Rata Tinggi Badan : " << rata1;
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
    cin >> konfirmasi;
    // Z.cetak();
  }

  void tambahdataBlt() {
    int sz;
    tulis.open("dataBalita.txt", ios::app);
    cout << endl;
    cout << "Berikut Tambah Data Balita Posyandu Bahagia...";
    cout << endl;
    cout << endl;
    cout << "Silahakan Tambah Data Balita...";
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Ingin Menanbah Berapa data : ";
    cin >> sz;
    for (int z = 0; z < sz; z++) {
      cout << "----------------------------------------------" << endl;
      cout << "Masukkan Nama Balita          : ";
      cin >> namaBalita;
      cout << "Masukkan Nama Ibu             : ";
      cin >> ibu;
      cout << "Masukkan Tinggi Balita        : ";
      cin >> tinggi;
      cout << "Masukkan Berat badan Balita   : ";
      cin >> berat;
      cout << "----------------------------------------------" << endl;
      tulis << norekam << ";" << namaBalita << ";" << ibu << ";" << tinggi
            << ";" << berat << endl;
    }
    tulis.close();
  }

  void ambilkode() {
    ambil.open("kode.txt");
    if (!ambil.fail()) {
      while (!ambil.eof()) 
      {
        ambil >> kodemedis;
      }
      ambil.close();
    } else 
    {
      cout << "File tidak ditemukan" << endl;
    }
  }

  void ambilbalcek()
{

    // ifstream ambil;

    // idxe = 0;
    string t;
    ambil.open("balitacek.txt");
    while (!ambil.eof())
      {
      ambil >> t;
      tokenizebalcek(t, ";");
      // idxe++;
    }

    ambil.close();
  }



void ambilbumilcek() 
{

    // ifstream ambil;

    // idxe = 0;
    string tbumil;
    ambil.open("bumilcek.txt");
    while (!ambil.eof()) 
    {
      ambil >> tbumil;
      tokenizebumilcek(tbumil, ";");
      // idxe++;
    }

    ambil.close();
  }




   void tokenizepng(string spng, string delpng = " ", int idxpng = 0) {
    string tpng;
    int i = 1;
    int startb, endb = -1 * delpng.size();
    do {
      startb = endb + delpng.size();
      endb = spng.find(delpng, startb);
      tpng = spng.substr(startb, endb - startb);

      if (i == 1) {
        nyoba[idxpng].kode = toInt(tpng);

      } else if (i == 2) {
        nyoba[idxpng].jenis = tpng;

      } else if (i == 3) {
        nyoba[idxpng].topik = tpng;
      }  else if (i == 4){
        nyoba[idxpng].tglLaksana = tpng;
      } else if (i == 5){
        nyoba[idxpng].pelaku = tpng;
      } else {
        nyoba[idxpng].tempat = tpng;
      }
      
      i++;

    } while (endb != -1);
  }
  



  // LLBalita<balita> Y;
  // doubleLL<balita> Z;
  // DoubleLinkedList Z[1000];
  void diumumkan();
  void Menu();
  void MenuTampilData();
  void TampilBalitaDinamis();
  void tampil();
  void Beli();
  void lihat();
  void cekKesehatan();
  void cekKesehatan2();
  void cetakinvoice();
  void ambildataLogin();
  void syaratBeli();
  bool sttsBeli = false;
  bool tertemu = false;
  KTP2 dataKTP;
  int pilihusr, pilihtampil;
  double beratt[1000], tinggii[1000], hasil1, hasil2, rata1, rata2;
  char konfirmasi;

  balita *blt = new balita[1000];
  balita *queblt = new balita[1000];

  string namaBalita, ibu;
  double tinggi, berat;
  void tampilObt();
  void tulisdatamedis();
  int norekam;
  int temu = -1;

  void tulisdate(int bayar);

  // queue
  void tampilAntrianblt();

  //  que priority
  void tampildataIBU_Hamil();
  void tampilantrianBumil();
  void cekkesehatanv3();
  void cekkesehatanv4();
  void riwayatPeriksa();


private:
  string nikbeli;

  int idx;
  int idxe;
  int pilih;
  int batas;
  int kodemedis;
  int totbayar;
  int jumbayar;
  Transaksi *brgg = new Transaksi[1000];
  Transaksi *brggu = new Transaksi[1000];
  Transaksi *obt = new Transaksi[1000];
  // string dataKTP[1000];
  ofstream tulis;
  ofstream tulistod;
  ifstream ambil;
  ifstream ambilbdn;

  // stack
  ofstream tulishistory;
  ofstream tuliskuy;

  // antiran
  ifstream ambilantribal;

  // que priority
  ifstream ambildataIBU_HAMIL;
  ifstream ambilantrianbumil;
};




void User:: diumumkan()
{
  ifstream jukut;
  int idxpng = 0;
    string tpg;
    jukut.open("Pengumuman.txt");

    while (!jukut.eof()) {
      getline(jukut, tpg);
      tokenizepng(tpg, ";", idxpng);
      idxpng++;
    }

    system("clear");
    cout<<"Berikut Pengumumman Yang Tersedia..."<<endl;
    cout << "----------------------------------------------" << endl;
    for(int i =0 ; i< idxpng -1 ; i++)
    {
      cout << "----------------------------------------------" << endl;
      cout<<"Jenis    : "<<nyoba[i].jenis<<endl;
      cout<<"Tema     : "<<nyoba[i].topik<<endl;
      cout<<"Tgl      : "<<nyoba[i].tglLaksana<<endl;
      cout<<"Peserta  : "<<nyoba[i].pelaku<<endl;
      cout<<"Tempat   : "<<nyoba[i].tempat<<endl;
      cout << "----------------------------------------------" << endl;
      cout << endl;
    }

  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirmasi;
}





void User::tampilantrianBumil()
{
  int idxIBA = 0;
  string tIBA;
  ambildataIBU_HAMIL.open("ibuhamilantri.txt");
  while (!ambildataIBU_HAMIL.eof()) {
    ambildataIBU_HAMIL >> tIBA;
    tokenizeIBHMLantri(tIBA, ";", idxIBA);
    idxIBA++;
    // X.ReSize(idx);
    // cout<<"P"<<endl;
  }
  ambildataIBU_HAMIL.close();
  system("clear");
  cout << "Berikut Antrian Ibu Hamil Posyandu...";
  cout << endl;

    string temp;
    int tempwaw;
  for(int n =0; n < idxIBA -1 ;n++)
  {
  for (int m = 0; m < idxIBA -2; m++) 
  {
    // cout << Aibhml[h].Anamaib_hamil;
        if (Aibhmlantri[m].Ausiakehamilanantri < Aibhmlantri[m + 1].Ausiakehamilanantri)
        {
          
          tempwaw = Aibhmlantri[m].Anorekamib_hamilantri;
          Aibhmlantri[m].Anorekamib_hamilantri = Aibhmlantri[m + 1].Anorekamib_hamilantri;
          Aibhmlantri[m + 1].Anorekamib_hamilantri = tempwaw ;


          temp = Aibhmlantri[m].Anamaib_hamilantri;
          Aibhmlantri[m].Anamaib_hamilantri = Aibhmlantri[m+1].Anamaib_hamilantri;
          Aibhmlantri[m+1].Anamaib_hamilantri = temp;
          

          tempwaw = Aibhmlantri[m].Ausiakehamilanantri;
          Aibhmlantri[m].Ausiakehamilanantri = Aibhmlantri[m+1].Ausiakehamilanantri;
          Aibhmlantri[m + 1].Ausiakehamilanantri = tempwaw;


          tempwaw = Aibhmlantri[m].Aberatib_hamilantri;
          Aibhmlantri[m].Aberatib_hamilantri = Aibhmlantri[m+1].Aberatib_hamilantri;
          Aibhmlantri[m+1].Aberatib_hamilantri = tempwaw;


          tempwaw = Aibhmlantri[m].Ausiaib_hamilantri;
          Aibhmlantri[m].Ausiaib_hamilantri = Aibhmlantri[m+1].Ausiaib_hamilantri;
          Aibhmlantri[m+1].Ausiaib_hamilantri = tempwaw;


          tempwaw = Aibhmlantri[m].Ahplib_TGLantri;
          Aibhmlantri[m].Ahplib_TGLantri = Aibhmlantri[m + 1].Ahplib_TGLantri;
          Aibhmlantri[m+1].Ahplib_TGLantri = tempwaw;


          tempwaw = Aibhmlantri[m].Ahplib_BLNantri;
          Aibhmlantri[m].Ahplib_BLNantri = Aibhmlantri[m + 1].Ahplib_BLNantri;
          Aibhmlantri[m+1].Ahplib_BLNantri = tempwaw;


          tempwaw = Aibhmlantri[m].Ahplib_THantri;
          Aibhmlantri[m].Ahplib_THantri = Aibhmlantri[m + 1].Ahplib_THantri;
          Aibhmlantri[m + 1].Ahplib_THantri = tempwaw;
          

          
        }
    
   

    // buat for
  }
}
  cout <<"Berikut Data Ibu Hamil Yang Tersedia...";
  cout<<endl;
  for (int l = 0 ; l < idxIBA -1; l++)
  {
     cout << "----------------------------------------------" << endl;
    cout << "No Rekam Bumil            : ";
    cout << Aibhmlantri[l].Anorekamib_hamilantri;
    cout << endl;
    cout << "Nama Bumil                : ";
    cout << Aibhmlantri[l].Anamaib_hamilantri;
    cout << endl;
    cout << "Usia Kehamilan (bulan)    : ";
    cout << Aibhmlantri[l].Ausiakehamilanantri;
    cout << endl;
    cout << "Berat Bumil               : ";
    cout << Aibhmlantri[l].Aberatib_hamilantri;
    cout << endl;
    cout << "Usia Bumil                : ";
    cout << Aibhmlantri[l].Ausiaib_hamilantri;
    cout << endl;
    cout << "Hari Prediksi Lahir (HPL) : ";
    cout << Aibhmlantri[l].Ahplib_TGLantri;
    cout << "/";
    cout << Aibhmlantri[l].Ahplib_BLNantri;
    cout << "/";
    cout << Aibhmlantri[l].Ahplib_THantri;
    cout << endl;

    cout << "----------------------------------------------" << endl;
  }
   cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirmasi;  
  // buat
}
  




void User::cekkesehatanv3() {
  int idxIB = 0;
  string tIB;
  ambildataIBU_HAMIL.open("dataIbu_Hamil.txt");
  while (!ambildataIBU_HAMIL.eof()) {
    ambildataIBU_HAMIL >> tIB;
    tokenizeIBHML(tIB, ";", idxIB);
    idxIB++;
    // X.ReSize(idx);
  }
  ambildataIBU_HAMIL.close();

  // cout << "Hail david disini ;D" << endl;
  // PriorityQueue tester;
  system("clear");
  cout <<"Berikut Daftar Ibu Hamil Yang Tersedia...";
  cout<<endl;
  for (int h = 0; h < idxIB - 1; h++) {
    // cout << Aibhml[h].Anamaib_hamil;

    cout << "----------------------------------------------" << endl;
    cout << "No Rekam Bumil            : ";
    cout << Aibhml[h].Anorekamib_hamil;
    cout << endl;
    cout << "Nama Bumil                : ";
    cout << Aibhml[h].Anamaib_hamil;
    cout << endl;
    cout << "Usia Kehamilan (bulan)    : ";
    cout << Aibhml[h].Ausiakehamilan;
    cout << endl;
    cout << "Berat Bumil               : ";
    cout << Aibhml[h].Aberatib_hamil;
    cout << endl;
    cout << "Usia Bumil                : ";
    cout << Aibhml[h].Ausiaib_hamil;
    cout << endl;
    cout << "Hari Prediksi Lahir (HPL) : ";
    cout << Aibhml[h].Ahplib_TGL;
    cout << "/";
    cout << Aibhml[h].Ahplib_BLN;
    cout << "/";
    cout << Aibhml[h].Ahplib_TH;
    cout << endl;
    // tester.Enqueue( Aibhml[h].Anorekamib_hamil, Aibhml[h].Anamaib_hamil,
    // Aibhml[h].Ausiakehamilan, Aibhml[h].Aberatib_hamil,
    // Aibhml[h].Ausiaib_hamil, Aibhml[h].Ahplib_TGL, Aibhml[h].Ahplib_BLN,
    // Aibhml[h].Ahplib_TH);

    cout << "----------------------------------------------" << endl;
  }

  string carnama;
  bool ditemukan = false;
  cout << endl;
  cout << "----------------------------------------------" << endl;
  cout << "Cek Kesehatan Atas Nama  : ";
  cin >> carnama;
  cout << "----------------------------------------------" << endl;
  system("clear");
  int datake;
  tuliskuy.open("ibuhamilantri.txt", ios ::app);
  for (int i = 0; i < idxIB - 1; i++) {
    if (carnama == Aibhml[i].Anamaib_hamil) {
      ditemukan = true;
      datake = i;
      // tertemu = true;
      temu = datake;
      // noblt = datake;
      break;
    }
  }
  if (ditemukan == true) {
    for (int j = 0; j < idxIB - 1; j++) {
      if (j == datake) {

        cout << "----------------------------------------------" << endl;
        cout << "Ibu hamil Atas Nama " << Aibhml[j].Anamaib_hamil;
        cout<<endl;
        cout << " Telah DiMasukkan Kedalam Antrian";
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << endl;
        tuliskuy << Aibhml[j].Anorekamib_hamil << ";" << Aibhml[j].Anamaib_hamil
                 << ";" << Aibhml[j].Ausiakehamilan << ";"
                 << Aibhml[j].Aberatib_hamil << ";" << Aibhml[j].Ausiaib_hamil
                 << ";" << Aibhml[j].Ahplib_TGL << ";" << Aibhml[j].Ahplib_BLN
                 << ";" << Aibhml[j].Ahplib_TH << endl;
        // tulis.close();
        // break;
      }
    }
    // tulis.close();
  }
  tuliskuy.close();

  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirmasi;
}





void User:: cekkesehatanv4()
{
    string stts_sehat;
    string cttn_sehat;
    // ambilbumilcek();
    string tanjay;
    ambil.open("bumilcek.txt");
    while (!ambil.eof()) {
      ambil >> tanjay;
      tokenizebumilcek(tanjay, ";");
      // idxe++;
    }

    ambil.close();
    if(bumilcek.namabumil == "")
    {
      system("clear");
      cout << "----------------------------------------------" << endl;
      cout <<"Data Pemeriksaan Kosong...";
      cout<<endl;
      cout<<"Silahakn Tunggu Admin Untuk Melakukan Pemeriksaan!!!";
      cout<<endl;
      cout<<"Silahkan Tunggu Beberapa Saat Lagi...";
      cout<<endl;
      cout << "----------------------------------------------" << endl;
    } 
    else 
    {
    
  
          cout << endl;
           system("clear");
          cout << "Ibu Hamil Yang Di Cek..." << endl;
          cout << "----------------------------------------------" << endl;
          cout << "No Rekam Bumil            : ";
          cout << bumilcek.norekambumil;
          cout << endl;
          cout << "Nama Bumil                : ";
          cout << bumilcek.namabumil;
          cout << endl;
          cout << "Usia Kehamilan (bulan)    : ";
          cout << bumilcek.usiahamil;
          cout << endl;
          cout << "Berat Bumil               : ";
          cout << bumilcek.beratbumil;
          cout << endl;
          cout << "Usia Bumil                : ";
          cout << bumilcek.usiabumil;
          cout << endl;
          cout << "Hari Prediksi Lahir (HPL) : ";
          cout << bumilcek.hplibTGL;
          cout << "/";
          cout << bumilcek.hplibBLN;
          cout << "/";
          cout << bumilcek.hplibTH;
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << endl;
          cout << endl;
      
      
          string tbdbm;
          int idxtbdbm = 0;
          ambilbdn.open("databidan.txt");
          while (!ambilbdn.eof()) {
            ambilbdn >> tbdbm;
            tokenizeBd(tbdbm, ";", idxtbdbm);
            idxtbdbm++;
          }
          ambilbdn.close();
        
      
      
          for (int y = 0; y < idxtbdbm - 1;y++ )
          {  
              if(bumilcek.usiahamil >= 1 && bumilcek.usiahamil <=3)
              {  
                  y = 0;
                  cout << "----------------------------------------------" << endl;
                  cout << "|\t\t\t  Fase Trimester 1\t\t\t\t | ";
                  cout << endl;
                  cout << "----------------------------------------------" << endl;
                  cout << "|\t Cek Kesehatan Berdasarkan Berat Badan \t |";
                  cout << endl;
                  cout << "----------------------------------------------" << endl;
                  cout << endl;
                  cout << "Bidan Yang Memeriksa ";
                  cout << endl;
                  cout << "----------------------------------------------" << endl;
                  cout << "NIP        : " << dataBidann[y].NIPn;
                     pohon.nomornya  =  dataBidann[y].NIPn; 
                  cout << endl;
                  cout << "Nama Bidan : " << dataBidann[y].namaBidann;
                    pohon.namanya = dataBidann[y].namaBidann;
                  cout << endl;
                  cout << "Alamat     : Jln " << dataBidann[y].jlnBidann;
                  cout << endl;
                  cout << "                 RT/RW     : " << dataBidann[y].rtBidann << "/"
                       << dataBidann[y].rwBidann;
                  cout << endl;
                  cout << "                 Kel/desa  : " << dataBidann[y].desaBidann;
                  cout << endl;
                  cout << "                 Kec       : " << dataBidann[y].kecBidann;
                  cout << endl;
                  cout << "                 Kab/Kota  : " << dataBidann[y].kabBidann;
                  cout << endl;
                  cout << "                 Provinsi  : " << dataBidann[y].provBidann;
                  cout << endl;
                  cout << "No hp      : " << dataBidann[y].noHpn;
                  cout << endl;
                  cout << "----------------------------------------------" << endl;
                  cout << endl;
                  cout << endl;
      
      
      
      
                  //tekan enter untuk melanjutkan
                  if(bumilcek.beratbumil < 50)
                  {
                    stts_sehat = "Kurang";
                  }
                  else if (bumilcek.beratbumil >= 50 && bumilcek.beratbumil <= 53)
                  {
                    stts_sehat = "Sehat";
                  }
                  else if (bumilcek.beratbumil > 53)
                  {
                    stts_sehat = "Berlebih";
                  }
                  break;
              }
                
              else if (bumilcek.usiahamil >= 4&& bumilcek.usiahamil <=6)
              {
                  y = 1;
                  cout << "----------------------------------------------" << endl;
                  cout << "|\t\t\t  Fase Trimester 2\t\t\t\t |";
                  cout << endl;
                  cout << "----------------------------------------------" << endl;
                  cout << "|\t Cek Kesehatan Berdasarkan Berat Badan \t |";
                  cout << endl;
                  cout << "----------------------------------------------" << endl;
                  cout << endl;
                  cout << "Bidan Yang Memeriksa ";
                  cout << endl;
                  cout << "----------------------------------------------" << endl;
                  cout << "NIP        : " << dataBidann[y].NIPn;
                    pohon.nomornya  =  dataBidann[y].NIPn; 
                  cout << endl;
                  cout << "Nama Bidan : " << dataBidann[y].namaBidann;
                pohon.namanya = dataBidann[y].namaBidann;
                  cout << endl;
                  cout << "Alamat     : Jln " << dataBidann[y].jlnBidann;
                  cout << endl;
                  cout << "                 RT/RW     : " << dataBidann[y].rtBidann << "/"
                       << dataBidann[y].rwBidann;
                  cout << endl;
                  cout << "                 Kel/desa  : " << dataBidann[y].desaBidann;
                  cout << endl;
                  cout << "                 Kec       : " << dataBidann[y].kecBidann;
                  cout << endl;
                  cout << "                 Kab/Kota  : " << dataBidann[y].kabBidann;
                  cout << endl;
                  cout << "                 Provinsi  : " << dataBidann[y].provBidann;
                  cout << endl;
                  cout << "No hp      : " << dataBidann[y].noHpn;
                  cout << endl;
                  cout << "----------------------------------------------" << endl;
                  cout << endl;
                  cout << endl;
      
      
                  //tekan enter untuk melanjutkan
                  if(bumilcek.beratbumil < 53)
                  {
                    stts_sehat = "Kurang";
                  }
                  else if (bumilcek.beratbumil >= 53 && bumilcek.beratbumil <= 55)
                  {
                    stts_sehat = "Sehat";
                  }
                  else if (bumilcek.beratbumil > 55)
                  {
                    stts_sehat = "Berlebih";
                  }
                  
                break;
              }
      
              else if (bumilcek.usiahamil >= 7 && bumilcek.usiahamil <=9)
              {
                  y = 2;
                  cout << "----------------------------------------------" << endl;
                  cout << "|\t\t\t  Fase Trimester 3\t\t\t\t |";
                  cout << endl;
                  cout << "----------------------------------------------" << endl;
                  cout << "|\t Cek Kesehatan Berdasarkan Berat Badan \t |";
                  cout << endl;
                  cout << "----------------------------------------------" << endl;
                  cout << endl;
                  cout << "Bidan Yang Memeriksa ";
                  cout << endl;
                  cout << "----------------------------------------------" << endl;
                  cout << "NIP        : " << dataBidann[y].NIPn;
                  pohon.nomornya  =  dataBidann[y].NIPn; 
                  cout << endl;
                  cout << "Nama Bidan : " << dataBidann[y].namaBidann;
                    pohon.namanya = dataBidann[y].namaBidann;
                  cout << endl;
                  cout << "Alamat     : Jln " << dataBidann[y].jlnBidann;
                  cout << endl;
                  cout << "                 RT/RW     : " << dataBidann[y].rtBidann << "/"
                       << dataBidann[y].rwBidann;
                  cout << endl;
                  cout << "                 Kel/desa  : " << dataBidann[y].desaBidann;
                  cout << endl;
                  cout << "                 Kec       : " << dataBidann[y].kecBidann;
                  cout << endl;
                  cout << "                 Kab/Kota  : " << dataBidann[y].kabBidann;
                  cout << endl;
                  cout << "                 Provinsi  : " << dataBidann[y].provBidann;
                  cout << endl;
                  cout << "No hp      : " << dataBidann[y].noHpn;
                  cout << endl;
                  cout << "----------------------------------------------" << endl;
                  cout << endl;
                  cout << endl;
      
      
                //tekan enter untuk melanjutkan
      
                if(bumilcek.beratbumil < 55)
                  {
                    stts_sehat = "Kurang";
                  }
                  else if (bumilcek.beratbumil >= 55 && bumilcek.beratbumil <= 58)
                  {
                    stts_sehat = "Sehat";
                  }
                  else if (bumilcek.beratbumil > 58)
                  {
                    stts_sehat = "Berlebih";
                  }
                break;
              }
          }
      
          if (stts_sehat == "Kurang")
          {
            cttn_sehat = "Perbanyak Makan-Makanan Yang Sehat Dan Bergizi\n" 
                         "Yaa Dan Juga Jangan Lupa Untuk Minum Susu Untuk\n"
                         "Menunjang Nutrisi Buah Hati DiKandungan. Ibu Harus\n" 
                         "Menghindari Hal Hal Kerja Berat, Merokok, Strees,\n" 
                         "Kelelahan dan lain. Namun Tetap Berolahraga Ringan\n" 
                         "Agar Sehat Dan Bugar.";
          }
          else if(stts_sehat == "Sehat")
          {
            cttn_sehat = "Tetap Menginsumsi Makanan Yang Bergizi Dan Minum\n" 
                         "Susu, Dan Tetap Berolahraga Ringan Saja Ya Bu.\n"
                         "Jangan Stres Dan Hindari Yang Merusak kesehatan\n"
                         "Kandungan, Seperti Asap\n Rokok Dan Kelelahan.";
          }
          else if (stts_sehat== "Berlebih")
          {
            cttn_sehat = "Perbanyak Mengonsumsi Buah Ya Bun, Jangan Stres\n"
                         "Dan Hindari Hal Yang Merusak Kandungan Seperti\n"
                         "Asap Rokok Dan Kelelahan.Tetap berolahraga Agar\n"
                         "Menjaga Kesehatan Bayi Dan Ibu.";
          }
      
          //disini
          ambildataLogin();
          // cout << endl;
          // cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << "|\t\t\t\t\t\t\t\t\t\t\t |" << endl;
          cout << "|\t\t\t  Posyandu Bahagia \t\t\t\t |";
          cout << endl;
          cout << "|\t\tHasil Pemeriksaan Bunda Hamil \t\t |";
          cout << endl;
          cout << "|\t\t\t\t\t\t\t\t\t\t\t |" << endl;
          cout << "----------------------------------------------" << endl;
          cout << endl;
      
          cout << "Penanggung Jawab " << endl;
          cout << "----------------------------------------------" << endl;
          cout << "| NIK                 : " << dataKTP.nik;
          cout << endl;
          cout << "| Nama                : " << dataKTP.nama;
          cout << endl;
          cout << "| TTL                 : " << dataKTP.tmptlahir << ","
               << dataKTP.tgllahir;
          cout << endl;
          cout << "| Jenis Kelamin       :  " << dataKTP.jklmn;
          cout << endl;
          cout << "| Gol. Darah          :  " << dataKTP.goldar;
          cout << endl;
          cout << "| Alamat              : Dusun " << dataKTP.dusun;
          cout << endl;
          cout << "| RT                  :  " << dataKTP.rt;
          cout << endl;
          cout << "| RW                  :  " << dataKTP.rw;
          cout << endl;
          cout << "| Desa                :  " << dataKTP.desa;
          cout << endl;
          cout << "| Kecamatan           :  " << dataKTP.kecamatan;
          cout << endl;
          cout << "| Kabupaten           :  " << dataKTP.kab;
          cout << endl;
          cout << "| Provinsi            :  " << dataKTP.prov;
          cout << endl;
          cout << "| Agama               :  " << dataKTP.agama;
          cout << endl;
          cout << "| Status Kawin        :  " << dataKTP.skawin;
          cout << endl;
          cout << "| Pekerjaan           :  " << dataKTP.pekerjaan;
          cout << endl;
          cout << "| Kewarganegaraan     :  " << dataKTP.knegara;
          cout << endl;
          cout << "| Berlaku Hingga      :  " << dataKTP.berhing;
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << endl;
          cout << "Berikut Hasil Pemeriksaan Ibu "<< bumilcek.namabumil;
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << "No Rekam Bumil            : ";
          cout << bumilcek.norekambumil;
          cout << endl;
          cout << "Nama Bumil                : ";
          cout << bumilcek.namabumil;
          cout << endl;
          cout << "Usia Kehamilan (bulan)    : ";
          cout << bumilcek.usiahamil;
          cout << endl;
          cout << "Berat Bumil               : ";
          cout << bumilcek.beratbumil;
          cout << endl;
          cout << "Usia Bumil                : ";
          cout << bumilcek.usiabumil;
          cout << endl;
          cout << "Hari Prediksi Lahir (HPL) : ";
          cout << bumilcek.hplibTGL;
          cout << "/";
          cout << bumilcek.hplibBLN;
          cout << "/";
          cout << bumilcek.hplibTH;
          cout << endl;
          cout << "Status Kesehatan          : " << stts_sehat;
          cout << endl;
          cout << endl;
          cout << "Catatan Kesehatan : ";
          cout << endl;
          cout << cttn_sehat;
          cout << endl;
          cout << "----------------------------------------------" << endl;


        ofstream catetbro;
        // int y;
        catetbro.open("datapohon.txt");
        catetbro << pohon.nomornya <<endl;
        catetbro << pohon.namanya <<endl;
        catetbro << bumilcek.norekambumil <<endl;
        catetbro << bumilcek.namabumil <<endl;
        catetbro << dataKTP.nik << endl;
        catetbro << dataKTP.nama;
        catetbro.close();
      
          ofstream catat;
          catat.open("bumilcek.txt");
          catat << " ";
          catat.close();
    }
  
    cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
    cin >> konfirmasi;
}


void User::riwayatPeriksa()
{  

  kelambi:
  string datafile[10];
  int indeks;
  ifstream take;
  take.open("datapohon.txt");

    if (!take.fail()) {
      indeks = 0;
      while (!take.eof()) {
        take >> datafile[indeks];
        indeks += 1;
      }
      take.close();
    } else {
      cout << "File tidak ditemukan" << endl;
    }


  //sedang mencoba
  //sek tak muleh
  BinaryTreeNode<string> x,y,z;
  x.data1 = datafile[0];
  x.data2 = datafile[1];
  y.data1 = datafile[2];
  y.data2 = datafile[3];
  z.data1 = datafile[4];
  z.data2 = datafile [5];
  x.LeftChild = &y;
	x.RightChild = &z;
	y.LeftChild = y.RightChild = z.LeftChild = z.RightChild = 0;
  system("clear");
  cout <<"----------------------------------------------" << endl;
  cout<< "|         Tampilan Dalam Bentuk Pohon        |";
  cout<<endl;
  cout <<"----------------------------------------------" << endl;
  // cout<<endl;
  cout<< "|\t\t\t\t====Bidan====                |";//dari sini 1579
  cout<<endl;
  cout<< "|\t\t\t\t||         ||                |";
  cout<<endl;
  cout<< "|\t\t\t\tVV         VV                |";
  cout<<endl;
  cout<< "|\t\t\t   Bumil    P.jawab              |";
  cout<<endl;
  cout <<"----------------------------------------------" << endl;
  // cout<< "\t||                   ||";
  // cout<<endl;
  // cout<< "\tVV                   VV";
  // cout<<endl;
  cout<<endl;
  cout <<"----------------------------------------------" << endl;
  cout <<"|               Kunjungi Secara              |";
  cout<<endl;
  cout <<"----------------------------------------------" << endl;
  cout <<"|   1.) Pre-Order                            |";
  cout<<endl;
  cout <<"|   2.) In-Order                             |";
  cout<<endl;
  cout <<"|   3.) Post-Order                           |";
  cout<<endl;
  cout <<"----------------------------------------------" << endl;
  cout <<"Masukkan Pilihan Anda[1/2/3] : ";
  int pilihaannn;
  cin>>pilihaannn;
  cout<<endl;

  cout<<endl;
  switch(pilihaannn)
  {
    case 1 :
      cout << "Kunjungan Preorder   : ";
      cout<<endl;
	    PreOrder(&x);
    	cout << endl;
      break;
    case 2 :
      cout << "Kunjungan InOrder    : "<<endl;
	    InOrder(&x);
    	cout << endl;
      break;
    case 3 : 
      cout << "Kunjungan Postorder  : "<<endl;
      cout<<endl;
	    PostOrder(&x);
    	cout << endl;
      break;
    default:
    cout<< "pilihan tidak ada, Silahkan pilih kembali "<<endl;
    goto kelambi;
      
    
  }
  // system("clear");
	
	
	

  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirmasi;
  
}


void User::tampildataIBU_Hamil() {
  int idxIB = 0;
  string tIB;
  ambildataIBU_HAMIL.open("dataIbu_Hamil.txt");
  while (!ambildataIBU_HAMIL.eof()) {
    ambildataIBU_HAMIL >> tIB;
    tokenizeIBHML(tIB, ";", idxIB);
    idxIB++;
    // X.ReSize(idx);
  }
  ambildataIBU_HAMIL.close();

  system("clear");
  cout << "Berikut Data Ibu Hamil Yang Tersedia..";
  cout << endl;
  
  for (int h = 0; h < idxIB - 1; h++) {
    // cout << Aibhml[h].Anamaib_hamil;

    cout << "----------------------------------------------" << endl;
    cout << "No Rekam Bumil            : ";
    cout << Aibhml[h].Anorekamib_hamil;
    cout << endl;
    cout << "Nama Bumil                : ";
    cout << Aibhml[h].Anamaib_hamil;
    cout << endl;
    cout << "Usia Kehamilan (bulan)    : ";
    cout << Aibhml[h].Ausiakehamilan;
    cout << endl;
    cout << "Berat Bumil               : ";
    cout << Aibhml[h].Aberatib_hamil;
    cout << endl;
    cout << "Usia Bumil                : ";
    cout << Aibhml[h].Ausiaib_hamil;
    cout << endl;
    cout << "Hari Prediksi Lahir (HPL) : ";
    cout << Aibhml[h].Ahplib_TGL;
    cout << "/";
    cout << Aibhml[h].Ahplib_BLN;
    cout << "/";
    cout << Aibhml[h].Ahplib_TH;
    cout << endl;

    cout << "----------------------------------------------" << endl;

    // buat for
  }
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirmasi;

  // buat
}

void User::tampilAntrianblt() {
  //  cout << " antri cok " << endl;

  // cout << "----------------------------------------------" << endl;
  // cout << "Antrian Kosong...";
  // cout <<endl;
  // cout << "----------------------------------------------" << endl;
  // cout << endl;

  int qidxx = 0;
  string qt;
  ambilantribal.open("balitaantri.txt");
  while (!ambilantribal.eof()) {
    ambilantribal >> qt;
    tokenizeQueBlt(qt, ";", qidxx);
    qidxx++;
    // X.ReSize(idx);
  }
  ambilantribal.close();
  

  for (int i = 0; i < qidxx - 1; i++) {

    cout << "----------------------------------------------" << endl;
    cout << " No Rekam Medis    : " << queblt[i].norekam;
    cout << endl;
    cout << " Nama Balita       : " << queblt[i].namaBalita;
    cout << endl;
    cout << " Nama Ibu          : " << queblt[i].ibu;
    cout << endl;
    cout << " Tinggi Balita     : " << queblt[i].tinggi;
    cout << endl;
    cout << " Berat Balita      : " << queblt[i].berat;
    cout << endl;
    cout << " Umur Balita       : " << queblt[i].umur << endl;
    cout << "----------------------------------------------" << endl;
  }

  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirmasi;
}

void User::tulisdate(int bayar) {
  cout << " Masukkan Tanggal : ";
  cin >> hisIn.htgl;
  cout << " Masukkan Bulan   : ";
  cin >> hisIn.hbln;
  cout << " Masukkan Tahun   : ";
  cin >> hisIn.hthn;
  hisIn.htotal = bayar;

  // cek
  // cout << hisIn.htgl << ";" << hisIn.hbln << ";" << hisIn.hthn << ";" <<
  // hisIn.htotal; cout << endl;
  tulishistory.open("tulishistory.txt", ios::app);
  if (!tulishistory.fail()) {

    tulishistory << hisIn.htgl << ";" << hisIn.hbln << ";" << hisIn.hthn << ";"
                 << hisIn.htotal;
    tulishistory << endl;

    tulishistory.close();
    // cout << "Sukses" << endl;
  } else {
    // cout << "Error!!!! ";
  }
}



void User::cekKesehatan() {

  int idxx = 0;
  string t;
  ambil.open("dataBalita.txt");
  while (!ambil.eof()) {
    ambil >> t;
    tokenizeBlt(t, ";", idxx);
    idxx++;
    // X.ReSize(idx);
  }
  ambil.close();

  system("clear");
  cout << endl;
  cout << endl;
  cout << "Daftar Data Balita Posyandu Bahagia..." << endl;
  for (int i = 0; i < idxx - 1; i++) {
    cout << "----------------------------------------------" << endl;
    cout << " No Rekam Medis    : " << blt[i].norekam;
    cout << endl;
    cout << " Nama Balita       : " << blt[i].namaBalita;
    cout << endl;
    cout << " Nama Ibu          : " << blt[i].ibu;
    cout << endl;
    cout << " Tinggi Balita     : " << blt[i].tinggi;
    cout << endl;
    cout << " Berat Balita      : " << blt[i].berat;
    cout << endl;
    cout << " Umur Balita       : " << blt[i].umur << endl;
    cout << "----------------------------------------------" << endl;
  }

  string carnama;
  bool ditemukan = false;
  cout << endl;
  cout << "----------------------------------------------" << endl;
  cout << "Cek Kesehatan Atas Nama  : ";
  cin >> carnama;
  cout << "----------------------------------------------" << endl;
  system("clear");
  int datake;
  tulistod.open("balitaantri.txt", ios ::app);
  for (int i = 0; i < idxx - 1; i++) {
    if (carnama == blt[i].namaBalita) {
      ditemukan = true;
      datake = i;
      tertemu = true;
      temu = datake;
      // noblt = datake;
      break;
    }
  }
  if (ditemukan == true) {
    for (int j = 0; j < idxx - 1; j++) {
      if (j == datake) {

        cout << "----------------------------------------------" << endl;
        cout << "Balita Atas Nama " << blt[j].namaBalita
             << " Telah DiMasukkan Kedalam Antrian";
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << endl;
        tulistod << blt[j].norekam << ";" << blt[j].namaBalita << ";"
                 << blt[j].ibu << ";" << blt[j].tinggi << ";" << blt[j].berat
                 << ";" << blt[j].umur << endl;
        // tulis.close();
        // break;
      }
    }
    // tulis.close();
  }
  tulistod.close();

  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirmasi;
}




void User::cekKesehatan2() {

  string brtsehat;
  string tgisehat;
  string ratabrt;
  string ratatgi;
  string catatanbrt;
  string catatantgi;
  // ambilbalcek();
  string tsd;
  ambil.open("balitacek.txt");
  while (!ambil.eof()) {
    ambil >> tsd;
    tokenizebalcek(tsd, ";");
    // idxe++;
  }

  ambil.close();
  if (balcek.namaBalitabal == "") {
    system("clear");
    cout << "----------------------------------------------";
    cout << endl;
    cout << "Pengecekan Belum Dilaksanakan Tunggu Sebentar";
    cout << endl;
    cout << "Silahkan Menunggu Admin Akan Memprosesnya...";
    cout << endl;
    cout << "----------------------------------------------";
    cout << endl;

    cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
    cin >> konfirmasi;

  } else {

    cout << endl;
    cout << "Balita Yang Di Cek..." << endl;
    cout << "----------------------------------------------" << endl;
    cout << "No Rekam Medis  : " << balcek.Norekam;
    cout << endl;
    cout << "Nama Balita     : " << balcek.namaBalitabal;
    cout << endl;
    cout << "Nama Ibu        : " << balcek.ibubal;
    cout << endl;
    cout << "Tinggi          : " << balcek.tinggibal;
    cout << endl;
    cout << "Berat           : " << balcek.beratbal;
    cout << endl;
    cout << "Umur            : " << balcek.umurbal;
    cout << endl;
    cout << "----------------------------------------------" << endl;

    string tt;
    int idxt = 0;
    ambilbdn.open("databidan.txt");
    while (!ambilbdn.eof()) 
    {
      ambilbdn >> tt;
      tokenizeBd(tt, ";", idxt);
      idxt++;
    }
    ambilbdn.close();

    for (int n = 0; n < idxt - 1; n++) {
      if (n == 0) {
        cout << endl;
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << "|\t\t\tCek Kesehatan Pertama\t\t\t | ";
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << "|\t\t\t\tCek Berat Badan \t\t\t |";
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << endl;
        cout << "Bidan Yang Memeriksa ";
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << "NIP        : " << dataBidann[n].NIPn;
        cout << endl;
        cout << "Nama Bidan : " << dataBidann[n].namaBidann;
        cout << endl;
        cout << "Alamat     : Jln " << dataBidann[n].jlnBidann;
        cout << endl;
        cout << "                 RT/RW     : " << dataBidann[n].rtBidann << "/"
             << dataBidann[n].rwBidann;
        cout << endl;
        cout << "                 Kel/desa  : " << dataBidann[n].desaBidann;
        cout << endl;
        cout << "                 Kec       : " << dataBidann[n].kecBidann;
        cout << endl;
        cout << "                 Kab/Kota  : " << dataBidann[n].kabBidann;
        cout << endl;
        cout << "                 Provinsi  : " << dataBidann[n].provBidann;
        cout << endl;
        cout << "No hp      : " << dataBidann[n].noHpn;
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << endl;
        cout << endl;

        if (balcek.umurbal >= 1 || balcek.umurbal <= 2) 
        {
          ratabrt = "8.9 - 12.2 Kg";
          if (balcek.beratbal < 8.9) 
          {
            brtsehat = "Kurang";
          }

          else if (balcek.beratbal >= 8.9 || balcek.beratbal <= 12.2) 
          {
            brtsehat = "Sehat";

          }

          else if (balcek.beratbal > 12.2) 
          {
            brtsehat = "Berlebih";
          }

        }

        else if (balcek.umurbal >= 2 || balcek.umurbal <= 3) 
        {
          ratabrt = "11.5 - 14.3 Kg";
          if (balcek.beratbal < 11.5) 
          {
            brtsehat = "Kurang";
          }

          else if (balcek.beratbal >= 11.5 || balcek.beratbal <= 14.3) 
          {
            brtsehat = "Sehat";

          }

          else if (balcek.beratbal > 14.3)
          {
            brtsehat = "Berlebih";
          }
        }

        else if (balcek.umurbal >= 3 || balcek.umurbal <= 4) 
        {
          ratabrt = "14.3 - 15.8 Kg";
          if (balcek.beratbal < 14.3) 
          {
            brtsehat = "Kurang";
          }

          else if (balcek.beratbal >= 14.3 || balcek.beratbal <= 15.8) 
          {
            brtsehat = "Sehat";

          }

          else if (balcek.beratbal > 15.8) 
          {
            brtsehat = "Berlebih";
          }
        }

        else if (balcek.umurbal >= 4 || balcek.umurbal <= 5) 
        {
          ratabrt = "15.8 - 17.8 Kg";
          if (balcek.beratbal < 15.8) 
          {
            brtsehat = "Kurang";
          }

          else if (balcek.beratbal >= 15.8 || balcek.beratbal <= 17.8) 
          {
            brtsehat = "Sehat";

          }

          else if (balcek.beratbal > 17.8) 
          {
            brtsehat = "Berlebih";
          }
        }
        cout << "Berat Dan Kesehatan Balita..." << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Rata-Rata Berat Di Umur Balita : " << ratabrt;
        cout << endl;
        cout << "Status Kesehatan Berat Badan   : " << brtsehat;
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << endl;
      } else if (n == 1) {
        cout << endl;
        cout << "\nTekan Enter Untuk Cek Kesehatan Kedua ⏎ ";
        cin.ignore();
        getchar();
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << "|\t\t\tCek kesehatan Kedua\t\t\t\t |";
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << "|\t\t\t  Cek Tinggi Badan\t\t\t\t |";
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << endl;
        cout << "Bidan Yang Memeriksa ";
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << "NIP        : " << dataBidann[n].NIPn;
        cout << endl;
        cout << "Nama Bidan : " << dataBidann[n].namaBidann;
        cout << endl;
        cout << "Alamat     : Jln " << dataBidann[n].jlnBidann;
        cout << endl;
        cout << "                 RT/RW     : " << dataBidann[n].rtBidann << "/"
             << dataBidann[n].rwBidann;
        cout << endl;
        cout << "                 Kel/desa  : " << dataBidann[n].desaBidann;
        cout << endl;
        cout << "                 Kec       : " << dataBidann[n].kecBidann;
        cout << endl;
        cout << "                 Kab/Kota  : " << dataBidann[n].kabBidann;
        cout << endl;
        cout << "                 Provinsi  : " << dataBidann[n].provBidann;
        cout << endl;
        cout << "No hp      : " << dataBidann[n].noHpn;
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << endl;
        cout << endl;

        if (balcek.umurbal >= 1 || balcek.umurbal <= 2) 
        {
          ratatgi = "74-87cm";
          if (balcek.tinggibal < 74) 
          {
            tgisehat = "Kurang";
          }

          else if (balcek.tinggibal >= 74 || balcek.tinggibal <= 87) 
          {
            tgisehat = "Sehat";

          }

          else if (balcek.tinggibal > 87) 
          {
            tgisehat = "Berlebih";
          }

        }

        else if (balcek.umurbal >= 2 || balcek.umurbal <= 3) 
        {
          ratatgi = "87-96cm";
          if (balcek.tinggibal < 87) 
          {
            tgisehat = "Kurang";
          }

          else if (balcek.tinggibal >= 87 || balcek.tinggibal <= 96) 
          {
            tgisehat = "Sehat";

          }

          else if (balcek.tinggibal > 96) 
          {
            tgisehat = "Berlebih";
          }
        }

        else if (balcek.umurbal >= 3 || balcek.umurbal <= 4) 
        {
          ratatgi = "96-103cm";
          if (balcek.tinggibal < 96)
          {
            tgisehat = "Kurang";
          }

          else if (balcek.tinggibal >= 96 || balcek.tinggibal <= 103) 
          {
            tgisehat = "Sehat";

          }

          else if (balcek.tinggibal > 103) 
          {
            tgisehat = "Berlebih";
          }
        }

        else if (balcek.umurbal >= 4 || balcek.umurbal <= 5) 
        {
          ratatgi = "103-110cm";
          if (balcek.tinggibal < 103)
          {
            tgisehat = "Kurang";
          }

          else if (balcek.tinggibal >= 103 || balcek.tinggibal <= 110)
          {
            tgisehat = "Sehat";

          }

          else if (balcek.tinggibal > 110) {
            tgisehat = "Berlebih";
          }
        }
        cout << "Tinggi Dan Kesehatan Balita...";
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Tinggi Balita Rata-Rata Sesuai Umur : " << ratatgi;
        cout << endl;
        cout << "Status Kesehatan Tinggi Badan       : " << tgisehat;
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << endl;
      } else if (n == 2) {
        cout << endl;
        cout << "\nTekan Enter Untuk Cek Kesehatan Ketiga ⏎ ";
        cin.ignore();
        getchar();
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << "|\t\t\tCek Kesehatan Ketiga\t\t\t |";
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << "|  Penyuluhan Dan Pencetakan Buku Posyandu\t |";
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << endl;
        cout << "Bidan Yang Bertanggung Jawab ";
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << "NIP        : " << dataBidann[n].NIPn;
        cout << endl;
        cout << "Nama Bidan : " << dataBidann[n].namaBidann;
        cout << endl;
        cout << "Alamat     : Jln " << dataBidann[n].jlnBidann;
        cout << endl;
        cout << "                 RT/RW     : " << dataBidann[n].rtBidann << "/"
             << dataBidann[n].rwBidann;
        cout << endl;
        cout << "                 Kel/desa  : " << dataBidann[n].desaBidann;
        cout << endl;
        cout << "                 Kec       : " << dataBidann[n].kecBidann;
        cout << endl;
        cout << "                 Kab/Kota  : " << dataBidann[n].kabBidann;
        cout << endl;
        cout << "                 Provinsi  : " << dataBidann[n].provBidann;
        cout << endl;
        cout << "No hp      : " << dataBidann[n].noHpn;
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << endl;

        if (brtsehat == "Kurang") 
        {

          catatanbrt =
              "Konsumsilah Makanan Yang Bergizi Dan Sangat\nDisarankan Untuk "
              "Minum Vitamin Penambah Nafsu Makan\n";

        } 
        else if (brtsehat == "Sehat")
        {

          catatanbrt = "Tetap Jaga Pola Makan Dengan Mengonsumsi Makanan\nYang "
                       "Bergizi Yaa Dan Juga Jangan Lupa Untuk Berolahraga\n";

        } 
        else if (brtsehat == "Berlebih") 
        {

          catatanbrt = "Perbanyak Mengonsumsi Buah\nDan Juga Ajak Anak "
                       "Berolahraga Yaa\n";

        } 
        else 
        {
          cout << "-";
        }

        if (tgisehat == "Kurang") 
        {

          catatantgi = "Konsumsilah Makanan Yang Bergizi Untuk\nMenambah "
                       "Tinggi Badan Seperti Ikan, Telur Dan Lain-Lain\n";

        }
        else if (tgisehat == "Sehat") 
        {

          catatantgi = "Tetap Jaga Pola Makan Dengan Mengonsumsi\nMakanan Yang "
                       "Bergizi Dan Juga Minum Vitamin Yaa\n";

        } 
        else if (tgisehat == "Berlebih") 
        {

          catatantgi = "Tidak Apa Apa Yaa, Mungkin Dari Faktor\nGenetik "
                       "Sehingga Anak Tumbuh Lebih Tinggi Dari Rata-Rata\n";
        }

        cout << "Catatan Kesehatan Balita Atas Nama : ";
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Nama Balita     : " << balcek.namaBalitabal;
        cout << endl;
        cout << "Nama Ibu        : " << balcek.ibubal;
        cout << endl;
        cout << "Tinggi          : " << balcek.tinggibal;
        cout << endl;
        cout << "Berat           : " << balcek.beratbal;
        cout << endl;
        cout << "Umur            : " << balcek.umurbal;
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << endl;
        cout << endl;
        cout << "Catatan Berdasarkan Data Berat Badan...";
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << catatanbrt;
        cout << "----------------------------------------------" << endl;
        cout << endl;
        cout << endl;
        cout << "Catatan Berdasarkan Data Tinggi Badan...";
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << catatantgi;
        cout << "----------------------------------------------" << endl;
      }
    }

    // ambilkode();
    cout << "\nTekan Enter Untuk Melihat Buku Posyandu ⏎ ";
    cin.ignore();
    getchar();
    system("clear");

    if (balcek.Norekam == 0)
    {
      ambilkode();
      balcek.Norekam = kodemedis;
      kodemedis++;
    }
    ambildataLogin();
    cout << endl;
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "|\t\t\t\t\t\t\t\t\t\t\t |" << endl;
    cout << "|\t\t\t  Posyandu Bahagia \t\t\t\t |";
    cout << endl;
    cout << "|\t\t\tBuku Posyandu Bahagia \t\t\t |";
    cout << endl;
    cout << "|\t\t\t\t\t\t\t\t\t\t\t |" << endl;
    cout << "----------------------------------------------" << endl;
    cout << endl;

    cout << "Penanggung Jawab " << endl;
    cout << "----------------------------------------------" << endl;
    cout << "| NIK                 : " << dataKTP.nik;
    cout << endl;
    cout << "| Nama                : " << dataKTP.nama;
    cout << endl;
    cout << "| TTL                 : " << dataKTP.tmptlahir << ","
         << dataKTP.tgllahir;
    cout << endl;
    cout << "| Jenis Kelamin       :  " << dataKTP.jklmn;
    cout << endl;
    cout << "| Gol. Darah          :  " << dataKTP.goldar;
    cout << endl;
    cout << "| Alamat              : Dusun " << dataKTP.dusun;
    cout << endl;
    cout << "| RT                  :  " << dataKTP.rt;
    cout << endl;
    cout << "| RW                  :  " << dataKTP.rw;
    cout << endl;
    cout << "| Desa                :  " << dataKTP.desa;
    cout << endl;
    cout << "| Kecamatan           :  " << dataKTP.kecamatan;
    cout << endl;
    cout << "| Kabupaten           :  " << dataKTP.kab;
    cout << endl;
    cout << "| Provinsi            :  " << dataKTP.prov;
    cout << endl;
    cout << "| Agama               :  " << dataKTP.agama;
    cout << endl;
    cout << "| Status Kawin        :  " << dataKTP.skawin;
    cout << endl;
    cout << "| Pekerjaan           :  " << dataKTP.pekerjaan;
    cout << endl;
    cout << "| Kewarganegaraan     :  " << dataKTP.knegara;
    cout << endl;
    cout << "| Berlaku Hingga      :  " << dataKTP.berhing;
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << endl;
    cout << "Buku Posyandu Balita Atas Nama..." << endl;
    cout << "----------------------------------------------" << endl;
    cout << "No Rekam Medis        : " << balcek.Norekam;
    cout << endl;
    cout << "Nama Balita           : " << balcek.namaBalitabal;
    cout << endl;
    cout << "Nama Ibu              : " << balcek.ibubal;
    cout << endl;
    cout << "Tinggi                : " << balcek.tinggibal;
    cout << endl;
    cout << "Berat                 : " << balcek.beratbal;
    cout << endl;
    cout << "Umur                  : " << balcek.umurbal;
    cout << endl;
    cout << "Status Berat Badan    : " << brtsehat;
    cout << endl;
    cout << "Status Tinggi Badan   : " << tgisehat;
    cout << endl;
    cout << endl;
    cout << "Catatan Berat Badan   : ";
    cout << endl;
    cout << catatanbrt;
    cout << endl;
    cout << "Catatan Tinggi Badan  : ";
    cout << endl;
    cout << catatantgi;
    cout << "----------------------------------------------" << endl;

    tulis.open("kode.txt");
    tulis << kodemedis;
    tulis.close();

    tulis.open("balitacek.txt");
    tulis << "";
    tulis.close();
    cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
    cin >> konfirmasi;
  }
}

void User::tulisdatamedis() {
  int idxx = 0;
  string t;
  ambil.open("dataBalita.txt");
  while (!ambil.eof()) {
    ambil >> t;
    tokenizeBlt(t, ";", idxx);
    idxx++;
    // X.ReSize(idx);
  }
  ambil.close();

  tulis.open("dataBalita.txt");
  for (int v = 0; v < idxx - 1; v++) 
  {
    if (v == temu) 
    {
      blt[v].norekam = balcek.Norekam;
      tulis << blt[v].norekam << ";" << blt[v].namaBalita << ";" << blt[v].ibu
            << ";" << blt[v].tinggi << ";" << blt[v].berat << ";" << blt[v].umur
            << endl;
    } else 
    {
      tulis << blt[v].norekam << ";" << blt[v].namaBalita << ";" << blt[v].ibu
            << ";" << blt[v].tinggi << ";" << blt[v].berat << ";" << blt[v].umur
            << endl;
    }
  }
}

void User::MenuTampilData() {

  cout << endl;
  cout << "|--------------Menu Data Balita---------------|" << endl;
  cout << "|\t\t\t\t\t\t\t\t\t\t\t  |";
  cout << endl;
  cout << "|---------------------------------------------|" << endl;
  cout << "| Menu Tampil Data Balita\t\t\t\t\t  |";
  cout << endl;
  cout << "|---------------------------------------------|" << endl;
  cout << "| 1. Secara Dinamis\t\t\t\t\t\t\t  |";
  cout << endl;
  cout << "| 2. Pakai Linklist\t\t\t\t\t\t\t  |";
  cout << endl;
  cout << "| 3. Keluar \t\t\t\t\t\t\t\t  |";
  cout << endl;
  cout << "|\t\t\t\t\t\t\t\t\t\t\t  |";
  cout << endl;
  cout << "|--------------Menu Data Balita---------------|" << endl;
  cout << "Masukkan Pilihan[1/2/3] : ";
  cin >> pilihtampil;
}

void User::ambildataLogin() {

  // ifstream ambil;

  // idxe = 0;
  string t;
  ambil.open("dataLogin.txt");
  while (!ambil.eof()) {
    ambil >> t;
    tokenizez(t, ";");
    // idxe++;
  }
  ambil.close();
}

void User ::TampilBalitaDinamis() {
  cout << "Berikut Daftar Data Balita Dinamis...";
  ambildataDinamisBlt();
  cout << G << endl;
  cout << "Rata-Rata Berat Badan  : " << rata2;
  cout << endl;
  cout << "Rata-Rata Tinggi Badan : " << rata1;
  cout << endl;
  cout << "----------------------------------------------" << endl;
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirmasi;
}

void User::Menu() {
  cout << endl;
  cout << "|------------------Menu User------------------|" << endl;
  cout << "|\t\t\t\t\t\t\t\t\t\t\t  |" << endl;
  cout << "|---------------------------------------------|" << endl;
  cout << "| Main Menu User Posyandu Bahagia\t\t\t  |";
  cout << endl;
  cout << "|---------------------------------------------|" << endl;
  cout << "| 1.  Lihat Data Balita\t\t\t\t\t\t  |";
  cout << endl;
  cout << "| 2.  Beli Vaksin Dan Obat\t\t\t\t\t  |";
  cout << endl;
  cout << "| 3.  Cek kesehatan Balita\t\t\t\t\t  |";
  cout << endl;
  cout << "| 4.  Lihat Antrian Pemeriksaan Balita\t\t  |";
  cout << endl;
  cout << "| 5.  Cek Balita Yang Telah Di Periksa\t\t  |";
  cout << endl;
  cout << "| 6.  Lihat Data Ibu Hamil\t\t\t\t\t  |";
  cout << endl;
  cout << "| 7.  Cek kesehatan Ibu Hamil\t\t\t\t  |";
  cout << endl;
  cout << "| 8.  Lihat Antrian Pemeriksaan Ibu Hamil\t  |";
  cout << endl;
  cout << "| 9.  Cek Ibu Hamil Yang Telah Di Periksa\t  |";
  cout << endl;
  cout << "| 10. Lihat Riwayat Periksa\t\t\t\t\t  |";
  cout << endl;
  cout << "| 11. Lihat Pengumuman\t\t\t\t\t\t  |";
  cout << endl;
  cout << "| 0.  Keluar \t\t\t\t\t\t\t\t  |";
  cout << endl;
  cout << "|\t\t\t\t\t\t\t\t\t\t\t  |" << endl;
  cout << "|------------------Menu User------------------|" << endl;
  cout << "Masukkan Pilihan[1/2/3//4/5/6/7/8/9/10/11/0] : ";
  cin >> pilihusr;
}

void User::tampil() {
  //   ambildataLogin();
  //   cout << endl;
  //   // nikbeli = dataKTP.nik;
  // cout<< "testing "<<endl;
  //   cout << dataKTP.tmptlahir <<endl;
  //   cout << dataKTP.tgllahir << endl;
  cout << "-------------Vaksin Yang Tersedia-------------" << endl;
  ambildatabrg();
  for (int i = 0; i < idx - 1; i++) {
    cout << "----------------------------------------------" << endl;
    cout << "ID Vaksin    : " << brgg[i].id;
    cout << endl;
    cout << "Nama Vaksin  : " << brgg[i].nama;
    cout << endl;
    cout << "Stok Vakin   : " << brgg[i].stok;
    cout << endl;
    cout << "Harga Vaksin : " << brgg[i].harga;
    cout << endl;
    cout << "----------------------------------------------" << endl;
  }
}

void User::tampilObt() {
  //   ambildataLogin();
  //   cout << endl;
  //   // nikbeli = dataKTP.nik;
  // cout<< "testing "<<endl;
  //   cout << dataKTP.tmptlahir <<endl;
  //   cout << dataKTP.tgllahir << endl;
  system("clear");
  cout << "-------------Obat Yang Tersedia-------------" << endl;
  ambildataobt();
  for (int i = 0; i < idx - 1; i++) {
    cout << "----------------------------------------------" << endl;
    cout << "ID Obat      : " << obt[i].id;
    cout << endl;
    cout << "Nama Obat    : " << obt[i].nama;
    cout << endl;
    cout << "Stok Obat    : " << obt[i].stok;
    cout << endl;
    cout << "Harga Obat   : " << obt[i].harga;
    cout << endl;
    cout << "----------------------------------------------" << endl;
  }
}

void User::Beli() {
  int choice;
  ambildataLogin();
daftar:
  // pilihan nanti mau obat atau vaksin
  system("clear");
  cout << "----------------------------------------------" << endl;
  cout << "|\t  Silahkan Beli Yang Anda Butuhkan\t\t |";
  cout << endl;
  cout << "----------------------------------------------" << endl;
  cout << "| 1. Vaksin \t\t\t\t\t\t\t\t |";
  cout << endl;
  cout << "| 2. Obat \t\t\t\t\t\t\t\t\t |";
  cout << endl;
  cout << "----------------------------------------------" << endl;
  cout << "Masukkan Pilihan [1/2] : ";
  cin >> choice;
  if (choice == 1) {
    system("clear");
    tampil();
    int jumlah;
    string masuk;
    bool ketemu;
    int datake;
    cout << endl;
    cout << "Masukkan ID Vaksin Yang Ingin Di Beli  : ";
    cin >> masuk;
    for (int i = 0; i < idx - 1; i++) {
      if (masuk == brgg[i].id) {
        ketemu = true;
        datake = i;
        break;
      }
    }
    // nik , if
    if (ketemu) {
      cout << "Masukkan Jumlah Yang Ingin di Beli     : ";
      cin >> jumlah;
      cout << "----------------------------------------------" << endl;
      brgg[datake].stok = brgg[datake].stok - jumlah;
      int total = brgg[datake].harga * jumlah;
      tulis.open("data.txt");
      for (int i = 0; i < idx - 1; i++) 
      {
        tulis << brgg[i].id << ";" << brgg[i].nama << ";" << brgg[i].stok << ";"
              << brgg[i].harga << endl;
      }
      tulis.close();

      tulis.open("daftarBelanja.txt", ios::app);
      for (int i = 0; i < idx - 1; i++) 
      {
        if (i == datake) 
        {

          tulis << brgg[i].id << ";" << brgg[i].nama << ";" << brgg[i].stok
                << ";" << brgg[i].harga << ";" << jumlah << ";" << total
                << endl;
        }
      }
      tulis.close();
    }
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Barang Anda Berhasil Di Tambah Ke Keranjang... ";
    cout << endl;
    cout << "----------------------------------------------" << endl;
  }

  else if (choice == 2)
  {
    tampilObt();
    int jumlah;
    string masuk;
    bool ketemu;
    int datake;
    cout << endl;
    cout << "Masukkan ID Obat Yang Ingin Di Beli  : ";
    cin >> masuk;
    for (int i = 0; i < idx - 1; i++) 
    {
      if (masuk == obt[i].id)
      {
        ketemu = true;
        datake = i;
        break;
      }
    }
    // nik , if
    if (ketemu)
    {
      cout << "Masukkan Jumlah Yang Ingin di Beli   : ";
      cin >> jumlah;
      cout << "----------------------------------------------" << endl;
      obt[datake].stok = obt[datake].stok - jumlah;
      int total = obt[datake].harga * jumlah;
      tulis.open("dataobat.txt");
      for (int i = 0; i < idx - 1; i++)
        {
        tulis << obt[i].id << ";" << obt[i].nama << ";" << obt[i].stok << ";"
              << obt[i].harga << endl;
      }
      tulis.close();

      tulis.open("daftarBelanja.txt", ios::app);
      for (int i = 0; i < idx - 1; i++) 
      {
        if (i == datake) 
        {

          tulis << obt[i].id << ";" << obt[i].nama << ";" << obt[i].stok << ";"
                << obt[i].harga << ";" << jumlah << ";" << total << endl;
        }
      }
      tulis.close();
    }
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Barang Anda Berhasil Di Tambah Ke Keranjang... ";
    cout << endl;
    cout << "----------------------------------------------" << endl;
  }
}
// break;

// tampil();
// ambildataLogin();

// char p;
// cout << "Apakah Anda Ingin Belanja Lagi? [y/n] : ";
// cin >> p;
// if (p == 'y' || p == 'Y')
// {
//     goto daftar;
// }

void User::lihat() 
{
  ambildatabeli();
  // int totbayar;
  totbayar = 0;
  for (int i = 0; i < idx - 1; i++) 
  {
    Transaksi transaksiN(brggu[i].id, brggu[i].nama, brggu[i].stok,
                         brggu[i].harga, brggu[i].jumlah, brggu[i].total);
    totbayar += brggu[i].total;
    x.sisipBelakang(transaksiN);
  }
  cout << endl;
  cout << "--------Berikut Keranjang Belanja Dari--------";
  cout << endl;
  // nikbeli = dataKTP.nik;
  // for (int i = 1; i < idxe-1; i++) {
  //   if (nikbeli == dataKTP[i].nik) {
  //     cout << "NIK : "<< dataKTP[i].nik << endl;
  //     }
  //   }
  cout << endl;
  cout << "                            Tn/ny : " << dataKTP.nama;
  cout << endl;
  cout << "----------------------------------------------" << endl;
  cout << "ID \tNAMA BARANG\t    HARGA\tJUMLAH\t TOTAL ";
  cout << endl;
  cout << "----------------------------------------------" << endl;
  cout << x;
  cout << "----------------------------------------------" << endl << endl;
  cout << "Total Belanjaan Yang Harus DiBayar : " << totbayar;
  cout << endl;
  cout << "\n";
  cout << "----------------------------------------------" << endl;
  cout << "Lakukan Pembayaran Dan Cetak Invoice... ";
  cout << endl;
  cout << "Tekan Enter Untuk Lanjut ⏎ ";
  getchar();
  cout << "----------------------------------------------" << endl;
  cetakinvoice();
  tulisdate(totbayar);
}

void User::cetakinvoice() {
  cout << "\n";
pembayaran:
  cout << "Masukkan Jumlah Bayar Anda : ";
  cin >> jumbayar;
  cout << "----------------------------------------------" << endl;
  cout << endl;
  cout << "----------------------------------------------" << endl;
  cout << "\t\t\t Pembayaran Berhasil ";
  cout << endl;
  cout << "\t\t Terima Kasih Telah Berbelanja";
  cout << endl;
  cout << "----------------------------------------------" << endl;
  cout << "Enter Untuk Liat Struck Belanja ⏎ ";
  cin.ignore();
  getchar();
  system("clear");

  if (jumbayar < totbayar) {
    cout << "Uang Anda Tidak Cukup, Silahkan Coba Lagi!";
    cout << endl;
    cout << "----------------------------------------------" << endl;
    goto pembayaran;
  } else {
    cout << "----------------------------------------------" << endl;
    tulis.open("struck.txt");
    tulis << "----------------------------------------------" << endl;
    tulis << "|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t |" << endl;
    tulis << "|\t\t\t\t\t\t\t\tPosyandu Bahagia \t\t\t\t\t\t |" << endl;
    tulis << "|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t |" << endl;
    tulis << "----------------------------------------------" << endl;
    // for (int i = 1; i < idxe-1; i++) {
    //  if (nikbeli == dataKTP[i].nik) {
    tulis << "| NIK                 : " << dataKTP.nik;
    tulis << endl;
    tulis << "| Nama                : " << dataKTP.nama;
    tulis << endl;
    tulis << "| TTL                 : " << dataKTP.tmptlahir << ","
          << dataKTP.tgllahir;
    tulis << endl;
    tulis << "| Jenis Kelamin       :  " << dataKTP.jklmn;
    tulis << endl;
    tulis << "| Gol. Darah          :  " << dataKTP.goldar;
    tulis << endl;
    tulis << "| Alamat              : Dusun " << dataKTP.dusun;
    tulis << endl;
    tulis << "| RT                  :  " << dataKTP.rt;
    tulis << endl;
    tulis << "| RW                  :  " << dataKTP.rw;
    tulis << endl;
    tulis << "| Desa                :  " << dataKTP.desa;
    tulis << endl;
    tulis << "| Kecamatan           :  " << dataKTP.kecamatan;
    tulis << endl;
    tulis << "| Kabupaten           :  " << dataKTP.kab;
    tulis << endl;
    tulis << "| Provinsi            :  " << dataKTP.prov;
    tulis << endl;
    tulis << "| Agama               :  " << dataKTP.agama;
    tulis << endl;
    tulis << "| Status Perkawinan   :  " << dataKTP.skawin;
    tulis << endl;
    tulis << "| Pekerjaan           :  " << dataKTP.pekerjaan;
    tulis << endl;
    tulis << "| Kewarganegaraan     :  " << dataKTP.knegara;
    tulis << endl;
    tulis << "| Berlaku Hingga      :  " << dataKTP.berhing;
    tulis << endl;
    //    }
    // }
    // disini nama user yg belanja
    tulis << "----------------------------------------------" << endl;
    tulis << "ID\tNAMA BARANG\t  HARGA\t JUMLAH\t TOTAL ";
    tulis << endl;
    tulis << "----------------------------------------------" << endl;
    tulis << x;
    tulis << "----------------------------------------------" << endl;
    tulis << "| Total Yang Harus Dibayar         : " << totbayar;
    tulis << endl;
    tulis << "| Yang dibayarkan                  : " << jumbayar;
    tulis << endl;
    if (jumbayar > totbayar) {
      int kembalian = jumbayar - totbayar;
      tulis << "| Kembalian                        : " << kembalian;
      tulis << endl;
    }
    tulis << "----------------------------------------------" << endl;
    tulis << "  TERIMA KASIH TELAH MELAKUKAN TRANSAKSI";
    tulis << endl;
    tulis << "----------------------------------------------" << endl;
    tulis.close();
  }

  cout << "----------------------------------------------" << endl;
  cout << "|\t\t\t\t\t\t\t\t\t\t\t |" << endl;
  cout << "|\t\t\t\tPosyandu Bahagia \t\t\t |";
  cout << endl;
  cout << "|\t\t\t\t\t\t\t\t\t\t\t |" << endl;
  cout << "----------------------------------------------" << endl;
  // for (int i = 1; i < idxe-1; i++) {
  //   if (nikbeli == dataKTP[i].nik) {
  cout << "| NIK                 : " << dataKTP.nik;
  cout << endl;
  cout << "| Nama                : " << dataKTP.nama;
  cout << endl;
  cout << "| TTL                 : " << dataKTP.tmptlahir << ","
       << dataKTP.tgllahir;
  cout << endl;
  cout << "| Jenis Kelamin       :  " << dataKTP.jklmn;
  cout << endl;
  cout << "| Gol. Darah          :  " << dataKTP.goldar;
  cout << endl;
  cout << "| Alamat              : Dusun " << dataKTP.dusun;
  cout << endl;
  cout << "| RT                  :  " << dataKTP.rt;
  cout << endl;
  cout << "| RW                  :  " << dataKTP.rw;
  cout << endl;
  cout << "| Desa                :  " << dataKTP.desa;
  cout << endl;
  cout << "| Kecamatan           :  " << dataKTP.kecamatan;
  cout << endl;
  cout << "| Kabupaten           :  " << dataKTP.kab;
  cout << endl;
  cout << "| Provinsi            :  " << dataKTP.prov;
  cout << endl;
  cout << "| Agama               :  " << dataKTP.agama;
  cout << endl;
  cout << "| Status Perkawin     :  " << dataKTP.skawin;
  cout << endl;
  cout << "| Pekerjaan           :  " << dataKTP.pekerjaan;
  cout << endl;
  cout << "| Kewarganegaraan     :  " << dataKTP.knegara;
  cout << endl;
  cout << "| Berlaku Hingga      :  " << dataKTP.berhing;
  cout << endl;
  //   }
  // }
  // disini nama user yg belanja
  cout << "----------------------------------------------" << endl;
  cout << "ID\tNAMA BARANG\t  HARGA\t JUMLAH\t TOTAL ";
  cout << endl;
  cout << "----------------------------------------------" << endl;
  cout << x;
  cout << "----------------------------------------------" << endl;
  cout << "| Total Yang Harus Dibayar          : " << totbayar;
  cout << endl;
  cout << "| Yang dibayarkan                   : " << jumbayar;
  cout << endl;
  if (jumbayar > totbayar) {
    int kembalian = jumbayar - totbayar;
    cout << "| Kembalian                         : " << kembalian;
    cout << endl;
  }
  cout << "----------------------------------------------" << endl;
  cout << "  TERIMA KASIH TELAH MELAKUKAN TRANSAKSI";
  cout << endl;
  cout << "----------------------------------------------" << endl;

  tulis.open("daftarBelanja.txt");
  tulis << "";
  tulis.close();
}
// tambahan menu untuk obat