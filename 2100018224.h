#include "StuckArray1d.h"
#include "antrilah.h"
#include "array1d.h"
#include "barang.h"
// #include "bumil.h"
// #include "quepriorityIBUHAMIL.h"
#include "queuebal.h"
#include "AVLtree.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;




struct Dathpen {
  int tglp;
  int blnp;
  int thp;
  int totalp;
} hpen[100];

struct IbuHamil {
  int norekamib_hamil;
  string namaib_hamil;
  double usiakehamilan;
  double usiaib_hamil;
  double beratib_hamil;
  // double hplib_hamil;
  double hplib_TGL;
  double hplib_BLN;
  double hplib_TH;

} ibhml;

struct EditIbuHamil{
  double usiakehamilan;
  double beratib_hamil;
}newibhml; 

struct EditOBalita {
  int tingBalEdit;
  int brtBalEdit;
  int umrBalbEdit;
} newBL;

struct EditObat {
  string namaObEdit;
  int stokObEdit;
  int hargaObEdit;
} newOB;


struct EditVaksin {
  string namaEdit;
  int stokEdit;
  int hargaEdit;
} newVak;

struct Balita {
  int Norekam;
  string namaBal;
  string ibBal;
  double tingBal;
  double bertBal;
  int umrBal;
} blt[1000];

struct KTP3 {
  string namaKTP;
  string nikKTP;
  string provKTP;
  string tmptLahir;
  string tglLahir;
  string dusun;
  string rt;
  string rw;
  string jk;
  string desa;
  string kec;
  string agama;
  string stts;
  string kerja;
  string wn;
  string bh;
  string kab;
  string goldar;
} dataKTP;

struct KTPBidan {
  string NIP;
  string namaBidan;
  string jlnBidan;
  string rtBidan;
  string rwBidan;
  string kecBidan;
  string kabBidan;
  string desaBidan;
  string nikBidan;
  string provBidan;
  string tmptLahirBidan;
  string tglLahirBidan;
  string noHp;
  double gajiBID;
} dataBidan[1000];



struct editBidan{
  string noHpEDIT;
  string jlnBidanEDIT;
  string rtBidanEDIT;
  string rwBidanEDIT;
  string kecBidanEDIT;
  string kabBidanEDIT;
  string desaBidanEDIT;
  string provBidanEDIT;
}newBID;

class Admin {
public:
  Array1D<barang> X;
  int toInt(string x) {
    int y;

    stringstream ss;
    ss << x;
    ss >> y;

    return y;
  }

  double toDouble(string x) {
    double r;

    stringstream ss;
    ss << x;
    ss >> r;

    return r;
  }

  int jumtotal(int angkaa[], int n) {

    if (n < 0) {
      return 0;
    } else {
      return angkaa[n] + jumtotal(angkaa, n - 1);
    }
  }

  double proses_jum(double angka[], int n) {

    if (n < 0) {
      return 0;
    } else {
      return angka[n] + proses_jum(angka, n - 1);
    }
  }

  double rata(double w, int e) {
    double r = 0;
    r = w / e;
    return r;
  }






  void tokenizeHP(string sp, string delp = " ", int idxp = 0) {
    string tmpp;
    int ip = 1;
    int startp, endp = -1 * delp.size();
    do {
      startp = endp + delp.size();
      endp = sp.find(delp, startp);
      tmpp = sp.substr(startp, endp - startp);

      if (ip == 1) {
        hpen[idxp].tglp = toInt(tmpp);

      } else if (ip == 2) {
        hpen[idxp].blnp = toInt(tmpp);

      } else if (ip == 3) {
        hpen[idxp].thp = toInt(tmpp);
      } else {
        hpen[idxp].totalp = toInt(tmpp);
      }
      ip++;

    } while (endp != -1);
  }

  void lihatdatahPen() {
    int idxtp = 0;
    string tp;
    ambilhpen.open("tulishistory.txt");
    while (!ambilhpen.eof()) {
      ambilhpen >> tp;
      tokenizeHP(tp, ";", idxtp);
      idxtp++;
    }
    ambilhpen.close();

    system("clear");
    cout << "Berikut Data Pendapatan Posyandu...";
    cout << endl;
    cout << "----------------------------------------------" << endl;
    for (int jp = 0; jp < idxtp - 1; jp++)
    // for (int jp = idxtp - 2; jp > -1; jp--)
    {
      cout << endl;

      cout << "Tanggal/Bulan/Tahun     : " << hpen[jp].tglp << "/"
           << hpen[jp].blnp << "/" << hpen[jp].thp;
      cout << endl;
      cout << "Total                   : Rp " << hpen[jp].totalp;
      cout << endl;
      totallo[jp] = hpen[jp].totalp;
    }
    long hasillo;
    hasillo = jumtotal(totallo, idxtp - 2);
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Total seluruh Pendapatan Rp " << hasillo << endl;
    cout << "----------------------------------------------" << endl;
    cout << endl;
    cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
    cin >> konfirm;
  }

  void tokenizeBB(string sb, string delb = " ", int idxb = 0) {
    string tmpb;
    int i = 1;
    int startb, endb = -1 * delb.size();
    do {
      startb = endb + delb.size();
      endb = sb.find(delb, startb);
      tmpb = sb.substr(startb, endb - startb);

      if (i == 1) {
        blt[idxb].Norekam = toInt(tmpb);

      } else if (i == 2) {
        blt[idxb].namaBal = tmpb;

      } else if (i == 3) {
        blt[idxb].ibBal = tmpb;
      } else if (i == 4) {
        blt[idxb].tingBal = toDouble(tmpb);
      } else if (i == 5) {
        blt[idxb].bertBal = toDouble(tmpb);
      } else {
        blt[idxb].umrBal = toInt(tmpb);
      }
      i++;

    } while (endb != -1);
  }

  void LihatdataBalita() {
    int idxb = 0;
    string tb;
    ambilb.open("dataBalita.txt");

    while (!ambilb.eof()) {
      ambilb >> tb;
      tokenizeBB(tb, ";", idxb);
      idxb++;
    }
    ambilb.close();
    cout << "Berikut Daftar Balita Yang Tersedia..." << endl;
    for (int s = 0; s < idxb - 1; s++) {
      cout << "----------------------------------------------" << endl;
      cout << " No Rekam medis    : " << blt[s].Norekam;
      cout << endl;
      cout << " Nama Balita       : " << blt[s].namaBal;
      cout << endl;
      cout << " Nama Ibu          : " << blt[s].ibBal;
      cout << endl;
      cout << " Tinggi Balita     : " << blt[s].tingBal;
      cout << endl;
      cout << " Berat Balita      : " << blt[s].bertBal;
      cout << endl;
      cout << " Umur Balita       : " << blt[s].umrBal;
      cout << endl;
      cout << "----------------------------------------------" << endl;

      tinggii[s] = blt[s].tingBal;
      beratt[s] = blt[s].bertBal;
    }
    hasil1 = proses_jum(tinggii, idxb - 1);
    hasil2 = proses_jum(beratt, idxb - 1);
    rata1 = rata(hasil1, idxb - 1);
    rata2 = rata(hasil2, idxb - 1);
    cout << "Rata-Rata Berat Badan  : " << rata2;
    cout << endl;
    cout << "Rata-Rata Tinggi Badan : " << rata1;
    cout << endl;
    cout << "----------------------------------------------";
    cout << endl;
    cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
    cin >> konfirm;
  }

  void tokenizez(string sz, string delz = " ") {
    string tmpz;
    int i = 1;
    int startz, end = -1 * delz.size();
    do {
      startz = end + delz.size();
      end = sz.find(delz, startz);
      tmpz = sz.substr(startz, end - startz);

      if (i == 1) {
        dataKTP.nikKTP = tmpz;
      } else if (i == 2) {
        dataKTP.namaKTP = tmpz;
      } else if (i == 3) {
        dataKTP.provKTP = tmpz;
      } else if (i == 4) {
        dataKTP.tmptLahir = tmpz;
      } else if (i == 5) {
        dataKTP.tglLahir = tmpz;
      } else if (i == 6) {
        dataKTP.dusun = tmpz;
      } else if (i == 7) {
        dataKTP.rt = tmpz;
      } else if (i == 8) {
        dataKTP.rw = tmpz;
      } else if (i == 9) {
        dataKTP.desa = tmpz;
      } else if (i == 10) {
        dataKTP.kec = tmpz;
      } else if (i == 11) {
        dataKTP.kab = tmpz;
      } else if (i == 12) {
        dataKTP.agama = tmpz;
      } else if (i == 13) {
        dataKTP.stts = tmpz;
      } else if (i == 14) {
        dataKTP.kerja = tmpz;
      } else if (i == 15) {
        dataKTP.wn = tmpz;
      } else if (i == 16) {
        dataKTP.bh = tmpz;
      } else if (i == 17) {
        dataKTP.jk = tmpz;
      } else {
        dataKTP.goldar = tmpz;
      }
      i++;

    } while (end != -1);
  }

  void ambildataLogin() {
    string t;
    ambil.open("dataLogin.txt");
    while (!ambil.eof()) {
      ambil >> t;
      tokenizez(t, ";");
    }
    ambil.close();
  }

  

