#include <fstream>
#include <iostream>
#include <sstream>
#include "bumil.h"
#include "quepriorityIBUHAMIL.h"
#include <stdlib.h>
#include <string>
using namespace std;



struct tambahDataBidan {
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
} tamBID;





struct Balitaa {
  int Norekam;
  string namaBal;
  string ibBal;
  double tingBal;
  double bertBal;
  int umrBal;
} bltt[1000];







struct AIbuHamill {
  int Anorekamib_hamil;
  string Anamaib_hamil;
  int Ausiakehamilan;
  int Ausiaib_hamil;
  int Aberatib_hamil;
  // int hplib_hamil;
  int Ahplib_TGL;
  int Ahplib_BLN;
  int Ahplib_TH;

} Aibhmll[100];




struct oraumum
{
  int kode;
  string tglLaksana;
  string jenis, pelaku,tempat, topik;
}; oraumum njejel[100];

struct pengum{
  string newjenis;
  string newpelaku;
}newp;


struct KTP
{
    string namatxt = "admin";
    string niktxt = "1";
    string provtxt;
    string tmpttxt;
    string tgltxt;
    //tambah sini
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
    string kabtxt;
    string goldartxt;
} toLogin[10];

class Login
{
private:
    // pengubah status
    bool statusAdmin = false;
    bool statusLogin = false;
    int indeks;
    string inputnama;
    string inputnik;
    string inputnamaL;
    string inputnikL;
    string provinput;

    //tambah ini
    string goldarinput;
    string kabinput;
    string jklmninput;
    string agamainput;
    string skawininput;
    string pekerjaaninput;
    string knegarainput;
    string tmptlahirinput;
    string tgllahirinput;

    string dusuninput;
    string rtinput;
    string rwinput;
    string desainput;
    string kecamataninput;

    int pilihanJK;
    int pilihanGD;
    int pilihanAG;
    int pilihanSK;
    int pilihanWN;


    ifstream jukut;
    bumil *IBH = new bumil[1000];
    


public:


    char konfirmation;


