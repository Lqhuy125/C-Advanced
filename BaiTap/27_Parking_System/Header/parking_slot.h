#ifndef __PARKING_SLOT_
#define __PARKING_SLOT_

#include <iostream>

using namespace std;

class Dimensions
{
private:
    float length;
    float width;
public:
    Dimensions(float l, float w) : length(l), width(w) {};

    float getLength();
    float getWidth();
};

typedef enum{   //se Code o file vehicle.h
    MOTOBIKE,
    CAR, 
    bike
} VehicleType;

class ParkingSlot
{
private:
    Dimensions Slotsize;
public:
    bool isOccupied;        //Trạng thái vị trí đỗ
    VehicleType slotType;   //Loại vị trí(xe máy, ô tô, ...)
    int slotNumber;         //STT của xe đó

    ParkingSlot(VehicleType type, int number, Dimensions size) : isOccupied(false), slotType(type), slotNumber(number), Slotsize(size) {};

    bool checkStatus();
    void updateStatus(bool status);
    VehicleType getSlotType();
    int getSlotNumber();
    Dimensions getSize();
};

#endif