  void ambildataBidan() {
    int idxt = 0;
    string t;
    ambil.open("databidan.txt");
    while (!ambil.eof()) {
      ambil >> t;
      tokenizeBd(t, ";", idxt);
      idxt++;
    }
    ambil.close();

    system("clear");
    cout << "Berikut Daftar bidan...";
    for (int j = 0; j < idxt - 1; j++) {
      cout << endl;
      cout << "----------------------------------------------" << endl;
      cout << "NIP bidan     : " << dataBidan[j].NIP;
      cout << endl;
      cout << "NIK Bidan     : " << dataBidan[j].nikBidan;
      cout << endl;
      cout << "Nama Bidan    : " << dataBidan[j].namaBidan;
      cout << endl;
      cout << "TTL Bidan     : " << dataBidan[j].tmptLahirBidan << ","
           << dataBidan[j].tglLahirBidan;
      cout << endl;
      cout << "Alamat Bidan  :  Jln " << dataBidan[j].jlnBidan;
      cout << endl;
      cout << "                 RT/RW     : " << dataBidan[j].rtBidan << "/"
           << dataBidan[j].rwBidan;
      cout << endl;
      cout << "                 Kel/desa  : " << dataBidan[j].desaBidan;
      cout << endl;
      cout << "                 Kec       : " << dataBidan[j].kecBidan;
      cout << endl;
      cout << "                 Kab/Kota  : " << dataBidan[j].kabBidan;
      cout << endl;
      cout << "                 Provinsi  : " << dataBidan[j].provBidan;
      cout << endl;
      cout << "No HP Bidan   : " << dataBidan[j].noHp;
      cout << endl;
      cout << "----------------------------------------------" << endl;
    }
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
        dataBidan[idxd].NIP = tmpd;
      } 
      else if (i == 2) 
      {
        dataBidan[idxd].nikBidan = tmpd;
      } 
      else if (i == 3) 
      {
        dataBidan[idxd].namaBidan = tmpd;
      } 
      else if (i == 4) 
      {
        dataBidan[idxd].provBidan = tmpd;
      } 
      else if (i == 5) 
      {
        dataBidan[idxd].tglLahirBidan = tmpd;
      } 
      else if (i == 6) 
      {
        dataBidan[idxd].tmptLahirBidan = tmpd;
      } 
      else if (i == 7) 
      {
        dataBidan[idxd].noHp = tmpd;
      } 
      else if (i == 8) 
      {
        dataBidan[idxd].jlnBidan = tmpd;
      } 
      else if (i == 9) 
      {
        dataBidan[idxd].rtBidan = tmpd;
      } 
      else if (i == 10) 
      {
        dataBidan[idxd].rwBidan = tmpd;
      } 
      else if (i == 11) 
      {
        dataBidan[idxd].desaBidan = tmpd;
      } 
      else if (i == 12) 
      {
        dataBidan[idxd].kecBidan = tmpd;
      } 
      else if (i == 13)
      {
        dataBidan[idxd].kabBidan = tmpd;
      }
      else 
      {
        dataBidan[idxd].gajiBID = toDouble(tmpd);
      }
      i++;

    } while (endd != -1);
  }

  void cekBidan() {
    ambildataBidan();
    cout << endl;

    cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
    cin >> konfirm;
  }

  void Lihatdataobat() {
    int idxr = 0;
    string to;
    ambilo.open("dataobat.txt");
    while (!ambilo.eof()) {
      ambilo >> to;
      tokenize1(to, ";", idxr);
      idxr++;
      // X.ReSize(idx);
    }
    ambil.close();
    cout << "Berikut Daftar Obat Yang Tersedia..." << endl;
    for (int q = 0; q < idxr - 1; q++) {
      cout << "----------------------------------------------" << endl;
      cout << "ID Obat     : " << obt[q].id;
      cout << endl;
      cout << "Nama Obat   : " << obt[q].nama;
      cout << endl;
      cout << "Stok Obat   : " << obt[q].stok;
      cout << endl;
      cout << "Harga Obat  : " << obt[q].harga;
      cout << endl;
      cout << "----------------------------------------------" << endl;
    }

    cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
    cin >> konfirm;
  }

  void tokenize1(string sr, string delr = " ", int idxr = 0) {
    string tmpr;
    int i = 1;
    int startr, endr = -1 * delr.size();
    do {
      startr = endr + delr.size();
      endr = sr.find(delr, startr);
      tmpr = sr.substr(startr, endr - startr);

      if (i == 1) {
        obt[idxr].id = tmpr;

      } else if (i == 2) {
        obt[idxr].nama = tmpr;
      } else if (i == 3) {
        obt[idxr].stok = toInt(tmpr);
      } else {
        obt[idxr].harga = toInt(tmpr);
      }
      i++;

    } while (endr != -1);
  }

  void ambildataDinamis() {
    int idx = 0;
    string t;
    ambil.open("data.txt");
    while (!ambil.eof()) {
      ambil >> t;
      tokenize(t, ";", idx);
      idx++;
      // X.ReSize(idx);
    }
    ambil.close();
    // Array1D<barang> X(idx);
    X.ReSize(idx);
    for (int i = 0; i < idx; i++) {
      barang tambah(brg[i].id, brg[i].nama, brg[i].stok, brg[i].harga);
      X[i] = tambah;
    }
    cout << X;
  }

  void tokenize(string s, string del = " ", int idx = 0) {
    string tmp;
    int i = 1;
    int start, end = -1 * del.size();
    do {
      start = end + del.size();
      end = s.find(del, start);
      tmp = s.substr(start, end - start);

      if (i == 1) {
        brg[idx].id = tmp;

      } else if (i == 2) {
        brg[idx].nama = tmp;
      } else if (i == 3) {
        brg[idx].stok = toInt(tmp);
      } else {
        brg[idx].harga = toInt(tmp);
      }
      i++;

    } while (end != -1);
  }

 

  void memprosesAntriBal() {
    Queuebal<Balita> testersahaja(1);
    int idxyu = 0;
    string tbi;
    ambilb.open("balitaantri.txt");

    while (!ambilb.eof()) {
      ambilb >> tbi;
      tokenizeBB(tbi, ";", idxyu);
      idxyu++;
    }
    ambilb.close();

    for (int a = 0; a < idxyu - 1; a++) {
      testersahaja.Enqueue(blt[a].Norekam, blt[a].namaBal, blt[a].ibBal,
                           blt[a].tingBal, blt[a].bertBal, blt[a].umrBal);
    }
    if (testersahaja.IsEmpty()) {
      system("clear");
      cout << "Tidak Ada Balita Untuk Di Periksa...";
      cout << endl;
    } else {
      testersahaja.tampil();

      // testersahaja.Enqueue(blt.Norekam,blt.namaBal,
      // blt.ibBal,blt.tingBal,blt.bertBal,blt.umrBal); cout<< "haloo "<<endl;
      ofstream woy;

      cout << endl;
      // cout<< " sopo " << testersahaja.FirstNama()<<endl;
      char jijik;
      cout << "Apakah Anda Ingin Memproses Antrian Balita? [y/n] ";
      cin >> jijik;
      if (jijik == 'Y' || jijik == 'y') {
        woy.open("balitacek.txt");
        woy << testersahaja.FirstNorekam() << ";" << testersahaja.FirstNama()
            << ";" << testersahaja.FirstIbu() << ";"
            << testersahaja.FirstTinggi() << ";" << testersahaja.FirstBerat()
            << ";" << testersahaja.FirstUmur();
        cout << endl;

        woy.close();
        cout << endl;
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Balita Atas Nama " << testersahaja.FirstNama()
             << " Telah Di Proses ";
        cout << endl;
        cout << "----------------------------------------------" << endl;
        testersahaja.Dequeue();

        ofstream woi;
        woi.open("balitaantri.txt");

        while (!testersahaja.IsEmpty()) {
          woi << testersahaja.FirstNorekam() << ";" << testersahaja.FirstNama()
              << ";" << testersahaja.FirstIbu() << ";"
              << testersahaja.FirstTinggi() << ";" << testersahaja.FirstBerat()
              << ";" << testersahaja.FirstUmur() << endl;
          testersahaja.Dequeue();
        }
        woi.close();
      }
    }

    cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
    cin >> konfirm;
  }




  

  int menu();
  void restok();
  void restokObat();
  void tambahdata();
  void tambahdataobat();
  void tambahdataBalita();
  void hapusdataBalita();
  void lihatdataDinamis();
  void lihatdataobat();
  void hapusdata();
  void hapusdataobat();

  void cetakNPWPbidan();
  // edit
  void editdataVaksin();
  void editdataObat();

  void editdataBidan();
  void editdataBalita();

  // stack
  void historyPendapatan();
  void tulishistoryPendapatan();

  // queue
  void lihatBalantri();

  // quepriority
  void tambahDataIBU_HAMIL();

  // bidan
  void hpsdataBIDAN();
  void edtdataBIDAN();
  void tambahdataBidan();

  //bumil
  void hpsdataBUMIL();
  void editdataBUMIL();

  //avltree
  void StrukturBidan();


  //pengumuman
  void pengumuman();
  void lihatPengumuman();
  void hpsPengumuman();
  void editPengummuman();


  int pilih;
  char konfirm;

private:
  string id;
  string nama;
  int harga;
  int stok;
  string namaBalita;
  string ibu;
  int tinggi;
  int berat;
  int umur;
  ofstream tulis;
  ifstream ambil, ambilo;
  ifstream ambilc;
  ofstream tulisb;
  ifstream ambilb;

  //bidan
  ofstream tulisBID;

  ofstream tulisnew; // edit data vaksin
  ifstream ambilnew;
  int pilmenuEdit; // edit data menu

  ofstream tulisnewB;
  ifstream ambilnewB;
  int pilmenuEditB;

  // stack
  ifstream ambilhpen;
  ofstream tulishpen;

  ifstream ambilhpenB;
  ofstream tulishpenB;

  // que priority
  ofstream tulisIBU_HAMIL;

  int totallo[1000];
  antri *ant = new antri[1000];
  int size;
  int loc;
  string DataBalita[1000];
  double beratt[1000];
  double tinggii[1000];
  double umurr[1000];
  double hasil1;
  double hasil2;
  double rata1;
  double rata2;
  barang *brg = new barang[1000];
  barang *obt = new barang[1000];
 
};