    void tokenizeIBHMLL(string sIBU, string delIBU = " ", int idxIBU = 0) {
    string tmpIBU;
    int iIBU = 1;
    int start, end = -1 * delIBU.size();

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
      start = end + delIBU.size();
      end = sIBU.find(delIBU, start);
      tmpIBU = sIBU.substr(start, end - start);

      if (iIBU == 1) 
      {
        Aibhmll[idxIBU].Anorekamib_hamil = toInt(tmpIBU);
      } 
      else if (iIBU  == 2) 
      {
        Aibhmll[idxIBU].Anamaib_hamil = tmpIBU;
      } 
      else if (iIBU  == 3) 
      {
        Aibhmll[idxIBU].Ausiakehamilan = toInt(tmpIBU);
      } 
      else if (iIBU  == 4) 
      {
        Aibhmll[idxIBU].Aberatib_hamil = toInt(tmpIBU);
      } 
      else if (iIBU  == 5) 
      {
        Aibhmll[idxIBU].Ausiaib_hamil = toInt(tmpIBU);
      } 
      else if (iIBU  == 6) 
      {
        Aibhmll[idxIBU].Ahplib_TGL = toInt(tmpIBU);
      } 
      else if (iIBU  == 7) 
      {
        Aibhmll[idxIBU].Ahplib_BLN = toInt(tmpIBU);
      } 
      else 
      {
        Aibhmll[idxIBU].Ahplib_TH = toInt(tmpIBU);
      }
      iIBU++;

    } while (end != -1);
  }

    
    
    void tokenize(string s, string del = " ", int idx = 0)
    {
        string tmp;
        int i = 1;
        int start, end = -1 * del.size();
        do
        {
            start = end + del.size();
            end = s.find(del, start);
            tmp = s.substr(start, end - start);

            if (i == 1)
            {
                toLogin[idx].namatxt = tmp;
            }
            else if (i == 2)
            {
                toLogin[idx].niktxt = tmp;
            }
            else if (i==3)
            {
                toLogin[idx].provtxt = tmp;
            }
            else if(i==4)
            {
               toLogin[idx].tmpttxt = tmp;
            }
            else if(i==5)
            {
               toLogin[idx].tgltxt = tmp;
            }
            else if(i==6)
            {
               toLogin[idx].dusun = tmp;
            }
            else if(i==7)
            {
               toLogin[idx].rt = tmp;
            }
            else if(i==8)
            {
               toLogin[idx].rw = tmp;
            }
            else if(i==9)
            {
               toLogin[idx].desa = tmp;
            }
            else if(i==10)
            {
               toLogin[idx].kec = tmp;
            }
            else if(i==11)
            {
               toLogin[idx].kabtxt = tmp;
            }
            else if(i==12)
            {
               toLogin[idx].agama = tmp;
            }
            else if(i==13)
            {
               toLogin[idx].stts = tmp;
            }
            else if(i==14)
            {
               toLogin[idx].kerja = tmp;
            }
            else if(i==15)
            {
               toLogin[idx].wn = tmp;
            }
            else if(i==16)
            {
               toLogin[idx].bh = tmp;
            }
            else if (i==17)
            {
              toLogin[idx].jk = tmp;
            }
            else 
            {
              toLogin[idx].goldartxt = tmp;
            }


          
            i++;

        } 
          while (end != -1);
    }


  int toInt(string x) {
    int y;

    stringstream ss;
    ss << x;
    ss >> y;

    return y;
  }


  double toDouble(string x) {
    double y;

    stringstream ss;
    ss << x;
    ss >> y;

    return y;
  }




   void tokenizeBBT(string sbt, string delbt = " ", int idxbt = 0) {
    string tmpbt;
    int i = 1;
    int startb, endb = -1 * delbt.size();
    do {
      startb = endb + delbt.size();
      endb = sbt.find(delbt, startb);
      tmpbt = sbt.substr(startb, endb - startb);

      if (i == 1) {
        bltt[idxbt].Norekam = toInt(tmpbt);

      } else if (i == 2) {
        bltt[idxbt].namaBal = tmpbt;

      } else if (i == 3) {
        bltt[idxbt].ibBal = tmpbt;
      } else if (i == 4) {
        bltt[idxbt].tingBal = toDouble(tmpbt);
      } else if (i == 5) {
        bltt[idxbt].bertBal = toDouble(tmpbt);
      } else {
        bltt[idxbt].umrBal = toInt(tmpbt);
      }
      i++;

    } while (endb != -1);
  }



   double penjum(double angka[], int n) {

    if (n < 0) {
      return 0;
    } else {
      return angka[n] + penjum(angka, n - 1);
    }
  }

  double tara(double w, int e) {
    double r = 0;
    r = w / e;
    return r;
  }








  void LihatdataBalita() {
    ifstream ambilb;
    double hasill;
    double hasilll;
    double tara1;
    double tara2;
    double duwur[1000];
    double abot[1000];
    int idxb = 0;
    string tb;
    ambilb.open("dataBalita.txt");

    while (!ambilb.eof()) {
      ambilb >> tb;
      tokenizeBBT(tb, ";", idxb);
      idxb++;
    }
    ambilb.close();
    cout << "Berikut Daftar Balita Yang Tersedia..." << endl;
    for (int s = 0; s < idxb - 1; s++) {
      cout << "----------------------------------------------" << endl;
      cout << " No Rekam medis    : " << bltt[s].Norekam;
      cout << endl;
      cout << " Nama Balita       : " << bltt[s].namaBal;
      cout << endl;
      cout << " Nama Ibu          : " << bltt[s].ibBal;
      cout << endl;
      cout << " Tinggi Balita     : " << bltt[s].tingBal;
      cout << endl;
      cout << " Berat Balita      : " << bltt[s].bertBal;
      cout << endl;
      cout << " Umur Balita       : " << bltt[s].umrBal;
      cout << endl;
      cout << "----------------------------------------------" << endl;

      duwur[s] = bltt[s].tingBal;
      abot[s] = bltt[s].bertBal;
    }
    hasill = penjum(duwur, idxb - 1);
    hasilll = penjum(abot, idxb - 1);
    tara1 = tara(hasill, idxb - 1);
    tara2 = tara(hasilll, idxb - 1);
    cout << "Rata-Rata Berat Badan  : " << tara2;
    cout << endl;
    cout << "Rata-Rata Tinggi Badan : " << tara1;
    cout << endl;
    cout << "----------------------------------------------";
    cout << endl;
    cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
    cin >> konfirmation;
  }



   void tokenizeIBML(string sIB, string delIB = " ", int idxIB = 0) {
    string tmpIB;
    int iIB = 1;
    int start, end = -1 * delIB.size();

    do {
      start = end + delIB.size();
      end = sIB.find(delIB, start);
      tmpIB = sIB.substr(start, end - start);

      if (iIB == 1) {
        IBH[idxIB].norekamib = toInt(tmpIB);
      } else if (iIB == 2) {
        IBH[idxIB].ibu_hamil = tmpIB;
      } else if (iIB == 3) {
        IBH[idxIB].usia_hamil = toInt(tmpIB);
      } else if (iIB == 4) {
        IBH[idxIB].brtib_hamil = toInt(tmpIB);
      } else if (iIB == 5) {
        IBH[idxIB].usiaib = toInt(tmpIB);
      } else if (iIB == 6) {
        IBH[idxIB].hpl_TGL = toInt(tmpIB);
      } else if (iIB == 7) {
        IBH[idxIB].hpl_BLN = toInt(tmpIB);
      } else {
        IBH[idxIB].hpl_TH = toInt(tmpIB);
      }
      iIB++;

    } while (end != -1);
  }







  void ambildataIbuha() {
    int idxibh = 0;
    string tibh;
    jukut.open("dataIbu_Hamil.txt");
    while (!jukut.eof()) {
      jukut >> tibh;
      tokenizeIBML(tibh, ";", idxibh);
      idxibh++;
    }
    jukut.close();
    system("clear");
    cout << "Berikut Data Ibu Hamil Yang Tersedia...";
    cout << endl;
    for (int h = 0; h < idxibh - 1; h++) {
      // cout << Aibhmll[h].Anamaib_hamil;

      cout << "----------------------------------------------" << endl;
      cout << "No Rekam Bumil            : ";
      cout << IBH[h].norekamib;
      cout << endl;
      cout << "Nama Bumil                : ";
      cout << IBH[h].ibu_hamil;
      cout << endl;
      cout << "Usia Kehamilan (bulan)    : ";
      cout << IBH[h].usia_hamil;
      cout << endl;
      cout << "Berat Bumil               : ";
      cout << IBH[h].brtib_hamil;
      cout << endl;
      cout << "Usia Bumil                : ";
      cout << IBH[h].usiaib;
      cout << endl;
      cout << "Hari Prediksi Lahir (HPL) : ";
      cout << IBH[h].hpl_TGL;
      cout << "/";
      cout << IBH[h].hpl_BLN;
      cout << "/";
      cout << IBH[h].hpl_TH;
      cout << endl;

      cout << "----------------------------------------------" << endl;

      
    }// tutup for

    cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
    cin >> konfirmation;
  }





   void proseslahantribumil() {
    system("clear");

    PriorityQueue Gasaakk;
    int idxibh = 0;
    string tibh;
    jukut.open("ibuhamilantri.txt");
    while (!jukut.eof()) {
      jukut >> tibh;
      tokenizeIBML(tibh, ";", idxibh);
      idxibh++;
    }
    jukut.close();

    for (int h = 0; h < idxibh - 1; h++) {

      Gasaakk.Enqueue(IBH[h].norekamib, IBH[h].ibu_hamil, IBH[h].usia_hamil,
                      IBH[h].brtib_hamil, IBH[h].usiaib, IBH[h].hpl_TGL,
                      IBH[h].hpl_BLN, IBH[h].hpl_TH);

      // buat for
    }
    if (Gasaakk.isEmpty()) {
      cout << "Tidak Ada Bumil Untuk DiPeriksa";
    } else {

      while (!Gasaakk.isEmpty()) {

        cout << "Berikut Data Antrian Bumil Yang Tersedia...";
        cout << endl;
        cout << "----------------------------------------------" << endl;
        cout << "No Rekam Bumil              : " << Gasaakk.Firstrekam();
        cout << endl;
        cout << "Nama Bumil                  : " << Gasaakk.FirstNama();
        cout << endl;
        cout << "Usia Kehamilan (bulan)      : " << Gasaakk.FirstUsiaHamil();
        cout << endl;
        cout << "Berat Bumil                 : " << Gasaakk.FirstBerat();
        cout << endl;
        cout << "Usia Bumil                  : " << Gasaakk.FirstUsiaIbu();
        cout << endl;
        cout << "Hari Prediksi Lahir (HPL)   : " << Gasaakk.FirstTGL() << "/"
             << Gasaakk.FirstBLN() << "/" << Gasaakk.FirstTH();
        cout << endl;
        cout << "----------------------------------------------" << endl;

        Gasaakk.Dequeue();
      }

      for (int h = 0; h < idxibh - 1; h++) {

        Gasaakk.Enqueue(IBH[h].norekamib, IBH[h].ibu_hamil, IBH[h].usia_hamil,
                        IBH[h].brtib_hamil, IBH[h].usiaib, IBH[h].hpl_TGL,
                        IBH[h].hpl_BLN, IBH[h].hpl_TH);

        // buat for
      }

      ofstream woyelah;

      cout << endl;
      // cout<< " sopo " << testersahaja.FirstNama()<<endl;
      char skuylah;
      cout << "Apakah Anda Ingin Memproses Antrian Bumil? [y/n] ";
      cin >> skuylah;
      if (skuylah == 'Y' || skuylah == 'y') {
        woyelah.open("bumilcek.txt");
        woyelah << Gasaakk.Firstrekam() << ";" << Gasaakk.FirstNama() << ";"
                << Gasaakk.FirstUsiaHamil() << ";" << Gasaakk.FirstBerat()
                << ";" << Gasaakk.FirstUsiaIbu() << ";" << Gasaakk.FirstTGL()
                << ";" << Gasaakk.FirstBLN() << ";" << Gasaakk.FirstTH();
        cout << endl;

        woyelah.close();
        //      cout << endl;
        //      cout << endl;
        system("clear");
        cout << "----------------------------------------------" << endl;
        cout << " Bunda Atas Nama " << Gasaakk.FirstNama()
             << " Telah Di Proses ";
        cout << endl;
        cout << "----------------------------------------------" << endl;
        Gasaakk.Dequeue();

        ofstream woilah;
        woilah.open("ibuhamilantri.txt");

        while (!Gasaakk.isEmpty()) {
          woilah << Gasaakk.Firstrekam() << ";" << Gasaakk.FirstNama() << ";"
                 << Gasaakk.FirstUsiaHamil() << ";" << Gasaakk.FirstBerat()
                 << ";" << Gasaakk.FirstUsiaIbu() << ";" << Gasaakk.FirstTGL()
                 << ";" << Gasaakk.FirstBLN() << ";" << Gasaakk.FirstTH()
                 << endl;
          Gasaakk.Dequeue();
        }
        woilah.close();

      } // tutup if
    }
    cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
    cin >> konfirmation;
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
        njejel[idxpng].kode = toInt(tpng);

      } else if (i == 2) {
        njejel[idxpng].jenis = tpng;

      } else if (i == 3) {
        njejel[idxpng].topik = tpng;
      }  else if (i == 4){
        njejel[idxpng].tglLaksana = tpng;
      } else if (i == 5){
        njejel[idxpng].pelaku = tpng;
      } else {
        njejel[idxpng].tempat = tpng;
      }
      
      i++;

    } while (endb != -1);
  }





    void tampildataIBU_Hamil();
    void tambahdataBalita() ;
    void tambahdataBidan();
    void hpsdataBUMIL();
    void editdataBUMIL();
    void tambahDataIBU_HAMIL();
    void tambahdata();
    void tambahdataobat();
    void pengumuman();
    void lihatPengumuman();
    void editPengumuman();
    void hpsPengumuman();
    void tulisKTP();
    void ambilKTP();
    void mainLogin();
    bool isLogin();
    bool isAdmin();
    int no;
} lo;






