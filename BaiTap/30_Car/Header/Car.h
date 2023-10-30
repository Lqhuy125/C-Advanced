#ifndef __CAR_H
#define __CAR_H

#include <iostream>

using namespace std;

class Car
{
    protected:
        string HANG_XE;
        string MAU_XE;
        int SO_BANH;
    public:
        Car(string hangxe, string mauxe, int sobanh) : HANG_XE(hangxe), MAU_XE(mauxe), SO_BANH(sobanh) {}

        virtual void hienThi() const;
        virtual string getType() const = 0;
};



#endif