/* 
    1. Thêm mới sinh viên
    2. Cập nhật thông tin sinh viên
    3. Xoá sinh viên bằng ID
    4. Tìm kiếm sinh viên theo tên ( Nhập tên in ra các thong tin của đối tượng)
    5. Sắp xếp sinh viên theo điểm trung bình
    6. Sắp xếp sinh viên theo tên
    7. Hiển thị danh sách sinh viên
 */
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
void SinhVien::changeName(){
    string new_name;
    cout<<"Enter new name: ";
    cin>>new_name;
    NAME = new_name;
}
void SinhVien::changeGender(){
    int number;
    do{
        cout << "Enter student new gender(0:Female 1:Male): ";
        
        cin>>number;
        if(number == 0) GIOITINH = NU;
        else GIOITINH = NAM;
        if(number > 1 || number < 0){
            cout<<"Gioi tinh khong thoa man\nEnter student gender agian: ";
        }
    }
    while(number > 1 || number < 0);
}
void SinhVien::changeAge(){
    int tuoi;
    do{
        cout<<"Enter student age: ";
        cin>>tuoi;
        TUOI = tuoi;
        if(tuoi > 50 || tuoi < 18){
            cout<<"Please enter age again!\nEnter student age(18->50): ";
        }
    }
    while(tuoi > 50 || tuoi < 18);
}
void SinhVien::changeToan(){
    float toan;
    do{
        cout<<"enter math point: ";
        cin>>toan;
        DIEMTOAN = toan;
        if(toan < 0 || toan > 10){
            cout<<"Diem khong thoa man\nEnter math point agian: ";
        }
    }
    while(toan < 0 || toan > 10);
}
void SinhVien::changeVan(){
    float diemvan;
    do{
        cout<<"enter math point: ";
        cin>>diemvan;
        DIEMVAN = diemvan;
        if(diemvan < 0 || diemvan > 10){
            cout<<"Diem khong thoa man\nEnter van point agian: ";
        }
    }
    while(diemvan < 0 || diemvan > 10);
}
void SinhVien::changeLy(){
    float diemly;
    do{
        cout<<"enter math point: ";
        cin>>diemly;
        DIEMLY = diemly;
        if(diemly < 0 || diemly > 10){
            cout<<"Diem khong thoa man\nEnter ly point agian: ";
        }
    }
    while(diemly < 0 || diemly > 10);
}
void SinhVien::information(){
    cout<<"-----------------------------------\n";
    cout<<"ID: "<<ID<<endl;
    cout<<"Name: "<<NAME<<endl;
    cout<<"Age: "<<TUOI<<endl;
    cout<<"Gender: "<<GIOITINH<<endl;
    cout<<"Diem Toan: "<<DIEMTOAN<<endl;
    cout<<"Diem Van: "<<DIEMVAN<<endl;
    cout<<"Diem Ly: "<<DIEMLY<<endl;
}