bool Login::isLogin()
{ 
  return statusLogin; 
}




bool Login::isAdmin() 
{ 
  return statusAdmin; 
}






void Login::tambahdataBalita() {
  int ssx;
  int no_rekam;
  ofstream tulisb;
  string namaBalita;
  string ibu;
  double tinggi;
  double berat;
  int umur;
  tulisb.open("dataBalita.txt", ios::app);
  cout << endl;
  cout << "Berikut Tambah Data Balita Posyandu Bahagia...";
  cout << endl;
  cout << endl;
  cout << "Silahakan Tambah Data Balita...";
  cout << endl;
  cout << "----------------------------------------------" << endl;
  cout << "Ingin Menanbah Berapa Data : ";
  cin >> ssx;
  for (int z = 0; z < ssx; z++) {
    cout << "----------------------------------------------" << endl;
    cout << "Masukkan No rekam Balita       : ";
    cin >> no_rekam;
    cout << "Masukkan Nama Balita           : ";
    cin >> namaBalita;
    cout << "Masukkan Nama Ibu              : ";
    cin >> ibu;
    cout << "Masukkan Tinggi Balita         : ";
    cin >> tinggi;
    cout << "Masukkan Berat badan Balita    : ";
    cin >> berat;
    cout << "Masukkan Umur badan Balita     : ";
    cin >> umur;
    cout << "----------------------------------------------" << endl;
    tulisb << no_rekam << ";" << namaBalita << ";" << ibu << ";" << tinggi
           << ";" << berat << ";" << umur << endl;
  }
  tulisb.close();
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirmation;
}