void Admin::pengumuman()
{
  string jenis;
  int tgl,bln,thn;
  string pelaku;
  string tempat = "Posyandu Bahagia";
  string usiaha;
  string topik;
  int pilihlah;
  int kode;

  system("clear");
  cout << "----------------------------------------------" << endl;
  cout<<"               Tambah Pengumuman ";
  cout <<endl;
  cout << "----------------------------------------------" << endl;
  cout<<endl;
  cout <<"Masukkan Kode Pengumuman : "; 
  cin>> kode; 
  cout << "----------------------------------------------" << endl;
  ulang1:
  cout <<endl;
  cout << "|----------------------------------------------|" << endl;
  cout << "|             Jenis Pengumuman                 |"<<endl;
  cout << "|----------------------------------------------|" << endl;
  cout << "|      1. Penyuluhan                           |"<<endl;
  cout << "|      2. Pemeriksaan                          |"<<endl;
  cout << "|----------------------------------------------|" << endl;
  cout<<"Masukkan Pilihan Anda [1/2] : ";
  cin >>pilihlah;
  if(pilihlah ==1)
  {
    jenis = "Penyuluhan";
    pilihlah =0;
  }
  else if (pilihlah == 2)
  {
    jenis = "Pemeriksaan";
     pilihlah =0;
  }
  else 
  {
    cout << "Pilihan Tidak Tersedia "<<endl;
    cin.ignore();
    cout << "\nTekan Enter Untuk Memilih Kembali ⏎ ";
    cout<<endl;
    getchar();
    goto ulang1;
  }
  cin.ignore();
  system("clear");
  cout<<"Masukkan Tema Kegiatan  : ";
  getline(cin, topik);

  // cout<<"Tanggal Pelaksanaan : ";
  // cin>>tgl;
  cout<<"Masukkan Tahun      : ";
  cin>>thn;
  ulang2:
  cout<<"Masukkan Bulan      : ";
  cin>>bln;
  if(bln >=1 && bln <= 12)
  {
    bln= bln;
  }
  else 
  {
    cout<<"Format Salah "<<endl;
    cin.ignore();
    cout << "Tekan Enter Untuk Kembali ⏎ ";
    cout<<endl;
    getchar();
    goto ulang2;
  }
  ulang3:
  cout<<"Masukkan Tanggal    : ";cin>>tgl;
  if(bln == 1 && tgl >= 1 && tgl <= 31|| bln == 3 && tgl >= 1 && tgl <= 31|| bln == 5 && tgl >= 1 && tgl <= 31|| bln == 7 && tgl >= 1 && tgl <= 31|| bln == 8 && tgl >= 1 && tgl <= 31|| bln == 10 && tgl >= 1 && tgl <= 31 || bln == 12 && tgl >= 1 && tgl <= 31)
  {
    tgl = tgl;
  }
  else if (bln == 4 && tgl >= 1 && tgl <= 30 || bln == 6 && tgl >= 1 && tgl <= 30|| bln == 9 && tgl >= 1 && tgl <= 30|| bln == 11 && tgl >= 1 && tgl <= 30)
  {
    tgl = tgl;
  }
  else if (bln == 2 && tgl >= 1 && tgl <= 29)
  {
    tgl = tgl;
  }
  else
  {
    cout<<"format salah "<<endl;
    cin.ignore();
    cout << "Tekan Enter Untuk Kembali ⏎ ";
    getchar();
    goto ulang3;
  }

  
  ulang4:
  cout<<endl;
  cout << "|----------------------------------------------|" << endl;
  cout << "|             Pilih Peserta                    |"<<endl;
  cout << "|----------------------------------------------|" << endl;
  cout << "|             1. Balita                        |"<<endl;
  cout << "|             2. Bumil                         |"<<endl;
  cout << "|----------------------------------------------|" << endl;
  cout << "Masukkan Pilihan Anda [1/2] : ";cin >>pilihlah;
  if(pilihlah ==1)
  {
     pelaku = "Balita";
    pilihlah =0;
  }
  else if(pilihlah ==2)
  {
    pelaku = "Bumil";
     pilihlah =0;
  }
  else 
  {
    cout << "Pilihan Tidak Tersedia "<<endl;
    cin.ignore();
    cout << "Tekan Enter Untuk Kembali ⏎ ";
    getchar();
    goto ulang4;
  }

  ofstream buka;
  buka.open("Pengumuman.txt", ios::app);
  buka << kode <<";" << jenis <<";"<<topik<<";"<< tgl<<"/"<<bln<<"/"<<thn<<";"<<pelaku<<";"<<tempat<<endl;
  buka.close();
  cout<<endl;
  cout << "----------------------------------------------" << endl;
  cout<<"Pilihan Berhasil..."<<endl<<endl;
  cout << "----------------------------------------------" << endl;
  
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirm;

}







void Admin::StrukturBidan()
{
  balikgile:
  int idxsttk = 0;
    string ttk;
    ambil.open("databidan.txt");
    while (!ambil.eof()) {
      ambil >> ttk;
      tokenizeBd(ttk, ";", idxsttk);
      idxsttk++;
    }
    ambil.close();

  nodeptr root;
  nodeptr root1;
  bstree bst;
  root = NULL;
  root1 = NULL;

    int gajiBDN;
    string NIPBDN;
    string namaBDN;
    string jlnBDN;
    string rtBDN;
    string rwBDN;
    string kecBDN;
    string kabBDN;
    string desaBDN;
    string nikBDN;
    string provBDN;
    string tmptLahirBDN;
    string tglLahirBDN;
    string noHpBDN;

  for(int i =0; i<idxsttk-1;i++)
  {
    bst.insert(dataBidan[i].gajiBID,dataBidan[i].NIP,dataBidan[i].nikBidan, dataBidan[i].namaBidan,dataBidan[i].provBidan,dataBidan[i].tglLahirBidan,dataBidan[i].tmptLahirBidan,dataBidan[i].noHp,dataBidan[i].jlnBidan,dataBidan[i].rtBidan,dataBidan[i].rwBidan,dataBidan[i].desaBidan,dataBidan[i].kecBidan,dataBidan[i].kabBidan,root);
  }
  
cout<<endl;
int pilihsu;
cout <<"----------------------------------------------" << endl;
cout <<"|  Struktur Bidan AVL Tree berdasarkan Gaji  |";
cout << endl;
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
cin>>pilihsu;
cout<<endl;
  cout<<endl;

 switch(pilihsu)
  {
    case 1 :
      cout << "Kunjungan Preorder   : ";
      cout<<endl;
	    bst.preorder(root);
    	cout << endl;
      break;
    case 2 :
      cout << "Kunjungan InOrder    : "<<endl;
	    bst.inorder(root);
    	cout << endl;
      break;
    case 3 : 
      cout << "Kunjungan Postorder  : "<<endl;
      cout<<endl;
	    bst.postorder(root);
    	cout << endl;
      break;
    default:
    cout<< "pilihan tidak ada, Silahkan pilih kembali "<<endl;
    cout<<"Pilih yg bener makanyaaa "<<endl;
    goto balikgile;
      
    
  }



  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirm;
}