SinhVien::SinhVien(string name, int tuoi, typeGioiTinh gioitinh, float ly, float Toan, float Van){
    static int id = 1000;
    ID = id++;
    
    NAME = name;
    TUOI = tuoi;
    GIOITINH = gioitinh;
    DIEMLY = ly;
    DIEMTOAN = Toan;
    DIEMVAN = Van;
}

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
void menu::sortStudentbyGPA(){
    list<SinhVien>::iterator it1, it2;

    for (it1 = database.begin(); it1 != database.end(); ++it1) {
        for (it2 = next(it1); it2 != database.end(); ++it2) {
            if (it1->getDiemTB() > it2->getDiemTB()) {
                swap(*it1, *it2);
            }
        }
    }
}
void menu::sortStudentbyName(){
    list<SinhVien>::iterator it1, it2;

    for (it1 = database.begin(); it1 != database.end(); ++it1) {
        for (it2 = next(it1); it2 != database.end(); ++it2) {
            if (it1->getName() > it2->getName()) {
                swap(*it1, *it2);
            }
        }
    }
}
void menu::findStudentbyName(){
    string find_name;
    cout<<"Nhap ten sinh vien can tim: ";
    cin>>find_name;

    bool check = false;
    for(SinhVien it:database){
        if(it.getName()==find_name){
            it.information();
            check = true;
        }
    }
    if(check==false) cout<<"Ten khong ton tai\n";
}
void menu::deleteStudentbyID(){
    flag_delete: 
    int id;
    cout<<"Nhap ID sinh vien can delete: ";
    cin>>id;

    list<SinhVien>::iterator position = database.begin();
    int check=0;
    for(SinhVien item : database){
        if(item.getID() == id){
            database.erase(position);
            cout<<"Xoa thanh cong\nPress 1 de tiep tuc xoa\nPress 0 de thoat\n";
            flag_temp_delete: cout<<"enter options: ";
            int key; cin>>key;
            if(key<0 && key>1){
                cout<<"Gia tri khong hop le! Moi nhap lai";
                goto flag_temp_delete;
            }
            if(key==1) goto flag_delete;
            else{
                cout<<"Exit delete. OK\n";
                break;
            } //goto exit_delete;
        }
        check++;
        position++;
    }
    if(check==database.size()) cout<<"ID khong ton tai!\n";
    //exit_delete: 
}
void menu::updateInformationbyID(){
    int id;
    cout<<"Nhap ID sinh vien can update: ";
    cin>>id;
    //Chua check xem co ton tai ID hay khong
    for(SinhVien &it : database){
        if (it.getID() == id){
            int options;
            do{
                repeat_change:
                cout<<"choose options:"<<endl;
                cout<<"press 1 to change name."<<endl;
                cout<<"press 2 to change sex."<<endl;
                cout<<"press 3 to change age."<<endl;
                cout<<"press 4 to change diem Toan"<<endl;
                cout<<"press 5 to change diem Van"<<endl;
                cout<<"press 6 to change diem ly"<<endl;
                cout<<"press 7 to exit update student"<<endl;
                cout<<"press other number to back!"<<endl;
                cout<<"enter options:";
                
                cin>>options;
                switch (options)
                {
                case 1:
                    it.changeName();
                    break;
                case 2:
                    it.changeGender();
                    break;
                case 3:
                    it.changeAge();
                    break;
                case 4:
                    it.changeToan();
                    break;
                case 5:
                    it.changeVan();
                    break;
                case 6:
                    it.changeLy();
                    break;
                case 7:
                    goto exit_update;
                    break;  
                }
                if(options > 7 || options < 0){
                    cout<<"Number khong hop le! Hay nhap lai: \n";
                }
                else cout<<"Da sua xong\n";
            } while(options > 7 || options < 0);
                
            int temp;
            do{
                
                cout<<"1: Tiep tuc sua them\n0: Quay lai menu\nXin moi nhap: ";
                cin>>temp;
                if(temp<0 || temp>1){
                    cout<<"Nhap khong hop le! Hay nhap lai: ";
                }
                if(temp == 1) goto repeat_change;
                else if(temp == 0){
                    goto exit_update;
                    break;
                }
            } while(temp<0 || temp>1);
        }
        exit_update:
            cout<<"Exit update. OK\n";
            break;
    }
}
void menu::displayInformation(){
    for (SinhVien item : database){
        item.information();
    }
}
void menu::addSinhVien(){
    string name;
    int tuoi;
    typeGioiTinh gioitinh;
    float diemtoan, diemvan, diemly;

    while(1){
            repeat_add:
            cout<<"Enter student name: ";
            cin>>name;
            cout<<"Enter student age: ";

            flag_tuoi_add: cin>>tuoi;
            if(tuoi > 50 || tuoi < 18)
            {
                cout<<"Please enter age again!\nEnter student age(18->50): ";
                goto flag_tuoi_add;
            }

            cout << "Enter student gender(0:Female 1:Male): ";
            int number;
            flag_gender_add: cin>>number;
            if(number == 0) gioitinh = NU;
            else gioitinh = NAM;
            if(number > 1 || number < 0){
                cout<<"Gioi tinh khong thoa man\nEnter student gender agian: ";
                goto flag_gender_add;
            }

            cout<<"enter math point: ";
            flag_math: cin>>diemtoan;
            if(diemtoan < 0 || diemtoan > 10){
                cout<<"Diem khong thoa man\nEnter math point agian: ";
                goto flag_math;
            }

            cout<<"enter math point: ";
            flag_ly: cin>>diemly;
            if(diemly < 0 || diemly > 10){
                cout<<"Diem khong thoa man\nEnter ly point agian: ";
                goto flag_ly;
            }

            cout<<"enter math point: ";
            flag_van: cin>>diemvan;
            if(diemvan < 0 || diemvan > 10){
                cout<<"Diem khong thoa man\nEnter van point agian: ";
                goto flag_van;
            }

            SinhVien sv(name, tuoi, gioitinh, diemly, diemtoan, diemvan);
            database.push_back(sv);

            int temp;
            cout<<"Da nhap xong\n";
            cout<<"1: Tiep tuc them sinh vien\n0: Quay lai menu\nXin moi nhap: ";
            flag_temp: cin>>temp;
            if(temp<0 && temp>1){
                cout<<"Nhap sai! Hay nhap lai: ";
                goto flag_temp;
            }
            if(temp == 1) goto repeat_add;
            else break;
    }
}
int main()
{
    SinhVien sv1 = SinhVien("Quang", 21, NAM, 9, 7, 8); 
    SinhVien sv2 = SinhVien("Cuong", 22, NAM, 6, 7, 8); 
    SinhVien sv3 = SinhVien("Lan", 19, NU, 10,9,10); 

    menu menu;
    menu.database.push_back(sv1);
    menu.database.push_back(sv2);
    menu.database.push_back(sv3);
    while(1){
        int options;
        cout<<"*******************************************************"<<endl;
        cout<<"choose options!"<<endl;
        cout<<"press 1 to add a new student"<<endl;
        cout<<"press 2 to update student's information by ID"<<endl;
        cout<<"press 3 to delete student by ID"<<endl;
        cout<<"press 4 to find student by name"<<endl;
        cout<<"press 5 to sort students by GPA"<<endl;
        cout<<"press 6 to sort students by name"<<endl;
        cout<<"press 7 to display students list"<<endl;
        cout<<"press 8 to exit"<<endl;
        cout<<"enter options: ";
        cin>>options;

        switch (options)
        {
        case 1:
            menu.addSinhVien();
            break;
        case 2:
            menu.updateInformationbyID();
            break;
        case 3:
            menu.deleteStudentbyID();
            break;
        case 4:
            menu.findStudentbyName();
            break;
        case 5:
            menu.sortStudentbyGPA();
            break;
        case 6:
            menu.sortStudentbyName();
            break;    
        case 7:
            menu.displayInformation();
            break;
        case 8:
            goto exit_while;
            break;
        default:
            break;
        }
    }
    exit_while: cout << "Exit. Oke" << endl;
    return 0;
}