void Login::mainLogin()
{
    cout << "\nSilahkan Login Terlebih Dahulu...!";
    cout << endl;
    // ambiltoLogin
    ambilKTP();
    cout << "----------------------------------------------" << endl;
    cout << "Masukkan Username    : ";
    cin >> inputnamaL;
    cout << "Masukkan NIK Anda    : ";
    cin >> inputnikL;
    cout << "----------------------------------------------" << endl;

    if (toLogin[0].namatxt == inputnamaL && toLogin[0].niktxt == inputnikL)
    {
        statusLogin = true;
        no = 0;
      ofstream tulis;

        tulis.open("dataLogin.txt");
        tulis << toLogin[no].niktxt << ";" << toLogin[no].namatxt << ";" << toLogin[no].provtxt<< ";" << toLogin[no].tmpttxt<< ";" << toLogin[no].tgltxt<<";"<<toLogin[no].dusun<<";"<<toLogin[no].rt <<";"<<toLogin[no].rw<<";"<<toLogin[no].desa<<";"<<toLogin[no].kec<<";"<<toLogin[no].kabtxt<<";"<<toLogin[no].agama<<";"<<toLogin[no].stts<<";"<<toLogin[no].kerja<<";"<<toLogin[no].wn<<";"<<toLogin[no].bh<<";"<<toLogin[no].jk<<";"<<toLogin[no].goldartxt;

        tulis.close();
        statusAdmin = true;
    }
    else if (toLogin[1].namatxt == inputnamaL && toLogin[1].niktxt == inputnikL)
    {

        statusLogin = true;
        no = 1;
        ofstream tulis;

        tulis.open("dataLogin.txt");
        tulis << toLogin[no].niktxt << ";" << toLogin[no].namatxt << ";" << toLogin[no].provtxt<< ";" << toLogin[no].tmpttxt<< ";" << toLogin[no].tgltxt<<";"<<toLogin[no].dusun<<";"<<toLogin[no].rt <<";"<<toLogin[no].rw<<";"<<toLogin[no].desa<<";"<<toLogin[no].kec<<";"<<toLogin[no].kabtxt<<";"<<toLogin[no].agama<<";"<<toLogin[no].stts<<";"<<toLogin[no].kerja<<";"<<toLogin[no].wn<<";"<<toLogin[no].bh<<";"<<toLogin[no].jk<<";"<<toLogin[no].goldartxt;

        tulis.close();
        statusAdmin = false;
    }
    else if (toLogin[2].namatxt == inputnamaL && toLogin[2].niktxt == inputnikL)
    {

        statusLogin = true;
        no = 2;
        ofstream tulis;

        tulis.open("dataLogin.txt");
       tulis << toLogin[no].niktxt << ";" << toLogin[no].namatxt << ";" << toLogin[no].provtxt<< ";" << toLogin[no].tmpttxt<< ";" << toLogin[no].tgltxt<<";"<<toLogin[no].dusun<<";"<<toLogin[no].rt <<";"<<toLogin[no].rw<<";"<<toLogin[no].desa<<";"<<toLogin[no].kec<<";"<<toLogin[no].kabtxt<<";"<<toLogin[no].agama<<";"<<toLogin[no].stts<<";"<<toLogin[no].kerja<<";"<<toLogin[no].wn<<";"<<toLogin[no].bh<<";"<<toLogin[no].jk<<";"<<toLogin[no].goldartxt;

        tulis.close();
        statusAdmin = false;
    }
    else
    {
        statusLogin = false;
    }
}





  void Login::tampildataIBU_Hamil() {
  int idxIB = 0;
    ifstream ambildataIBU_HAMIL;
  string tIB;
  ambildataIBU_HAMIL.open("dataIbu_Hamil.txt");
  while (!ambildataIBU_HAMIL.eof()) {
    ambildataIBU_HAMIL >> tIB;
    tokenizeIBHMLL(tIB, ";", idxIB);
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
    cout << Aibhmll[h].Anorekamib_hamil;
    cout << endl;
    cout << "Nama Bumil                : ";
    cout << Aibhmll[h].Anamaib_hamil;
    cout << endl;
    cout << "Usia Kehamilan (bulan)    : ";
    cout << Aibhmll[h].Ausiakehamilan;
    cout << endl;
    cout << "Berat Bumil               : ";
    cout << Aibhmll[h].Aberatib_hamil;
    cout << endl;
    cout << "Usia Bumil                : ";
    cout << Aibhmll[h].Ausiaib_hamil;
    cout << endl;
    cout << "Hari Prediksi Lahir (HPL) : ";
    cout << Aibhmll[h].Ahplib_TGL;
    cout << "/";
    cout << Aibhmll[h].Ahplib_BLN;
    cout << "/";
    cout << Aibhmll[h].Ahplib_TH;
    cout << endl;

    cout << "----------------------------------------------" << endl;

    // buat for
  }
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirmation;

  // buat
}





  void Login::editdataBUMIL(){
    ofstream tulisnew;
    int newberatbumil;
    int newusiakehamilan;
    int pilmenuEdit;
  int idxibh = 0;
    string tibh;
    jukut.open("dataIbu_Hamil.txt");
    while (!jukut.eof()) {
      jukut >> tibh;
      tokenizeIBML(tibh, ";", idxibh);
      idxibh++;
    }
    jukut.close();
    system("clear");
    cout << "Berikut Data Ibu Hamil Yang Tersedia...";
    cout << endl;
    for (int h = 0; h < idxibh - 1; h++) {
      // cout << Aibhmll[h].Anamaib_hamil;

      cout << "----------------------------------------------" << endl;
      cout << "No Rekam Bumil            : ";
      cout << IBH[h].norekamib;
      cout << endl;
      cout << "Nama Bumil                : ";
      cout << IBH[h].ibu_hamil;
      cout << endl;
      cout << "Usia Kehamilan (bulan)    : ";
      cout << IBH[h].usia_hamil;
      cout << endl;
      cout << "Berat Bumil               : ";
      cout << IBH[h].brtib_hamil;
      cout << endl;
      cout << "Usia Bumil                : ";
      cout << IBH[h].usiaib;
      cout << endl;
      cout << "Hari Prediksi Lahir (HPL) : ";
      cout << IBH[h].hpl_TGL;
      cout << "/";
      cout << IBH[h].hpl_BLN;
      cout << "/";
      cout << IBH[h].hpl_TH;
      cout << endl;

      cout << "----------------------------------------------" << endl;
    
      
    }// tutup for

    string pilNamibh;
    bool ketemu = false;
    int datakeED;

    cout << endl;
    cout << "Silahkan Pilih Nama Ibu Hamil Yang Ingin DiEdit : ";
    cin >> pilNamibh;

    for (int b = 0; b < idxibh - 1; b++) {
      if (pilNamibh == IBH[b].ibu_hamil) {
        ketemu = true;
        datakeED = b;
        break;
      }
    }

      if (ketemu == true) {
  editdatabml:
    cout << "----------------------------------------------" << endl;
    cout << endl;
    cout << "Menu Edit Data Ibu Hamil";
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "1. Edit Usia Kehamilan ";
    cout << endl;
    cout << "2. Edit Berat Bumil ";
    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << " Masukkan Pilihan [1/2] : ";
    cin >> pilmenuEdit;

  switch (pilmenuEdit) {
    case 1: {
      cout << endl;
      cout << "----------------------------------------------" << endl;
      cout << " Masukkan Usia Kehamilan Yang Ingin di Edit : ";
      cin >> newusiakehamilan;;
      cout << "----------------------------------------------" << endl;

      tulisnew.open("dataIbu_Hamil.txt");
      for (int c = 0; c < idxibh - 1; ++c) {
        if (c == datakeED) {
          IBH[c].usia_hamil = newusiakehamilan;;
          tulisnew << IBH[c].norekamib << ";" << IBH[c].ibu_hamil
                     << ";" << IBH[c].usia_hamil << ";" << IBH[c].brtib_hamil
                     << ";" << IBH[c].usiaib << ";" << IBH[c].hpl_TGL
                     << ";" << IBH[c].hpl_BLN << ";" << IBH[c].hpl_TH << endl;
          system("clear");
          cout << "----------------------------------------------" << endl;
          cout << "Usia Kehamilan Berhasil Di Edit Ke -> " << newusiakehamilan;;
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << endl;
        } else {
          tulisnew << IBH[c].norekamib << ";" << IBH[c].ibu_hamil
                     << ";" << IBH[c].usia_hamil << ";" << IBH[c].brtib_hamil
                     << ";" << IBH[c].usiaib << ";" << IBH[c].hpl_TGL
                     << ";" << IBH[c].hpl_BLN << ";" << IBH[c].hpl_TH << endl;
        }
      }
      tulisnew.close();

      break;
      }//tutup case
    case 2: {
      cout << endl;
      cout << "----------------------------------------------" << endl;
      cout << " Masukkan Berat Bumi Yang Ingin di Edit : ";
      cin >> newberatbumil;
      cout << "----------------------------------------------" << endl;

      tulisnew.open("dataIbu_Hamil.txt");
      for (int c = 0; c < idxibh - 1; ++c) {
        if (c == datakeED) {
          IBH[c].brtib_hamil = newberatbumil;
          tulisnew << IBH[c].norekamib << ";" << IBH[c].ibu_hamil
                     << ";" << IBH[c].usia_hamil << ";" << IBH[c].brtib_hamil
                     << ";" << IBH[c].usiaib << ";" << IBH[c].hpl_TGL
                     << ";" << IBH[c].hpl_BLN << ";" << IBH[c].hpl_TH << endl;
          system("clear");
          cout << "----------------------------------------------" << endl;
          cout << "Berat Bumi Berhasil Di Edit Ke -> " << newberatbumil;
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << endl;
        } else {
          tulisnew << IBH[c].norekamib << ";" << IBH[c].ibu_hamil
                     << ";" << IBH[c].usia_hamil << ";" << IBH[c].brtib_hamil
                     << ";" << IBH[c].usiaib << ";" << IBH[c].hpl_TGL
                     << ";" << IBH[c].hpl_BLN << ";" << IBH[c].hpl_TH << endl;
        }
      }
      tulisnew.close();

      break;
      }//tutup case
    } //tutup switch
  } //tutup if
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirmation;
}