void Admin::edtdataBIDAN(){
  int idxt = 0;
    string t;
    ambil.open("databidan.txt");
    while (!ambil.eof()) {
      ambil >> t;
      tokenizeBd(t, ";", idxt);
      idxt++;
    }
    ambil.close();

    system("clear");
    cout << "Berikut Daftar bidan...";
    for (int j = 0; j < idxt - 1; j++) {
      cout << endl;
      cout << "----------------------------------------------" << endl;
      cout << "NIP bidan     : " << dataBidan[j].NIP;
      cout << endl;
      cout << "NIK Bidan     : " << dataBidan[j].nikBidan;
      cout << endl;
      cout << "Nama Bidan    : " << dataBidan[j].namaBidan;
      cout << endl;
      cout << "TTL Bidan     : " << dataBidan[j].tmptLahirBidan << ","
           << dataBidan[j].tglLahirBidan;
      cout << endl;
      cout << "Alamat Bidan  :  Jln " << dataBidan[j].jlnBidan;
      cout << endl;
      cout << "                 RT/RW     : " << dataBidan[j].rtBidan << "/"
           << dataBidan[j].rwBidan;
      cout << endl;
      cout << "                 Kel/desa  : " << dataBidan[j].desaBidan;
      cout << endl;
      cout << "                 Kec       : " << dataBidan[j].kecBidan;
      cout << endl;
      cout << "                 Kab/Kota  : " << dataBidan[j].kabBidan;
      cout << endl;
      cout << "                 Provinsi  : " << dataBidan[j].provBidan;
      cout << endl;
      cout << "No HP Bidan   : " << dataBidan[j].noHp;
      cout << endl;
      cout << "----------------------------------------------" << endl;
    }
    string pilNIPbd;
    bool ketemu = false;
    int datakeED;

    cout << endl;
    cout << "Silahkan Pilih NIP Bidan Yang Ingin DiEdit : ";
    cin >> pilNIPbd;

    for (int b = 0; b < idxt - 1; b++) {
      if (pilNIPbd == dataBidan[b].NIP) {
        ketemu = true;
        datakeED = b;
        break;
      }
    }
      if (ketemu == true) {
  editdataBID:
    cout << "----------------------------------------------" << endl;
    cout << endl;
    cout << "Menu Edit Data Bidan";
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "1. Edit No HP Bidan ";
    cout << endl;
    cout << "2. Edit Alamat Jalan Bidan ";
    cout << endl;
    cout << "3. Edit Alamat RT Bidan ";
    cout << endl;
    cout << "4. Edit Alamat RW Bidan ";
    cout << endl;
    cout << "5. Edit Alamat Kel/Desa Bidan ";
    cout << endl;
    cout << "6. Edit Alamat Kec Bidan ";
    cout << endl;
    cout << "7. Edit Alamat Kab/Kota Bidan ";
    cout << endl;
    cout << "8. Edit Alamat Provinsi Bidan ";
    cout << endl;    
    cout << "----------------------------------------------" << endl;
    cout << " Masukkan Pilihan [1/2/3/4/5/6/7/8] : ";
    cin >> pilmenuEdit;

  switch (pilmenuEdit) {
    case 1: {
      cout << endl;
      cout << "----------------------------------------------" << endl;
      cout << " Masukkan No HP Bidan Yang Ingin di Edit : ";
      cin >> newBID.noHpEDIT;
      cout << "----------------------------------------------" << endl;

      tulisnew.open("databidan.txt");
      for (int c = 0; c < idxt - 1; ++c) {
        if (c == datakeED) {
          dataBidan[c].noHp = newBID.noHpEDIT;
          tulisnew << dataBidan[c].NIP << ";" << dataBidan[c].nikBidan <<";" << dataBidan[c].namaBidan <<";" << dataBidan[c].provBidan <<";" << dataBidan[c].tglLahirBidan <<";" << dataBidan[c].tmptLahirBidan <<";" << dataBidan[c].noHp <<";" << dataBidan[c].jlnBidan <<";" << dataBidan[c].rtBidan << ";" << dataBidan[c].rwBidan << ";" << dataBidan[c].desaBidan << ";" << dataBidan[c].kecBidan <<";" << dataBidan[c].kabBidan << endl;
          system("clear");
          cout << "----------------------------------------------" << endl;
          cout << "No HP Bidan Berhasil Di Edit Ke -> " << newBID.noHpEDIT;
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << endl;
        } else {
          tulisnew << dataBidan[c].NIP << ";" << dataBidan[c].nikBidan <<";" << dataBidan[c].namaBidan <<";" << dataBidan[c].provBidan <<";" << dataBidan[c].tglLahirBidan <<";" << dataBidan[c].tmptLahirBidan <<";" << dataBidan[c].noHp <<";" << dataBidan[c].jlnBidan <<";" << dataBidan[c].rtBidan << ";" << dataBidan[c].rwBidan << ";" << dataBidan[c].desaBidan << ";" << dataBidan[c].kecBidan <<";" << dataBidan[c].kabBidan << endl;;
        }
      }
      tulisnew.close();

      break;
      }//tutup case
    case 2: {
      cout << endl;
      cout << "----------------------------------------------" << endl;
      cout << " Masukkan Alamat RT Bidan Yang Ingin di Edit : ";
      cin >> newBID.jlnBidanEDIT;
      cout << "----------------------------------------------" << endl;

      tulisnew.open("databidan.txt");
      for (int c = 0; c < idxt - 1; ++c) {
        if (c == datakeED) {
          dataBidan[c].jlnBidan = newBID.jlnBidanEDIT;
          tulisnew << dataBidan[c].NIP << ";" << dataBidan[c].nikBidan <<";" << dataBidan[c].namaBidan <<";" << dataBidan[c].provBidan <<";" << dataBidan[c].tglLahirBidan <<";" << dataBidan[c].tmptLahirBidan <<";" << dataBidan[c].noHp <<";" << dataBidan[c].jlnBidan <<";" << dataBidan[c].rtBidan << ";" << dataBidan[c].rwBidan << ";" << dataBidan[c].desaBidan << ";" << dataBidan[c].kecBidan <<";" << dataBidan[c].kabBidan << endl;
          system("clear");
          cout << "----------------------------------------------" << endl;
          cout << "Alamat RT Berhasil Di Edit Ke -> " << newBID.jlnBidanEDIT;
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << endl;
        } else {
          tulisnew << dataBidan[c].NIP << ";" << dataBidan[c].nikBidan <<";" << dataBidan[c].namaBidan <<";" << dataBidan[c].provBidan <<";" << dataBidan[c].tglLahirBidan <<";" << dataBidan[c].tmptLahirBidan <<";" << dataBidan[c].noHp <<";" << dataBidan[c].jlnBidan <<";" << dataBidan[c].rtBidan << ";" << dataBidan[c].rwBidan << ";" << dataBidan[c].desaBidan << ";" << dataBidan[c].kecBidan <<";" << dataBidan[c].kabBidan << endl;;
        }
      }
      tulisnew.close();

      break;
      }//tutup case
    case 3: {
      cout << endl;
      cout << "----------------------------------------------" << endl;
      cout << " Masukkan Alamat RT Bidan Yang Ingin di Edit : ";
      cin >> newBID.rtBidanEDIT;
      cout << "----------------------------------------------" << endl;

      tulisnew.open("databidan.txt");
      for (int c = 0; c < idxt - 1; ++c) {
        if (c == datakeED) {
          dataBidan[c].rtBidan = newBID.rtBidanEDIT;
          tulisnew << dataBidan[c].NIP << ";" << dataBidan[c].nikBidan <<";" << dataBidan[c].namaBidan <<";" << dataBidan[c].provBidan <<";" << dataBidan[c].tglLahirBidan <<";" << dataBidan[c].tmptLahirBidan <<";" << dataBidan[c].noHp <<";" << dataBidan[c].jlnBidan <<";" << dataBidan[c].rtBidan << ";" << dataBidan[c].rwBidan << ";" << dataBidan[c].desaBidan << ";" << dataBidan[c].kecBidan <<";" << dataBidan[c].kabBidan << endl;
          system("clear");
          cout << "----------------------------------------------" << endl;
          cout << "Alamat RT Berhasil Di Edit Ke -> " << newBID.rtBidanEDIT;
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << endl;
        } else {
          tulisnew << dataBidan[c].NIP << ";" << dataBidan[c].nikBidan <<";" << dataBidan[c].namaBidan <<";" << dataBidan[c].provBidan <<";" << dataBidan[c].tglLahirBidan <<";" << dataBidan[c].tmptLahirBidan <<";" << dataBidan[c].noHp <<";" << dataBidan[c].jlnBidan <<";" << dataBidan[c].rtBidan << ";" << dataBidan[c].rwBidan << ";" << dataBidan[c].desaBidan << ";" << dataBidan[c].kecBidan <<";" << dataBidan[c].kabBidan << endl;;
        }
      }
      tulisnew.close();

      break;
      }//tutup case
    case 4: {
      cout << endl;
      cout << "----------------------------------------------" << endl;
      cout << " Masukkan Alamat RW Bidan Yang Ingin di Edit : ";
      cin >> newBID.rwBidanEDIT;
      cout << "----------------------------------------------" << endl;

      tulisnew.open("databidan.txt");
      for (int c = 0; c < idxt - 1; ++c) {
        if (c == datakeED) {
          dataBidan[c].rwBidan = newBID.rwBidanEDIT;
          tulisnew << dataBidan[c].NIP << ";" << dataBidan[c].nikBidan <<";" << dataBidan[c].namaBidan <<";" << dataBidan[c].provBidan <<";" << dataBidan[c].tglLahirBidan <<";" << dataBidan[c].tmptLahirBidan <<";" << dataBidan[c].noHp <<";" << dataBidan[c].jlnBidan <<";" << dataBidan[c].rtBidan << ";" << dataBidan[c].rwBidan << ";" << dataBidan[c].desaBidan << ";" << dataBidan[c].kecBidan <<";" << dataBidan[c].kabBidan << endl;
          system("clear");
          cout << "----------------------------------------------" << endl;
          cout << "Alamat RW Berhasil Di Edit Ke -> " << newBID.rwBidanEDIT;
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << endl;
        } else {
          tulisnew << dataBidan[c].NIP << ";" << dataBidan[c].nikBidan <<";" << dataBidan[c].namaBidan <<";" << dataBidan[c].provBidan <<";" << dataBidan[c].tglLahirBidan <<";" << dataBidan[c].tmptLahirBidan <<";" << dataBidan[c].noHp <<";" << dataBidan[c].jlnBidan <<";" << dataBidan[c].rtBidan << ";" << dataBidan[c].rwBidan << ";" << dataBidan[c].desaBidan << ";" << dataBidan[c].kecBidan <<";" << dataBidan[c].kabBidan << endl;;
        }
      }
      tulisnew.close();

      break;
      }//tutup case
    case 5: {
      cout << endl;
      cout << "----------------------------------------------" << endl;
      cout << " Masukkan Alamat Kel/Desa Bidan Yang Ingin di Edit : ";
      cin >> newBID.desaBidanEDIT;
      cout << "----------------------------------------------" << endl;

      tulisnew.open("databidan.txt");
      for (int c = 0; c < idxt - 1; ++c) {
        if (c == datakeED) {
          dataBidan[c].desaBidan = newBID.desaBidanEDIT;
          tulisnew << dataBidan[c].NIP << ";" << dataBidan[c].nikBidan <<";" << dataBidan[c].namaBidan <<";" << dataBidan[c].provBidan <<";" << dataBidan[c].tglLahirBidan <<";" << dataBidan[c].tmptLahirBidan <<";" << dataBidan[c].noHp <<";" << dataBidan[c].jlnBidan <<";" << dataBidan[c].rtBidan << ";" << dataBidan[c].rwBidan << ";" << dataBidan[c].desaBidan << ";" << dataBidan[c].kecBidan <<";" << dataBidan[c].kabBidan << endl;
          system("clear");
          cout << "----------------------------------------------" << endl;
          cout << "Alamat Kel/Desa Berhasil Di Edit Ke -> " << newBID.desaBidanEDIT;
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << endl;
        } else {
          tulisnew << dataBidan[c].NIP << ";" << dataBidan[c].nikBidan <<";" << dataBidan[c].namaBidan <<";" << dataBidan[c].provBidan <<";" << dataBidan[c].tglLahirBidan <<";" << dataBidan[c].tmptLahirBidan <<";" << dataBidan[c].noHp <<";" << dataBidan[c].jlnBidan <<";" << dataBidan[c].rtBidan << ";" << dataBidan[c].rwBidan << ";" << dataBidan[c].desaBidan << ";" << dataBidan[c].kecBidan <<";" << dataBidan[c].kabBidan << endl;;
        }
      }
      tulisnew.close();

      break;
      }//tutup case
    case 6: {
      cout << endl;
      cout << "----------------------------------------------" << endl;
      cout << " Masukkan Alamat Kec Bidan Yang Ingin di Edit : ";
      cin >> newBID.kecBidanEDIT;
      cout << "----------------------------------------------" << endl;

      tulisnew.open("databidan.txt");
      for (int c = 0; c < idxt - 1; ++c) {
        if (c == datakeED) {
          dataBidan[c].kecBidan = newBID.kecBidanEDIT;
          
          tulisnew << dataBidan[c].NIP << ";" << dataBidan[c].nikBidan <<";" << dataBidan[c].namaBidan <<";" << dataBidan[c].provBidan <<";" << dataBidan[c].tglLahirBidan <<";" << dataBidan[c].tmptLahirBidan <<";" << dataBidan[c].noHp <<";" << dataBidan[c].jlnBidan <<";" << dataBidan[c].rtBidan << ";" << dataBidan[c].rwBidan << ";" << dataBidan[c].desaBidan << ";" << dataBidan[c].kecBidan <<";" << dataBidan[c].kabBidan << endl;
          system("clear");
          cout << "----------------------------------------------" << endl;
          cout << "Alamat Kec Berhasil Di Edit Ke -> " << newBID.kecBidanEDIT;
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << endl;
        } else {
          tulisnew << dataBidan[c].NIP << ";" << dataBidan[c].nikBidan <<";" << dataBidan[c].namaBidan <<";" << dataBidan[c].provBidan <<";" << dataBidan[c].tglLahirBidan <<";" << dataBidan[c].tmptLahirBidan <<";" << dataBidan[c].noHp <<";" << dataBidan[c].jlnBidan <<";" << dataBidan[c].rtBidan << ";" << dataBidan[c].rwBidan << ";" << dataBidan[c].desaBidan << ";" << dataBidan[c].kecBidan <<";" << dataBidan[c].kabBidan << endl;;
        }
      }
      tulisnew.close();

      break;
      }//tutup case
    case 7: {
      cout << endl;
      cout << "----------------------------------------------" << endl;
      cout << " Masukkan Alamat Kab/Kota Bidan Yang Ingin di Edit : ";
      cin >> newBID.kabBidanEDIT;
      cout << "----------------------------------------------" << endl;

      tulisnew.open("databidan.txt");
      for (int c = 0; c < idxt - 1; ++c) {
        if (c == datakeED) {
          dataBidan[c].kabBidan = newBID.kabBidanEDIT;
          
          tulisnew << dataBidan[c].NIP << ";" << dataBidan[c].nikBidan <<";" << dataBidan[c].namaBidan <<";" << dataBidan[c].provBidan <<";" << dataBidan[c].tglLahirBidan <<";" << dataBidan[c].tmptLahirBidan <<";" << dataBidan[c].noHp <<";" << dataBidan[c].jlnBidan <<";" << dataBidan[c].rtBidan << ";" << dataBidan[c].rwBidan << ";" << dataBidan[c].desaBidan << ";" << dataBidan[c].kecBidan <<";" << dataBidan[c].kabBidan << endl;
          system("clear");
          cout << "----------------------------------------------" << endl;
          cout << "Alamat Kab/Kota Berhasil Di Edit Ke -> " << newBID.kabBidanEDIT;
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << endl;
        } else {
          tulisnew << dataBidan[c].NIP << ";" << dataBidan[c].nikBidan <<";" << dataBidan[c].namaBidan <<";" << dataBidan[c].provBidan <<";" << dataBidan[c].tglLahirBidan <<";" << dataBidan[c].tmptLahirBidan <<";" << dataBidan[c].noHp <<";" << dataBidan[c].jlnBidan <<";" << dataBidan[c].rtBidan << ";" << dataBidan[c].rwBidan << ";" << dataBidan[c].desaBidan << ";" << dataBidan[c].kecBidan <<";" << dataBidan[c].kabBidan << endl;;
        }
      }
      tulisnew.close();

      break;
      }//tutup case
    case 8: {
      cout << endl;
      cout << "----------------------------------------------" << endl;
      cout << " Masukkan Alamat Provinsi Bidan Yang Ingin di Edit : ";
      cin >> newBID.provBidanEDIT;
      cout << "----------------------------------------------" << endl;

      tulisnew.open("databidan.txt");
      for (int c = 0; c < idxt - 1; ++c) {
        if (c == datakeED) {
          dataBidan[c].provBidan = newBID.provBidanEDIT;
          
          tulisnew << dataBidan[c].NIP << ";" << dataBidan[c].nikBidan <<";" << dataBidan[c].namaBidan <<";" << dataBidan[c].provBidan <<";" << dataBidan[c].tglLahirBidan <<";" << dataBidan[c].tmptLahirBidan <<";" << dataBidan[c].noHp <<";" << dataBidan[c].jlnBidan <<";" << dataBidan[c].rtBidan << ";" << dataBidan[c].rwBidan << ";" << dataBidan[c].desaBidan << ";" << dataBidan[c].kecBidan <<";" << dataBidan[c].kabBidan << endl;
          system("clear");
          cout << "----------------------------------------------" << endl;
          cout << "Alamat Provinsi Berhasil Di Edit Ke -> " << newBID.provBidanEDIT;
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << endl;
        } else {
          tulisnew << dataBidan[c].NIP << ";" << dataBidan[c].nikBidan <<";" << dataBidan[c].namaBidan <<";" << dataBidan[c].provBidan <<";" << dataBidan[c].tglLahirBidan <<";" << dataBidan[c].tmptLahirBidan <<";" << dataBidan[c].noHp <<";" << dataBidan[c].jlnBidan <<";" << dataBidan[c].rtBidan << ";" << dataBidan[c].rwBidan << ";" << dataBidan[c].desaBidan << ";" << dataBidan[c].kecBidan <<";" << dataBidan[c].kabBidan << endl;;
        }
      }
      tulisnew.close();

      break;
      }//tutup case
    }//tutup switch 
  }//tutup if
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirm;
}






