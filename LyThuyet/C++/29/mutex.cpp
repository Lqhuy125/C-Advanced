/* 
    Problem: 1 app ngan hang co 2 function

    func1: nap tien
    func2: rut tien

    Chi 1 trong 2 func duoc thuc hien trong cung thoi diem

    case: 1: nap xong roi rut
          2: rut xong roi nap

    Vì vậy cần khoá các điều kiện cho nhau      
*/

#include <iostream>
#include <thread> // Da luong
#include <chrono> // Tao delay
#include <mutex>

using namespace std;

int taiKhoan = 100;
//khai bao bien voi kieu du lieu mutex toan cuc
mutex taiKhoanMutex; 

void napTien(int soTien){

    lock_guard<mutex> lock(taiKhoanMutex); 
    //khi duoc goi lenh nay voi bien taiKhoanMutex toan cuc 
    //thi chi co the su dung 1 trong 2 khi lenh nay duoc viet

    taiKhoan += soTien;

    cout << "Tai khoan: " << soTien << endl;
}

void rutTien(int soTien){
    lock_guard<mutex> lock(taiKhoanMutex);

    taiKhoan += soTien;

    cout << "Tai khoan: " << soTien << endl;

}
int main(int argc, char const *argv[])
{
    thread t1(napTien, 20); // co bao nhieu parameter thi truyen bay nhieu vao
    thread t2(rutTien, 20);

    t1.join();
    t2.join();
    
    return 0;
}