void Login::hpsdataBUMIL(){

  int idxibh = 0;
    string tibh;
    jukut.open("dataIbu_Hamil.txt");
    while (!jukut.eof()) {
      jukut >> tibh;
      tokenizeIBML(tibh, ";", idxibh);
      idxibh++;
    }
    jukut.close();
    system("clear");
    cout << "Berikut Data Ibu Hamil Yang Tersedia...";
    cout << endl;
    for (int h = 0; h < idxibh - 1; h++) {
      // cout << Aibhmll[h].Anamaib_hamil;

      cout << "----------------------------------------------" << endl;
      cout << "No Rekam Bumil            : ";
      cout << IBH[h].norekamib;
      cout << endl;
      cout << "Nama Bumil                : ";
      cout << IBH[h].ibu_hamil;
      cout << endl;
      cout << "Usia Kehamilan (bulan)    : ";
      cout << IBH[h].usia_hamil;
      cout << endl;
      cout << "Berat Bumil               : ";
      cout << IBH[h].brtib_hamil;
      cout << endl;
      cout << "Usia Bumil                : ";
      cout << IBH[h].usiaib;
      cout << endl;
      cout << "Hari Prediksi Lahir (HPL) : ";
      cout << IBH[h].hpl_TGL;
      cout << "/";
      cout << IBH[h].hpl_BLN;
      cout << "/";
      cout << IBH[h].hpl_TH;
      cout << endl;

      cout << "----------------------------------------------" << endl;

      
    }// tutup for

    string pilnamaibh;
    bool ketemu = false;
    int datake;
    cout << endl << endl;
    cout << "Silahkan Pilih Nama Ibu Hamil Yang Ingin DiHapus : ";
    cin >> pilnamaibh;
    for (int i = 0; i < idxibh - 1; i++) {
      if (pilnamaibh == IBH[i].ibu_hamil) {
        ketemu = true;
        datake = i;
        break;
      }
    }//tutup for
    if (ketemu == true) {
    ofstream tulis;
    tulis.open("dataIbu_Hamil.txt");
    for (int i = 0; i < idxibh - 1; ++i) {
      if (i != datake) {
        tulis << IBH[i].norekamib << ";" << IBH[i].ibu_hamil
                     << ";" << IBH[i].usia_hamil << ";" << IBH[i].brtib_hamil
                     << ";" << IBH[i].usiaib << ";" << IBH[i].hpl_TGL
                     << ";" << IBH[i].hpl_BLN << ";" << IBH[i].hpl_TH << endl;
      }
    }
    tulis.close();
    cout << "----------------------------------------------" << endl;
    cout << "Nama Ibu Hamil Yang Anda Pilih Berhasil Di Hapus ";
    cout << endl;
    cout << "----------------------------------------------" << endl;
  }


  
    cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
    cin >> konfirmation;
  
  
}






void Login::tambahDataIBU_HAMIL() {

    ofstream tulisIBU_HAMIL;
  int norekamib_hamil;
  string namaib_hamil;
  int usiakehamilan;
  int beratib_hamil;
  int usiaib_hamil;
  int hplib_TGL;
  int hplib_BLN;
  int hplib_TH;
  system("clear");
  int tamdatibhml;
  tulisIBU_HAMIL.open("dataIbu_Hamil.txt", ios::app);

  cout << "Berikut Menu Tambah Data Bumil...";
  cout << endl;
  cout << "----------------------------------------------" << endl;
  cout << endl;
  cout << endl;
  cout << "Masukkan Jumlah Data Ibu Hamil : ";
  cin >> tamdatibhml;
  for (int h = 0; h < tamdatibhml; h++) {

    cout << "----------------------------------------------" << endl;
    cout << "Masukkan No Rekam Bumil           : ";
    cin >> norekamib_hamil;
    cout << "Masukkan Nama Bumil               : ";
    cin >> namaib_hamil;
    cout << "Masukkan Usia Kehamilan (bulan)   : ";
    cin >> usiakehamilan;
    cout << "Masukkan Berat Bumil              : ";
    cin >> beratib_hamil;
    cout << "Masukkan Usia Bumil               : ";
    cin >> usiaib_hamil;
    cout << "Masukkan Hari Prediksi Lahir (HPL)";
    cout << endl;
    cout << " Tanggal             : ";
    cin >> hplib_TGL;
    cout << " Bulan               : ";
    cin >> hplib_BLN;
    cout << " Tahun               : ";
    cin >> hplib_TH;

    cout << endl;
    cout << "Data Berhasil Di Input!!!" << endl;
    cout << "----------------------------------------------" << endl;

    if (!tulisIBU_HAMIL.fail()) {

      tulisIBU_HAMIL << norekamib_hamil << ";" << namaib_hamil
                     << ";" << usiakehamilan << ";" << beratib_hamil
                     << ";" << usiaib_hamil << ";" << hplib_TGL
                     << ";" << hplib_BLN << ";" << hplib_TH << endl;

      tulisIBU_HAMIL.close();
    } else {
      cout << "Error!!!! ";
    }

    // buat for
  }

  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirmation;

  // buat void
}







  void Login::tambahdata() {
  int sz;
    ofstream tulis;
    string id;
    string nama;
    int stok;
    int harga;
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
  cin >> konfirmation;
}