void Admin::hpsdataBIDAN(){
  int idxt = 0;
    string t;
    ambil.open("databidan.txt");
    while (!ambil.eof()) {
      ambil >> t;
      tokenizeBd(t, ";", idxt);
      idxt++;
    }
    ambil.close();

    system("clear");
    cout << "Berikut Daftar bidan...";
    for (int j = 0; j < idxt - 1; j++) {
      cout << endl;
      cout << "----------------------------------------------" << endl;
      cout << "NIP bidan     : " << dataBidan[j].NIP;
      cout << endl;
      cout << "NIK Bidan     : " << dataBidan[j].nikBidan;
      cout << endl;
      cout << "Nama Bidan    : " << dataBidan[j].namaBidan;
      cout << endl;
      cout << "TTL Bidan     : " << dataBidan[j].tmptLahirBidan << ","
           << dataBidan[j].tglLahirBidan;
      cout << endl;
      cout << "Alamat Bidan  :  Jln " << dataBidan[j].jlnBidan;
      cout << endl;
      cout << "                 RT/RW     : " << dataBidan[j].rtBidan << "/"
           << dataBidan[j].rwBidan;
      cout << endl;
      cout << "                 Kel/desa  : " << dataBidan[j].desaBidan;
      cout << endl;
      cout << "                 Kec       : " << dataBidan[j].kecBidan;
      cout << endl;
      cout << "                 Kab/Kota  : " << dataBidan[j].kabBidan;
      cout << endl;
      cout << "                 Provinsi  : " << dataBidan[j].provBidan;
      cout << endl;
      cout << "No HP Bidan   : " << dataBidan[j].noHp;
      cout << endl;
      cout << "----------------------------------------------" << endl;
    }

  string pilNIP;
  bool ketemu = false;
  int datake;
  cout << endl << endl;
  cout << "Silahkan Pilih NIP BIDAN Yang Ingin DiHapus : ";
  cin >> pilNIP;
  for (int i = 0; i < idxt - 1; i++) {
    if (pilNIP == dataBidan[i].NIP) {
      ketemu = true;
      datake = i;
      break;
    }
  }
  if (ketemu == true) {
    ofstream tulis;
    tulis.open("databidan.txt");
    for (int i = 0; i < idxt - 1; ++i) {
      if (i != datake) {
        tulis << dataBidan[i].NIP << ";" << dataBidan[i].nikBidan <<";" << dataBidan[i].namaBidan <<";" << dataBidan[i].provBidan <<";" << dataBidan[i].tglLahirBidan <<";" << dataBidan[i].tmptLahirBidan <<";" << dataBidan[i].noHp <<";" << dataBidan[i].jlnBidan <<";" << dataBidan[i].rtBidan << ";" << dataBidan[i].rwBidan << ";" << dataBidan[i].desaBidan << ";" << dataBidan[i].kecBidan <<";" << dataBidan[i].kabBidan << endl;
      }
    }
    tulis.close();
    cout << "----------------------------------------------" << endl;
    cout << "NIP BIDAN Yang Anda Pilih Berhasil Di Hapus ";
    cout << endl;
    cout << "----------------------------------------------" << endl;
  }
  
  
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirm;
}



void Admin::historyPendapatan() {
  system("clear");
  cout << "Berikut History Pendapatan Posyandu...";
  cout << endl;
  int idxtph = 0;
  string tph;

  stack hispen;

  int total, hari, bulan, tahun;

  ambilhpenB.open("tulishistory.txt");
  while (!ambilhpenB.eof()) {
    ambilhpenB >> tph;
    tokenizeHP(tph, ";", idxtph);
    idxtph++;
  }
  ambilhpenB.close();

  for (int jpxq = 0; jpxq < idxtph - 1; jpxq++) {

    hispen.pushArray(hpen[jpxq].tglp, hpen[jpxq].blnp, hpen[jpxq].thp,
                     hpen[jpxq].totalp);
  }
  // tampil
  // hispen.tampil();

  // tampilsatusatu
  while (!hispen.isempty()) {
    // tulishpen.open("dataHistoryPendapatan.txt");
    // if(!tulishpen.fail()){
    //   tulishpen << "Tanggal/Bulan/Tahun : " << hispen.ambilatasTgl() << "/"
    //   << hispen.ambilatasBulan() << "/" << hispen.ambilatastahun() << endl;
    // tulishpen << "Total               : "<< hispen.ambilatasTotal() << endl;
    // }
    // else{
    //   cout << "error";
    // }

    cout << "----------------------------------------------" << endl;
    cout << "Tanggal/Bulan/Tahun : " << hispen.ambilatasTgl() << "/"
         << hispen.ambilatasBulan() << "/" << hispen.ambilatastahun();
    cout << endl;
    cout << "Total               : " << hispen.ambilatasTotal();
    cout << endl;
    cout << "----------------------------------------------" << endl;

    hispen.popStack();
  }

  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirm;
};

void Admin::editdataBalita() {

  int idxbq = 0;
  string tbq;
  ambilb.open("dataBalita.txt");

  while (!ambilb.eof()) {
    ambilb >> tbq;
    tokenizeBB(tbq, ";", idxbq);
    idxbq++;
  }
  ambilb.close();
  cout << "Berikut Daftar Balita Yang Tersedia..." << endl;
  for (int s = 0; s < idxbq - 1; s++) {
    cout << "----------------------------------------------" << endl;
    cout << " No Rekam Medis    : " << blt[s].Norekam;
    cout << endl;
    cout << " Nama Balita       : " << blt[s].namaBal;
    cout << endl;
    cout << " Nama Ibu          : " << blt[s].ibBal;
    cout << endl;
    cout << " Tinggi Balita     : " << blt[s].tingBal;
    cout << endl;
    cout << " Berat Balita      : " << blt[s].bertBal;
    cout << endl;
    cout << " Umur Balita       : " << blt[s].umrBal;
    cout << endl;
    cout << "----------------------------------------------" << endl;
  }  
    string pilNamBal;
  bool ketemu = false;
  int datakeED;

  cout << endl;
  cout << "Silahkan Pilih Nama Balita Yang Ingin DiEdit : ";
  cin >> pilNamBal;

  for (int b = 0; b < idxbq - 1; b++) {
    if (pilNamBal == blt[b].namaBal) {
      ketemu = true;
      datakeED = b;
      break;
    }
  }
  if (ketemu == true) {
  editdatabal:
    cout << "----------------------------------------------" << endl;
    cout << endl;
    cout << "Menu Edit Data Balita";
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "1. Edit Tinggi Balita ";
    cout << endl;
    cout << "2. Edit Berat Balita ";
    cout << endl;
    cout << "3. Edit Umur Balita ";
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << " Masukkan Pilihan [1/2/3] : ";
    cin >> pilmenuEdit;

  switch (pilmenuEdit) {
    case 1: {
      cout << endl;
      cout << "----------------------------------------------" << endl;
      cout << " Masukkan Tinggi Balita Yang Ingin di Edit : ";
      cin >> newBL.tingBalEdit;
      cout << "----------------------------------------------" << endl;

      tulisnew.open("dataBalita.txt");
      for (int c = 0; c < idxbq - 1; ++c) {
        if (c == datakeED) {
          blt[c].tingBal = newBL.tingBalEdit;
          tulisnew << blt[c].Norekam << ";" << blt[c].namaBal << ";" <<  blt[c].ibBal
                   << ";" << blt[c].tingBal << ";" << blt[c].bertBal << ";" << blt[c].umrBal << endl;
          system("clear");
          cout << "----------------------------------------------" << endl;
          cout << "Tinggi Balita Berhasil Di Edit Ke -> " << newBL.tingBalEdit;
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << endl;
        } else {
          tulisnew << blt[c].Norekam << ";" << blt[c].namaBal << ";" <<  blt[c].ibBal
                   << ";" << blt[c].tingBal << ";" << blt[c].bertBal << ";" << blt[c].umrBal << endl;
        }
      }
      tulisnew.close();

      break;
      }//tutup case
    case 2: {
      cout << endl;
      cout << "----------------------------------------------" << endl;
      cout << " Masukkan Berat Balita Yang Ingin di Edit : ";
      cin >> newBL.brtBalEdit;
      cout << "----------------------------------------------" << endl;

      tulisnew.open("dataBalita.txt");
      for (int c = 0; c < idxbq - 1; ++c) {
        if (c == datakeED) {
          blt[c].bertBal = newBL.brtBalEdit;
          tulisnew << blt[c].Norekam << ";" << blt[c].namaBal << ";" <<  blt[c].ibBal
                   << ";" << blt[c].tingBal << ";" << blt[c].bertBal << ";" << blt[c].umrBal << endl;
          system("clear");
          cout << "----------------------------------------------" << endl;
          cout << "Tinggi Balita Berhasil Di Edit Ke -> " << newBL.brtBalEdit;
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << endl;
        } else {
          tulisnew << blt[c].Norekam << ";" << blt[c].namaBal << ";" <<  blt[c].ibBal
                   << ";" << blt[c].tingBal << ";" << blt[c].bertBal << ";" << blt[c].umrBal << endl;
        }
      }
      tulisnew.close();

      break;
      }//tutup case
    case 3: {
      cout << endl;
      cout << "----------------------------------------------" << endl;
      cout << " Masukkan Umur Balita Yang Ingin di Edit : ";
      cin >> newBL.umrBalbEdit;
      cout << "----------------------------------------------" << endl;

      tulisnew.open("dataBalita.txt");
      for (int c = 0; c < idxbq - 1; ++c) {
        if (c == datakeED) {
          blt[c].umrBal = newBL.umrBalbEdit;
          tulisnew << blt[c].Norekam << ";" << blt[c].namaBal << ";" <<  blt[c].ibBal
                   << ";" << blt[c].tingBal << ";" << blt[c].bertBal << ";" << blt[c].umrBal << endl;
          system("clear");
          cout << "----------------------------------------------" << endl;
          cout << "Tinggi Balita Berhasil Di Edit Ke -> " << newBL.umrBalbEdit;
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << endl;
        } else {
          tulisnew << blt[c].Norekam << ";" << blt[c].namaBal << ";" <<  blt[c].ibBal
                   << ";" << blt[c].tingBal << ";" << blt[c].bertBal << ";" << blt[c].umrBal << endl;
        }
      }
      tulisnew.close();

      break;
      }//tutup case
    }//tutup switch  
    
    
  
    
  }
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirm;
}

