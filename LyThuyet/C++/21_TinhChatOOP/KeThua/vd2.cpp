#include <iostream>
#include <string>

using namespace std;

class DoiTuong{
    public:
        int TUOI;
        string TEN;

        void SetThongTin(string ten, int tuoi);
        void getThongTin();
};
void DoiTuong::SetThongTin(string ten, int tuoi){
    TEN = ten;
    TUOI = tuoi;
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
    dt.SetThongTin("Huy", 21);
    dt.getThongTin();

    SinhVien sv;
    sv.SetThongTin("Cuong", 22, 1001, "THCN2");
    sv.getThongTin();



    return 0;
}