void Login::tambahdataobat() {
   ofstream tulis;
    string id;
    string nama;
    int stok;
    int harga;
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
  cin >> konfirmation;
}
  





  void Login::lihatPengumuman()
{
  int idxpng = 0;
    string tpg;
    jukut.open("Pengumuman.txt");

    while (!jukut.eof()) {
      getline(jukut, tpg);
      tokenizepng(tpg, ";", idxpng);
      idxpng++;
    }
    jukut.close();
  system("clear");
  
  cout<<"Berikit Pengmumman Yang Tersedia...";
  cout<<endl;
  cout << "----------------------------------------------" << endl;
  cout<<endl;
    for(int i =0 ; i< idxpng -1 ; i++)
    {
      cout << "----------------------------------------------" << endl;
      cout<<"Kode     : "<<njejel[i].kode<<endl;
      cout<<"Jenis    : "<<njejel[i].jenis<<endl;
      cout<<"Tema     : "<<njejel[i].topik<<endl;
      cout<<"Tgl      : "<<njejel[i].tglLaksana<<endl;
      cout<<"Peserta  : "<<njejel[i].pelaku<<endl;
      cout<<"Tempat   : "<<njejel[i].tempat<<endl;
      cout << "----------------------------------------------" << endl;
      cout << endl;
      
    }

    
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirmation;
}





void Login::pengumuman()
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
  cin >> konfirmation;

}





void Login::hpsPengumuman()
{
    int idxpng = 0;
    string tpg;
    jukut.open("Pengumuman.txt");

    while (!jukut.eof()) {
      getline(jukut, tpg);
      tokenizepng(tpg, ";", idxpng);
      idxpng++;
    }
    jukut.close();
    system("clear");
    cout << "Pengumuman Yang Tersedia... ";
    cout<<endl;
    cout << "----------------------------------------------" << endl;
    cout << endl;
    for(int i =0 ; i< idxpng -1 ; i++)
    {
      cout << "----------------------------------------------" << endl;
      cout<<"Kode     : "<<njejel[i].kode<<endl;
      cout<<"Jenis    : "<<njejel[i].jenis<<endl;
      cout<<"Tema     : "<<njejel[i].topik<<endl;
      cout<<"Tgl      : "<<njejel[i].tglLaksana<<endl;
      cout<<"Peserta  : "<<njejel[i].pelaku<<endl;
      cout<<"Tempat   : "<<njejel[i].tempat<<endl;
      cout << "----------------------------------------------" << endl;
      cout << endl;
      
    }
  
  int pilKD;
  bool ketemu = false;
  int datake;
  cout << endl;
  cout << "Silahkan Pilih Kode Pengumuman Yang Ingin DiHapus : ";
  cin >> pilKD;
  for (int i = 0; i < idxpng - 1; i++) {
    if (pilKD == njejel[i].kode) {
      ketemu = true;
      datake = i;
      break;
    }
  }
  if (ketemu == true) {
    ofstream tulis;
    tulis.open("Pengumuman.txt");
    for (int a = 0; a < idxpng - 1; ++a) {
      if (a != datake) {
        tulis << njejel[a].kode <<";" << njejel[a].jenis <<";"<<njejel[a].topik<<";"<< njejel[a].tglLaksana <<";"<< njejel[a].pelaku <<";"<<njejel[a].tempat<<endl;
      }
    }
    tulis.close();
    cout << "----------------------------------------------" << endl;
    cout << "Kode Pengumuman Yang Anda Pilih Berhasil Di Hapus ";
    cout << endl;
    cout << "----------------------------------------------" << endl;
  }

  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirmation;
  
}