void Admin::editdataObat() {
  int idxr = 0;
  string to;
  ambilo.open("dataobat.txt");
  while (!ambilo.eof()) {
    ambilo >> to;
    tokenize1(to, ";", idxr);
    idxr++;
    // X.ReSize(idx);
  }
  ambil.close();
  system("clear");
  cout << "Berikut Data Yang Tersedia...";
  cout << endl;
  for (int q = 0; q < idxr - 1; q++) {
    cout << "----------------------------------------------" << endl;
    cout << "ID Obat     : " << obt[q].id;
    cout << endl;
    cout << "nama Obat   : " << obt[q].nama;
    cout << endl;
    cout << "stok Obat   : " << obt[q].stok;
    cout << endl;
    cout << "harga Obat  : " << obt[q].harga;
    cout << endl;
    cout << "----------------------------------------------" << endl;
  }

  string pilihid;
  bool ketemu = false;
  int datakeED;

  cout << endl;
  cout << "Silahkan Pilih (ID) Obat Yang Ingin DiEdit : ";
  cin >> pilihid;

  for (int b = 0; b < idxr - 1; b++) {
    if (pilihid == obt[b].id) {
      ketemu = true;
      datakeED = b;
      break;
    }
  }
  if (ketemu == true) {
  editdatavak:
    cout << "----------------------------------------------" << endl;
    cout << endl;
    cout << "Menu Edit Data Obat";
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "1. Edit Nama Obat ";
    cout << endl;
    cout << "2. Edit Stok Obat ";
    cout << endl;
    cout << "3. Edit Harga Obat ";
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << " Masukkan Pilihan [1/2/3] : ";
    cin >> pilmenuEdit;
    switch (pilmenuEdit) {
    case 1: {
      cout << endl;
      cout << "----------------------------------------------" << endl;
      cout << " Masukkan Nama Obat Yang Ingin di Edit : ";
      cin >> newOB.namaObEdit;
      cout << "----------------------------------------------" << endl;

      tulisnew.open("dataobat.txt");
      for (int c = 0; c < idxr - 1; ++c) {
        if (c == datakeED) {
          obt[c].nama = newOB.namaObEdit;
          tulisnew << obt[c].id << ";" << obt[c].nama << ";" << obt[c].stok
                   << ";" << obt[c].harga << endl;
          system("clear");
          cout << "----------------------------------------------" << endl;
          cout << "Nama Obat Berhasil Di Edit Ke -> " << newOB.namaObEdit;
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << endl;
        } else {
          tulisnew << obt[c].id << ";" << obt[c].nama << ";" << obt[c].stok
                   << ";" << obt[c].harga << endl;
        }
      }
      tulisnew.close();

      break;
    }
    case 2: {
      cout << endl;
      cout << "----------------------------------------------" << endl;
      cout << " Masukkan Stok Obat Yang Ingin di Edit : ";
      cin >> newOB.stokObEdit;
      cout << "----------------------------------------------" << endl;

      tulisnew.open("dataobat.txt");
      for (int c = 0; c < idxr - 1; ++c) {
        if (c == datakeED) {
          obt[c].stok = newOB.stokObEdit;
          tulisnew << obt[c].id << ";" << obt[c].nama << ";" << obt[c].stok
                   << ";" << obt[c].harga << endl;
          system("clear");
          cout << "----------------------------------------------" << endl;
          cout << "Stok Obat Berhasil Di Edit Ke -> " << newOB.stokObEdit;
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << endl;
        } else {
          tulisnew << obt[c].id << ";" << obt[c].nama << ";" << obt[c].stok
                   << ";" << obt[c].harga << endl;
        }
      }
      tulisnew.close();

      break;
    }
    case 3: {
      cout << endl;
      cout << "----------------------------------------------" << endl;
      cout << " Masukkan Harga Obat Yang Ingin di Edit : ";
      cin >> newOB.hargaObEdit;
      cout << "----------------------------------------------" << endl;

      tulisnew.open("data.txt");

      for (int c = 0; c < idxr - 1; ++c) {

        if (c == datakeED) {
          obt[c].harga = newOB.hargaObEdit;
          tulisnew << obt[c].id << ";" << obt[c].nama << ";" << obt[c].stok
                   << ";" << obt[c].harga << endl;
          system("clear");
          cout << "----------------------------------------------" << endl;
          cout << "Herga Obat Berhasil Di Edit Ke -> " << newOB.hargaObEdit;
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << endl;
        } else {
          tulisnew << obt[c].id << ";" << obt[c].nama << ";" << obt[c].stok
                   << ";" << obt[c].harga << endl;
        }
      }
      tulisnew.close();

      break;
    }
    default: {
      cout << " ulang " << endl;
      goto editdatavak;
      break;
    }
    }
  }
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirm;
}

void Admin::editdataVaksin() {
  system("clear");
  int idxed = 0;
  string ted;
  ambilnew.open("data.txt");
  while (!ambilnew.eof()) {
    ambilnew >> ted;
    tokenize(ted, ";", idxed);
    idxed++;
  }
  ambilnew.close();
  // ambildataDinamis();
  for (int a = 0; a < idxed - 1; a++) {
    cout << "----------------------------------------------" << endl;
    cout << "ID Vaksin     : " << brg[a].id;
    cout << endl;
    cout << "nama Vaksin   : " << brg[a].nama;
    cout << endl;
    cout << "stok Vaksin   : " << brg[a].stok;
    cout << endl;
    cout << "harga Vaksin  : " << brg[a].harga;
    cout << endl;
    cout << "----------------------------------------------" << endl;
  }

  string pilihid;
  bool ketemu = false;
  int datakeED;

  cout << endl << endl;
  cout << "Silahkan Pilih (ID) Vaksin Yang Ingin DiEdit : ";
  cin >> pilihid;

  for (int b = 0; b < idxed - 1; b++) {
    if (pilihid == brg[b].id) {
      ketemu = true;
      datakeED = b;
      break;
    }
  }

  if (ketemu == true) {
  editdatavak:
    cout << "----------------------------------------------" << endl;
    cout << "Menu Edit Data Vaksin";
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "1. Edit Nama Vaksin ";
    cout << endl;
    cout << "2. Edit Stok Vaksin ";
    cout << endl;
    cout << "3. Edit Harga Vaksin ";
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << " Masukkan Pilihan [1/2/3] : ";
    cin >> pilmenuEdit;
    switch (pilmenuEdit) {
    case 1: {
      cout << endl;
      cout << "----------------------------------------------" << endl;
      cout << " Masukkan Nama Vaksin Yang Ingin di Edit : ";
      cin >> newVak.namaEdit;
      cout << "----------------------------------------------" << endl;

      tulisnew.open("data.txt");
      for (int c = 0; c < idxed - 1; ++c) {
        if (c == datakeED) {
          brg[c].nama = newVak.namaEdit;
          tulisnew << brg[c].id << ";" << brg[c].nama << ";" << brg[c].stok
                   << ";" << brg[c].harga << endl;
          system("clear");
          cout << "----------------------------------------------" << endl;
          cout << "Nama Vaksin Berhasil Di Edit Ke -> " << newVak.namaEdit;
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << endl;
        } else {
          tulisnew << brg[c].id << ";" << brg[c].nama << ";" << brg[c].stok
                   << ";" << brg[c].harga << endl;
        }
      }
      tulisnew.close();

      break;
    }
    case 2: {
      cout << endl;
      cout << "----------------------------------------------" << endl;
      cout << " Masukkan Stok Vaksin Yang Ingin di Edit : ";
      cin >> newVak.stokEdit;
      cout << "----------------------------------------------" << endl;

      tulisnew.open("data.txt");
      for (int c = 0; c < idxed - 1; ++c) {
        if (c == datakeED) {
          brg[c].stok = newVak.stokEdit;
          tulisnew << brg[c].id << ";" << brg[c].nama << ";" << brg[c].stok
                   << ";" << brg[c].harga << endl;
          system("clear");
          cout << "----------------------------------------------" << endl;
          cout << "Stok Vaksin Berhasil Di Edit Ke -> " << newVak.stokEdit;
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << endl;
        } else {
          tulisnew << brg[c].id << ";" << brg[c].nama << ";" << brg[c].stok
                   << ";" << brg[c].harga << endl;
        }
      }

      tulisnew.close();
      break;
    }
    case 3: {
      cout << endl;
      cout << "----------------------------------------------" << endl;
      cout << " Masukkan Harga Vaksin Yang Ingin di Edit : ";
      cin >> newVak.hargaEdit;
      cout << "----------------------------------------------" << endl;

      tulisnew.open("data.txt");

      for (int c = 0; c < idxed - 1; ++c) {

        if (c == datakeED) {
          brg[c].harga = newVak.hargaEdit;
          tulisnew << brg[c].id << ";" << brg[c].nama << ";" << brg[c].stok
                   << ";" << brg[c].harga << endl;
          system("clear");
          cout << "----------------------------------------------" << endl;
          cout << "Harga Vaksin Berhasil Di Edit Ke -> " << newVak.hargaEdit;
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << endl;
        } else {
          tulisnew << brg[c].id << ";" << brg[c].nama << ";" << brg[c].stok
                   << ";" << brg[c].harga << endl;
        }
      }
      tulisnew.close();

      break;
    }
    default: {
      cout << " ulang " << endl;
      goto editdatavak;
      break;
    }
    }
  }

  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirm;
}

