#include <iostream>
using namespace std;

class hPendapatan
{
public:
    hPendapatan(int TOTAL = 0 , int TGL = 0, int BLN = 0, int TH = 0)
    {
      total = TOTAL;
      tgl = TGL;
      bln = BLN;
      th = TH;
      
    }

    int total;
    int tgl;
    int bln;
    int th;
}