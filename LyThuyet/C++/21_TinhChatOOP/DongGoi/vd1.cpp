//Tính đống gói: object không thể truy cập trực tiếp vào các property mà phải thông qua method
#include <iostream>
#include <string>

using namespace std;


class DoiTuong{
    protected:
        int TUOI;
        string TEN;
    public:
        void SetThongTin(string ten, int tuoi);
        void getThongTin();
};
void DoiTuong::SetThongTin(string ten, int tuoi){
    if(tuoi == 0) cout<<"Khong hop le"<<endl;
    else
    {
        TEN = ten;
        TUOI = tuoi;
    }
}
void DoiTuong::getThongTin(){
    cout<<"Ten: "<<TEN<<endl;
    cout<<"Tuoi: "<<TUOI<<endl;
}

class SinhVien : public DoiTuong{
    public:
        
        int MSSV;
        string LOP;

        
        void SetThongTin(string ten, int tuoi, int mssv, string lop){ //override
            TEN = ten;
            TUOI = tuoi;
            MSSV = mssv;
            LOP = lop;
        }

        void getThongTin(){
            cout<<"Ten: "<<TEN<<endl;
            cout<<"Tuoi: "<<TUOI<<endl;
            cout<<"Lop: "<<LOP<<endl;
            cout<<"MSSV: "<<MSSV<<endl;
        }
        
};


int main(int argc, char const *argv[])
{
    DoiTuong dt; // dt is object
    dt.SetThongTin("Huy", 11);
    dt.getThongTin();

    SinhVien sv;
    sv.SetThongTin("Cuong", 22, 1001, "THCN2");
    sv.getThongTin();



    return 0;
}