void Login::editPengumuman()
{
  int pilmenuEdit;
  ofstream tulisnew;
  int idxpng = 0;
    string tpg;
    jukut.open("Pengumuman.txt");

    while (!jukut.eof()) {
      getline(jukut, tpg);
      tokenizepng(tpg, ";", idxpng);
      idxpng++;
    }
  jukut.close();
    system("clear");
    cout << "Pengumuman Yang Tersedia... ";
    cout<<endl;
    cout << "----------------------------------------------" << endl;
    cout << endl;
    for(int i =0 ; i< idxpng -1 ; i++)
    {
      cout << "----------------------------------------------" << endl;
      cout<<"Kode     : "<<njejel[i].kode<<endl;
      cout<<"Jenis    : "<<njejel[i].jenis<<endl;
      cout<<"Tema     : "<<njejel[i].topik<<endl;
      cout<<"Tgl      : "<<njejel[i].tglLaksana<<endl;
      cout<<"Peserta  : "<<njejel[i].pelaku<<endl;
      cout<<"Tempat   : "<<njejel[i].tempat<<endl;
      cout << "----------------------------------------------" << endl;
      cout << endl;
      
    }
  int pilKD;
  bool ketemu = false;
  int datake;
  int pilpil;
  cout << endl << endl;
  cout << "Silahkan Pilih Kode Pengumuman Yang Ingin DiEDIT : ";
  cin >> pilKD;
  for (int i = 0; i < idxpng - 1; i++) {
    if (pilKD == njejel[i].kode) {
      ketemu = true;
      datake = i;
      break;
    }
  }

  if (ketemu == true) {
  editdatabml:
    cout << "----------------------------------------------" << endl;
    cout << endl;
    cout << "|----------------------------------------------|" << endl;
    cout << "|         Menu Edit Data Pengumuman            |";
    cout << endl;
    cout << "|----------------------------------------------|" << endl;
    cout << "|       1. Edit Jenis Pengumuman               |";
    cout << endl;
    cout << "|       2. Edit Peserta Pengumuman             |";
    cout << endl;
    cout << "|----------------------------------------------|" << endl;
    cout << "Masukkan Pilihan Anda [1/2] : ";
    cin >> pilmenuEdit;

  switch (pilmenuEdit) {
    case 1: {
      cout << endl;
      ulang1:
      cout << "|----------------------------------------------|" << endl;
      cout << "|             Jenis Pengumuman                 |"<<endl;
      cout << "|----------------------------------------------|" << endl;
      cout << "|      1. Penyuluhan                           |"<<endl;
      cout << "|      2. Pemeriksaan                          |"<<endl;
      cout << "|----------------------------------------------|" << endl;
      cout<<"Masukkan Pilihan anda [1/2] : ";cin >>pilpil;
      if(pilpil ==1)
      {
        newp.newjenis = "Penyuluhan";
        pilpil =0;
      }
      else if (pilpil == 2)
      {
        newp.newjenis = "Pemeriksaan";
         pilpil =0;
      }
      else 
      {
        cout << "Pilihan Tidak Tersedia "<<endl;
        cin.ignore();
        cout << "Tekan Enter Untuk Kembali ⏎ ";
        getchar();
        goto ulang1;
      }
      cout << "----------------------------------------------" << endl;

      tulisnew.open("Pengumuman.txt");
      for (int c = 0; c < idxpng - 1; ++c) {
        if (c == datake) {
          njejel[c].jenis = newp.newjenis;
          tulisnew << njejel[c].kode <<";" << njejel[c].jenis <<";"<<njejel[c].topik<<";"<< njejel[c].tglLaksana <<";"<< njejel[c].pelaku <<";"<<njejel[c].tempat<<endl;
          system("clear");
          cout << "----------------------------------------------" << endl;
          cout << "Jenis Pengumuman Berhasil Di Edit Ke -> " << newp.newjenis;
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << endl;
        } else {
          tulisnew << njejel[c].kode <<";" << njejel[c].jenis <<";"<<njejel[c].topik<<";"<< njejel[c].tglLaksana <<";"<< njejel[c].pelaku <<";"<<njejel[c].tempat<<endl;
        }
      }
      tulisnew.close();

      break;
      }//tutup case
    case 2: {
      cout << endl;
      cout << "----------------------------------------------" << endl;
      ulang4:
      cout << "|----------------------------------------------|" << endl;
      cout << "|             Pilih Peserta                    |"<<endl;
      cout << "|----------------------------------------------|" << endl;
      cout << "|             1. Balita                        |"<<endl;
      cout << "|             2. Bumil                         |"<<endl;
      cout << "|----------------------------------------------|" << endl;
      cout << "Masukkan Pilihan Anda [1/2] : ";cin >>pilpil;
      if(pilpil ==1)
      {
         newp.newpelaku = "Balita";
        pilpil =0;
      }
      else if(pilpil ==2)
      {
        newp.newpelaku = "Bumil";
         pilpil =0;
      }
      else 
      {
        cout << "Pilihan Tidak Tersedia "<<endl;
        cin.ignore();
        cout << "Tekan Enter Untuk Kembali ⏎ ";
        getchar();
        goto ulang4;
      }
      cout << "----------------------------------------------" << endl;

      tulisnew.open("Pengumuman.txt");
      for (int c = 0; c < idxpng - 1; ++c) {
        if (c == datake) {
          njejel[c].pelaku = newp.newpelaku;
          tulisnew << njejel[c].kode <<";" << njejel[c].jenis <<";"<<njejel[c].topik<<";"<< njejel[c].tglLaksana <<";"<< njejel[c].pelaku <<";"<<njejel[c].tempat<<endl;
          system("clear");
          cout << "----------------------------------------------" << endl;
          cout << "Peserta Pengumuman Berhasil Di Edit Ke -> " <<  newp.newpelaku;
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cout << endl;
        } else {
          tulisnew << njejel[c].kode <<";" << njejel[c].jenis <<";"<<njejel[c].topik<<";"<< njejel[c].tglLaksana <<";"<< njejel[c].pelaku <<";"<<njejel[c].tempat<<endl;
        }
      }
      tulisnew.close();

      break;
      }//tutup case
    } //tutup switch
  } //tutup if


  
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirmation;
}






