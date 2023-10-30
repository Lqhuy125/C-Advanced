#include <Motor.h>

void Motor::hienThi(){
    Car::hienThi();
    cout << "Xe motor loai: " << LOAI_XE << "." << endl;
}