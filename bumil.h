#include <iostream>
#include <string>
using namespace std;

class bumil
{
public:
    bumil(int NOREKAMHML = 0, string IBUHML = "", int USIAHML = 0, int BERATHML = 0, int USIAIB = 0, int LAHIRTGL = 0, int LAHIRBLN = 0, int LAHIRTH = 0)
    {
        norekamib = NOREKAMHML;
        // namaBalita = NAMA;
        ibu_hamil = IBUHML;
        usia_hamil = USIAHML;
        // tinggi = TINGGI;
        brtib_hamil = BERATHML;
        usiaib = USIAIB;
        hpl_TGL = LAHIRTGL;
        hpl_BLN = LAHIRBLN;
        hpl_TH = LAHIRTH;
    }
    int norekamib;
    string ibu_hamil;
    double usia_hamil;
    // double tinggi;
    double brtib_hamil; 
    double usiaib;
    double hpl_TGL;
    double hpl_BLN;
    double hpl_TH;

    // string namaB; 
};