void Login::tulisKTP()
{
    ofstream writedata;
    writedata.open("ktp.txt", ios::app);

    cout << "Masukkan Username       : ";
    cin >> inputnama;
    cout << "Masukkan NIK Anda       : ";
    cin >> inputnik;
    cout << "Masukkan Prov Anda    : ";
    cin >> provinput;
    //tambah ini
    cout << "Masukkan Kab Anda : " ;
    cin >> kabinput;
    cout << "Masukkan GolDar Anda : " ;
    cin >> goldarinput;
    cout << "Masukkan JenisKel Anda : " ;
    cin >> jklmninput;
    cout << "Masukkan Agama Anda :";
    cin >> agamainput;
    cout << "Masukkan Status Kawin Anda :";
    cin >> skawininput;
    cout << "Masukkan Pekerjaan Anda :";
    cin >> pekerjaaninput;
    cout << "Masukkan kewarganegaraan Anda :";
    cin >> knegarainput;
    cout << endl;

    cout << "Provinsi : ";
    cin >> provinput;
  
    cout << "Kabupaten :";
    cin >> kabinput;
  
    cout << "NIK : ";
    cin >> inputnik;
    
    cout << "NAMA : ";
    cin >> inputnama;
  
    cout << "tempat tanggal lahir" << endl;
    cout << "tempat : ";
    cin >> tmptlahirinput;
    cout << "tanggal lahir (dd-mm-yyyy) : ";
    cin >> tgllahirinput;
    
    jk_ulang:
    cout << "Jenis kelamin :";
    cout<< endl;
    cout << " 1.Laki-Laki \n 2.perempuan \n";
    cout << "pilihan : ";
    cin >> pilihanJK;
    switch (pilihanJK) 
    {
      case 1: 
        {
        jklmninput = "LAKI-LAKI";
        break;
      }
      case 2: 
        {
        jklmninput = "PEREMPUAN";
        break;
      }
      default: 
        {
        cout << " ulang ";
        cout << endl;
        goto jk_ulang;
        break;
      }
    }
  
    gd_ulang:
    cout << "golongan darah :";
    cout << endl;
    cout << " 1. A \n 2. B \n 3. AB \n 4. O";
    cout << endl;
    cout << "pilihan: ";
    cin >> pilihanGD;
    switch (pilihanGD) 
    {
        case 1: 
          {
          
        goldarinput = "A";
        break;
      }
        case 2: 
          {
        goldarinput = "B";
        break;
      }
        case 3: 
          {
        goldarinput = "AB";
        break;
      }
        case 4: 
          {
        goldarinput = "O";
        break;
      }
      default: 
        {
        cout << " ulang " << endl;
        goto gd_ulang;
        break;
      }
    }
  
    cout << "Alamat : \n";
    cout << "Alamat (Dusun/Jalan): ";
    cin >> dusuninput;
    cout << "Rt: ";
    cin >> rtinput;
    cout << "Rw: ";
    cin >> rwinput;
    cout << "Kel/Desa : ";
    cin >> desainput;
    cout << "Kecamatan : ";
    cin >> kecamataninput;
  
    agama_ulang:
    cout << "agama : " << endl;
    cout << " 1. islam\n 2. kristen\n 3. katolik\n 4. hindu\n 5. budha\n";
    cout << "pilihan : ";
    cin >> pilihanAG;
    switch (pilihanAG) 
    {
      case 1: 
        {
        agamainput = "ISLAM";
        break;
      }
      case 2: 
        {
        agamainput = "KRISTEN";
        break;
      }
      case 3:
        {
        agamainput = "KATOLIK";
        break;
      }
      case 4:
        {
        agamainput = "HINDU";
        break;
      }
      case 5: 
        {
        agamainput = "BUDHA";
        break;
      }
      case 6: 
        {
        agamainput = "KONGHUCU";
        break;
      }
        default: 
          {
        cout << " ulang ";
          cout 
            << endl;  
        goto agama_ulang;
        break;  
      }
    }
    status_ulang:
    cout << "status perkawinan : ";
    cout << endl;
    cout << " 1. sudah menikah";
     cout<< endl;
  cout<<"2. belum menikah";
  cout <<
    endl;
    cout << "pilihan : ";
    cin >> pilihanSK;
    switch (pilihanSK) 
    {
      case 1: 
        {
       
        skawininput = "SUDAH MENIKAH";
        break;
      }
      case 2: 
        {
        skawininput = "BELUM KAWIN";
        break;
      }
        default: 
          {
          cout << " ulang " << endl;
          goto status_ulang;
          break;
      }
    }
  
    cout << "pekerjaan : ";
    cin >> pekerjaaninput;
  
    kewarga_ulang:
    cout << "kewarganegaraan : ";
    cout << endl;
    cout << " 1. WNI \n 2. WNA \n";
    cout << "pilihan: ";
    cin >> pilihanWN;
    switch (pilihanWN) 
    {
    case 1: 
      {
      
      knegarainput = "WNI";
      break;
    }
    case 2: 
      {
      knegarainput = "WNA";
      break;
    }
    default: 
      {
      cout << "ulang";
      cout << endl;
      goto kewarga_ulang;
      break;
      }
    }
  
    if (!writedata.fail())
    {

      
      
          
        writedata << inputnama << ";" 
          << inputnik << ";" 
          << provinput << ";" 
          << tmptlahirinput << ";" 
          << tgllahirinput << ";" 
          << /*tambah dari sini*/ kabinput 
          << ";" << jklmninput << ";" 
          << goldarinput << ";" << dusuninput
          << ";" << rtinput << ";" << rwinput << ";"
          << desainput << ";" 
          << kecamataninput;
      writedata 
        << endl;
          
          
          // << kabinput <<";" << goldarinput << ";" << jklmninput <<";"<< agamainput<<";" << skawininput <<";"<< pekerjaaninput << ";" << knegarainput;
      
        writedata.close();
        cout << "Sukses" << endl;
    }
    else
    {
        cout << "Error!!!! ";
    }
}

void Login::ambilKTP()
{


    ifstream readData;
    // string t;

    int idx = 0;
    string t;
    readData.open("ktp.txt");
    while (!readData.eof())
    {
        readData >> t;
        tokenize(t, ";", idx);
        idx++;
    }
    readData.close();

}





void Login::tambahdataBidan(){
  system("clear");
  ofstream tulisBID;
  int tambnykdatBID;
  tulisBID.open("databidan.txt", ios::app);

  cout << "Berikut Menu Tambah Data Bidan...";
  cout << endl;
  cout << "----------------------------------------------" << endl;
  cout << endl;
  cout << endl;
  cout << "Masukkan Jumlah Data Bidan : ";
  cin >> tambnykdatBID;

  for (int h = 0; h < tambnykdatBID; h++) 
  {
    cout << "----------------------------------------------" << endl;
    cout << "Masukkan NIP bidan           : ";
    cin >> tamBID.NIP;
    cout << "Masukkan NIK Bidan           : ";
    cin >> tamBID.nikBidan;
    cout << "Masukkan Nama Bidan          : ";
    cin >> tamBID.namaBidan;
    cout << "Masukkan Tempat Lahir Bidan  : ";
    cin >> tamBID.tmptLahirBidan;
    cout << "Masukkan Tanggal Lahir Bidan " << endl;
    cout << "                  dd-mm-yyyy : ";
    cin >> tamBID.tglLahirBidan;
    cout << "Masukkan Alamat Bidan        : Jln ";
    cin >> tamBID.jlnBidan;
    cout << "Masukkan RT                  : ";
    cin >> tamBID.rtBidan;
    cout << "Masukkan RW                  : ";
    cin >> tamBID.rwBidan;
    cout << "Masukkan Kel/desa            : " ;
    cin >> tamBID.desaBidan;
    cout << "Masukkan Kec                 : ";
    cin >> tamBID.kecBidan;
    cout << "Masukkan Kab/Kota            : ";
    cin >> tamBID.kabBidan;
    cout << "Masukkan Provinsi            : ";
    cin >> tamBID.provBidan;
    cout << "Masukkan No HP Bidan         : ";
    cin >> tamBID.noHp;
    cout << endl;
    cout << "Data Berhasil Di Input!!!" << endl;
    cout << "----------------------------------------------" << endl;

    if (!tulisBID.fail()) {

      tulisBID << tamBID.NIP << ";" << tamBID.nikBidan <<";" << tamBID.namaBidan <<";" << tamBID.provBidan <<";" << tamBID.tglLahirBidan <<";" << tamBID.tmptLahirBidan <<";" << tamBID.noHp <<";" << tamBID.jlnBidan <<";" << tamBID.rtBidan << ";" << tamBID.rwBidan << ";" << tamBID.desaBidan << ";" << tamBID.kecBidan <<";" << tamBID.kabBidan << endl;

      tulisBID.close();
    } else {
      cout << "Error!!!! ";
    }

    // buat for
  }

  
  
  cout << "Apakah Anda Ingin Kembali Ke Main Menu? [y/n] ";
  cin >> konfirmation;
}