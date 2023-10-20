#include <iostream>
#include <string>
using namespace std;

class DoiTuong{
    public:
    int TUOI;
    string TEN;
};
class SinhVien : public DoiTuong{
    public:
    int MSSV;
    string LOP;
};
class HocSinh : public SinhVien{
    public:
    int MSHS;
};

int main(int argc, char const *argv[])
{
    SinhVien sv;

    sv.MSSV = 100;
    sv.LOP = "THCN1";
    sv.TEN = "Huy";
    sv.TUOI = 20;

    HocSinh hs;
    hs.MSHS;
    hs.MSSV;
    hs.LOP;
    hs.TUOI;
    hs.TEN;

    return 0;
}
