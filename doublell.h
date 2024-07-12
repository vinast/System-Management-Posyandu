  #include<iostream>
using namespace std;

struct Nodeee
{
	string ibu;
  string namaBalita;
  double tinggi;
  double berat;
  double umur;
  int norekam;
	Nodeee *next;
	Nodeee *prev;
};

Nodeee *head;
Nodeee *tail;

class DoubleLinkedList{
	public:
		void inisialisasi()
		{
			head = NULL;
			tail = NULL;
		}
		int isEmpt()
		{
			if(head == NULL)
			{
				return 1;
			}
			else
			{
				return 0;
			}
	}





void inputData(int norekam,string namaBalita,string ibu, double tinggi, double berat, double umur)
		{
		  Nodeee *input = new Nodeee;
      input -> norekam = norekam;
      input -> namaBalita = namaBalita;
			input -> ibu = ibu;
			input -> tinggi = tinggi;
			input -> berat = berat;
      input -> umur = umur;
			input -> next = NULL;
			input -> prev = NULL;
			if(isEmpt()==1)
			{
				head = input;
				head->next = NULL;
				head->prev = NULL;
				tail = head;
			}
			else
			{
				tail->next = input;
				input->prev = tail;
				tail = input;
			}
		}





void hapusData()
		{
			string name;
			if(head!=NULL)
			{
				if(head->next!=NULL)
				{
					Nodeee *hapus = head;
					name = head->namaBalita;
					cout<<"\nData "<<name<<" Telah Dihapus";
          cout <<endl;
					head = head->next;
					head->prev = NULL;
					delete hapus;
				}
				else
				{
					name = head->namaBalita;
					cout<<"\nData "<<name<<" Telah Dihapus";
          cout<<endl;
					head = NULL;
				}
			}
			else
			{
				cout<<"\nLinked List Kosong Tiddak Dapat Melakukan Penghapusan!!!";
        cout <<endl;
			}
		}





void tampilData()
		{
			Nodeee *cetak  = head;
			if(head!=NULL)
			{
        
				while(cetak!=NULL)
				{
          int i=0;
					while(cetak!=NULL)
					{
            cout <<"List Ke - "<<i+1<<endl;
            cout<<"----------------------------------------------"<<endl;
            cout<<"No rekam medis       : "<<cetak->norekam;
            cout <<endl;
						cout<<"Nama Balita          : "<<cetak->namaBalita;
            cout <<endl;
            cout<<"Nama Ibu             : "<<cetak->ibu;
            cout <<endl;
						cout<<"Tinggi Balita        : "<<cetak->tinggi;
            cout <<endl;
						cout<<"Berat Balita         : "<<cetak->berat;
            cout <<endl;
            cout<<"Umur Balita          : "<<cetak->umur;
            cout <<endl;
            cout<<"----------------------------------------------"<<endl;
						cetak = cetak->next;
            i++;
					}
				}
			}
			else
			{
				cout<<"Data Kosong";
        cout<<endl;
			}
		}
};