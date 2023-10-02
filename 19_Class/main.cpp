#include <iostream>
#include <string>
using namespace std;

class SinhVien{ //vd 0x01
    public:

        //Set up conductor (class init)
        //Khoi tao gia trị ban dau

        // Conductor khong co tham so dau vao
        // SinhVien()
        // {
        //     static int s_mssv = 10000;
        //     name = "Tuan";
        //     age = 20;
        //     mssv = s_mssv;
        //     s_mssv++;
        //     lop = "TDH1";
        // }

        //conductor co tham so dau vao
        SinhVien(string l_ten, int l_tuoi, string l_lop)
        {
            static int s_mssv = 10000;
            name = l_ten;
            age = l_tuoi;
            mssv = s_mssv;
            s_mssv++;
            lop = l_lop;
        }


        string name;    //property   //0x01
        int age;        
        static int mssv;       
        string lop;

        void display();      //method
        

        //Detector
        //Thu hoi vung nho cua 
        ~SinhVien(){
            cout<<"Huy object "<< name <<endl;
        }
};

//Khoi tao ban dau
int SinhVien::mssv;

void SinhVien::display(){
    {
            cout<<"Ten: "<<name<<endl; 
            cout<<"Age: "<<age<<endl;
            cout<<"Mssv: "<<mssv<<endl;
            cout<<"Lop: "<<lop<<endl;
        }
}
int main(int argc, char const *argv[])
{
    //Su dung conductor k co parameter
    // SinhVien sv1; //object
    // sv1.age = 20;
    // sv1.name = "Hoang";
    // sv1.lop = "THCN2";
    // sv1.display();

    // cout<<"-------------------"<<endl;
    
    // SinhVien sv2; //object
    // sv2.age = 20;
    // sv2.name = "Cuong";
    // sv2.lop = "THCN1";
    // sv2.display();


    //su dung conductor có tham số
    SinhVien sv1("Tuan", 22, "KTD01"), sv2("Nam", 21, "THCN2");
    sv1.display();
    cout<<"-------------------"<<endl;
    sv2.display();


    return 0;
}
