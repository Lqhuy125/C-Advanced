#ifndef __MOTOR_H
#define __MOTOR_H

#include <Car.h>
#include <iostream>
#include <Motor.h>

using namespace std;

class Motor : public Car{
    private: 
        string LOAI_XE;
    public:
        Motor(string hangxe, string mauxe, int sobanh, string loaixe) : Car(hangxe, mauxe, sobanh), LOAI_XE(loaixe) {};

        void hienThi();
        string getType() const override {
            return "Motor";
        }
};

#endif