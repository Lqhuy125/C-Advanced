#ifndef __OTO_H
#define __OTO_H

#include <Car.h>
#include <iostream>

using namespace std;

class Oto : public Car{

    private:
    int SO_GHE;
    string KIEU_DONG_CO;

    public:
    Oto(string hangxe, string mauxe, int sobanh, int soghe, string dongco) : Car(hangxe, mauxe, sobanh), SO_GHE(soghe), KIEU_DONG_CO(dongco) {}

    void hienThi();
    string getType() const override {
        return "Oto";
    }
    
};


#endif