void Admin::cetakNPWPbidan() {
  int indx = 0;
  string t;
  ambil.open("databidan.txt");
  while (!ambil.eof()) {
    ambil >> t;
    tokenizeBd(t, ";", indx);
    indx++;
  }
  ambil.close();
  system("clear");
  cout << endl;
  cout << "Berikut Daftar Bidan Yang Bertugas " << endl;
  for (int q = 0; q < indx - 1; q++) {
    cout << "----------------------------------------------" << endl;
    cout << "NIP bidan     : " << dataBidan[q].NIP;
    cout << endl;
    cout << "NIK Bidan     : " << dataBidan[q].nikBidan;
    cout << endl;
    cout << "Nama Bidan    : " << dataBidan[q].namaBidan;
    cout << endl;
    cout << "TTL Bidan     : " << dataBidan[q].tmptLahirBidan << ","
         << dataBidan[q].tglLahirBidan;
    cout << endl;
    cout << "Alamat Bidan  :  Jln " << dataBidan[q].jlnBidan;
    cout << endl;
    cout << "                 RT/RW     : " << dataBidan[q].rtBidan << "/"
         << dataBidan[q].rwBidan;
    cout << endl;
    cout << "                 Kel/desa  : " << dataBidan[q].desaBidan;
    cout << endl;
    cout << "                 Kec       : " << dataBidan[q].kecBidan;
    cout << endl;
    cout << "                 Kab/Kota  : " << dataBidan[q].kabBidan;
    cout << endl;
    cout << "                 Provinsi  : " << dataBidan[q].provBidan;
    cout << endl;
    cout << "No HP Bidan   : " << dataBidan[q].noHp;
    cout << endl;
    cout << "----------------------------------------------" << endl;
  }

  string pilihnip;
  bool ketemu = false;
  int datakeED;
  string Npwp;

  cout << endl << endl;
  cout << "----------------------------------------------" << endl;
  cout << "Silahkan Pilih NIP Bidan Yang Ingin Dicetak NPWP nya : ";
  cin >> pilihnip;
  cout << "----------------------------------------------" << endl;

  for (int b = 0; b < indx - 1; b++) {

    if (pilihnip == dataBidan[b].NIP) {
      ketemu = true;
      datakeED = b;
      break;
    }
  }
  if (ketemu == true) {
    for (int c = 0; c < indx - 1; ++c) {
      if (c == datakeED) {
        cout << "Masukkan NPWP : ";
        cin >> Npwp;
        system("clear");
        cout << endl;
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << "KEMENTERIAN KEUANGAN REPUBLIK INDONESIA ";
        cout << endl;
        cout << "      DIREKTORAT JENDRAL PAJAK ";
        cout << endl;
        cout << endl;
        cout << "NPWP     : " << Npwp;
        cout << endl;
        cout << "Nama     : " << dataBidan[c].namaBidan;
        cout << endl;
        cout << "NIK      : " << dataBidan[c].nikBidan;
        cout << endl;
        // cout<<"Alamat   : "<< dataBidan[c].provBidan;
        cout << endl;
        cout << "Jalan " << dataBidan[c].jlnBidan << " RT "
             << dataBidan[c].rtBidan << "  RW " << dataBidan[c].rwBidan << "  "
             << dataBidan[c].desaBidan << "  ";
        cout << endl;
        cout << dataBidan[c].kecBidan << "  " << dataBidan[c].kabBidan << " "
             << dataBidan[c].provBidan;
        cout << endl;
        cout << endl;
        cout << "             KPP Pratama Yogyakarta";
        cout << endl;
        cout << "----------------------------------------------" << endl;
      }
    }
  }
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirm;
}



void Admin::hapusdataBalita() {
  int idxb = 0;
  string tb;
  ambilb.open("dataBalita.txt");

  while (!ambilb.eof()) {
    ambilb >> tb;
    tokenizeBB(tb, ";", idxb);
    idxb++;
  }
  ambilb.close();
  for (int s = 0; s < idxb - 1; s++) {
    cout << "----------------------------------------------" << endl;
    cout << " No Rekam Medis    : " << blt[s].Norekam;
    cout << endl;
    cout << " Nama Balita       : " << blt[s].namaBal;
    cout << endl;
    cout << " Nama Ibu          : " << blt[s].ibBal;
    cout << endl;
    cout << " Tinggi Balita     : " << blt[s].tingBal;
    cout << endl;
    cout << " Berat Balita      : " << blt[s].bertBal;
    cout << endl;
    cout << " Umur Balita       : " << blt[s].umrBal;
    cout << endl;
    cout << "----------------------------------------------" << endl;
  }
  string pilihnama;
  bool ketemu = false;
  int datake;
  cout << endl << endl;
  cout << "Silahkan Pilih Nama Balita Yang Ingin DiHapus : ";
  cin >> pilihnama;
  for (int i = 0; i < idxb - 1; i++) {
    if (pilihnama == blt[i].namaBal) {
      ketemu = true;
      datake = i;
      break;
    }
  }
  if (ketemu == true) {
    ofstream tulis;
    tulis.open("dataBalita.txt");
    for (int i = 0; i < idxb - 1; ++i) {
      if (i != datake) {
        tulis << blt[i].Norekam << ";" << blt[i].namaBal << ";" << blt[i].ibBal
              << ";" << blt[i].tingBal << ";" << blt[i].bertBal << ";"
              << blt[i].umrBal << endl;
      }
    }
    tulis.close();
    cout << "----------------------------------------------" << endl;
    cout << "Data Balita Yang Anda Pilih Berhasil Di Hapus ";
    cout << endl;
    cout << "----------------------------------------------" << endl;
  }
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirm;
}

void Admin::tambahdata() {
  int sz;
  tulis.open("data.txt", ios::app);
  cout << endl;
  cout << "Berikut Tambah Data Vaksin Posyandu Bahagia...";
  cout << endl;
  cout << endl;
  cout << "Silahakan Tambah Data Vaskin...";
  cout << endl;
  cout << "----------------------------------------------" << endl;
  cout << "Ingin Menanbah Berapa data : ";
  cin >> sz;
  for (int z = 0; z < sz; z++) {
    cout << "----------------------------------------------" << endl;
    cout << "Masukkan ID          : ";
    cin >> id;
    cout << "Masukkan Nama Vaskin : ";
    cin >> nama;
    cout << "Masukkan Stok        : ";
    cin >> stok;
    cout << "Masukkan Harga       : ";
    cin >> harga;
    cout << "----------------------------------------------" << endl;
    tulis << id << ";" << nama << ";" << stok << ";" << harga;
    cout << endl;
    cout << nama << " Berhasil Di Tambahakan!!!";
    cout << endl;
    cout << endl;
  }
  tulis.close();
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirm;
}

void Admin::tambahdataobat() {
  int sz;
  tulis.open("dataobat.txt", ios::app);
  cout << endl;
  cout << "Berikut Tambah Data Obat Posyandu Bahagia..." << endl;
  cout << endl;
  cout << "Silahakan Tambah Data Obat..." << endl;
  cout << "----------------------------------------------" << endl;
  cout << "Ingin Menambah Berapa data : ";
  cin >> sz;
  for (int z = 0; z < sz; z++) {
    cout << "----------------------------------------------" << endl;
    cout << "Masukkan ID          : ";
    cin >> id;
    cout << "Masukkan Nama Obat   : ";
    cin >> nama;
    cout << "Masukkan Stok        : ";
    cin >> stok;
    cout << "Masukkan Harga       : ";
    cin >> harga;
    cout << "----------------------------------------------" << endl;
    tulis << id << ";" << nama << ";" << stok << ";" << harga << endl;
    cout << "Vaksin" << nama << " Berhasil Di Tambahakan!!!";
    cout << endl;
    cout << endl;
  }
  tulis.close();
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirm;
}

void Admin::lihatdataDinamis() {
  ambildataDinamis();
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirm;
}

// void Admin::lihatdataobat() {
//   Lihatdataobat();
//   cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
//   cin >> konfirm;
// }

void Admin::hapusdata() {
  system("clear");
  int idx = 0;
  string t;
  ambil.open("data.txt");
  while (!ambil.eof()) {
    ambil >> t;
    tokenize(t, ";", idx);
    idx++;
  }
  ambil.close();
  cout << "Vaksin Yang Tersedia...";
  cout << endl;
  // ambildataDinamis();
  for (int i = 0; i < idx - 1; i++) {
    cout << "----------------------------------------------" << endl;
    cout << "ID Vaksin     : " << brg[i].id;
    cout << endl;
    cout << "nama Vaksin   : " << brg[i].nama;
    cout << endl;
    cout << "stok Vaksin   : " << brg[i].stok;
    cout << endl;
    cout << "harga Vaksin  : " << brg[i].harga;
    cout << endl;
    cout << "----------------------------------------------" << endl;
  }
  string pilihid;
  bool ketemu = false;
  int datake;
  cout << endl << endl;
  cout << "Silahkan Pilih (ID) Data Yang Ingin DiHapus : ";
  cin >> pilihid;
  for (int i = 0; i < idx - 1; i++) {
    if (pilihid == brg[i].id) {
      ketemu = true;
      datake = i;
      break;
    }
  }
  if (ketemu == true) {
    ofstream tulis;
    tulis.open("data.txt");
    for (int i = 0; i < idx - 1; ++i) {
      if (i != datake) {
        tulis << brg[i].id << ";" << brg[i].nama << ";" << brg[i].stok << ";"
              << brg[i].harga;
        cout << endl;
      }
    }
    tulis.close();
    cout << "----------------------------------------------" << endl;
    cout << "ID Vaksin Yang Anda Pilih Berhasil Di Hapus ";
    cout << endl;
    cout << "----------------------------------------------" << endl;
  }
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirm;
}

void Admin::hapusdataobat() {
  int idx = 0;
  string t;
  ambil.open("dataobat.txt");
  while (!ambil.eof()) {
    ambil >> t;
    tokenize(t, ";", idx);
    idx++;
  }
  ambil.close();
  // ambildataDinamis();
  for (int i = 0; i < idx - 1; i++) {
    cout << "----------------------------------------------" << endl;
    cout << "ID Obat     : " << obt[i].id;
    cout << endl;
    cout << "nama Obat   : " << obt[i].nama;
    cout << endl;
    cout << "stok Obat   : " << obt[i].stok;
    cout << endl;
    cout << "harga Obat  : " << obt[i].harga;
    cout << endl;
    cout << "----------------------------------------------" << endl;
  }
  string pilihid;
  bool ketemu = false;
  int datake;
  cout << endl << endl;
  cout << "Silahkan Pilih (ID) Data Yang Ingin DiHapus : ";
  cin >> pilihid;
  for (int i = 0; i < idx - 1; i++) {
    if (pilihid == obt[i].id) {
      ketemu = true;
      datake = i;
      break;
    }
  }
  if (ketemu == true) {
    ofstream tulis;
    tulis.open("dataobat.txt");
    for (int i = 0; i < idx - 1; ++i) {
      if (i != datake) {
        tulis << obt[i].id << ";" << obt[i].nama << ";" << obt[i].stok << ";"
              << obt[i].harga << endl;
      }
    }
    tulis.close();
    cout << "----------------------------------------------" << endl;
    cout << "ID Obat Yang Anda Pilih Berhasil Di Hapus ";
    cout << endl;
    cout << "----------------------------------------------" << endl;
  }
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirm;
}

