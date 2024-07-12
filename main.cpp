#include "2100018181.h"
#include "2100018224.h"
#include "2100018183.h"
#include <iostream>

using namespace std;

int main() {

  // lo.tulisKTP();

  // cek
  cout << "----------------------------------------------" << endl;
  cout << "|\t\t\t\t\t\t\t\t\t\t\t |" << endl;
  cout << "|\t\t\t\tPosyandu Bahagia \t\t\t |";
  cout << endl;
  cout << "|\t\t\t\t\t\t\t\t\t\t\t |" << endl;
  cout << "----------------------------------------------" << endl;
  cout << endl;

  Admin adm;
  User usr;
  // adm.StrukturBidan();
  //  cout<<endl;
  //   adm.lihatdatahPen();
  // cout << endl;
  // adm.historyPendapatan();
  // adm.restokObat();
  // adm.restokObat();

  // adm.tulishistoryPendapatan();
  // usr.cekKesehatan();
  //    adm.maungetest();
  //   usr.cekKesehatan2();

  // adm.tambahDataIBU_HAMIL();
  // usr.tampildataIBU_Hamil();
  // usr.cekkesehatanv3();// nambah data antrian pemeriksaan bumil
  // usr.cekkesehatanv3();
  // adm.proseslahantribumil();//memproses antrian bumil
  // usr.tampilantrianBumil();//nampilin antrian di user
  // usr.cekkesehatanv4();//nampilin bumil yg mau di cek

  //usr.riwayatPeriksa();//implements tree.,''

  // adm.ambildataIbuha(); //lihat data ibuhamil, bisa di bikin fungsi baru aja buat manggil

   //adm.editdataBalita(); 
   // adm.hpsdataBIDAN();
    //adm.edtdataBIDAN();

   //adm.tambahdataBidan(); -->> tambah data bidan
   //adm.cekBidan(); 

   // adm.hpsdataBUMIL();
    //adm.editdataBUMIL();

  //usr.diumumkan();
  
    // adm.pengumuman();
    // adm.lihatPengumuman();
    
    //adm.hpsPengumuman();  
    //adm.editPengummuman();
    
  awal:
      lo.mainLogin();
      if (lo.isLogin() == true)
      {
          if (lo.isAdmin() == true)
          {
              // cout << " admin.h";
              // system("cls");
              system("clear"); // replit
              cout << "----------------------------------------------" <<endl; 
              cout << "|\t\t\t\t\t\t\t\t\t\t\t |" << endl; 
              cout << "|\t\t\t\tPosyandu Bahagia \t\t\t |";
              cout << endl; 
              cout << "|\t\t\t\t\t\t\t\t\t\t\t |" << endl; 
              cout << "----------------------------------------------" << endl
                   << endl;
              cout << "Selamat Datang Admin => " << toLogin[lo.no].namatxt
                   << endl;
              cin.ignore();
              cout << endl;
              cout << "Tekan Enter Untuk Melanjutkan ⏎ ";
              getchar();

          // panggil isi library admin.h
          awalAdmin:
              adm.menu();
              if (adm.pilih == 1)
              {
                  system("clear");
                  lo.tambahdata();
                  if (lo.konfirmation == 'y' || lo.konfirmation == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  }
              }
              else if (adm.pilih == 2)
              {
                  system("clear");
                  adm.lihatdataDinamis();
                  if (adm.konfirm == 'y' || adm.konfirm == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  }
              }
              else if (adm.pilih == 3)
              {
                  // system("clear");
                  adm.hapusdata();
                  if (adm.konfirm == 'y' || adm.konfirm == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  }
              }
              else if (adm.pilih == 4)
              {
                  system("clear");
                  adm.editdataVaksin();
                  //adm.tambahdataBalita();
                  //adm.hapusdata();
                  if (adm.konfirm == 'y' || adm.konfirm == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  }
              }
                else if (adm.pilih == 5)
              {
                  system("clear");
                  adm.restok();
                  //adm.LihatdataBalita();
                  //adm.hapusdata();
                  if (adm.konfirm == 'y' || adm.konfirm == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  }
              }
              else if (adm.pilih == 6)
              {
                  lo.tambahdataBalita();
                  //adm.hapusdataBalita();
                  if (lo.konfirmation == 'y' || lo.konfirmation == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  }
              }
              else if (adm.pilih == 7)
              {
                  system("clear");
                  lo.LihatdataBalita();
                  //adm.tambahdataobat();
                  //adm.hapusdata();
                  if (lo.konfirmation == 'y' || lo.konfirmation == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  }
              }
                else if (adm.pilih == 8)
              {
                  system("clear");
                  //adm.Lihatdataobat();
                  adm.hapusdataBalita();
                  //adm.hapusdata();
                  if (adm.konfirm == 'y' || adm.konfirm == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  }
              }
              else if (adm.pilih == 9)
              {
                   adm.editdataBalita();
                  //adm.hapusdataobat();
                  if (adm.konfirm == 'y' || adm.konfirm == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  }
              }
              else if (adm.pilih == 10)
              {

                  //adm.restok();
                  adm.memprosesAntriBal();
                  //adm.tambahdataobat();
                  if (adm.konfirm == 'y' || adm.konfirm == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  }
              }
              else if (adm.pilih == 11)
              {
                  lo.tambahdataobat();
                  // adm.Lihatdataobat();
                  //adm.editdataVaksin();
                  if (lo.konfirmation == 'y' || lo.konfirmation == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  }//tutup if dalam
              }//tutup elseif
                
              else if (adm.pilih == 12)
              {
                  adm.Lihatdataobat();  
                  //adm.hapusdataobat();
                  //adm.cekBidan();
                  if (adm.konfirm == 'y' || adm.konfirm == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  }
              }
              else if (adm.pilih == 13)
              {
                  adm.hapusdataobat();
                  //adm.editdataObat();
                  //adm.cetakNPWPbidan();
                  if (adm.konfirm == 'y' || adm.konfirm == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  }
              }
              else if (adm.pilih == 14)
              {
                  //adm.restokObat();
                  adm.editdataObat();
                  if (adm.konfirm == 'y' || adm.konfirm == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  }
              }
              else if (adm.pilih == 15)
              {

                  adm.restokObat();
                  if (adm.konfirm == 'y' || adm.konfirm == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  }
              }
              else if (adm.pilih == 16)
              {
                  lo.tambahdataBidan();
                  
                  // adm.Lihatdataobat();
                  //adm.editdataVaksin();
                  if (lo.konfirmation == 'y' || lo.konfirmation == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  }//tutup if dalam
              }//tutup elseif
              else if (adm.pilih == 17)
              {
                  adm.cekBidan();
                  //adm.lihatdatahPen();
                  if (adm.konfirm == 'y' || adm.konfirm == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  }
              }
              else if (adm.pilih == 18)
              {

                  //adm.historyPendapatan();
                  adm.hpsdataBIDAN();
                  if (adm.konfirm == 'y' || adm.konfirm == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  }
              }
              else if (adm.pilih == 19)
              {

                  //adm.memprosesAntriBal();
                  adm.edtdataBIDAN();
                  if (adm.konfirm == 'y' || adm.konfirm == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  } // tutup if
              }// tutup else if
              else if (adm.pilih == 20)
              {
                  adm.cetakNPWPbidan();
                  //adm.tambahDataIBU_HAMIL();
                  if (adm.konfirm == 'y' || adm.konfirm == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  } // tutup if
              }// tutup else if
              else if (adm.pilih == 21)
              {
                  adm.StrukturBidan();
                  //adm.ambildataIbuha();
                  if (adm.konfirm == 'y' || adm.konfirm == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  } // tutup if
              }// tutup else if  
              else if (adm.pilih == 22)
              {
                  // adm.historyPendapatan();
                  adm.lihatdatahPen();
                  //adm.proseslahantribumil();
                  if (adm.konfirm == 'y' || adm.konfirm == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  } // tutup if
              }// tutup else if
              else if (adm.pilih == 23)
              {
                  
                  adm.historyPendapatan();
                  if (adm.konfirm == 'y' || adm.konfirm == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  } // tutup if
              }// tutup else if 
              else if (adm.pilih == 24)
              {
                  
                lo.tambahDataIBU_HAMIL();
                  if (lo.konfirmation == 'y' || lo.konfirmation == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  } // tutup if
              }// tutup else if 
              else if (adm.pilih == 25)
              {
                  
                lo.ambildataIbuha();
                  if (lo.konfirmation == 'y' || lo.konfirmation == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  } // tutup if
              }// tutup else if 
              else if (adm.pilih == 26)
              {
                  
                lo.hpsdataBUMIL();
                  if (lo.konfirmation == 'y' || lo.konfirmation == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  } // tutup if
              }// tutup else if   
              else if (adm.pilih == 27)
              {
                lo.editdataBUMIL();
                  if (lo.konfirmation == 'y' || lo.konfirmation == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  } // tutup if
              }// tutup else if   
              else if (adm.pilih == 28)
              {
                  lo.proseslahantribumil();
                  if (lo.konfirmation == 'y' || lo.konfirmation == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  } // tutup if
              }// tutup else if
              else if (adm.pilih == 29)
              {
                  lo.pengumuman();
                  if (lo.konfirmation == 'y' || lo.konfirmation == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  } // tutup if
              }// tutup else if
              else if (adm.pilih == 30)
              {
                  lo.lihatPengumuman();
                  if (lo.konfirmation == 'y' || lo.konfirmation == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  } // tutup if
              }// tutup else if
              else if (adm.pilih == 31)
              {
                  lo.hpsPengumuman();
                  if (lo.konfirmation == 'y' || lo.konfirmation == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  } // tutup if
              }// tutup else if
              else if (adm.pilih == 32)
              {
                  lo.editPengumuman();
                  if (lo.konfirmation == 'y' || lo.konfirmation == 'y')
                  {
                      system("clear");
                      goto awalAdmin;
                  } // tutup if
              }// tutup else if  
              else
              {
                  goto akhir;
              }
          }
          else
          {
              // cout << " user.h";
              // system("cls");
              system("clear"); // replit
              cout << "----------------------------------------------" <<
              endl; cout << "|\t\t\t\t\t\t\t\t\t\t\t |" << endl; cout <<
              "|\t\t\t\tPosyandu Bahagia \t\t\t |"; cout << endl; cout <<
              "|\t\t\t\t\t\t\t\t\t\t\t |" << endl; cout <<
              "----------------------------------------------" << endl; 
            cout << "\nSelamat Datang User => " << toLogin[lo.no].namatxt; 
            cout << endl; 
            cin.ignore(); 
            cout << " \nTekan Enter Untuk Melanjutkan ⏎ "; 
            getchar();

            awalUser:
              usr.Menu();
              if (usr.pilihusr == 1)
              {
                  system("clear");
                  usr.MenuTampilData();
                    if(usr.pilihtampil== 1){
                      system("clear");
                      usr.TampilBalitaDinamis();
                      if (usr.konfirmasi == 'y' || usr.konfirmasi == 'y')
                  {
                      system("clear");
                      goto awalUser;
                  }

                  }
                    else if(usr.pilihtampil == 2 )
                    {
                      system("clear");
                      usr.lihatdataBlt();
                      if (usr.konfirmasi == 'y' || usr.konfirmasi == 'y')
                    {
                      system("clear");
                      goto awalUser;
                    }
                      else {
                        goto akhir;
                      }
                }

              }
              else if (usr.pilihusr == 2)
              {

          Beli:
              usr.Beli();
              cout << endl;
              char backUser;
              cout << "Apakah Anda Ingin Membeli Lagi? [y/n] ";
              cin >> backUser;
              if (backUser == 'y' || backUser == 'Y')
              {
                  system("clear");
                  goto Beli;
              }
              else
              {
                  cout << endl;
                  cout << "\nTekan Enter Untuk Melihat Keranjang Anda ⏎ ";
                  cin.ignore();
                  getchar();

                  system("clear");
                  goto Keranjang;
              }
              cout << "----------------------------------------------" <<
              endl; Keranjang:
              // Lihat Daftar Keranjang
              usr.lihat();
              char backKer;
              cout << "Apakah Anda Ingin Melihat Keranjang\nAnda Lagi ? [y/n] ";
              cin >> backKer;
              if (backKer == 'y' || backKer == 'Y'){
                system("clear");
                goto Keranjang;
              }
              else {

              cout << endl;
              system("clear");
              goto akhir;
              }
          }
          else if (usr.pilihusr == 3)
          {
              balikcek:
              usr.cekKesehatan();
              // if(usr.tertemu == true)
              // {
              // usr.cekKesehatan2();

              // usr.tulisdatamedis();
                if (usr.konfirmasi == 'y' || usr.konfirmasi == 'y')
                  {
                      usr.tertemu = false;
                      usr.temu = -1;
                      system("clear");
                      goto awalUser;
                  }

            else
              {
              //   cin.ignore();
              // getchar();
                goto akhir;
              }

          }

           else if (usr.pilihusr == 4)
          {
            // cout << "test" << endl;
            usr.tampilAntrianblt();
            if (usr.konfirmasi == 'y' || usr.konfirmasi == 'y')
                    {
                      //tokenzise baru manggil balita cek.txt

                      system("clear");
                      goto awalUser;
                    }
                      else {
                        goto akhir;
                      }
            }
          else if (usr.pilihusr == 5)
          {

            usr.cekKesehatan2();

            usr.tulisdatamedis();
            if (usr.konfirmasi == 'y' || usr.konfirmasi == 'y')
                    {
                      //tokenzise baru manggil balita cek.txt

                      system("clear");
                      goto awalUser;
                    }
                      else {
                        goto akhir;
                      }
            }// buat pematas pilihusr
           else if (usr.pilihusr == 6)
          {

            lo.tampildataIBU_Hamil();

            //usr.tulisdatamedis();
            if (lo.konfirmation == 'y' || lo.konfirmation == 'y')
                    {
                      //tokenzise baru manggil balita cek.txt

                      system("clear");
                      goto awalUser;
                    }
                      else {
                        goto akhir;
                      }
            }// buat pematas pilihusr  
          else if (usr.pilihusr == 7)
          {

            usr.cekkesehatanv3();

            //usr.tulisdatamedis();
            if (usr.konfirmasi == 'y' || usr.konfirmasi == 'y')
                    {
                      //tokenzise baru manggil balita cek.txt

                      system("clear");
                      goto awalUser;
                    }
                      else {
                        goto akhir;
                      }
            }// buat pematas pilihusr
          else if (usr.pilihusr == 8)
          {

           usr.tampilantrianBumil();

            //usr.tulisdatamedis();
            if (usr.konfirmasi == 'y' || usr.konfirmasi == 'y')
                    {
                      //tokenzise baru manggil balita cek.txt

                      system("clear");
                      goto awalUser;
                    }
                      else {
                        goto akhir;
                      }
            }// buat pematas pilihusr
            
           else if (usr.pilihusr == 9)
          {

           usr.cekkesehatanv4();

            //usr.tulisdatamedis();
            if (usr.konfirmasi == 'y' || usr.konfirmasi == 'y')
                    {
                      //tokenzise baru manggil balita cek.txt

                      system("clear");
                      goto awalUser;
                    }
                      else {
                        goto akhir;
                      }
            }// buat pematas pilihusr
            else if (usr.pilihusr == 10)
          {

           usr.riwayatPeriksa();
        
            //usr.tulisdatamedis();
            if (usr.konfirmasi == 'y' || usr.konfirmasi == 'y')
                    {
                      //tokenzise baru manggil balita cek.txt

                      system("clear");
                      goto awalUser;
                    }
                      else {
                        goto akhir;
                      }
            }// buat pematas pilihusr 
          else if (usr.pilihusr == 11)
          {

           usr.diumumkan();
        
            //usr.tulisdatamedis();
            if (usr.konfirmasi == 'y' || usr.konfirmasi == 'y')
                    {
                      //tokenzise baru manggil balita cek.txt

                      system("clear");
                      goto awalUser;
                    }
                      else {
                        goto akhir;
                      }
            }// buat pematas pilihusr   
          } // batas login user keknya wkwk
        
      } // buat pembatas login if awal 

      else
      {
          // system("cls");
          system("clear"); // replit
          cout << "\nUsername Atau NIK Tidak Terdaftar!!!";
          cout << "\nTekan Enter Untuk Login Kembali ⏎ ";
          cout << endl;
          cout << "----------------------------------------------" << endl;
          cin.ignore();
          getchar();
          goto awal;
      }

  akhir:
      cout << "\nTekan Enter Untuk Keluar ⏎ ";
      cin.ignore();
      getchar();
      cout << "\n----------------------------------------------" << endl;
      cout << "\t\t\t\tTerimakasih...";
      cout << endl;
      cout << "----------------------------------------------" << endl;
  
  
  return 0;
}