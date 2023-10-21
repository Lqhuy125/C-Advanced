#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

typedef enum{
    NU,
    NAM
} typeGioiTinh;

typedef enum{
    GIOI,
    KHA,
    TRUNGBINH,
    YEU
} typeHocLuc;

class SinhVien{
    private:
        int ID;
        string NAME;
        int TUOI;
        typeGioiTinh GIOITINH;
        typeHocLuc HOCLUC;
        float DIEMTB;
        double DIEMLY, DIEMTOAN, DIEMVAN;
    public:
        SinhVien(string name, int tuoi, typeGioiTinh gioitinh, float diemLy, float diemToan, float diemVan);
        double getDiemTB() {
             DIEMTB = (DIEMLY+DIEMTOAN+DIEMVAN)/3; 
             return DIEMTB; 
        }
        typeHocLuc getHocLuc(){
            //DIEMTB = (DIEMLY+DIEMTOAN+DIEMVAN)/3;
            if(DIEMTB >= 8) HOCLUC = GIOI;
            else if (DIEMTB >= 6.5) HOCLUC = KHA;
            else if(DIEMTB >= 5) HOCLUC = TRUNGBINH;
            else HOCLUC = YEU;
            return HOCLUC;
        };

        int getID() {return ID;};
        string getName() {return NAME;};
        int getTuoi()  {return TUOI;};
        typeGioiTinh getGioiTinh() {return GIOITINH;};
        float getDiemToan() {return DIEMTOAN;};
        float getDiemLy() {return DIEMLY;};
        float getDiemVan() {return DIEMVAN;};

        void information();

        void changeName();
        void changeGender();
        void changeAge();
        void changeToan();
        void changeVan();
        void changeLy();
};

class menu{
    public:
        list<SinhVien> database;

        void addSinhVien();
        void displayInformation();
        void updateInformationbyID();
        void deleteStudentbyID();
        void findStudentbyName();
        void sortStudentbyGPA();
        void sortStudentbyName();
};