void Admin::restok() {
  ambildataLogin();
  system("clear");
  int idx = 0;
  string t;
  ambil.open("data.txt");
  while (!ambil.eof()) {
    ambil >> t;
    tokenize(t, ";", idx);
    idx++;
  }
  ambil.close();
  cout << "Vaksin Yang Tersedia..." << endl;
  for (int i = 0; i < idx - 1; i++) {
    cout << "----------------------------------------------" << endl;
    cout << "ID Vaksin     : " << brg[i].id;
    cout << endl;
    cout << "nama Vaksin   : " << brg[i].nama;
    cout << endl;
    cout << "stok Vaksin   : " << brg[i].stok;
    cout << endl;
    cout << "harga Vaksin  : " << brg[i].harga;
    cout << endl;
    cout << "----------------------------------------------" << endl;
  }
  string pilihid;
  bool ketemu = false;
  int datake;
  cout << endl << endl;
  cout << "Berikut Menu Restok Vaksin...";
  cout << endl;
  cout << endl;
  cout << "----------------------------------------------" << endl;
  cout << "Silahkan Pilih (ID) Data Yang Ingin DiRestok : ";
  cin >> pilihid;
  for (int i = 0; i < idx - 1; i++) {
    if (pilihid == brg[i].id) {
      ketemu = true;
      datake = i;
      break;
    }
  }
  if (ketemu == true) {
    string RS;
    int tmbh;
    ofstream tulis;
    cin.ignore();
    cout << "Masukkan Departemen/Rumah sakit              : ";
    getline(cin, RS);
    cout << "Masukkan Jumlah Stok Yang Ingin DiTambahkan  : ";
    cin >> tmbh;
    cout << "----------------------------------------------" << endl;
    tulis.open("data.txt");
    for (int i = 0; i < idx - 1; ++i) {
      if (i == datake) {
        brg[i].stok = tmbh + brg[i].stok;
        tulis << brg[i].id << ";" << brg[i].nama << ";" << brg[i].stok << ";"
              << brg[i].harga << endl;
        system("clear");
        // data penanggung jawab di lengkapin sekalian
        cout << "                     Penanggung jawab : " << dataKTP.namaKTP;
        cout << endl;
        cout << "Stok Masuk Dari Rumah Sakit/Departemen : " << RS;
        cout << endl;
        cout << "----------------------------------------------";
        cout << endl;
        cout << "ID \tNAMA BARANG\t    Stok Masuk\t TOTAL ";
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << brg[i].id << "\t" << brg[i].nama << "\t   " << tmbh << "\t\t  "
             << brg[i].stok;
        cout << endl;
        cout << "----------------------------------------------" << endl;
      } else {
        tulis << brg[i].id << ";" << brg[i].nama << ";" << brg[i].stok << ";"
              << brg[i].harga << endl;
      }
    }
    tulis.close();
  }
  cout << endl;
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirm;
}

void Admin::restokObat() {
  ambildataLogin();
  system("clear");
  int idxp = 0;
  string ty;
  ambil.open("dataobat.txt");
  while (!ambil.eof()) {
    ambil >> ty;
    tokenize1(ty, ";", idxp);
    idxp++;
    // X.ReSize(idx);
  }
  ambil.close();
  for (int q = 0; q < idxp - 1; q++) {
    cout << "----------------------------------------------" << endl;
    cout << "ID Obat     : " << obt[q].id;
    cout << endl;
    cout << "nama Obat   : " << obt[q].nama;
    cout << endl;
    cout << "stok Obat   : " << obt[q].stok;
    cout << endl;
    cout << "harga Obat  : " << obt[q].harga;
    cout << endl;
    cout << "----------------------------------------------" << endl;
  }
  string pilihid;
  bool ketemu = false;
  int datake;
  cout << endl << endl;
  cout << "Berikut Menu Restok Obat...";
  cout << endl;
  cout << endl;
  cout << "----------------------------------------------" << endl;
  cout << "Silahkan Pilih (ID) Data Yang Ingin DiRestok : ";
  cin >> pilihid;
  for (int i = 0; i < idxp - 1; i++) {
    if (pilihid == obt[i].id) {
      ketemu = true;
      datake = i;
      break;
    }
  }
  if (ketemu == true) {
    string RS;
    int tmbh;
    ofstream tulis;
    cin.ignore();
    cout << "Masukkan Departemen/Rumah sakit              : ";
    getline(cin, RS);
    cout << "Masukkan Jumlah Stok Yang Ingin DiTambahkan  : ";
    cin >> tmbh;
    cout << "----------------------------------------------" << endl;
    tulis.open("dataobat.txt");
    for (int i = 0; i < idxp - 1; ++i) {
      if (i == datake) {
        obt[i].stok = tmbh + obt[i].stok;
        tulis << obt[i].id << ";" << obt[i].nama << ";" << obt[i].stok << ";"
              << obt[i].harga << endl;
        system("clear");
        // data penanggung jawab di lengkapin sekalian
        cout << "                     Penanggung jawab : " << dataKTP.namaKTP;
        cout << endl;
        cout << "Stok Masuk Dari Rumah Sakit/Departemen : " << RS;
        cout << endl;
        cout << "----------------------------------------------";
        cout << endl;
        cout << "ID \tNAMA BARANG\t    Stok Masuk\t TOTAL ";
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << obt[i].id << "\t" << obt[i].nama << "\t   " << tmbh << "\t\t  "
             << obt[i].stok;
        cout << endl;
        cout << "----------------------------------------------" << endl;
      } else {
        tulis << obt[i].id << ";" << obt[i].nama << ";" << obt[i].stok << ";"
              << obt[i].harga << endl;
      }
    }
    tulis.close();
  }
  cout << endl;
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirm;
}

int Admin::menu() {

  cout << endl;
  cout << "|------------------Menu Admin-----------------|";
  cout << endl;
  cout << "| \t\t\t\t\t\t\t\t\t\t\t  |" << endl;
  cout << "|---------------------------------------------|" << endl;
  cout << "| Main Menu Admin Posyandu Bahagia\t\t\t  |";
  cout << endl;
  cout << "|---------------------------------------------|" << endl;
  cout << "| 1.  Tambah Data Vaskin\t\t\t\t\t  | ";
  cout << endl;
  cout << "| 2.  Lihat Data Vaksin \t\t\t\t\t  | ";
  cout << endl;
  cout << "| 3.  Hapus Data Vaksin\t\t\t\t\t\t  | ";
  cout << endl;
  cout << "| 4.  Edit Data Vaksin\t\t\t\t\t\t  | ";
  cout << endl;
  cout << "| 5.  Restok Vaksin\t\t\t\t\t\t\t  | ";
  cout << endl;
  cout << endl;

  cout << "| 6.  Tambah Data Balita\t\t\t\t\t  | ";
  cout << endl;
  cout << "| 7.  Lihat Data Balita\t\t\t\t\t\t  | ";
  cout << endl;
  cout << "| 8.  Hapus Data Balita\t\t\t\t\t\t  | ";
  cout << endl;
  cout << "| 9.  Edit Data Balita\t\t\t\t\t\t  | ";
  cout << endl;
  cout << "| 10. Proses Antrian Cek Kesehatan Balita\t  | ";
  cout << endl;
  cout << endl;

  cout << "| 11. Tambah Data Obat\t\t\t\t\t\t  | ";
  cout << endl;
  cout << "| 12. Lihat Data Obat \t\t\t\t\t\t  |  ";
  cout << endl;
  cout << "| 13. Hapus Data Obat\t\t\t\t\t\t  | ";
  cout << endl;
  cout << "| 14. Edit Data Obat\t\t\t\t\t\t  | ";
  cout << endl;
  cout << "| 15. Restok Obat\t\t\t\t\t\t\t  | ";
  cout << endl;
  cout << endl;

  cout << "| 16. Tambah Data Bidan\t\t\t\t\t\t  | ";
  cout << endl;
  cout << "| 17. Lihat Data Bidan\t\t\t\t\t\t  | ";
  cout << endl;
  cout << "| 18. Hapus Data Bidan\t\t\t\t\t\t  | ";
  cout << endl;
  cout << "| 19. Edit Data Bidan\t\t\t\t\t\t  | ";
  cout << endl;
  cout << "| 20. Cetak NPWP Bidan\t\t\t\t\t\t  | ";
  cout << endl;
  cout << "| 21. Struktur Bidan (AVL)\t\t\t\t\t  | ";
  cout << endl;
  cout << endl;

  cout << "| 22. Lihat Data Pendapatan\t\t\t\t\t  | ";
  cout << endl;
  cout << "| 23. History Pendapatan\t\t\t\t\t  | ";
  cout << endl;
  cout << endl;

  cout << "| 24. Tambah Data Ibu Hamil\t\t\t\t\t  | ";
  cout << endl;
  cout << "| 25. Lihat Data Ibu Hamil\t\t\t\t\t  | ";
  cout << endl;
  cout << "| 26. Hapus Data Ibu Hamil\t\t\t\t\t  | ";
  cout << endl;
  cout << "| 27. Edit Data Ibu Hamil\t\t\t\t\t  |";
  cout << endl;
  cout << "| 28. Proses Antrian Cek Kesehatan Ibu Hamil  | ";
  cout << endl;
  cout << endl;
  cout << "| 29.  Tambah Data Pengumuman\t\t\t\t  | ";
  cout << endl;
  cout << "| 30.  Lihat Data Pengumuman\t\t\t\t  | ";
  cout << endl;
  cout << "| 31.  Hapus Data Pengumuman\t\t\t\t  | ";
  cout << endl;
  cout << "| 32.  Edit Data Pengumuman\t\t\t\t\t  | ";
  cout << endl;
  cout << endl;
  cout << "| 0.  Keluar \t\t\t\t\t\t\t      |";
  cout << endl;
  cout << "| \t\t\t\t\t\t\t\t\t\t\t  |";
  cout << endl;
  cout << "|------------------Menu Admin-----------------|";
  cout << endl;
  cout << "Masukkan Pilihan [01/02/03/04/05/06/07/08/09/10/ ";
  cout << endl;
  cout << "\t\t\t\t  11/12/13/14/15/16/17/18/19/20/ ";
  cout << endl;
  cout << "\t\t\t\t  21/22/23/24/25/26/27/28/29/30/ ";
  cout << endl;
  cout << "\t\t\t\t  31/32/0] : ";
  cin >> pilih;
  return pilih;
}